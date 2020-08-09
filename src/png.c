/*
 * png.c is part of simple-png
 *
 * Mason Daub (C) 2020
 * https://github.com/mdaub/simple-png
 * 
 * See the COPYRIGHT file at the top-level directory of this distribution
 * for details of code ownership.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "../include/spng/png.h"
#include "crc32.h"
#include <errno.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include <zlib.h>

#if defined(_DEBUG) && !defined(DEBUG)
#undef _DEBUG
#define DEBUG
#elif !defined(NDEBUG) && !defined(DEBUG)
#undef NDEBUG
#define DEBUG
#endif

/* max number of bytes to write in a IDAT chunk */
#define CHUNK 16384

#define ABS(A) ((A) < 0 ? -(A) : (A))

/* Size of IHDR chunk */
#define _png_IHDR_data_size 13ULL

/* CRC constants */
#define _png_crc32 0xedb88320U
#define _png_crc32_init 0xffffffffU

/* precomputed CRCs */
#define IDAT_CRC 0xca50f9e1U
#define PLTE_CRC 0xb45776aaU

/* windows file binary mode */
#ifdef _WIN32
#include <fcntl.h>
#include <io.h>
#define SET_FILE_BINARY(x) { int _fd = _fileno(x); _setmode(_fd, _O_BINARY); }
#else 
#define SET_FILE_BINARY(x)
#endif

/* enumeration of endianness */
enum endianness
{
    _big_endian = 0,
    _little_endian,
    _png_undefined,
};

/* enumeration of the scanline filter methods */
enum filter_method
{
    png_filter_none = 0,
    png_filter_sub,
    png_filter_up,
    png_filter_average,
    png_filter_paeth
};

/* Function Prototypes */
void swap_endianness(void* ptr, size_t size);
int get_chunk(FILE* fp, uint32_t* chunk_length, uint8_t** buffer, size_t* buff_len);
int png_allocate(png_s* image);
int png_inflate(FILE* fp, uint32_t chunk_size, uint8_t* output, size_t output_size);
void png_free_chunks(png_s* image);

/* png.c global variables */
static int _endianness = _png_undefined;
static int _ignore_crc_error = 0;

int SPNG_ERRNO = SPNG_NO_ERROR;

/**
 * @brief Finds the endianness of the CPU this has been compiled for
 * it does this by creating a char pointer that points to the first byte of the int
 * since the int is equal to 1 if the char is equal to one as well the memory must be
 * stored in little endian form
 * @return int returns the endianness of the system
 */
static inline int get_endianness(void)
{
    if (_endianness != _png_undefined) return _endianness;
    int a = 1, * b = &a;
    return *(char*)(b) == 1 ? _little_endian : _big_endian;
}

/**
 * @brief Returns a descriptive string about an spng error
 * @param spng_errno the simple png error number (SPNG_ERRNO)
 * @return const char* a c_string about the error
 */
const char* spngErrorStr(int spng_errno)
{
    switch (spng_errno)
    {
    case SPNG_NO_ERROR:
        return "No error";
    case SPNG_MEM_ERROR:
        return "Error allocating memory";
    case SPNG_NO_MEM:
        return "Buffer did not contain enough space";
    case SPNG_BAD_PARAM:
        return "Parameters were out of range or invalid";
    case SPNG_CRC_ERROR:
        return "Cyclic rendundancy check failed";
    case SPNG_BAD_FILE:
        return "File is not a png image or contained bad format";
    case SPNG_IO_ERROR:
        return strerror(errno);
    case SPNG_DEFLATE_ERROR:
        return "Deflate encountered an error and was unable to continue";
    case SPNG_INFLATE_ERROR:
        return "Inflate encountered an error and was unable to continue";
    default:
        return "Invalid error number";
    }
}


/**
 * @brief Creates a png object with the defined parameters
 *
 * @param width the width of the image in pixels
 * @param height the height of the image in pixels
 * @param colour_format specifies the png colour format
 * @return png_s* returns NULL and sets SPNG_ERRNO on error, new png image struct on success
 */
