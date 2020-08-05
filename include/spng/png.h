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


#ifndef _SPNG_PNG_H
#define _SPNG_PNG_H

#include <stdio.h>
#include <stdint.h>

#ifdef __cplusplus
#ifndef SPNG_NO_NAMESPACE
namespace spng {
#endif
    extern "C" {
#endif

#define _SPNG_VERSION "1.3.0"
#define _SPNG_VERSION_MAJOR 1
#define _SPNG_VERSION_MINOR 3
#define _SPNG_VERSION_TWEAK 0

/* NOTE: (0, 0) is the bottom left hand corner in Simple PNG */

#if defined(SPNG_RUNTIME) && defined(SPNG_STATIC)
#error "Cannot set both SPNG_RUNTIME and SPNG_STATIC"
#endif

#if defined(_WIN32) && defined(SPNG_BUILD_SHARED)
#define SPNG_EXPORT __declspec(dllexport)
#elif defined(_WIN32) && defined(SPNG_RUNTIME) && !defined(SPNG_STATIC)
#define SPNG_EXPORT __declspec(dllimport)
#else
#define SPNG_EXPORT
#endif

/* SPNG return values */
#define SPNG_OK          0
#define SPNG_ERROR     (-1)

/* SPNG error codes */
#define SPNG_NO_ERROR        ( 0) /* clear code */
#define SPNG_MEM_ERROR       (-1) /* error allocating memory */
#define SPNG_NO_MEM          (-2) /* not enough memory passed to function */
#define SPNG_BAD_PARAM       (-3) /* bad parameters in function */
#define SPNG_CRC_ERROR       (-4) /* crc error in png file data */
#define SPNG_BAD_FILE        (-5) /* invalid file format */
#define SPNG_IO_ERROR        (-6) /* error using system io, errno should be set by them */
#define SPNG_DEFLATE_ERROR   (-7) /* issue with zlib deflate algorithm */
#define SPNG_INFLATE_ERROR   (-8) /* issue with zlib inflate algorithm */

extern int SPNG_EXPORT SPNG_ERRNO;

/**
 * @brief Returns a descriptive string about an spng error
 * @param spng_errno the simple png error number (SPNG_ERRNO)
 * @return const char* a c_string about the error
 */
SPNG_EXPORT const char* spngErrorStr(int spng_errno);


/**
 * @brief the different colour formats for png images
 */
typedef enum png_colour_type
{
    png_greyscale        = 0,
    png_truecolour       = 2,
    png_RGB              = 2,
    png_colour_palette   = 3,
    png_greyscale_alpha  = 4,
    png_truecolour_alpha = 6,
    png_RGBA             = 6,
} _png_colour_type;

/**
 * @brief the various bit depths for png images
 */
typedef enum png_bit_depth
{
    png_bd_1  = 1,
    png_bd_2  = 2,
    png_bd_4  = 4,
    png_bd_8  = 8,
    png_bd_16 = 16
} _png_bit_depth;

/**
 * @brief compression levels
 */
typedef enum png_compression
{
    png_compression_default = 9
} _png_compression;

enum filter_method
{
    png_filter_none = 0,
    png_filter_sub,
    png_filter_up,
    png_filter_average,
    png_filter_paeth
};

/**
 * @brief a structure to hold generic chunk information
 */
struct _png_chunk
{
    uint32_t length;
    char name[4];
    void *data;
    uint32_t crc;
};

/**
 * @brief a structure to hold IHDR chunk data
 */
struct _png_IHDR_data
{
    uint32_t width;
    uint32_t height;
    uint8_t bit_depth;
    uint8_t colour_type;
    uint8_t compression_method;
    uint8_t filter_method;
    uint8_t interlace_method;
};

/**
 * @brief Contains data necessary to create a png image
 * users should only access the changeable fields and read only fields
 */
typedef struct png_s
{
    /* User changeable fields */
    int _invert_x, _invert_y;
    uint32_t* colours;
    uint8_t* data;
    
    /* Read ONLY */
    size_t data_size;
    uint32_t width, height;
    int bit_depth;
    int colour_format;
    const char* filename;

    /* internal png data structures */
    struct _png_chunk IHDR;
    struct _png_IHDR_data IHDR_data;
    struct _png_chunk PLTE;
    struct _png_chunk IDAT;
    struct _png_chunk IEND;

    struct _png_chunk* extra_chunks;
    unsigned int num_extra_allocated;
    unsigned int num_extra_chunks;

    /* stored data to reduce computation time */
    unsigned char bytes_per_pixel;
    unsigned char pixels_per_byte;
    unsigned char bitmask;
    size_t row_size;

    /* to keep track if the data fields have changed endianness already */
    int swapped;
} png_s;


/**
 * @brief Creates a png object with the defined parameters
 *
 * @param width the width of the image in pixels
 * @param height the height of the image in pixels
 * @param colour_format specifies the png colour format
 * @param bit_depth specifies the bit depth of the colour format
 * @return png_s* returns NULL and sets SPNG_ERRNO on error, new png image struct on success
 */
SPNG_EXPORT png_s* png_create
(uint32_t height, uint32_t width, _png_colour_type colour_format, _png_bit_depth bit_depth);

/**
 * @brief Creates a png object from a png file
 *
 * @param filename the file path to the image
 * @return png_s* returns NULL and sets SPNG_ERROR on error, new png image struct on success
 */
SPNG_EXPORT png_s* png_open(const char* filename);

/**
 * @brief ignores crc errors on the next png_open call
 */
SPNG_EXPORT void png_ignore_crc_error();

/**
 * @brief attempts to write the PNG file define in image to a file
 *
 * @param image the png_s defining the image
 * @param filename the path to the output file
 * @return int returns SPNG_ERROR and sets SPNG_ERROR on error, SPNG_OK on success
 */
SPNG_EXPORT int png_write(png_s*, const char* filename);

/**
 * @brief Sets a pixel to a specified colour
 * The colour must be of the same format specified when the png was created
 * @param image the png object to modify
 * @param x the x coordinate of the pixel
 * @param y the y coordinate of the pixel
 * @param colour the colour value in the same format
 * @return int returns SPNG_ERROR and sets SPNG_ERRNO on error, SPNG_OK on success
 */
SPNG_EXPORT int png_setp(png_s*, uint32_t x, uint32_t y, uint64_t colour);

/**
 * @brief Gets the colour of a specific pixel
 * The colour is returned in the same format as defined in the image
 * @param image the png object to read
 * @param x the x coordinate of the pixel
 * @param y the y coordinate of the pixel
 * @param colour the colour of the pixel
 * @return int returns SPNG_ERROR and sets SPNG_ERROR on error, SPNG_OK on success
 */
SPNG_EXPORT int png_getp(png_s* image, uint32_t x, uint32_t y, uint64_t* colour);

/**
 * @brief free's the data allocated in a png struct
 * 
 * @param image the png object to free
 */
SPNG_EXPORT void png_free(png_s*);


#ifdef __cplusplus
#ifndef SPNG_NO_NAMESPACE
}
#endif
}
#endif

#endif /* ifndef __PNG_H */