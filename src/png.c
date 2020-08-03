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

#include "png.h"
#include "crc32.h"
#include <errno.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include <zlib.h>
#define CHUNK 16384


int get_endianness(void);
void swap_endianness(void* ptr, size_t size);
int _endianness = _png_undefined;

#define _png_crc32 0xedb88320UL
#define _png_crc32_init 0xffffffffL
#define _png_chunk_IEND (struct _png_chunk){0ULL, {'I', 'E', 'N', 'D'}, NULL, _crc32("IEND", 4)}
#define _png_IHDR_data_size 13UL

/**
 * @brief Finds the endianness of the CPU this has been compiled for
 * it does this by creating a char pointer that points to the first byte of the int
 * since the int is equal to 1 if the char is equal to one as well the memory must be
 * stored in little endian form
 * @return int 
 */
int get_endianness(void)
{
    if(_endianness != _png_undefined) return _endianness;
    int a = 1, *b = &a;
    return *(char*)(b) == 1 ? _little_endian : _big_endian;
}


/**
 * @brief Creates a png object with the defined parameters
 * 
 * @param width         the width of the image in pixels
 * @param height        the height of the image in pixels
 * @param color_format  specifies the png color format
 * @param bit_depth     specifies the bit depth of the color format
 * @return png_s*  returns NULL and sets errno on error, returns a pointer to the new object on success
 */
png_s* png_create
(uint32_t width, uint32_t height, _png_color_type color_format, _png_bit_depth bit_depth)
{
    /* check for bad color format and bit depth combinations */
    if(color_format == 0 && (bit_depth != 1 && bit_depth != 2 && bit_depth != 4 && bit_depth != 8 && bit_depth != 16)){
        errno = EINVAL;
        return NULL;
    }
    else if(color_format == 2 && (bit_depth != 8 && bit_depth != 16))
    {
        errno = EINVAL;
        return NULL;
    }
    else if(color_format == 3 && (bit_depth != 1 && bit_depth != 2 && bit_depth != 4 && bit_depth != 8))
    {
        printf("%d", bit_depth);
        errno = EINVAL;
        return NULL;
    }
    else if(color_format == 4 && (bit_depth != 8 && bit_depth != 16))
    {
        errno = EINVAL;
        return NULL;
    }
    else if(color_format == 6 && (bit_depth != 8 && bit_depth != 16))
    {
        errno = EINVAL;
        return NULL;
    }
    else if(color_format !=0 && color_format != 2 && color_format != 3 && color_format != 4 && color_format != 6)
    {
        errno = EINVAL;
        return NULL;
    }
    /* height and width must be greater than 0 */
    if(height == 0 || width == 0)
    {
        errno = EINVAL;
        return NULL;
    }
    png_s* png_struct = (png_s*)malloc(sizeof(png_s));
    if(png_struct == NULL)
    {
        /* malloc should have set errno = ENOMEM */
        return NULL;
    }
    png_struct->IHDR_data = (struct _png_IHDR_data){width, height, bit_depth, color_format, 0, 0, 0};
    png_struct->IHDR = (struct _png_chunk){13ULL, {'I', 'H', 'D', 'R'}, &(png_struct->IHDR_data), 0ULL};
    png_struct->PLTE = (struct _png_chunk){0ULL , {'P', 'L', 'T', 'E'}, NULL, 0ULL};
    png_struct->IDAT = (struct _png_chunk){0ULL , {'I', 'D', 'A', 'T'}, NULL, 0ULL};
    png_struct->IEND = _png_chunk_IEND;
    png_struct->_invert_x = 0;
    png_struct->_invert_y = 1;
    png_struct->width = width;
    png_struct->height = height;
    png_struct->filename = NULL;
    png_struct->colors = NULL;
    size_t data_length = 0;
    /* allocate the correct amount of memory for each color format and bit depth */
    /* the extra height bytes is for the filter byte on each scan line */
    if(color_format == 0)
    {
        data_length = ((size_t)width * (size_t)height * (size_t)bit_depth + 7UL) / 8UL + 1UL * (size_t)height;
    }
    else if(color_format == 2)
    {
        data_length = ((size_t)width * (size_t)height * (size_t)bit_depth * 3UL) / 8UL + (size_t)height;
    }
    if(color_format == 3)
    {
        data_length = ((size_t)width * (size_t)height * (size_t)bit_depth + 7UL) / 8UL + (size_t)height;
        png_struct->PLTE.length = (1U << bit_depth) * 3;
        png_struct->PLTE.data = calloc((1ULL << bit_depth) * 4UL, 1UL);
        if(png_struct->PLTE.data == NULL)
        {
            free(png_struct);
            return NULL;
        }
        png_struct->colors = png_struct->PLTE.data;
    }
    else if(color_format == 4)
    {
        data_length = (size_t)width * (size_t)height * (size_t)bit_depth / 4 + (size_t)height;
    }
    else if(color_format == 6)
    {
        data_length = (size_t)width * (size_t)height * (size_t)bit_depth / 2 + (size_t)height;
    }
    png_struct->data = (uint8_t*)calloc(data_length, 1);
    png_struct->data_size = data_length;
    if(png_struct->data == NULL)
    {
        if(png_struct->PLTE.data != NULL) free(png_struct->PLTE.data);
        free(png_struct);
        return NULL;
    }
    return png_struct;
}