png_s* png_create
(uint32_t width, uint32_t height, png_colour_format colour_format)
{
    int colour_type = colour_format & 0xf;
    int bit_depth = colour_format >> 4;
    /* check for bad colour format and bit depth combinations */
    if(colour_type == 0 && (bit_depth != 1 && bit_depth != 2 && bit_depth != 4 && bit_depth != 8 && bit_depth != 16)){
        SPNG_ERRNO = SPNG_BAD_PARAM;
        return NULL;
    }
    else if(colour_type == 2 && (bit_depth != 8 && bit_depth != 16))
    {
        SPNG_ERRNO = SPNG_BAD_PARAM;
        return NULL;
    }
    else if(colour_type == 3 && (bit_depth != 1 && bit_depth != 2 && bit_depth != 4 && bit_depth != 8))
    {
        SPNG_ERRNO = SPNG_BAD_PARAM;
        return NULL;
    }
    else if(colour_type == 4 && (bit_depth != 8 && bit_depth != 16))
    {
        SPNG_ERRNO = SPNG_BAD_PARAM;
        return NULL;
    }
    else if(colour_type == 6 && (bit_depth != 8 && bit_depth != 16))
    {
        SPNG_ERRNO = SPNG_BAD_PARAM;
        return NULL;
    }
    else if(colour_type != 0 && colour_type != 2 && colour_type != 3 && colour_type != 4 && colour_type != 6)
    {
        SPNG_ERRNO = SPNG_BAD_PARAM;
        return NULL;
    }
    /* height and width must be greater than 0 */
    if(height == 0 || width == 0)
    {
        SPNG_ERRNO = SPNG_BAD_PARAM;
        return NULL;
    }
    png_s* png_struct = (png_s*)malloc(sizeof(png_s));
    if(png_struct == NULL)
    {
        SPNG_ERRNO = SPNG_MEM_ERROR;
        return NULL;
    }
    /* initialize data members */
    png_struct->IHDR_data = (struct _png_IHDR_data){width, height, bit_depth, colour_type, 0, 0, 0};
    png_struct->IHDR = (struct _png_chunk){13ULL, {'I', 'H', 'D', 'R'}, &(png_struct->IHDR_data), 0ULL};
    png_struct->PLTE = (struct _png_chunk){0ULL , {'P', 'L', 'T', 'E'}, NULL, 0ULL};
    png_struct->IDAT = (struct _png_chunk){0ULL , {'I', 'D', 'A', 'T'}, NULL, 0ULL};
    png_struct->_invert_x = 0;
    png_struct->_invert_y = 1;
    png_struct->width = width;
    png_struct->height = height;
    png_struct->filename = NULL;
    png_struct->colours = NULL;
    png_struct->colour_format = colour_format;
    png_struct->bit_depth = bit_depth;
    png_struct->swapped = 0;

    png_struct->num_extra_chunks = 0;
    png_struct->num_extra_allocated = 0;
    png_struct->extra_chunks = NULL;

    /* computes data helpful for changing colours of pixels */
    int ndepth = colour_type == png_greyscale || colour_type == png_colour_palette ? 1 : colour_type == png_greyscale_alpha ? 2 : colour_type == png_truecolour ? 3 : 4;
    png_struct->bytes_per_pixel = ndepth * png_struct->bit_depth / 8;
    png_struct->pixels_per_byte = 8 / bit_depth;
    png_struct->bitmask = (1U << bit_depth) - 1;
    png_struct->row_size = (size_t)png_struct->width * (size_t)png_struct->bytes_per_pixel + 1;

    if(png_allocate(png_struct) != SPNG_OK)
    {
        png_free(png_struct);
        return NULL;
    }
    return png_struct;
}

/**
 * @brief Creates a png object from a png file
 *
 * @param filename the file path to the image
 * @return png_s* returns NULL and sets SPNG_ERROR on error, new png image struct on success
 */
