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

#include <zlib.h>

/* max number of bytes to write in a IDAT chunk */
#define CHUNK 16384

#define ABS(A) ((A) < 0 ? -(A) : (A))

#define _png_crc32 0xedb88320UL
#define _png_crc32_init 0xffffffffL
#define _png_chunk_IEND (struct _png_chunk){0ULL, {'I', 'E', 'N', 'D'}, NULL, _crc32("IEND", 4)}
#define _png_IHDR_data_size 13UL

#if defined(_DEBUG) && !defined(DEBUG)
#undef _DEBUG
#define DEBUG
#elif defined(NDEBUG) && !defined(DEBUG)
#undef NDEBUG
#define DEBUG
#endif

enum endianness
{
    _big_endian = 0,
    _little_endian,
    _png_undefined,
};

/* Function Prototypes */
void swap_endianness(void* ptr, size_t size);
int get_chunk(FILE* fp, uint32_t* frame_length, uint8_t** buffer, size_t* buff_len);
int png_allocate(png_s* image);
int png_inflate(FILE* source, uint32_t input_size, uint8_t** buffer, size_t* buff_size, uint8_t* output, size_t output_size);
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
 * @param bit_depth specifies the bit depth of the colour format
 * @return png_s* returns NULL and sets SPNG_ERRNO on error, returns a new png_s* on success
 */
