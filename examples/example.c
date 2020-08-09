/*
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

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>
#define SPNG_STATIC
#include "../include/spng/png.h"
#include "../include/spng/drawing.h"

#define WHITE 0xffffff
#define BLACK 0x000000

/* NOTE: (0, 0) is the bottom left hand corner in Simple PNG by default 
 * You can change the inversion of x and y by setting the corresponding 
 * fields in the png_s struct
 */

int main(void)
{   
    /* create a 500 x 500 pixel image */
    int width = 500;
    int height = 500;
    /* create a PNG struct with png_truecolor color type and 8 bit depth (24 bits per pixel) */
    png_s* image = png_create(width, height, png_RGB8);
    if(image == NULL)
    {
        fprintf(stderr, "Error creating png image: %s\n", spngErrorStr(SPNG_ERRNO));
        return 0;
    }
    else puts("Sent image to examples/example.png");
    /* data is allocated with calloc so default color will be 0 */
    draw_rectangle(image, 5, 5, width - 1 - 5, height - 1 - 5, 0x606060);
    /* codepage 437 is a 9*16 font */
    prints(image, "Hello World! \x03", width / 2 - (strlen("Hello World!  ") / 2) * SPNG_CHARACTER_WIDTH * 2, height/2 + SPNG_CHARACTER_HEIGHT * 2, 2, WHITE);
    if (png_write(image, "examples/example.png") != SPNG_OK)
    {
        fprintf(stderr, "Error writing 'examples/example.png': %s\n", spngErrorStr(SPNG_ERRNO));
    }
    png_free(image);
    width = SPNG_CHARACTER_WIDTH * 32;
    height = SPNG_CHARACTER_HEIGHT * 8;
    image = png_create(width, height, png_RGB8);
    if(image == NULL)
    {
        puts("Error creating png struct.");
        return 0;
    }
    int i, j;
    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 32; j++)
        {
            printc(image, i*32 + j, SPNG_CHARACTER_WIDTH * j, height - 1 - SPNG_CHARACTER_HEIGHT * i, 1, WHITE);
        }
    }
    if (png_write(image, "examples/example2.png") != SPNG_OK)
    {
        fprintf(stderr, "Error writing 'examples/example2.png': %s\n", spngErrorStr(SPNG_ERRNO));
    }
    else puts("Sent image to examples/example2.png");
    png_free(image);
    return 0;
}