png_s* png_open(const char* filename)
{
#ifdef DEBUG
    printf("\n**** %s(%s) ****\n", __FUNCTION__, filename);
#endif
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        SPNG_ERRNO = SPNG_IO_ERROR;
        return NULL;
    }
    SET_FILE_BINARY(fp) /* Forces windows not to convert line endings */
    png_s* image = (png_s*)malloc(sizeof(png_s));
    if (image == NULL)
    {
        fclose(fp);
        SPNG_ERRNO = SPNG_MEM_ERROR;
        return NULL;
    }

    /* initialize the png_s */
    image->IHDR = (struct _png_chunk){ 13ULL, {'I', 'H', 'D', 'R'}, &(image->IHDR_data), 0ULL };
    image->PLTE = (struct _png_chunk){ 0ULL , {'P', 'L', 'T', 'E'}, NULL, 0ULL };
    image->IDAT = (struct _png_chunk){ 0ULL , {'I', 'D', 'A', 'T'}, NULL, 0ULL };
    image->_invert_x = 0;
    image->_invert_y = 1;
    image->filename = filename;
    image->colours = NULL;

    image->num_extra_allocated = 10;
    image->num_extra_chunks = 0;
    image->extra_chunks = calloc(image->num_extra_allocated, sizeof(struct _png_chunk));

    /* allocate data for read buffer */
    size_t data_length = 65536ULL;
    uint8_t* data = (uint8_t*)malloc(data_length);
    if (data == NULL || image->extra_chunks == NULL)
    {
        fclose(fp);
        free(image);
        if(data) free(data);
        if (image->extra_chunks) free(image->extra_chunks);
        SPNG_ERRNO = SPNG_MEM_ERROR;
        return NULL;
    }
    /* Check to see if file is actually a png file */
    if (fread(data, 1, 8, fp) != 8 || strncmp("\x89PNG\x0d\x0a\x1a\x0a", (const char*)data, 8))
    {
        fclose(fp);
        free(image->extra_chunks);
        free(image);
        free(data);
        SPNG_ERRNO = SPNG_BAD_FILE;
        return NULL;
    }
    /* loop through the chunks in a file */
    while (!feof(fp))
    {
        uint32_t chunk_size;
        if (get_chunk(fp, &chunk_size, &data, &data_length) != SPNG_OK)
        {
            fclose(fp);
            free(data);
            png_free(image);
            return NULL;
        }
#ifdef DEBUG
        char name_buffer[5];
        memcpy(name_buffer, (const char*)data, 4);
        name_buffer[4] = '\0';
        printf("chunk name: '%s' size: %d\n\r", name_buffer, (int)chunk_size);
#endif
        /* IHDR chunk */
        if (strncmp((const char*)data, "IHDR", 4) == 0)
        {
            /* read the IHDR chunk fields */
            if (get_endianness() == _little_endian) swap_endianness(data + 4, 4);
            memcpy(&(image->width), data + 4, 4);
            image->IHDR_data.width = image->width;

            if (get_endianness() == _little_endian) swap_endianness(data + 8, 4);
            memcpy(&(image->height), data + 8, 4);
            image->IHDR_data.height = image->height;

            image->IHDR_data.bit_depth = data[12];
            image->bit_depth = (int)data[12];
            image->IHDR_data.colour_type = data[13];
            image->colour_format = (int)data[13] | (int)data[12] << 4;
            image->IHDR_data.compression_method = data[14];
            image->IHDR_data.filter_method = data[15];
            image->IHDR_data.interlace_method = data[16];
            image->swapped = 0;

            /* computes data helpful for changing colours of pixels */
            int colour_format = image->IHDR_data.colour_type;
            int ndepth = colour_format == png_greyscale || colour_format == png_colour_palette ? 1 : colour_format == png_greyscale_alpha ? 2 : colour_format == png_truecolour ? 3 : 4;
            image->bytes_per_pixel = (ndepth * image->bit_depth + 7) / 8;
            image->pixels_per_byte = 8 / image->bit_depth;
            image->bitmask = (1U << image->bit_depth) - 1;
            image->row_size = (size_t)image->width * (size_t)image->bytes_per_pixel + 1;

            if (png_allocate(image) != SPNG_OK)
            {
                fclose(fp);
                free(data);
                png_free(image);
                return NULL;
            }
        }
        else if (strncmp((const char*)data, "PLTE", 4) == 0)
        {
            /* png_allocate should have allocated PLTE.data already */
            if (image->PLTE.data == NULL)
            {
                fclose(fp);
                free(data);
                png_free(image);
                SPNG_ERRNO = SPNG_BAD_FILE;
                return NULL;
            }
            memcpy(image->colours, data + 4, chunk_size);
        }
        else if (strncmp((const char*)data, "tIME", 4) == 0);
        else if (strncmp((const char*)data, "IDAT", 4) == 0)
        {
            /* uncompress the data */
            if(png_inflate(fp, chunk_size, image->data, image->data_size)
                != SPNG_OK)
            {
                fclose(fp);
                free(data);
                png_free(image);
                return NULL;
            }
            uint32_t row;
            /* undo filtering on the scanlines */
            for (row = 0; row < image->height; row++)
            {
                size_t row_size = image->row_size;
                size_t row_offset = row * row_size;
                unsigned char filter_method = image->data[row_offset];
                switch (filter_method)
                {
                /* Sub filter reversal */
                case png_filter_sub:
                {
                    uint32_t x;
                    for (x = 0; x < image->width * image->bytes_per_pixel; x++)
                    {
                        uint32_t index = (uint32_t)row_offset + x + 1;
                        image->data[index] += x < image->bytes_per_pixel ? 0 : image->data[index - image->bytes_per_pixel];
                    }
                    break;
                }
                /* Up filter reversal */
                case png_filter_up:
                {
                    uint32_t x;
                    if (!row) break;
                    for (x = 0; x < image->width * image->bytes_per_pixel; x++)
                    {
                        uint32_t index = (uint32_t)row_offset + 1 + x;
                        image->data[index] += row == 0 ? 0 : image->data[index - row_size];
                    }
                    break;
                }
                /* Average filter reversal */
                case png_filter_average:
                {
                    uint32_t x;
                    for (x = 0; x < image->width * image->bytes_per_pixel; x++)
                    {
                        uint8_t* byte = &image->data[row_offset + 1 + x],
                            Sub = x < image->bytes_per_pixel ? 0 : *(byte - image->bytes_per_pixel),
                            Up = row == 0 ? 0 : *(byte - row_size);
                        *byte += ((int)Sub + (int)Up) / 2;
                    }
                    break;
                }
                /* Paeth filter reversal */
                case png_filter_paeth:
                {
                    uint32_t x;
                    for (x = 0; x < image->width * image->bytes_per_pixel; x++)
                    {
                        int
                            Sub = x - image->bytes_per_pixel,
                            Left = Sub < 0 ? 0 : image->data[row_offset + Sub + 1],
                            Up = row == 0 ? 0 : image->data[row_size * (row - 1) + x + 1],
                            Up_Left = row == 0 || Sub < 0 ? 0 : image->data[row_size * (row - 1) + 1 + Sub],
                            paeth = 0, p = Left + Up - Up_Left, pa = ABS(p - Left), pb = ABS(p - Up), pc = ABS(p - Up_Left);
                        paeth = pa <= pb && pa <= pc ? Left : pb <= pc ? Up : Up_Left;

                        image->data[row_offset + x + 1] += (unsigned char)paeth;
                    }
                    break;
                }
                }
                image->data[row_offset] = png_filter_none;
            }
        }
        /* break on IEND */
        else if (strncmp((const char*)data, "IEND", 4) == 0) break;
        /* preserve any unknown chunks */
        else
        {
            /* allocate more chunks if necessary */
            if (image->num_extra_allocated == image->num_extra_chunks)
            {
                struct _png_chunk* temp = calloc((size_t)image->num_extra_allocated * 2, sizeof(struct _png_chunk));
                if (temp == NULL)
                {
                    fclose(fp);
                    free(data);
                    png_free(image);
                    SPNG_ERRNO = SPNG_MEM_ERROR;
                    return NULL;
                }
                /* copy over the original data */
                memcpy(temp, image->extra_chunks, sizeof(struct _png_chunk)* image->num_extra_chunks);
                png_free_chunks(image);
                image->extra_chunks = temp;
                image->num_extra_allocated *= 2;
            }
            /* copy chunk info */
            memcpy(image->extra_chunks[image->num_extra_chunks].name, data, 4);
            image->extra_chunks[image->num_extra_chunks].length = chunk_size;
            image->extra_chunks[image->num_extra_chunks].data = malloc(chunk_size);
            if (image->extra_chunks[image->num_extra_chunks].data == NULL)
            {
                fclose(fp);
                free(data);
                png_free(image);
                SPNG_ERRNO = SPNG_MEM_ERROR;
                return NULL;
            }
            /* copy chunk data and CRC */
            memcpy(image->extra_chunks[image->num_extra_chunks].data, data + 4, chunk_size);
            memcpy(&image->extra_chunks[image->num_extra_chunks].crc, data + chunk_size + 4, 4);
            image->num_extra_chunks++;
        }
        /* make sure EOF flag is set */
        int c = fgetc(fp);
        ungetc(c, fp);
    }
    if (fclose(fp) < 0)
    {
        SPNG_ERRNO = SPNG_IO_ERROR;
    }
    free(data);
    _ignore_crc_error = 0;
    return image;
}

