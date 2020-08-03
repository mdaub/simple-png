/*
 * png.h is part of simple-png
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


#ifndef __PNG_H
#define __PNG_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdint.h>

#define _PNG_VERSION "1.1.0"
#define _PNG_VERSION_MAJOR 1
#define _PNG_VERSION_MINOR 1

/* NOTE: (0, 0) is the bottom left hand corner in Simple PNG */

#if defined(_WIN32) && defined(SPNG_BUILD_SHARED)
#define SPNG_EXPORT __declspec(dllexport)
#else
#define SPNG_EXPORT
#endif

enum
{
    _big_endian = 0,
    _little_endian,
    _png_undefined,
    _png_error = EOF
};

typedef enum png_color_type
{
    png_greyscale        = 0,
    png_truecolour       = 2,
    png_colour_palette   = 3,
    png_greyscale_alpha  = 4,
    png_truecolour_alpha = 6
} _png_color_type;

typedef enum png_bit_depth
{
    png_bd_1  = 1,
    png_bd_2  = 2,
    png_bd_4  = 4,
    png_bd_8  = 8,
    png_bd_16 = 16
} _png_bit_depth;

typedef enum png_compression
{
    png_compression_default = 9
} _png_compression;


struct _png_chunk
{
    uint32_t length;
    char name[4];
    void *data;
    uint32_t crc;
};

/* This struct needs to be packed since we attempt to directly write it with fwrite */
struct _png_IHDR_data
{
    uint32_t width;
    uint32_t height;
    uint8_t bit_depth;
    uint8_t color_type;
    uint8_t compression_method;
    uint8_t filter_method;
    uint8_t interlace_method;
};

/**
 * @brief A struct to hold 
 * 
 */
typedef struct png_s
{
    struct _png_chunk IHDR;
    struct _png_IHDR_data IHDR_data;
    struct _png_chunk PLTE;
    uint32_t* colors;
    struct _png_chunk IDAT;
    size_t data_size;
    uint8_t* data;
    struct _png_chunk IEND;

    int _invert_x, _invert_y;
    uint32_t width, height;
    char* filename;
} png_s;


/**
 * @brief Creates a png object with the defined parameters
 * 
 * @param width         the width of the image in pixels
 * @param height        the height of the image in pixels
 * @param color_format  specifies the png color format
 * @param bit_depth     specifies the bit depth of the color format
 * @return png_s*  returns NULL and sets errno on error, returns a pointer to the new object on success
 */
SPNG_EXPORT png_s* png_create
(uint32_t height, uint32_t width, _png_color_type color_format, _png_bit_depth bit_depth);


/**
 * @brief attempts to write the PNG file define in image to a file
 * 
 * @param image the struct png defining the image
 * @param filename the path to the output file
 * @return int returns EOF on eror, 0 otherwise
 */
SPNG_EXPORT int png_write(png_s*, const char* filename);

/**
 * @brief Sets a pixel to a specified color
 * The color must be of the same format specified when the png was created
 * @param image the png object to modify
 * @param x the x coordinate of the pixel
 * @param y the y coordinate of the pixel
 * @param color the color value in the same format
 * @return int returns 0 on success, EOF on failure and sets errno
 */
SPNG_EXPORT int png_setp(png_s*, uint32_t x, uint32_t y, uint64_t color);

/**
 * @brief free's the data allocated in a png struct
 * 
 * @param image the png object to free
 */
SPNG_EXPORT void png_free(png_s*);


#ifdef __cplusplus
}
#endif

#endif /* ifndef __PNG_H */