/*
 * This file is part of nbody.
 *
 * Mason Daub (C) 2020
 * https://github.com/mdaub/nbody
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

#ifndef BMP_H
#define BMP_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define BMP_HEADER_LEN 0xe // length of BMP header
#define DIB_HEADER_LEN 40 // BITMAPINFOHEADER length
extern const unsigned char codepage_437[256][18];

typedef struct _bitmap {
    uint8_t* raw;
    uint32_t* colors;
    int compression;
    uint16_t bpp;
    int32_t width;
    int32_t height;
    FILE* fp;
    char* filename;
} bitmap;

enum {

    bmp_1bpp = 1,
    bmp_2bpp = 2,
    bmp_4bpp = 4,
    bmp_8bpp = 8,
    bmp_16bpp = 16,
    bmp_24bpp = 24,
    bmp_32bpp = 32,
    NONE = 0,
    BI_RGB = 0,
    BI_RLE8 = 1,
    BI_RLE4 = 2,
    BI_BITFIELDS = 3,
    BI_JPEG = 4,
    BI_PNG = 5,
    BI_ALPHABITFIELDS = 6,
    BI_CMYK = 11,
    BI_CMYKRLE8 = 12,
    BI_CMYKRLE4 = 13
};

bitmap* bmp_open(const char*, int32_t, int32_t, uint16_t, int);

int bmp_close(bitmap*); // saves all of the data for the bitmap

// sets a pixel to a color according to the bpp
int setp(bitmap*, int32_t, int32_t, uint32_t);

int draw_circle(bitmap*, int32_t, int32_t, int32_t, uint32_t);

int draw_ring(bitmap*, int32_t, int32_t, int32_t, int32_t, uint32_t);

int draw_square(bitmap*, int32_t, int32_t, int32_t, uint32_t);

int draw_rectangle(bitmap* bmp, int32_t x0, int32_t y0, int32_t x1, int32_t y1, uint32_t col);

int draw_line(bitmap*, int32_t, int32_t, int32_t, int32_t, uint32_t, uint32_t);

int add_color(bitmap*, uint8_t, uint32_t);

void printc(bitmap*, uint32_t, int32_t, int32_t, uint32_t, uint32_t);

int prints(bitmap*, const char*, int32_t, int32_t, uint32_t, uint32_t);

#ifdef __cplusplus
}
#endif

#endif