/**
 * @brief Gets chunk data from a png file
 *    Resets file pointer to original position on error and
 *    reallocates memory if the chunk is too large
 *
 * @param fp file pointer for png file
 * @param chunk_length pointer to the length in bytes of the png chunk
 *  (excludes name at the beginning and crc at the end)
 * @param buffer pointer to the buffer for the chunk data to be stored
 * @param buff_len pointer to the size of the buffer
 * @return int returns SPNG_ERROR on error and sets SPNG_ERRNO, SPNG_OK on success 
 */
int get_chunk(FILE* fp, uint32_t* chunk_length, uint8_t** buffer, size_t* buff_len)
{
    /* check for bad parameters */
    if (ferror(fp) || buffer == NULL || chunk_length == NULL || buff_len == NULL)
    {
        SPNG_ERRNO = SPNG_BAD_PARAM;
        return SPNG_ERROR;
    }
    /* read the chunk length */
    unsigned char chunk_header[8];
    size_t ret = fread(chunk_header, 1, 8, fp);
    *chunk_length = *(uint32_t*)chunk_header;
    if(get_endianness() == _little_endian) swap_endianness(chunk_length, 4);
    if (ret != 8ULL || ferror(fp))
    {
        fseek(fp, -(long)ret, SEEK_CUR);
        SPNG_ERRNO = SPNG_IO_ERROR;
        return SPNG_ERROR;
    }
    /* check that the chunk name is valid BEFORE allocating memory */
    if (!isalpha(chunk_header[4]) || !isalpha(chunk_header[5]) ||
        !isalpha(chunk_header[6]) || !isalpha(chunk_header[7]))
    {
        fseek(fp, -(long)ret, SEEK_CUR);
        SPNG_ERRNO = SPNG_BAD_FILE;
        return SPNG_ERROR;
    }
    /* Reallocate the buffer if necessary */
    if ((size_t)*chunk_length + 8ULL > *buff_len)
    {
        uint8_t* temp_buffer = (uint8_t*)malloc((size_t)*chunk_length + 8ULL);
        if (temp_buffer == NULL)
        {
            fseek(fp, -(long)ret, SEEK_CUR);
            SPNG_ERRNO = SPNG_NO_MEM;
            return SPNG_ERROR;
        }
        free(*buffer);
        *buffer = temp_buffer;
        *buff_len = (size_t)*chunk_length + 8ULL;
    }
    /* copy chunk name */
    memcpy(*buffer, chunk_header + 4, 4);
    if (strncmp((const char*)*buffer, "IDAT", 4) == 0)
    {
        return SPNG_OK; /* IDAT reading will be handled by png_inflate */
    }
    /* read the chunk data */
    ret = fread(*buffer + 4, 1, (size_t)*chunk_length + 4ULL, fp);
    if (ret != (size_t)*chunk_length + 4ULL || ferror(fp))
    {
        fseek(fp, -((long)ret + 8), SEEK_CUR);
        SPNG_ERRNO = SPNG_IO_ERROR;
        return SPNG_ERROR;
    }
    /* CRC check */
    if (!_ignore_crc_error)
    {
        uint32_t crc = _crc32(*buffer, (size_t)*chunk_length + 4ULL);
        /* swap the byte order of computed CRC so the original data is not modified */
        if (get_endianness() == _little_endian) swap_endianness(&crc, 4);
        if(crc != *(uint32_t*)(*buffer + *chunk_length + 4))
        {
            fseek(fp, -((long)ret + 4), SEEK_CUR);
            SPNG_ERRNO = SPNG_CRC_ERROR;
            return SPNG_ERROR;
        }
    }
    
    return SPNG_OK;
}


/**
 * @brief ignores crc errors on the next png_open call
 */
void png_ignore_crc_error()
{
    _ignore_crc_error = 1;
}

/**
 * @brief attempts to write the PNG file define in image to a file
 * 
 * @param image the png_s defining the image
 * @param filename the path to the output file
 * @return int returns SPNG_ERROR and sets SPNG_ERROR on error, SPNG_OK on success
 */
