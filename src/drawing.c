/*
 * drawing.c is part of simple-png
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

#include "drawing.h"
#include "codepage-437.h"

#define ABS(A) ((A) < 0 ? -(A) : (A));

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
int draw_circle(image_s* img, int32_t x, int32_t y, int32_t radius, uint64_t col) {
    if(img == NULL) return -1;
    if(radius == 0) {
        png_setp(img, x, y, col);
        return 0;
    }
    int i, j;
    int32_t temp = radius*radius;
    const int32_t temp_rad = -radius;
    for(i = radius; i >= temp_rad; i--) {
        for(j = temp_rad; j <= radius; j++) {
            if(i*i + j*j <= temp) {
                png_setp(img, j + x, i + y, col);
            }
        }
    }
    return 0;
}

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
int draw_ring(image_s* img, int32_t x, int32_t y, int32_t outer_radius, int32_t inner_radius, uint64_t col){
    if(img == NULL) return -1;
    if(outer_radius == 0) {
        png_setp(img, x, y, col);
        return 0;
    }
    if(inner_radius > outer_radius){
        return 0;
    }
    if(inner_radius == 0){
        return draw_circle(img, x, y, outer_radius, col);
    }
    int i, j;
    const int outer_square = outer_radius * outer_radius;
    const int inner_square = inner_radius * inner_radius;
    const int temp_radius = -outer_radius;
    for(i = outer_radius; i >= temp_radius; i--) {
        for(j = temp_radius; j <= outer_radius; j++) {
            if(i*i + j*j <= outer_square && i*i + j*j >= inner_square) {
                png_setp(img, j + x, i + y, col);
            }
        }
    }
    return 0;
}

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
int draw_square(image_s* img, int32_t x, int32_t y, int32_t side_length, uint64_t col) {
    if(img == NULL) return -1;
    int i, j;
    for(i = 0; i < side_length; i++) {
        for(j = 0; j < side_length; j++) {
            png_setp(img, i + x, j + y, col);
        }
    }
    return 0;
}

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
int draw_rectangle(image_s* img, int32_t x0, int32_t y0, int32_t x1, int32_t y1, uint64_t col)
{
    if(img == NULL) return -1;
    if(x1 < x0) 
    {
        int32_t temp = x0;
        x0 = x1;
        x1 = temp;
    }
    if(y1 < y0)
    {
        int32_t temp = y0;
        y0 = y1;
        y1 = temp;
    }
    int i, j;
    for(i = x0; i <= x1; i++)
    {
        for(j = y0; j <= y1; j++)
        {
            png_setp(img, i, j, col);
        }
    }
    return 0;
}

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
int draw_line(image_s* img, int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint32_t width, uint64_t col) {
    /* Besenham's line drawing algorithm based line drawing function */
    if(img == NULL) return -1;
    enum {
        QUAD1 = 1,
        QUAD2 = 2,
        QUAD3 = 3,
        QUAD4 = 4,
        VERT = 5,
        HORZ = 6
    } quadrant = QUAD1;
    if(x2 > x1 && y2 >= y1) quadrant = QUAD1;
    else if(x2 <= x1 && y2 > y1) quadrant = QUAD2;
    else if(x2 < x1 && y2 <= y1) quadrant = QUAD3;
    else if(x2 >= x1 && y2 < y1) quadrant = QUAD4;
    int m_y = 2 * ABS(y2 - y1);
    int m_x = 2 * ABS(x2 - x1);
    /* for drawing horizontal lines */
    if(m_y == 0) {
        int x = x2 > x1 ? x1 : x2;
        int endx = x2 > x1 ? x2 : x1;
        for( ; x <= endx; x++) {
            draw_circle(img, x, y1, width, col);
        }
    }
    /* for drawing vertical lines */
    else if(m_x == 0) {
        int y = y2 > y1 ? y1 : y2;
        int endy = y2 > y1 ? y2 : y1;
        for( ; y <= endy; y++) {
            draw_circle(img, x1, y, width, col);
        }
    }
    /* for drawing lines with m < 1 */
    else if(m_y < m_x) {
        int m_error = m_y - m_x/2;
        int x = quadrant == QUAD1 || quadrant == QUAD4 ? x1 : x2;
        int endx = x == x1 ? x2 : x1;
        int y = x == x1 ? y1 : y2;
        int inc = quadrant == QUAD1 || quadrant == QUAD3 ? 1 : -1;
        for( ; x <= endx; x++) {
            draw_circle(img, x, y, width, col);
            m_error += m_y;
            if(m_error >= 0) {
                y += inc;
                m_error -= m_x;
            }
        }
    }
    /* for drawing lines with m >= 1 */
    else {
        int m_error = m_x - m_y/2;
        int x = quadrant == QUAD1 || quadrant == QUAD2 ? x1 : x2;
        int y = x == x1 ? y1 : y2;
        int endy = y == y1 ? y2 : y1;
        int inc = quadrant == QUAD1 || quadrant == QUAD3 ? 1 : -1;
        for( ; y <= endy; y++) {
            draw_circle(img, x, y, width, col);
            m_error += m_x;
            if(m_error >= 0) {
                x += inc;
                m_error -= m_y;
            }
        }
    }
    return 0;
}

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
int printc(image_s* img, int input, int32_t x, int32_t y, uint32_t font_size, uint64_t col) {
    if(img == NULL) return -1;
    int i, j;
    for(i = 0; i < 18; i++) {
        for(j = 0; j < 8; j++) {
            if(codepage_437[input][i] & (1 << (j)) ) {
                if(font_size > 1) draw_square(img, x + font_size * (i%9), y - font_size*(j + (i > 8? 8 : 0)), font_size, col);
                else png_setp(img, x + i%9, y - (j + (i > 8 ? 8 : 0)), col);
            }
        }
    }
    return 0;
}

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
int prints(image_s* img, const char* input, int32_t x, int32_t y, uint32_t font_size, uint64_t col) {
    if(img == NULL) return -1;
    int i;
    for(i = 0; input[i] != '\0'; i++) {
        printc(img, input[i], x + i*9*font_size, y, font_size, col);
    }
    return i;
}

