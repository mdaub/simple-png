/*
 * drawing.h is part of simple-png
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

#ifndef __DRAWING_H
#define __DRAWING_H

#ifdef __cplusplus
extern "C" {
#endif

#define CHARACTER_HEIGHT 16
#define CHARACTER_WIDTH 9

/* Adapt drawing algorithms for Simple PNG */
#include "png.h"

typedef png_s image_s;


/**
 * @brief Draws a solid circle
 * 
 * @param img the image object to draw on
 * @param x center x coordinate
 * @param y center y coordinate
 * @param r the radius of the circle
 * @param colour the colour of the circle
 * @return int returns 0 on success, -1 otherwise
 */
SPNG_EXPORT int draw_circle(image_s* img, int32_t x, int32_t y, int32_t r, uint64_t colour);

/**
 * @brief Draws a ring
 * 
 * @param img the image object to draw on
 * @param x the center x coordinate
 * @param y the center y coordinate
 * @param ro outer radius
 * @param ri inner radius
 * @param colour the colour
 * @return int returns 0 on success, -1 otherwise
 */
SPNG_EXPORT int draw_ring(image_s* img, int32_t x, int32_t y, int32_t ro, int32_t ri, uint64_t colour);


/**
 * @brief Draws a square
 * 
 * @param img the image object to draw on
 * @param x upper left x coordinate
 * @param y upper left y coordinate
 * @param s side length in pixels
 * @param colour colour of the square
 * @return int returns 0 on success, -1 otherwise
 */
SPNG_EXPORT int draw_square(image_s* img, int32_t x, int32_t y, int32_t s, uint64_t colour);

/**
 * @brief Draws a rectangle
 * 
 * @param img the image object to draw on
 * @param x0 x of the first corner
 * @param y0 y of the first corner
 * @param x1 x of the second corner
 * @param y1 y of the second corner
 * @param colour the colour of the rectangle
 * @return int returns 0 on success, -1 otherwise
 */
SPNG_EXPORT int draw_rectangle(image_s* img, int32_t x0, int32_t y0, int32_t x1, int32_t y1, uint64_t colour);

/**
 * @brief Draws a line with Besenham's line algorithm
 * 
 * @param img the image object to draw on
 * @param x0 the x coordinate of the start of the line
 * @param y0 the y coordinate of the start of the line
 * @param x1 the x coordinate of the end of the line
 * @param y1 the y coordinate of the end of the line
 * @param width the width of the line
 * @param colour colour of the line
 * @return int returns 0 on success, -1 otherwise
 */
SPNG_EXPORT int draw_line(image_s* img, int32_t x0, int32_t y0, int32_t x1, int32_t y1, uint32_t width, uint64_t colour);

/**
 * @brief Prints a character on an image (codepage-437)
 * 
 * @param img the image object to draw on
 * @param character the character to draw
 * @param x the upper left x coordinate of the character
 * @param y the upper left y coordinate of the character
 * @param size the point size of the font
 * @param colour the colour of the character
 * @return int returns 0 on success, -1 otherwise
 */
SPNG_EXPORT int printc(image_s* img, int character, int32_t x, int32_t y, uint32_t size, uint64_t colour);

/**
 * @brief Prints a string on an image (codepage-437)
 * 
 * @param img the image object to draw on
 * @param str the string to draw
 * @param x the upper left x coordinate of the first character
 * @param y the upper left y coordinate of the first character
 * @param size the point size of the font
 * @param colour the colour of the characters
 * @return int returns 0 on success, -1 otherwise
 */
SPNG_EXPORT int prints(image_s* img, const char* str, int32_t x, int32_t y, uint32_t size, uint64_t colour);

#ifdef __cplusplus
}
#endif

#endif /* ifndef __DRAWING_H */