int png_write(png_s* image, const char* filename)
{
    if(image == NULL || filename == NULL)
    {
        errno = EINVAL;
        return EOF;
    }
    /* open file in binary mode so line ending characters are unchanged */
    FILE* fp = fopen(filename, "wb");
    if(fp == NULL)
    {
        return EOF;
    }
    SET_FILE_BINARY(fp) /* forces windows not to change line endings */
    /* PNG signature */
    fputs("\x89PNG\r\n\x1A\n", fp);

    /******************************** IHDR CHUNK ********************************/
    
    /* width and height are swapped before the CRC
     * so the byte order is the same as in the file 
     */
    if (get_endianness() == _little_endian && !image->swapped)
    {
        swap_endianness(&image->IHDR.length, 4ULL);
        swap_endianness(&image->IHDR_data.width, 4ULL);
        swap_endianness(&image->IHDR_data.height, 4ULL);
    }
    /* compute the CRC */
    image->IHDR.crc = part_crc32((image->IHDR.name), 4ULL, _png_crc32_init);
    image->IHDR.crc = part_crc32(&(image->IHDR_data.width), 4ULL, image->IHDR.crc);
    image->IHDR.crc = part_crc32(&(image->IHDR_data.height), 4ULL, image->IHDR.crc);
    image->IHDR.crc = part_crc32(&(image->IHDR_data.bit_depth), 1ULL, image->IHDR.crc);
    image->IHDR.crc = part_crc32(&(image->IHDR_data.colour_type), 1ULL, image->IHDR.crc);
    image->IHDR.crc = part_crc32(&(image->IHDR_data.compression_method), 1ULL, image->IHDR.crc);
    image->IHDR.crc = part_crc32(&(image->IHDR_data.filter_method), 1ULL, image->IHDR.crc);
    image->IHDR.crc = part_crc32(&(image->IHDR_data.interlace_method), 1ULL, image->IHDR.crc) ^ 0xffffffffU;
    /* swap the byte order of the CRC */
    if (get_endianness() == _little_endian)
    {
        swap_endianness(&image->IHDR.crc, 4ULL);
    }
    /* write the IHDR chunk */
    fwrite(&image->IHDR.length, 4ULL, 1ULL, fp);
    fwrite(&image->IHDR.name, 4ULL, 1ULL, fp);
    fwrite(&image->IHDR_data.width, 4ULL, 1ULL, fp);
    fwrite(&image->IHDR_data.height, 4ULL, 1ULL, fp);
    fputc(image->IHDR_data.bit_depth, fp);
    fputc(image->IHDR_data.colour_type, fp);
    fputc(image->IHDR_data.compression_method, fp);
    fputc(image->IHDR_data.filter_method, fp);
    fputc(image->IHDR_data.interlace_method, fp);
    fwrite(&image->IHDR.crc, 4ULL, 1ULL, fp);

    int chunks_have_sRGB = 0;
    int chunks_have_gAMA = 0;
    /* extra chunks */
    {
        size_t index;
        for (index = 0; index < image->num_extra_chunks; index++)
        {
            if (strncmp((const char*)image->extra_chunks[index].name, "sRGB", 4) == 0) chunks_have_sRGB = 1;
            if (strncmp((const char*)image->extra_chunks[index].name, "gAMA", 4) == 0) chunks_have_gAMA = 1;
            uint32_t length = image->extra_chunks[index].length;
            if (get_endianness() == _little_endian) swap_endianness(&length, 4);
            fwrite(&length, 1ULL, 4ULL, fp);
            fwrite(image->extra_chunks[index].name, 1ULL, 4ULL, fp);
            fwrite(image->extra_chunks[index].data, 1ULL, image->extra_chunks[index].length, fp);
            fwrite(&(image->extra_chunks[index].crc), 1ULL, 4ULL, fp);
        }
    }
    /* tIME chunk */
    {
        time_t t_epoch;
        time(&t_epoch);
        struct tm* t = localtime(&t_epoch);
        t->tm_year += 1900; /* tm_year is in years since 1900, and tIME expects the full number */
        unsigned char time_chunk[19] =
        {
            0, 0, 0, 7,                         /* length */
            't', 'I', 'M', 'E',                 /* name */
            t->tm_year >> 8, t->tm_year & 0xff, /* year */
            t->tm_mon + 1,                      /* month */
            t->tm_mday,                         /* day */
            t->tm_hour,                         /* hour */
            t->tm_min,                          /* minute */
            t->tm_sec,                          /* second */
            0, 0, 0, 0                          /* crc */
        };
        *(uint32_t*)(time_chunk + 15ULL) = _crc32(time_chunk + 4ULL, 11ULL);
        if (get_endianness() == _little_endian) swap_endianness(time_chunk + 15ULL, 4ULL);
        fwrite(time_chunk, 1ULL, 19ULL, fp);
    }
    /* certain chunks never change so there is no reason to recompute lengths and crc32's */
    /* sRGB CHUNK */
    if(!chunks_have_sRGB) fwrite("\x00\x00\x00\x01sRGB\x00\xae\xce\x1c\xe9", 1ULL, 13ULL, fp);
    /* gAMA CHUNK */
    if(!chunks_have_gAMA) fwrite("\x00\x00\x00\x04gAMA\x00\x00\xb1\x8f\x0b\xfc\x61\x05", 1ULL, 16ULL, fp);

    /******************************** PLTE CHUNK ********************************/
    if(image->IHDR_data.colour_type == png_colour_palette)
    {
        
        if(get_endianness() == _little_endian && !image->swapped) swap_endianness(&image->PLTE.length, 4ULL);
        fwrite(&image->PLTE.length, 4ULL, 1ULL, fp);
        fwrite(&image->PLTE.name, 4ULL, 1ULL, fp);
        image->PLTE.crc = PLTE_CRC;
        int i;
        int num_colours = 1 << image->bit_depth;
        for(i = 0; i < num_colours; i++)
        {
            if(get_endianness() == _little_endian && !image->swapped) swap_endianness((char*)image->PLTE.data + 4ULL * (size_t)i, 4ULL);
            image->PLTE.crc = part_crc32((char*)image->PLTE.data + 1ULL + 4ULL * (size_t)i, 3ULL, image->PLTE.crc);
            fwrite((char*)image->PLTE.data + 1ULL + 4ULL * (size_t)i, 3ULL, 1ULL, fp);
        }
        image->PLTE.crc ^= 0xffffffffU;
        if(get_endianness() == _little_endian) swap_endianness(&image->PLTE.crc, 4ULL);
        fwrite(&image->PLTE.crc, 4ULL, 1ULL, fp);
    }

    /******************************** IDAT CHUNK ********************************/
    
    /* initialize z_stream */
    int ret, flush;
    unsigned have;
    z_stream strm;
    /* Heap Allocate out to avoid stack overflow */
    unsigned char* out = calloc(CHUNK, sizeof(unsigned char));
    if (out == NULL)
    {
        SPNG_ERRNO = SPNG_MEM_ERROR;
        return SPNG_ERROR;
    }
    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;
    ret = deflateInit(&strm, Z_DEFAULT_COMPRESSION);
    if (ret != Z_OK)
    {
        free(out);
        SPNG_ERRNO = SPNG_DEFLATE_ERROR;
        return SPNG_ERROR;
    }
    uint32_t length = 0;
    uint32_t crc = IDAT_CRC;
    long length_pos = ftell(fp);
    fwrite(&length, 4ULL, 1ULL, fp);
    fwrite("IDAT", 1ULL, 4ULL, fp);
    uInt num_bytes = (uInt)image->data_size;
    /* PNG IDAT and deflate have a maximum chunk size so we have to loop through and do at most CHUNK bytes at a time */
    do
    {
        strm.avail_in = num_bytes >= CHUNK ? CHUNK : num_bytes;
        strm.next_in = image->data + image->data_size - num_bytes;
        num_bytes -= strm.avail_in;
        flush = num_bytes == 0 ? Z_FINISH : Z_NO_FLUSH;
        do 
        {
            strm.avail_out = CHUNK;
            strm.next_out = out;
            ret = deflate(&strm, flush);
            have = CHUNK - strm.avail_out;
            /* Finish current chunk and start new IDAT 
            chunk if over size */
            size_t out_offset = 0;
            if(length + have >= CHUNK){
                size_t num_to_write = CHUNK - length;
                out_offset = num_to_write;
                /* write the rest of the data to finish the chunk */
                if (fwrite(out, 1, num_to_write, fp) != num_to_write || ferror(fp))
                {
                    (void)deflateEnd(&strm);
                    free(out);
                    SPNG_ERRNO = SPNG_IO_ERROR;
                    return SPNG_ERROR;
                }
                have += length - CHUNK;
                length = CHUNK;
                /* overwrite the length placeholder to reflect the true value */
                fseek(fp, length_pos, SEEK_SET);
                if( get_endianness() == _little_endian) swap_endianness(&length, 4ULL);
                fwrite(&length, 4ULL, 1ULL, fp);
                fseek(fp, 0L, SEEK_END); /* return to the end of the file */
                /* Finish the crc32 */
                crc = part_crc32(out, num_to_write, crc) ^ 0xffffffffU;
                if(get_endianness() == _little_endian) swap_endianness(&crc, 4ULL);
                fwrite(&crc, 4ULL, 1ULL, fp); 
                /* start new IDAT CHUNK */
                length = 0;
                crc = IDAT_CRC;
                length_pos = ftell(fp);
                fwrite(&length, 4ULL, 1ULL, fp);
                fwrite("IDAT", 1ULL, 4ULL, fp);
            }
            /* offset is for IDAT chunks that finish in the middle of the out buffer */
            if(fwrite(out + out_offset, 1ULL, have, fp) != have || ferror(fp))
            {
                (void)deflateEnd(&strm);
                free(out);
                SPNG_ERRNO = SPNG_IO_ERROR;
                return SPNG_ERROR;
            }
            length += have;
            crc = part_crc32(out + out_offset, have, crc);
        }
        while(strm.avail_out == 0);
    }
    while(flush != Z_FINISH);
    (void)deflateEnd(&strm);
    free(out);
    /* overwrite the length placeholder to reflect the true value */
    fseek(fp, length_pos, SEEK_SET);
    if( get_endianness() == _little_endian) swap_endianness(&length, 4ULL);
    fwrite(&length, 4ULL, 1ULL, fp);
    fseek(fp, 0L, SEEK_END); /* return to the end of the file */
    /* Finish the crc32 by inverting everything at the end */
    crc ^= 0xffffffffU;
    if(get_endianness() == _little_endian) swap_endianness(&crc, 4ULL);
    fwrite(&crc, 4ULL, 1ULL, fp); 

    /******************************** IEND CHUNK ********************************/
    fwrite("\0\0\0\0IEND\xae\x42\x60\x82", 12ULL, 1ULL, fp);
    fclose(fp);
    image->swapped = 1;
    return SPNG_OK;
}