/**
 * @brief attempts to write the PNG file define in image to a file
 * 
 * @param image the png_s defining the image
 * @param filename the path to the output file
 * @return int returns EOF on eror, 0 otherwise
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
    if(get_endianness() == _little_endian)
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
        image->IHDR.crc = part_crc32(&(image->IHDR_data.color_type), 1UL, image->IHDR.crc);
        image->IHDR.crc = part_crc32(&(image->IHDR_data.compression_method), 1UL, image->IHDR.crc);
        image->IHDR.crc = part_crc32(&(image->IHDR_data.filter_method), 1UL, image->IHDR.crc);
        image->IHDR.crc = part_crc32(&(image->IHDR_data.interlace_method), 1UL, image->IHDR.crc) ^ 0xffffffffL;
        swap_endianness(&image->IHDR.crc, 4UL);
    }
    else
    {
        /* if the CPU is already big endian then we can just compute the crc32 */
        image->IHDR.crc = part_crc32((image->IHDR.name), 4UL, _png_crc32_init);
        image->IHDR.crc = part_crc32(&(image->IHDR_data.width), 4UL, image->IHDR.crc);
        image->IHDR.crc = part_crc32(&(image->IHDR_data.height), 4UL, image->IHDR.crc);
        image->IHDR.crc = part_crc32(&(image->IHDR_data.bit_depth), 1UL, image->IHDR.crc);
        image->IHDR.crc = part_crc32(&(image->IHDR_data.color_type), 1UL, image->IHDR.crc);
        image->IHDR.crc = part_crc32(&(image->IHDR_data.compression_method), 1UL, image->IHDR.crc);
        image->IHDR.crc = part_crc32(&(image->IHDR_data.filter_method), 1UL, image->IHDR.crc);
        image->IHDR.crc = part_crc32(&(image->IHDR_data.interlace_method), 1UL, image->IHDR.crc) ^ 0xffffffffL;
    }
    fwrite(&image->IHDR.length, 4UL, 1UL, fp);
    fwrite(&image->IHDR.name, 4UL, 1UL, fp);
    /* fwrite(&image->IHDR_data, 13UL, 1UL, fp); */
    fwrite(&image->IHDR_data.width, 4UL, 1UL, fp);
    fwrite(&image->IHDR_data.height, 4UL, 1UL, fp);
    fputc(image->IHDR_data.bit_depth, fp);
    fputc(image->IHDR_data.color_type, fp);
    fputc(image->IHDR_data.compression_method, fp);
    fputc(image->IHDR_data.filter_method, fp);
    fputc(image->IHDR_data.interlace_method, fp);
    fwrite(&image->IHDR.crc, 4UL, 1UL, fp);
    
    /* certain chunks never change so there is no reason to recompute lengths and crc32's */
    /* sRGB CHUNK */
    fwrite("\x00\x00\x00\x01sRGB\x00\xae\xce\x1c\xe9", 1UL, 13UL, fp);
    /* gAMA CHUNK */
    fwrite("\x00\x00\x00\x04gAMA\x00\x00\xb1\x8f\x0b\xfc\x61\x05", 1UL, 16UL, fp);

    /******************************** PLTE CHUNK ********************************/
    if(image->IHDR_data.color_type == png_colour_palette)
    {
        
        if(get_endianness() == _little_endian) swap_endianness(&image->PLTE.length, 4UL);
        fwrite(&image->PLTE.length, 4UL, 1UL, fp);
        fwrite(&image->PLTE.name, 4UL, 1UL, fp);
        image->PLTE.crc = part_crc32(image->PLTE.name, 4UL, _png_crc32_init);
        int i;
        int num_colors = 1 << image->IHDR_data.bit_depth;
        for(i = 0; i < num_colors; i++)
        {
            if(get_endianness() == _little_endian) swap_endianness((char*)image->PLTE.data + 4UL * (size_t)i, 4);
            image->PLTE.crc = part_crc32((char*)image->PLTE.data + 1UL + 4UL * (size_t)i, 3UL, image->PLTE.crc);
            fwrite((char*)image->PLTE.data + 1UL + 4UL * (size_t)i, 3UL, 1UL, fp);
        }
        image->PLTE.crc ^= 0xffffffffL;
        if(get_endianness() == _little_endian) swap_endianness(&image->PLTE.crc, 4UL);
        fwrite(&image->PLTE.crc, 4UL, 1UL, fp);
    }

    /******************************** IDAT CHUNK ********************************/
    const uint32_t IDAT_CRC = part_crc32("IDAT", 4, _png_crc32_init);
    /* initialize z_stream */
    int ret, flush;
    unsigned have;
    z_stream strm;
    /* Heap Allocate out to avoid stack overflow */
    unsigned char* out = calloc(CHUNK, sizeof(unsigned char));
    if (out == NULL)
        return -1;
    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;
    ret = deflateInit(&strm, Z_DEFAULT_COMPRESSION);
    if (ret != Z_OK)
    {
        free(out);
        return ret;
    }
    uint32_t length = 0;
    uint32_t crc = IDAT_CRC;
    long length_pos = ftell(fp);
    fwrite(&length, 4UL, 1UL, fp);
    fwrite("IDAT", 1, 4UL, fp);
    size_t num_bytes = image->data_size;
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
                return EOF; /* Z_ERRNO */
            }
            length += have;
            crc = part_crc32(out, have, crc);
        }
        while(strm.avail_out == 0);
        
        
    }
    while(flush != Z_FINISH);
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
    return 0;
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
    if(image->colors != NULL) free(image->colors);
    free(image);
}

