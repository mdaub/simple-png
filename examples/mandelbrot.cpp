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

/* This file is C++ simply to demonstrate how to use spng in C++ projects */

// defining SPNG_NO_NAMESPACE will get rid of the spng namespace
//#define SPNG_NO_NAMESPACE 
#define SPNG_STATIC
#include "../include/spng/png.h"
#include "../include/spng/drawing.h"
#include <iostream>

int main(void)
{
    /* create an RGBA image with a bit depth of 8 */
    spng::png_s* mdb_image = png_create(1920, 1080, spng::png_RGBA8);
    if(mdb_image == NULL)
    {
        std::cerr << "Error creating png image: " << spng::spngErrorStr(spng::SPNG_ERRNO) << std::endl;
        return 0;
    }
    /* 
     * Determines when to stop testing if a point is in the set.
     * The more iterations the more accurate the mandelbrot set becomes, but the longer it takes to run 
     */ 
    const int max_iterations = 256;
    
    /* constants for coordinate transformation */
    const float aspect_ratio = (float)mdb_image->height / (float)mdb_image->width;
    const float x0 = -2.25f, x1 = 1.25f;
    const float y0 = -(x1 - x0) * aspect_ratio / 2.0f, y1 = -y0;
    const float hscale = (x1 - x0) / (float)mdb_image->width;
    const float vscale = (y1 - y0) / (float)mdb_image->height;

    /* The mandlebrot set is defined as the set of all complex numbers C 
     * such that Z remains bounded in the function Zn = Zn-1^2 + C where Z0 = 0 */ 
    for(uint32_t y = 0U; y < mdb_image->height; y++)
    {
        for(uint32_t x = 0U; x < mdb_image->width; x++)
        {
            /* for every pixel convert the x and y coordinates into a point on the complex plain */
            float C_r = x * hscale + x0, C_i = y * vscale + y0;
            float Z_r = 0.0f, Z_i = 0.0f;
            int iterations = 0;
            while(iterations < max_iterations && Z_r * Z_r + Z_i * Z_i <= 4.0f)
            {
                float temp = Z_r * Z_r - Z_i * Z_i + C_r;
                Z_i = 2.0f * Z_r * Z_i + C_i;
                Z_r = temp;
                iterations++;
            }
            uint64_t color;
            /* If the iterations maxed out we assume the point is part of the mandelbrot set.
             * Colour the points inside the mandelbrot set black */
            if (iterations == max_iterations)
                color = 0x000000ff;
            /* For points outside the mandelbrot set we can colour them in greyscale to reveal
             * more of the structure based on how fast they diverged */
            else
            {
                uint32_t level = (uint32_t)(((float)iterations / (float) max_iterations) * 255.0f);
                color = (level << 24U) | (level << 16U) | (level << 8U) | 0xff;
            }
            /* draw the pixel */
            spng::png_setp(mdb_image, x, y, color);
        }
    }
    /* save the image and free it */
    if (spng::png_write(mdb_image, "examples/mandelbrot.png") != SPNG_OK)
    {
        std::cerr << "Error writing mandelbrot.png: " << spng::spngErrorStr(spng::SPNG_ERRNO) << std::endl;
    }
    else
    {
        std::cout << "Sent image to examples/mandelbrot.png." << std::endl;
    }
    spng::png_free(mdb_image);
    return 0;
}