/**
 * @brief free's the data allocated in a png struct
 * 
 * @param image the png object to free
 */
void png_free(png_s* image)
{
    if(image == NULL) return;
    if(image->data) free(image->data);
    if(image->colours) free(image->colours);
    png_free_chunks(image);
    free(image);
}

void png_free_chunks(png_s* image)
{
    size_t i;
    for (i = 0; i < image->num_extra_chunks; i++)
        free(image->extra_chunks[i].data);
    free(image->extra_chunks);
}

/**
 * @brief Swaps byte order
 * 
 * @param ptr pointer to the data that needs to be flipped
 * @param size the size in bytes of the data type
 */
void swap_endianness(void* ptr, size_t size)
{
    uint8_t *data = (uint8_t*)ptr;
    size_t i;
    for(i = 0; i < size/2; i++)
    {
        uint8_t temp = data[i];
        data[i] = data[size - 1 - i];
        data[size - 1 - i] = temp;
    }
}


/**
 * @brief Sets a pixel to a specified colour
 * The colour must be of the same format specified when the png was created
 * @param image the png object to modify
 * @param x the x coordinate of the pixel
 * @param y the y coordinate of the pixel
 * @param colour the colour value in the same format
 * @return int returns SPNG_ERROR and sets SPNG_ERRNO on error, SPNG_OK on success
 */