/**
 * @brief Swaps the order of bytes of a variable
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
 * @brief Sets a pixel to a specified color
 * The color must be of the same format specified when the png was created
 * @param image the png object to modify
 * @param x the x coordinate of the pixel
 * @param y the y coordinate of the pixel
 * @param color the color value in the same format
 * @return int returns 0 on success, EOF on failure and sets errno
 */
int png_setp(png_s* image, uint32_t x, uint32_t y, uint64_t color)
{
    if(image == NULL || x >= image->IHDR_data.width || y >= image->IHDR_data.height)
    {
        errno = EINVAL;
        return EOF;
    }
    if(image->_invert_y) y = image->IHDR_data.height - y - 1;
    if(image->_invert_x) x = image->IHDR_data.width  - x - 1;
    uint8_t* data = image->data;
    uint8_t color_format = image->IHDR_data.color_type;
    uint8_t depth = image->IHDR_data.bit_depth;
    uint32_t width = image->IHDR_data.width;
    int ndepth = color_format == png_greyscale || color_format == png_colour_palette ? 1 : color_format == png_greyscale_alpha ? 2 : color_format == png_truecolour ? 3 : 4;
    if(depth < 8)
    {
        int pixels_per_byte = 8 / depth;
        uint8_t bitmask = (1U << depth) - 1;
        size_t index = ((size_t)width + (size_t)pixels_per_byte - 1) / (size_t)pixels_per_byte + 1UL;
        index = index * y + x / pixels_per_byte + 1;
        size_t shift = ((size_t)pixels_per_byte - 1UL - (size_t)x % pixels_per_byte ) * (size_t)depth;
        data[index] &= ~(bitmask << shift);
        data[index] |= ((uint8_t)color & bitmask) << shift;
    }
    else
    {
        int bytes_per_pixel = ndepth * depth / 8;
        if(get_endianness() == _little_endian) swap_endianness(&color, bytes_per_pixel);
        size_t index = ((size_t)width * (size_t)bytes_per_pixel + 1UL) * (size_t)y + (size_t)x * (size_t)bytes_per_pixel + 1UL;
        int i;
        for(i = 0; i < bytes_per_pixel; i++)
        {
            data[index + i] = color & 0xff;
            color >>= 8;
        } 
    }
    return 0;
}