png_s* png_create
(uint32_t width, uint32_t height, _png_colour_type colour_format, _png_bit_depth bit_depth)
{
    /* check for bad colour format and bit depth combinations */
    if(colour_format == 0 && (bit_depth != 1 && bit_depth != 2 && bit_depth != 4 && bit_depth != 8 && bit_depth != 16)){
        SPNG_ERRNO = SPNG_BAD_PARAM;
        return NULL;
    }
    else if(colour_format == 2 && (bit_depth != 8 && bit_depth != 16))
    {
        SPNG_ERRNO = SPNG_BAD_PARAM;
        return NULL;
    }
    else if(colour_format == 3 && (bit_depth != 1 && bit_depth != 2 && bit_depth != 4 && bit_depth != 8))
    {
        SPNG_ERRNO = SPNG_BAD_PARAM;
        return NULL;
    }
    else if(colour_format == 4 && (bit_depth != 8 && bit_depth != 16))
    {
        SPNG_ERRNO = SPNG_BAD_PARAM;
        return NULL;
    }
    else if(colour_format == 6 && (bit_depth != 8 && bit_depth != 16))
    {
        SPNG_ERRNO = SPNG_BAD_PARAM;
        return NULL;
    }
    else if(colour_format !=0 && colour_format != 2 && colour_format != 3 && colour_format != 4 && colour_format != 6)
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
    png_struct->IHDR_data = (struct _png_IHDR_data){width, height, bit_depth, colour_format, 0, 0, 0};
    png_struct->IHDR = (struct _png_chunk){13ULL, {'I', 'H', 'D', 'R'}, &(png_struct->IHDR_data), 0ULL};
    png_struct->PLTE = (struct _png_chunk){0ULL , {'P', 'L', 'T', 'E'}, NULL, 0ULL};
    png_struct->IDAT = (struct _png_chunk){0ULL , {'I', 'D', 'A', 'T'}, NULL, 0ULL};
    png_struct->IEND = _png_chunk_IEND;
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
    png_struct->extra_chunks = 0;

    /* computes data helpful for changing colours of pixels */
    int ndepth = colour_format == png_greyscale || colour_format == png_colour_palette ? 1 : colour_format == png_greyscale_alpha ? 2 : colour_format == png_truecolour ? 3 : 4;
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
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        SPNG_ERRNO = SPNG_IO_ERROR;
        return NULL;
    }
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
    image->IEND = _png_chunk_IEND;
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
        free(image);
        free(data);
        free(image->extra_chunks);
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
            if(get_endianness() == _little_endian) swap_endianness(data + 4, 4);
            memcpy(&(image->width), data + 4, 4);
            image->IHDR_data.width = image->width;

            if (get_endianness() == _little_endian) swap_endianness(data + 8, 4);
            memcpy(&(image->height), data + 8, 4);
            image->IHDR_data.height = image->height;

            image->IHDR_data.bit_depth = data[12];
            image->bit_depth = (int)data[12];
            image->IHDR_data.colour_type = data[13];
            image->colour_format = (int)data[13];
            image->IHDR_data.compression_method = data[14];
            image->IHDR_data.filter_method = data[15];
            image->IHDR_data.interlace_method = data[16];
            image->swapped = 0;

            /* computes data helpful for changing colours of pixels */
            int colour_format = image->colour_format;
            int ndepth = colour_format == png_greyscale || colour_format == png_colour_palette ? 1 : colour_format == png_greyscale_alpha ? 2 : colour_format == png_truecolour ? 3 : 4;
            image->bytes_per_pixel = (ndepth * image->bit_depth + 7)/ 8;
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
            image->PLTE.name[0] = 'P';
            image->PLTE.name[1] = 'L';
            image->PLTE.name[2] = 'T';
            image->PLTE.name[3] = 'E';
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
        else if (strncmp((const char*)data, "IDAT", 4) == 0)
        {
            if (png_inflate(fp, chunk_size, &data, &data_length, image->data, image->data_size)
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
    if (ferror(fp) || buffer == NULL || chunk_length == NULL || buff_len == NULL)
    {
        SPNG_ERRNO = SPNG_BAD_PARAM;
        return SPNG_ERROR;
    }
    /* read the chunk length */
    size_t ret = fread(chunk_length, 1, 4, fp);
    if(get_endianness() == _little_endian) swap_endianness(chunk_length, 4);
    if (ret != 4ULL || ferror(fp))
    {
        fseek(fp, -(long)ret, SEEK_CUR);
        SPNG_ERRNO = SPNG_IO_ERROR;
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
    /* read the chunk data */
    ret = fread(*buffer, 1, (size_t)*chunk_length + 8ULL, fp);
    if (ret != (size_t)*chunk_length + 8ULL || ferror(fp))
    {
        fseek(fp, -((long)ret + 4), SEEK_CUR);
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
    /* PNG signature */
    fputs("\x89PNG\r\n\x1A\n", fp);

    /******************************** IHDR CHUNK ********************************/
    if(get_endianness() == _little_endian && !image->swapped)
    {
        /* swap the byte order on fields > 1 byte in size */
        swap_endianness(&image->IHDR.length, 4UL);
        swap_endianness(&image->IHDR_data.width, 4UL);
        swap_endianness(&image->IHDR_data.height, 4UL);
        /* compute the CRC32 then swap the byte order */
        image->IHDR.crc = part_crc32((image->IHDR.name), 4UL, _png_crc32_init);
        image->IHDR.crc = part_crc32(&(image->IHDR_data.width), 4UL, image->IHDR.crc);
        image->IHDR.crc = part_crc32(&(image->IHDR_data.height), 4UL, image->IHDR.crc);
        image->IHDR.crc = part_crc32(&(image->IHDR_data.bit_depth), 1UL, image->IHDR.crc);
        image->IHDR.crc = part_crc32(&(image->IHDR_data.colour_type), 1UL, image->IHDR.crc);
        image->IHDR.crc = part_crc32(&(image->IHDR_data.compression_method), 1UL, image->IHDR.crc);
        image->IHDR.crc = part_crc32(&(image->IHDR_data.filter_method), 1UL, image->IHDR.crc);
        image->IHDR.crc = part_crc32(&(image->IHDR_data.interlace_method), 1UL, image->IHDR.crc) ^ 0xffffffffL;
    }
    else
    {
        /* if the CPU is already big endian then we can just compute the crc32 */
        image->IHDR.crc = part_crc32((image->IHDR.name), 4UL, _png_crc32_init);
        image->IHDR.crc = part_crc32(&(image->IHDR_data.width), 4UL, image->IHDR.crc);
        image->IHDR.crc = part_crc32(&(image->IHDR_data.height), 4UL, image->IHDR.crc);
        image->IHDR.crc = part_crc32(&(image->IHDR_data.bit_depth), 1UL, image->IHDR.crc);
        image->IHDR.crc = part_crc32(&(image->IHDR_data.colour_type), 1UL, image->IHDR.crc);
        image->IHDR.crc = part_crc32(&(image->IHDR_data.compression_method), 1UL, image->IHDR.crc);
        image->IHDR.crc = part_crc32(&(image->IHDR_data.filter_method), 1UL, image->IHDR.crc);
        image->IHDR.crc = part_crc32(&(image->IHDR_data.interlace_method), 1UL, image->IHDR.crc) ^ 0xffffffffL;
    }
    if (get_endianness() == _little_endian)
    {
        swap_endianness(&image->IHDR.crc, 4UL);
    }
    fwrite(&image->IHDR.length, 4UL, 1UL, fp);
    fwrite(&image->IHDR.name, 4UL, 1UL, fp);
    fwrite(&image->IHDR_data.width, 4UL, 1UL, fp);
    fwrite(&image->IHDR_data.height, 4UL, 1UL, fp);
    fputc(image->IHDR_data.bit_depth, fp);
    fputc(image->IHDR_data.colour_type, fp);
    fputc(image->IHDR_data.compression_method, fp);
    fputc(image->IHDR_data.filter_method, fp);
    fputc(image->IHDR_data.interlace_method, fp);
    fwrite(&image->IHDR.crc, 4UL, 1UL, fp);

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
            fwrite(&length, 1, 4, fp);
            fwrite(image->extra_chunks[index].name, 1, 4, fp);
            fwrite(image->extra_chunks[index].data, 1, image->extra_chunks[index].length, fp);
            fwrite(&(image->extra_chunks[index].crc), 1, 4, fp);
        }
    }

    /* certain chunks never change so there is no reason to recompute lengths and crc32's */
    /* sRGB CHUNK */
    if(!chunks_have_sRGB) fwrite("\x00\x00\x00\x01sRGB\x00\xae\xce\x1c\xe9", 1UL, 13UL, fp);
    /* gAMA CHUNK */
    if(!chunks_have_gAMA) fwrite("\x00\x00\x00\x04gAMA\x00\x00\xb1\x8f\x0b\xfc\x61\x05", 1UL, 16UL, fp);

    /******************************** PLTE CHUNK ********************************/
    if(image->colour_format == png_colour_palette)
    {
        
        if(get_endianness() == _little_endian && !image->swapped) swap_endianness(&image->PLTE.length, 4UL);
        fwrite(&image->PLTE.length, 4UL, 1UL, fp);
        fwrite(&image->PLTE.name, 4UL, 1UL, fp);
        image->PLTE.crc = 0xb45776aa; /* part_crc32(image->PLTE.name, 4UL, _png_crc32_init); */
        int i;
        int num_colours = 1 << image->bit_depth;
        for(i = 0; i < num_colours; i++)
        {
            if(get_endianness() == _little_endian && !image->swapped) swap_endianness((char*)image->PLTE.data + 4UL * (size_t)i, 4);
            image->PLTE.crc = part_crc32((char*)image->PLTE.data + 1UL + 4UL * (size_t)i, 3UL, image->PLTE.crc);
            fwrite((char*)image->PLTE.data + 1UL + 4UL * (size_t)i, 3UL, 1UL, fp);
        }
        image->PLTE.crc ^= 0xffffffffL;
        if(get_endianness() == _little_endian) swap_endianness(&image->PLTE.crc, 4UL);
        fwrite(&image->PLTE.crc, 4UL, 1UL, fp);
    }

    /******************************** IDAT CHUNK ********************************/
    const uint32_t IDAT_CRC = 0xca50f9e1; /* part_crc32("IDAT", 4, _png_crc32_init); */
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
    fwrite(&length, 4UL, 1UL, fp);
    fwrite("IDAT", 1, 4UL, fp);
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
            /* Finish current chunk and start new IDAT chunk if over size */
            if(length + have > CHUNK){
                /* overwrite the length placeholder to reflect the true value */
                fseek(fp, length_pos, SEEK_SET);
                if( get_endianness() == _little_endian) swap_endianness(&length, 4UL);
                fwrite(&length, 4UL, 1UL, fp);
                fseek(fp, 0L, SEEK_END); /* return to the end of the file */
                /* Finish the crc32 by inverting everything at the end */
                crc ^= 0xffffffffL;
                if(get_endianness() == _little_endian) swap_endianness(&crc, 4UL);
                fwrite(&crc, 4UL, 1, fp); 
                /* start new IDAT CHUNK */
                length = 0;
                crc = IDAT_CRC;
                length_pos = ftell(fp);
                fwrite(&length, 4UL, 1UL, fp);
                fwrite("IDAT", 1, 4UL, fp);
            }
            if(fwrite(out, 1, have, fp) != have || ferror(fp))
            {
                (void)deflateEnd(&strm);
                free(out);
                SPNG_ERRNO = SPNG_IO_ERROR;
                return SPNG_ERROR;
            }
            length += have;
            crc = part_crc32(out, have, crc);
        }
        while(strm.avail_out == 0);
    }
    while(flush != Z_FINISH);
    (void)deflateEnd(&strm);
    free(out);
    /* overwrite the length placeholder to reflect the true value */
    fseek(fp, length_pos, SEEK_SET);
    if( get_endianness() == _little_endian) swap_endianness(&length, 4UL);
    fwrite(&length, 4UL, 1UL, fp);
    fseek(fp, 0L, SEEK_END); /* return to the end of the file */
    /* Finish the crc32 by inverting everything at the end */
    crc ^= 0xffffffffL;
    if(get_endianness() == _little_endian) swap_endianness(&crc, 4UL);
    fwrite(&crc, 4UL, 1, fp); 

    /******************************** IEND CHUNK ********************************/
    fwrite("\0\0\0\0IEND\xae\x42\x60\x82", 12UL, 1UL, fp);
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
    if(image->data != NULL) free(image->data);
    if(image->colours != NULL) free(image->colours);
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
        size_t index = ((size_t)width + (size_t)pixels_per_byte - 1) / (size_t)pixels_per_byte + 1UL;
        index = index * y + x / pixels_per_byte + 1;
        size_t shift = ((size_t)pixels_per_byte - 1UL - (size_t)x % pixels_per_byte ) * (size_t)depth;
        image->data[index] &= ~(bitmask << shift);
        image->data[index] |= ((uint8_t)colour & bitmask) << shift;
    }
    else
    {
        int bytes_per_pixel = image->bytes_per_pixel;
        /* swap the endianness if necessary */
        if (get_endianness() == _little_endian) swap_endianness(&colour, bytes_per_pixel);
        size_t index = image->row_size * (size_t)y + (size_t)x * (size_t)bytes_per_pixel +1UL;
        int i;
        for(i = 0; i < bytes_per_pixel; i++)
        {
            image->data[index + i] = colour & 0xff;
            colour >>= depth;
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
        size_t index = ((size_t)width + (size_t)pixels_per_byte - 1) / (size_t)pixels_per_byte + 1UL;
        index = index * y + x / pixels_per_byte + 1;
        size_t shift = ((size_t)pixels_per_byte - 1UL - (size_t)x % pixels_per_byte) * (size_t)depth;
        *colour = image->data[index];
        *colour >>= shift;
        *colour &= bitmask;
    }
    else
    {
        *colour = 0;
        int bytes_per_pixel = image->bytes_per_pixel;
        size_t index = image->row_size * (size_t)y + (size_t)x * (size_t)bytes_per_pixel + 1UL;
        int i;
        for (i = 0; i < bytes_per_pixel; i++)
        {
            *colour <<= depth;
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
    if (image->colour_format == png_greyscale)
    {
        data_length = ((size_t)image->width * (size_t)image->height * (size_t)image->bit_depth + 7UL) / 8UL + 1UL * (size_t)image->height;
    }
    else if (image->colour_format == png_truecolour)
    {
        data_length = ((size_t)image->width * (size_t)image->height * (size_t)image->bit_depth * 3UL) / 8UL + (size_t)image->height;
    }
    if (image->colour_format == png_colour_palette)
    {
        data_length = ((size_t)image->width * (size_t)image->height * (size_t)image->bit_depth + 7UL) / 8UL + (size_t)image->height;
        image->PLTE.length = (1U << image->bit_depth) * 3;
        image->PLTE.data = calloc((1ULL << image->bit_depth) * 4UL, 1UL);
        if (image->PLTE.data == NULL)
        {
            SPNG_ERRNO = SPNG_MEM_ERROR;
            return SPNG_ERROR;
        }
        image->colours = image->PLTE.data;
    }
    else if (image->colour_format == png_greyscale_alpha)
    {
        data_length = (size_t)image->width * (size_t)image->height * (size_t)image->bit_depth / 4 + (size_t)image->height;
    }
    else if (image->colour_format == 6)
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
 * @param source the file to read the png data from
 * @param input_size the initial read size of the first IDAT chunk
 * @param buffer read buffer for the chunk data
 * @param buff_size the size in bytes of the buffer
 * @param output the output data buffer, usually image->data
 * @param output_size the size in bytes of the output buffer
 * @return int returns SPNG_ERROR and sets SPNG_ERRNO on error, SPNG_OK on success
 */
int png_inflate(FILE* source, uint32_t input_size, uint8_t** buffer, size_t* buff_size, uint8_t* output, size_t output_size)
{
    int retval;
    unsigned have;
    z_stream strm;
    size_t index = 0; // points to where the current data is

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
        size_t left = input_size;
        do
        {
            strm.avail_in = (uInt)left > CHUNK ? CHUNK : (uInt)left;
            strm.next_in = *buffer + 4 + input_size - left;
            left = left < CHUNK ? 0 : left - CHUNK;
            if (strm.avail_in == 0)
            {
                break;
            }
            do
            {
                strm.avail_out = output_size - index > CHUNK ? CHUNK : (uInt)(output_size - index);
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
                have = CHUNK - strm.avail_out;
                index += have;
            } while (strm.avail_out == 0);

        } while (retval != Z_STREAM_END);
        
        if (get_chunk(source, &input_size, buffer, buff_size) != SPNG_OK)
            return SPNG_ERROR;
    } while (strncmp((const char*)buffer, "IDAT", 4) == 0);
    
    (void)inflateEnd(&strm);
    return SPNG_OK;
}