int png_setp(png_s* image, uint32_t x, uint32_t y, uint64_t colour)
{
    if(image == NULL || x >= image->width || y >= image->height)
    {
        SPNG_ERRNO = SPNG_BAD_PARAM;
        return SPNG_ERROR;
    }
    if(image->_invert_y) y = image->height - y - 1;
    if(image->_invert_x) x = image->width  - x - 1;
    uint8_t depth = image->bit_depth;
    uint32_t width = image->width;
    if(depth < 8)
    {
        int pixels_per_byte = image->pixels_per_byte;
        uint8_t bitmask = image->bitmask;
        size_t index = ((size_t)width + (size_t)pixels_per_byte - 1) / (size_t)pixels_per_byte + 1ULL;
        index = index * y + x / pixels_per_byte + 1ULL;
        size_t shift = ((size_t)pixels_per_byte - 1ULL - (size_t)x % pixels_per_byte ) * (size_t)depth;
        image->data[index] &= ~(bitmask << shift);
        image->data[index] |= ((uint8_t)colour & bitmask) << shift;
    }
    else
    {
        int bytes_per_pixel = image->bytes_per_pixel;
        /* swap the endianness if necessary */
        if (get_endianness() == _little_endian) swap_endianness(&colour, bytes_per_pixel);
        size_t index = image->row_size * (size_t)y + (size_t)x * (size_t)bytes_per_pixel +1ULL;
        int i;
        for(i = 0; i < bytes_per_pixel; i++)
        {
            image->data[index + i] = colour & 0xff;
            colour >>= 8;
        } 
    }
    return SPNG_OK;
}

/**
 * @brief Gets the colour of a specific pixel
 * The colour is returned in the same format as defined in the image
 * @param image the png object to read
 * @param x the x coordinate of the pixel
 * @param y the y coordinate of the pixel
 * @param colour the colour of the pixel
 * @return int returns SPNG_ERROR and sets SPNG_ERRNO on error, SPNG_OK on success
 */
int png_getp(png_s* image, uint32_t x, uint32_t y, uint64_t* colour)
{
    if (image == NULL || x >= image->width || y >= image->height)
    {
        SPNG_ERRNO = SPNG_BAD_PARAM;
        return SPNG_ERROR;
    }
    if (image->_invert_y) y = image->height - y - 1;
    if (image->_invert_x) x = image->width - x - 1;
    uint8_t depth = image->bit_depth;
    uint32_t width = image->width;
    if (depth < 8)
    {
        int pixels_per_byte = image->pixels_per_byte;
        uint8_t bitmask = image->bitmask;
        size_t index = ((size_t)width + (size_t)pixels_per_byte - 1) / (size_t)pixels_per_byte + 1ULL;
        index = index * y + x / pixels_per_byte + 1ULL;
        size_t shift = ((size_t)pixels_per_byte - 1ULL - (size_t)x % pixels_per_byte) * (size_t)depth;
        *colour = image->data[index];
        *colour >>= shift;
        *colour &= bitmask;
    }
    else
    {
        *colour = 0;
        int bytes_per_pixel = image->bytes_per_pixel;
        size_t index = image->row_size * (size_t)y + (size_t)x * (size_t)bytes_per_pixel + 1ULL;
        int i;
        for (i = 0; i < bytes_per_pixel; i++)
        {
            *colour <<= 8;
            *colour |= image->data[index + i];
        }
        /* swap the endianness if necessary */
        if (get_endianness() == _little_endian) 
            swap_endianness(&colour, bytes_per_pixel);
    }
    return SPNG_OK;
}

/**
 * @brief Allocates the memory for the data fields in a png_s
 * @param image the png_s to allocate memory for
 * @return int returns SPNG_ERROR and sets SPNG_ERRNO on error, SPNG_OK on success
 */
int png_allocate(png_s* image)
{
    size_t data_length = 0;
    /* determine the size of data from IHDR data and allocate memory */
    if (image->IHDR_data.colour_type == png_greyscale)
    {
        data_length = ((size_t)image->width * (size_t)image->height * (size_t)image->bit_depth + 7ULL) / 8ULL + 1ULL * (size_t)image->height;
    }
    else if (image->IHDR_data.colour_type == png_truecolour)
    {
        data_length = ((size_t)image->width * (size_t)image->height * (size_t)image->bit_depth * 3ULL) / 8ULL + (size_t)image->height;
    }
    if (image->IHDR_data.colour_type == png_colour_palette)
    {
        data_length = ((size_t)image->width * (size_t)image->height * (size_t)image->bit_depth + 7ULL) / 8ULL + (size_t)image->height;
        image->PLTE.length = (1UL << image->bit_depth) * 3;
        image->PLTE.data = calloc((1ULL << image->bit_depth) * 4ULL, 1ULL);
        if (image->PLTE.data == NULL)
        {
            SPNG_ERRNO = SPNG_MEM_ERROR;
            return SPNG_ERROR;
        }
        image->colours = image->PLTE.data;
    }
    else if (image->IHDR_data.colour_type == png_greyscale_alpha)
    {
        data_length = (size_t)image->width * (size_t)image->height * (size_t)image->bit_depth / 4 + (size_t)image->height;
    }
    else if (image->IHDR_data.colour_type == 6)
    {
        data_length = (size_t)image->width * (size_t)image->height * (size_t)image->bit_depth / 2 + (size_t)image->height;
    }
    image->data = (uint8_t*)calloc(data_length, 1);
    if (image->data == NULL)
    {
        SPNG_ERRNO = SPNG_MEM_ERROR;
        return SPNG_ERROR;
    }
    image->data_size = data_length;
    return SPNG_OK;
}


/**
 * @brief Uses the inflate algorithm (zlib) to uncompress IDAT chunks
 * @param fp the file to read the png data from
 * @param chunk_size the size of the first IDAT chunk
 * @param output the output buffer to store the inflated data
 * @param output_size the size of the output buffer
 * @return int returns SPNG_ERROR and sets SPNG_ERRNO on error, SPNG_OK on success
 */
int png_inflate(FILE* fp, uint32_t chunk_size, uint8_t* output, size_t output_size)
{
    int retval;
    unsigned have;
    z_stream strm;
    size_t index = 0; // points to where the current data is
    size_t input_size = chunk_size > CHUNK ? chunk_size : CHUNK;
    uint8_t* input = (uint8_t*)malloc(input_size);
    if (input == NULL)
    {
        SPNG_ERRNO = SPNG_MEM_ERROR;
        return SPNG_ERROR;
    };

    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;
    strm.avail_in = 0;
    strm.next_in = Z_NULL;
    retval = inflateInit(&strm);
    if (retval != Z_OK)
    {
        SPNG_ERRNO = SPNG_INFLATE_ERROR;
        return SPNG_ERROR;
    }
    do
    {
        /* reallocate memory if needed */
        if (chunk_size > input_size)
        {
            uint8_t* temp_input = (uint8_t*)realloc(input, chunk_size);
            if (temp_input == NULL)
            {
                free(input);
                (void)inflateEnd(&strm);
                SPNG_ERRNO = SPNG_MEM_ERROR;
                return SPNG_ERROR;
            }
            input = temp_input;
            input_size = chunk_size;
        }
        /* read chunk_size bytes */
        strm.avail_in = (uInt)fread(input, 1ULL, chunk_size, fp);
        /* read the crc at the end of the chunk */
        uint32_t rx_crc;
        size_t ret = fread(&rx_crc, 1ULL, 4ULL, fp);
        if (!_ignore_crc_error)
        {
            /* calculate the crc of the recieved chunk, starting with the crc for "IDAT" */
            uint32_t crc = part_crc32(input, chunk_size, IDAT_CRC) ^ 0xffffffffU;
            if (get_endianness() == _little_endian) swap_endianness(&crc, 4ULL);
            if (ret != 4 || crc != rx_crc)
            {
                SPNG_ERRNO = SPNG_CRC_ERROR;
                return SPNG_ERROR;
            }
        }
        /* read the next chunk header */
        unsigned char next_buffer[8];
        ret = fread(next_buffer, 1ULL, 8ULL, fp);
        uint32_t next_size = *(uint32_t*)next_buffer;
        /* if the next chunk is not IDAT unget the data and set next_size to 0 */
        if (strncmp((const char*)(next_buffer + 4ULL), "IDAT", 4ULL))
        {
            fseek(fp, -(long)ret, SEEK_CUR);
            next_size = 0;
        }
        else if (get_endianness() == _little_endian) swap_endianness(&next_size, 4ULL);
        
        if (ferror(fp) || strm.avail_in != chunk_size)
        {
            (void)inflateEnd(&strm);
            SPNG_ERRNO = SPNG_IO_ERROR;
        }
        if (strm.avail_in == 0)
        {
            break;
        }
        strm.next_in = input;
        uInt avail_out;
        do
        {
            /* run inflate on the chunk */
            avail_out = (uInt)(output_size - index);
            strm.avail_out = avail_out;
            strm.next_out = output + index;
            retval = inflate(&strm, Z_NO_FLUSH);
            switch (retval)
            {
            case Z_NEED_DICT:
                retval = Z_DATA_ERROR;
            case Z_DATA_ERROR:
            case Z_MEM_ERROR:
                (void)inflateEnd(&strm);
                SPNG_ERRNO = SPNG_INFLATE_ERROR;
                return SPNG_ERROR;
            }
            have = avail_out - strm.avail_out;
            index += have;
        } while (strm.avail_out == 0 && avail_out);
        chunk_size = next_size;

    } while (retval != Z_STREAM_END && chunk_size);

    (void)inflateEnd(&strm);
    return SPNG_OK;
}
