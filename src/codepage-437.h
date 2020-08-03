/*
 * codepage-437.h is part of simple-png
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

/* codepage 437 is a 16x9 font and character set from the old IBM PC's.
 * The data for this font was taken by parsing a bitmap of the original font.
 * each byte corresponds to a 8 pixel tall section of the character. The first
 * 9 bytes correspond to the first page, and the second set of 8 correspond to
 * the second. MSB -> top pixel.
 */
const unsigned char codepage_437[256][18] = {
// 0x0
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0x0,   // column 2, page 0: 0b00000000
        0x0,   // column 3, page 0: 0b00000000
        0x0,   // column 4, page 0: 0b00000000
        0x0,   // column 5, page 0: 0b00000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x1
    {
        0xf8,  // column 0, page 0: 0b11111000
        0x4,   // column 1, page 0: 0b00000100
        0x94,  // column 2, page 0: 0b10010100
        0x84,  // column 3, page 0: 0b10000100
        0x84,  // column 4, page 0: 0b10000100
        0x94,  // column 5, page 0: 0b10010100
        0x4,   // column 6, page 0: 0b00000100
        0xf8,  // column 7, page 0: 0b11111000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0x8,   // column 1, page 1: 0b00001000
        0x8,   // column 2, page 1: 0b00001000
        0x9,   // column 3, page 1: 0b00001001
        0x9,   // column 4, page 1: 0b00001001
        0x8,   // column 5, page 1: 0b00001000
        0x8,   // column 6, page 1: 0b00001000
        0x7,   // column 7, page 1: 0b00000111
        0x0    // column 8, page 1: 0b00000000
    },
// 0x2
    {
        0xf8,  // column 0, page 0: 0b11111000
        0xfc,  // column 1, page 0: 0b11111100
        0x6c,  // column 2, page 0: 0b01101100
        0x7c,  // column 3, page 0: 0b01111100
        0x7c,  // column 4, page 0: 0b01111100
        0x6c,  // column 5, page 0: 0b01101100
        0xfc,  // column 6, page 0: 0b11111100
        0xf8,  // column 7, page 0: 0b11111000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0xf,   // column 2, page 1: 0b00001111
        0xe,   // column 3, page 1: 0b00001110
        0xe,   // column 4, page 1: 0b00001110
        0xf,   // column 5, page 1: 0b00001111
        0xf,   // column 6, page 1: 0b00001111
        0x7,   // column 7, page 1: 0b00000111
        0x0    // column 8, page 1: 0b00000000
    },
// 0x3
    {
        0xe0,  // column 0, page 0: 0b11100000
        0xf0,  // column 1, page 0: 0b11110000
        0xf0,  // column 2, page 0: 0b11110000
        0xe0,  // column 3, page 0: 0b11100000
        0xf0,  // column 4, page 0: 0b11110000
        0xf0,  // column 5, page 0: 0b11110000
        0xe0,  // column 6, page 0: 0b11100000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x1,   // column 0, page 1: 0b00000001
        0x3,   // column 1, page 1: 0b00000011
        0x7,   // column 2, page 1: 0b00000111
        0xf,   // column 3, page 1: 0b00001111
        0x7,   // column 4, page 1: 0b00000111
        0x3,   // column 5, page 1: 0b00000011
        0x1,   // column 6, page 1: 0b00000001
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x4
    {
        0x80,  // column 0, page 0: 0b10000000
        0xc0,  // column 1, page 0: 0b11000000
        0xe0,  // column 2, page 0: 0b11100000
        0xf0,  // column 3, page 0: 0b11110000
        0xe0,  // column 4, page 0: 0b11100000
        0xc0,  // column 5, page 0: 0b11000000
        0x80,  // column 6, page 0: 0b10000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x1,   // column 1, page 1: 0b00000001
        0x3,   // column 2, page 1: 0b00000011
        0x7,   // column 3, page 1: 0b00000111
        0x3,   // column 4, page 1: 0b00000011
        0x1,   // column 5, page 1: 0b00000001
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x5
    {
        0xc0,  // column 0, page 0: 0b11000000
        0xc0,  // column 1, page 0: 0b11000000
        0xf0,  // column 2, page 0: 0b11110000
        0x38,  // column 3, page 0: 0b00111000
        0x38,  // column 4, page 0: 0b00111000
        0xf0,  // column 5, page 0: 0b11110000
        0xc0,  // column 6, page 0: 0b11000000
        0xc0,  // column 7, page 0: 0b11000000
        0x0,   // column 8, page 0: 0b00000000
        0x1,   // column 0, page 1: 0b00000001
        0x1,   // column 1, page 1: 0b00000001
        0x9,   // column 2, page 1: 0b00001001
        0xe,   // column 3, page 1: 0b00001110
        0xe,   // column 4, page 1: 0b00001110
        0x9,   // column 5, page 1: 0b00001001
        0x1,   // column 6, page 1: 0b00000001
        0x1,   // column 7, page 1: 0b00000001
        0x0    // column 8, page 1: 0b00000000
    },
// 0x6
    {
        0xc0,  // column 0, page 0: 0b11000000
        0xe0,  // column 1, page 0: 0b11100000
        0xf0,  // column 2, page 0: 0b11110000
        0xf8,  // column 3, page 0: 0b11111000
        0xf8,  // column 4, page 0: 0b11111000
        0xf0,  // column 5, page 0: 0b11110000
        0xe0,  // column 6, page 0: 0b11100000
        0xc0,  // column 7, page 0: 0b11000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x1,   // column 1, page 1: 0b00000001
        0x9,   // column 2, page 1: 0b00001001
        0xf,   // column 3, page 1: 0b00001111
        0xf,   // column 4, page 1: 0b00001111
        0x9,   // column 5, page 1: 0b00001001
        0x1,   // column 6, page 1: 0b00000001
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x7
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0x80,  // column 2, page 0: 0b10000000
        0xc0,  // column 3, page 0: 0b11000000
        0xc0,  // column 4, page 0: 0b11000000
        0x80,  // column 5, page 0: 0b10000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x1,   // column 2, page 1: 0b00000001
        0x3,   // column 3, page 1: 0b00000011
        0x3,   // column 4, page 1: 0b00000011
        0x1,   // column 5, page 1: 0b00000001
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x8
    {
        0xff,  // column 0, page 0: 0b11111111
        0xff,  // column 1, page 0: 0b11111111
        0x7f,  // column 2, page 0: 0b01111111
        0x3f,  // column 3, page 0: 0b00111111
        0x3f,  // column 4, page 0: 0b00111111
        0x7f,  // column 5, page 0: 0b01111111
        0xff,  // column 6, page 0: 0b11111111
        0xff,  // column 7, page 0: 0b11111111
        0x0,   // column 8, page 0: 0b00000000
        0xff,  // column 0, page 1: 0b11111111
        0xff,  // column 1, page 1: 0b11111111
        0xfe,  // column 2, page 1: 0b11111110
        0xfc,  // column 3, page 1: 0b11111100
        0xfc,  // column 4, page 1: 0b11111100
        0xfe,  // column 5, page 1: 0b11111110
        0xff,  // column 6, page 1: 0b11111111
        0xff,  // column 7, page 1: 0b11111111
        0x0    // column 8, page 1: 0b00000000
    },
// 0x9
    {
        0x0,   // column 0, page 0: 0b00000000
        0xc0,  // column 1, page 0: 0b11000000
        0x60,  // column 2, page 0: 0b01100000
        0x20,  // column 3, page 0: 0b00100000
        0x20,  // column 4, page 0: 0b00100000
        0x60,  // column 5, page 0: 0b01100000
        0xc0,  // column 6, page 0: 0b11000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x3,   // column 1, page 1: 0b00000011
        0x6,   // column 2, page 1: 0b00000110
        0x4,   // column 3, page 1: 0b00000100
        0x4,   // column 4, page 1: 0b00000100
        0x6,   // column 5, page 1: 0b00000110
        0x3,   // column 6, page 1: 0b00000011
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xa
    {
        0xff,  // column 0, page 0: 0b11111111
        0x3f,  // column 1, page 0: 0b00111111
        0x9f,  // column 2, page 0: 0b10011111
        0xdf,  // column 3, page 0: 0b11011111
        0xdf,  // column 4, page 0: 0b11011111
        0x9f,  // column 5, page 0: 0b10011111
        0x3f,  // column 6, page 0: 0b00111111
        0xff,  // column 7, page 0: 0b11111111
        0x0,   // column 8, page 0: 0b00000000
        0xff,  // column 0, page 1: 0b11111111
        0xfc,  // column 1, page 1: 0b11111100
        0xf9,  // column 2, page 1: 0b11111001
        0xfb,  // column 3, page 1: 0b11111011
        0xfb,  // column 4, page 1: 0b11111011
        0xf9,  // column 5, page 1: 0b11111001
        0xfc,  // column 6, page 1: 0b11111100
        0xff,  // column 7, page 1: 0b11111111
        0x0    // column 8, page 1: 0b00000000
    },
// 0xb
    {
        0x80,  // column 0, page 0: 0b10000000
        0xc0,  // column 1, page 0: 0b11000000
        0x60,  // column 2, page 0: 0b01100000
        0x74,  // column 3, page 0: 0b01110100
        0xdc,  // column 4, page 0: 0b11011100
        0x8c,  // column 5, page 0: 0b10001100
        0x3c,  // column 6, page 0: 0b00111100
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0x8,   // column 3, page 1: 0b00001000
        0xf,   // column 4, page 1: 0b00001111
        0x7,   // column 5, page 1: 0b00000111
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xc
    {
        0x0,   // column 0, page 0: 0b00000000
        0x78,  // column 1, page 0: 0b01111000
        0xfc,  // column 2, page 0: 0b11111100
        0x84,  // column 3, page 0: 0b10000100
        0x84,  // column 4, page 0: 0b10000100
        0xfc,  // column 5, page 0: 0b11111100
        0x78,  // column 6, page 0: 0b01111000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x2,   // column 1, page 1: 0b00000010
        0x2,   // column 2, page 1: 0b00000010
        0xf,   // column 3, page 1: 0b00001111
        0xf,   // column 4, page 1: 0b00001111
        0x2,   // column 5, page 1: 0b00000010
        0x2,   // column 6, page 1: 0b00000010
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xd
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0xfc,  // column 2, page 0: 0b11111100
        0xfc,  // column 3, page 0: 0b11111100
        0x14,  // column 4, page 0: 0b00010100
        0x14,  // column 5, page 0: 0b00010100
        0x1c,  // column 6, page 0: 0b00011100
        0x1c,  // column 7, page 0: 0b00011100
        0x0,   // column 8, page 0: 0b00000000
        0xc,   // column 0, page 1: 0b00001100
        0xe,   // column 1, page 1: 0b00001110
        0xf,   // column 2, page 1: 0b00001111
        0x7,   // column 3, page 1: 0b00000111
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xe
    {
        0x0,   // column 0, page 0: 0b00000000
        0xfc,  // column 1, page 0: 0b11111100
        0xfc,  // column 2, page 0: 0b11111100
        0x14,  // column 3, page 0: 0b00010100
        0x14,  // column 4, page 0: 0b00010100
        0x14,  // column 5, page 0: 0b00010100
        0xfc,  // column 6, page 0: 0b11111100
        0xfc,  // column 7, page 0: 0b11111100
        0x0,   // column 8, page 0: 0b00000000
        0x1c,  // column 0, page 1: 0b00011100
        0x1f,  // column 1, page 1: 0b00011111
        0xf,   // column 2, page 1: 0b00001111
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0xe,   // column 5, page 1: 0b00001110
        0xf,   // column 6, page 1: 0b00001111
        0x7,   // column 7, page 1: 0b00000111
        0x0    // column 8, page 1: 0b00000000
    },
// 0xf
    {
        0xa0,  // column 0, page 0: 0b10100000
        0xa0,  // column 1, page 0: 0b10100000
        0xc0,  // column 2, page 0: 0b11000000
        0x78,  // column 3, page 0: 0b01111000
        0x78,  // column 4, page 0: 0b01111000
        0xc0,  // column 5, page 0: 0b11000000
        0xa0,  // column 6, page 0: 0b10100000
        0xa0,  // column 7, page 0: 0b10100000
        0x0,   // column 8, page 0: 0b00000000
        0x2,   // column 0, page 1: 0b00000010
        0x2,   // column 1, page 1: 0b00000010
        0x1,   // column 2, page 1: 0b00000001
        0xf,   // column 3, page 1: 0b00001111
        0xf,   // column 4, page 1: 0b00001111
        0x1,   // column 5, page 1: 0b00000001
        0x2,   // column 6, page 1: 0b00000010
        0x2,   // column 7, page 1: 0b00000010
        0x0    // column 8, page 1: 0b00000000
    },
// 0x10
    {
        0xfe,  // column 0, page 0: 0b11111110
        0xfc,  // column 1, page 0: 0b11111100
        0xf8,  // column 2, page 0: 0b11111000
        0xf0,  // column 3, page 0: 0b11110000
        0xe0,  // column 4, page 0: 0b11100000
        0x40,  // column 5, page 0: 0b01000000
        0x40,  // column 6, page 0: 0b01000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0xf,   // column 0, page 1: 0b00001111
        0x7,   // column 1, page 1: 0b00000111
        0x3,   // column 2, page 1: 0b00000011
        0x1,   // column 3, page 1: 0b00000001
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x11
    {
        0x40,  // column 0, page 0: 0b01000000
        0x40,  // column 1, page 0: 0b01000000
        0xe0,  // column 2, page 0: 0b11100000
        0xf0,  // column 3, page 0: 0b11110000
        0xf8,  // column 4, page 0: 0b11111000
        0xfc,  // column 5, page 0: 0b11111100
        0xfe,  // column 6, page 0: 0b11111110
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x1,   // column 3, page 1: 0b00000001
        0x3,   // column 4, page 1: 0b00000011
        0x7,   // column 5, page 1: 0b00000111
        0xf,   // column 6, page 1: 0b00001111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x12
    {
        0x0,   // column 0, page 0: 0b00000000
        0x10,  // column 1, page 0: 0b00010000
        0x18,  // column 2, page 0: 0b00011000
        0xfc,  // column 3, page 0: 0b11111100
        0xfc,  // column 4, page 0: 0b11111100
        0x18,  // column 5, page 0: 0b00011000
        0x10,  // column 6, page 0: 0b00010000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x1,   // column 1, page 1: 0b00000001
        0x3,   // column 2, page 1: 0b00000011
        0x7,   // column 3, page 1: 0b00000111
        0x7,   // column 4, page 1: 0b00000111
        0x3,   // column 5, page 1: 0b00000011
        0x1,   // column 6, page 1: 0b00000001
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x13
    {
        0x0,   // column 0, page 0: 0b00000000
        0xfc,  // column 1, page 0: 0b11111100
        0xfc,  // column 2, page 0: 0b11111100
        0x0,   // column 3, page 0: 0b00000000
        0x0,   // column 4, page 0: 0b00000000
        0xfc,  // column 5, page 0: 0b11111100
        0xfc,  // column 6, page 0: 0b11111100
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0xd,   // column 1, page 1: 0b00001101
        0xd,   // column 2, page 1: 0b00001101
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0xd,   // column 5, page 1: 0b00001101
        0xd,   // column 6, page 1: 0b00001101
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x14
    {
        0x38,  // column 0, page 0: 0b00111000
        0x7c,  // column 1, page 0: 0b01111100
        0x44,  // column 2, page 0: 0b01000100
        0xfc,  // column 3, page 0: 0b11111100
        0xfc,  // column 4, page 0: 0b11111100
        0x4,   // column 5, page 0: 0b00000100
        0xfc,  // column 6, page 0: 0b11111100
        0xfc,  // column 7, page 0: 0b11111100
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0xf,   // column 3, page 1: 0b00001111
        0xf,   // column 4, page 1: 0b00001111
        0x0,   // column 5, page 1: 0b00000000
        0xf,   // column 6, page 1: 0b00001111
        0xf,   // column 7, page 1: 0b00001111
        0x0    // column 8, page 1: 0b00000000
    },
// 0x15
    {
        0xc4,  // column 0, page 0: 0b11000100
        0xee,  // column 1, page 0: 0b11101110
        0x3a,  // column 2, page 0: 0b00111010
        0x12,  // column 3, page 0: 0b00010010
        0x32,  // column 4, page 0: 0b00110010
        0xe6,  // column 5, page 0: 0b11100110
        0xc4,  // column 6, page 0: 0b11000100
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x8,   // column 0, page 1: 0b00001000
        0x19,  // column 1, page 1: 0b00011001
        0x13,  // column 2, page 1: 0b00010011
        0x12,  // column 3, page 1: 0b00010010
        0x17,  // column 4, page 1: 0b00010111
        0x1d,  // column 5, page 1: 0b00011101
        0x8,   // column 6, page 1: 0b00001000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x16
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0x0,   // column 2, page 0: 0b00000000
        0x0,   // column 3, page 0: 0b00000000
        0x0,   // column 4, page 0: 0b00000000
        0x0,   // column 5, page 0: 0b00000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0xf,   // column 0, page 1: 0b00001111
        0xf,   // column 1, page 1: 0b00001111
        0xf,   // column 2, page 1: 0b00001111
        0xf,   // column 3, page 1: 0b00001111
        0xf,   // column 4, page 1: 0b00001111
        0xf,   // column 5, page 1: 0b00001111
        0xf,   // column 6, page 1: 0b00001111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x17
    {
        0x0,   // column 0, page 0: 0b00000000
        0x10,  // column 1, page 0: 0b00010000
        0x18,  // column 2, page 0: 0b00011000
        0xfc,  // column 3, page 0: 0b11111100
        0xfc,  // column 4, page 0: 0b11111100
        0x18,  // column 5, page 0: 0b00011000
        0x10,  // column 6, page 0: 0b00010000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x9,   // column 1, page 1: 0b00001001
        0xb,   // column 2, page 1: 0b00001011
        0xf,   // column 3, page 1: 0b00001111
        0xf,   // column 4, page 1: 0b00001111
        0xb,   // column 5, page 1: 0b00001011
        0x9,   // column 6, page 1: 0b00001001
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x18
    {
        0x0,   // column 0, page 0: 0b00000000
        0x10,  // column 1, page 0: 0b00010000
        0x18,  // column 2, page 0: 0b00011000
        0xfc,  // column 3, page 0: 0b11111100
        0xfc,  // column 4, page 0: 0b11111100
        0x18,  // column 5, page 0: 0b00011000
        0x10,  // column 6, page 0: 0b00010000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0xf,   // column 3, page 1: 0b00001111
        0xf,   // column 4, page 1: 0b00001111
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x19
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0x0,   // column 2, page 0: 0b00000000
        0xfc,  // column 3, page 0: 0b11111100
        0xfc,  // column 4, page 0: 0b11111100
        0x0,   // column 5, page 0: 0b00000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x2,   // column 1, page 1: 0b00000010
        0x6,   // column 2, page 1: 0b00000110
        0xf,   // column 3, page 1: 0b00001111
        0xf,   // column 4, page 1: 0b00001111
        0x6,   // column 5, page 1: 0b00000110
        0x2,   // column 6, page 1: 0b00000010
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x1a
    {
        0x80,  // column 0, page 0: 0b10000000
        0x80,  // column 1, page 0: 0b10000000
        0x80,  // column 2, page 0: 0b10000000
        0xa0,  // column 3, page 0: 0b10100000
        0xe0,  // column 4, page 0: 0b11100000
        0xc0,  // column 5, page 0: 0b11000000
        0x80,  // column 6, page 0: 0b10000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x2,   // column 3, page 1: 0b00000010
        0x3,   // column 4, page 1: 0b00000011
        0x1,   // column 5, page 1: 0b00000001
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x1b
    {
        0x80,  // column 0, page 0: 0b10000000
        0xc0,  // column 1, page 0: 0b11000000
        0xe0,  // column 2, page 0: 0b11100000
        0xa0,  // column 3, page 0: 0b10100000
        0x80,  // column 4, page 0: 0b10000000
        0x80,  // column 5, page 0: 0b10000000
        0x80,  // column 6, page 0: 0b10000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x1,   // column 1, page 1: 0b00000001
        0x3,   // column 2, page 1: 0b00000011
        0x2,   // column 3, page 1: 0b00000010
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x1c
    {
        0xc0,  // column 0, page 0: 0b11000000
        0xc0,  // column 1, page 0: 0b11000000
        0x0,   // column 2, page 0: 0b00000000
        0x0,   // column 3, page 0: 0b00000000
        0x0,   // column 4, page 0: 0b00000000
        0x0,   // column 5, page 0: 0b00000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x3,   // column 0, page 1: 0b00000011
        0x3,   // column 1, page 1: 0b00000011
        0x2,   // column 2, page 1: 0b00000010
        0x2,   // column 3, page 1: 0b00000010
        0x2,   // column 4, page 1: 0b00000010
        0x2,   // column 5, page 1: 0b00000010
        0x2,   // column 6, page 1: 0b00000010
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x1d
    {
        0x80,  // column 0, page 0: 0b10000000
        0xc0,  // column 1, page 0: 0b11000000
        0xe0,  // column 2, page 0: 0b11100000
        0x80,  // column 3, page 0: 0b10000000
        0x80,  // column 4, page 0: 0b10000000
        0xe0,  // column 5, page 0: 0b11100000
        0xc0,  // column 6, page 0: 0b11000000
        0x80,  // column 7, page 0: 0b10000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x1,   // column 1, page 1: 0b00000001
        0x3,   // column 2, page 1: 0b00000011
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0x3,   // column 5, page 1: 0b00000011
        0x1,   // column 6, page 1: 0b00000001
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x1e
    {
        0x0,   // column 0, page 0: 0b00000000
        0x80,  // column 1, page 0: 0b10000000
        0xe0,  // column 2, page 0: 0b11100000
        0xf0,  // column 3, page 0: 0b11110000
        0xe0,  // column 4, page 0: 0b11100000
        0x80,  // column 5, page 0: 0b10000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x6,   // column 0, page 1: 0b00000110
        0x7,   // column 1, page 1: 0b00000111
        0x7,   // column 2, page 1: 0b00000111
        0x7,   // column 3, page 1: 0b00000111
        0x7,   // column 4, page 1: 0b00000111
        0x7,   // column 5, page 1: 0b00000111
        0x6,   // column 6, page 1: 0b00000110
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x1f
    {
        0x30,  // column 0, page 0: 0b00110000
        0xf0,  // column 1, page 0: 0b11110000
        0xf0,  // column 2, page 0: 0b11110000
        0xf0,  // column 3, page 0: 0b11110000
        0xf0,  // column 4, page 0: 0b11110000
        0xf0,  // column 5, page 0: 0b11110000
        0x30,  // column 6, page 0: 0b00110000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x3,   // column 2, page 1: 0b00000011
        0x7,   // column 3, page 1: 0b00000111
        0x3,   // column 4, page 1: 0b00000011
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x20
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0x0,   // column 2, page 0: 0b00000000
        0x0,   // column 3, page 0: 0b00000000
        0x0,   // column 4, page 0: 0b00000000
        0x0,   // column 5, page 0: 0b00000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x21
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0x38,  // column 2, page 0: 0b00111000
        0xfc,  // column 3, page 0: 0b11111100
        0xfc,  // column 4, page 0: 0b11111100
        0x38,  // column 5, page 0: 0b00111000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0xd,   // column 3, page 1: 0b00001101
        0xd,   // column 4, page 1: 0b00001101
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x22
    {
        0x0,   // column 0, page 0: 0b00000000
        0xe,   // column 1, page 0: 0b00001110
        0x1e,  // column 2, page 0: 0b00011110
        0x0,   // column 3, page 0: 0b00000000
        0x0,   // column 4, page 0: 0b00000000
        0x1e,  // column 5, page 0: 0b00011110
        0xe,   // column 6, page 0: 0b00001110
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x23
    {
        0x20,  // column 0, page 0: 0b00100000
        0xf8,  // column 1, page 0: 0b11111000
        0xf8,  // column 2, page 0: 0b11111000
        0x20,  // column 3, page 0: 0b00100000
        0xf8,  // column 4, page 0: 0b11111000
        0xf8,  // column 5, page 0: 0b11111000
        0x20,  // column 6, page 0: 0b00100000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x2,   // column 0, page 1: 0b00000010
        0xf,   // column 1, page 1: 0b00001111
        0xf,   // column 2, page 1: 0b00001111
        0x2,   // column 3, page 1: 0b00000010
        0xf,   // column 4, page 1: 0b00001111
        0xf,   // column 5, page 1: 0b00001111
        0x2,   // column 6, page 1: 0b00000010
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x24
    {
        0x38,  // column 0, page 0: 0b00111000
        0x7c,  // column 1, page 0: 0b01111100
        0x44,  // column 2, page 0: 0b01000100
        0x47,  // column 3, page 0: 0b01000111
        0x47,  // column 4, page 0: 0b01000111
        0xcc,  // column 5, page 0: 0b11001100
        0x98,  // column 6, page 0: 0b10011000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x6,   // column 0, page 1: 0b00000110
        0xc,   // column 1, page 1: 0b00001100
        0x8,   // column 2, page 1: 0b00001000
        0x38,  // column 3, page 1: 0b00111000
        0x38,  // column 4, page 1: 0b00111000
        0xf,   // column 5, page 1: 0b00001111
        0x7,   // column 6, page 1: 0b00000111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x25
    {
        0x30,  // column 0, page 0: 0b00110000
        0x30,  // column 1, page 0: 0b00110000
        0x0,   // column 2, page 0: 0b00000000
        0x80,  // column 3, page 0: 0b10000000
        0xc0,  // column 4, page 0: 0b11000000
        0x60,  // column 5, page 0: 0b01100000
        0x30,  // column 6, page 0: 0b00110000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0xc,   // column 0, page 1: 0b00001100
        0x6,   // column 1, page 1: 0b00000110
        0x3,   // column 2, page 1: 0b00000011
        0x1,   // column 3, page 1: 0b00000001
        0x0,   // column 4, page 1: 0b00000000
        0xc,   // column 5, page 1: 0b00001100
        0xc,   // column 6, page 1: 0b00001100
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x26
    {
        0x80,  // column 0, page 0: 0b10000000
        0xd8,  // column 1, page 0: 0b11011000
        0x7c,  // column 2, page 0: 0b01111100
        0xe4,  // column 3, page 0: 0b11100100
        0xbc,  // column 4, page 0: 0b10111100
        0xd8,  // column 5, page 0: 0b11011000
        0x40,  // column 6, page 0: 0b01000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0x8,   // column 3, page 1: 0b00001000
        0x7,   // column 4, page 1: 0b00000111
        0xf,   // column 5, page 1: 0b00001111
        0x8,   // column 6, page 1: 0b00001000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x27
    {
        0x0,   // column 0, page 0: 0b00000000
        0x10,  // column 1, page 0: 0b00010000
        0x1e,  // column 2, page 0: 0b00011110
        0xe,   // column 3, page 0: 0b00001110
        0x0,   // column 4, page 0: 0b00000000
        0x0,   // column 5, page 0: 0b00000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x28
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0xf0,  // column 2, page 0: 0b11110000
        0xf8,  // column 3, page 0: 0b11111000
        0xc,   // column 4, page 0: 0b00001100
        0x4,   // column 5, page 0: 0b00000100
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x3,   // column 2, page 1: 0b00000011
        0x7,   // column 3, page 1: 0b00000111
        0xc,   // column 4, page 1: 0b00001100
        0x8,   // column 5, page 1: 0b00001000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x29
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0x4,   // column 2, page 0: 0b00000100
        0xc,   // column 3, page 0: 0b00001100
        0xf8,  // column 4, page 0: 0b11111000
        0xf0,  // column 5, page 0: 0b11110000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x8,   // column 2, page 1: 0b00001000
        0xc,   // column 3, page 1: 0b00001100
        0x7,   // column 4, page 1: 0b00000111
        0x3,   // column 5, page 1: 0b00000011
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x2a
    {
        0x80,  // column 0, page 0: 0b10000000
        0xa0,  // column 1, page 0: 0b10100000
        0xe0,  // column 2, page 0: 0b11100000
        0xc0,  // column 3, page 0: 0b11000000
        0xc0,  // column 4, page 0: 0b11000000
        0xe0,  // column 5, page 0: 0b11100000
        0xa0,  // column 6, page 0: 0b10100000
        0x80,  // column 7, page 0: 0b10000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x2,   // column 1, page 1: 0b00000010
        0x3,   // column 2, page 1: 0b00000011
        0x1,   // column 3, page 1: 0b00000001
        0x1,   // column 4, page 1: 0b00000001
        0x3,   // column 5, page 1: 0b00000011
        0x2,   // column 6, page 1: 0b00000010
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x2b
    {
        0x0,   // column 0, page 0: 0b00000000
        0x80,  // column 1, page 0: 0b10000000
        0x80,  // column 2, page 0: 0b10000000
        0xe0,  // column 3, page 0: 0b11100000
        0xe0,  // column 4, page 0: 0b11100000
        0x80,  // column 5, page 0: 0b10000000
        0x80,  // column 6, page 0: 0b10000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x3,   // column 3, page 1: 0b00000011
        0x3,   // column 4, page 1: 0b00000011
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x2c
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0x0,   // column 2, page 0: 0b00000000
        0x0,   // column 3, page 0: 0b00000000
        0x0,   // column 4, page 0: 0b00000000
        0x0,   // column 5, page 0: 0b00000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x10,  // column 2, page 1: 0b00010000
        0x1e,  // column 3, page 1: 0b00011110
        0xe,   // column 4, page 1: 0b00001110
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x2d
    {
        0x80,  // column 0, page 0: 0b10000000
        0x80,  // column 1, page 0: 0b10000000
        0x80,  // column 2, page 0: 0b10000000
        0x80,  // column 3, page 0: 0b10000000
        0x80,  // column 4, page 0: 0b10000000
        0x80,  // column 5, page 0: 0b10000000
        0x80,  // column 6, page 0: 0b10000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x2e
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0x0,   // column 2, page 0: 0b00000000
        0x0,   // column 3, page 0: 0b00000000
        0x0,   // column 4, page 0: 0b00000000
        0x0,   // column 5, page 0: 0b00000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0xc,   // column 3, page 1: 0b00001100
        0xc,   // column 4, page 1: 0b00001100
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x2f
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0x0,   // column 2, page 0: 0b00000000
        0x80,  // column 3, page 0: 0b10000000
        0xc0,  // column 4, page 0: 0b11000000
        0x60,  // column 5, page 0: 0b01100000
        0x30,  // column 6, page 0: 0b00110000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0xc,   // column 0, page 1: 0b00001100
        0x6,   // column 1, page 1: 0b00000110
        0x3,   // column 2, page 1: 0b00000011
        0x1,   // column 3, page 1: 0b00000001
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x30
    {
        0xf0,  // column 0, page 0: 0b11110000
        0xf8,  // column 1, page 0: 0b11111000
        0xc,   // column 2, page 0: 0b00001100
        0xc4,  // column 3, page 0: 0b11000100
        0xc4,  // column 4, page 0: 0b11000100
        0xc,   // column 5, page 0: 0b00001100
        0xf8,  // column 6, page 0: 0b11111000
        0xf0,  // column 7, page 0: 0b11110000
        0x0,   // column 8, page 0: 0b00000000
        0x3,   // column 0, page 1: 0b00000011
        0x7,   // column 1, page 1: 0b00000111
        0xc,   // column 2, page 1: 0b00001100
        0x8,   // column 3, page 1: 0b00001000
        0x8,   // column 4, page 1: 0b00001000
        0xc,   // column 5, page 1: 0b00001100
        0x7,   // column 6, page 1: 0b00000111
        0x3,   // column 7, page 1: 0b00000011
        0x0    // column 8, page 1: 0b00000000
    },
// 0x31
    {
        0x0,   // column 0, page 0: 0b00000000
        0x10,  // column 1, page 0: 0b00010000
        0x18,  // column 2, page 0: 0b00011000
        0xfc,  // column 3, page 0: 0b11111100
        0xfc,  // column 4, page 0: 0b11111100
        0x0,   // column 5, page 0: 0b00000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x8,   // column 1, page 1: 0b00001000
        0x8,   // column 2, page 1: 0b00001000
        0xf,   // column 3, page 1: 0b00001111
        0xf,   // column 4, page 1: 0b00001111
        0x8,   // column 5, page 1: 0b00001000
        0x8,   // column 6, page 1: 0b00001000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x32
    {
        0x8,   // column 0, page 0: 0b00001000
        0xc,   // column 1, page 0: 0b00001100
        0x84,  // column 2, page 0: 0b10000100
        0xc4,  // column 3, page 0: 0b11000100
        0x64,  // column 4, page 0: 0b01100100
        0x3c,  // column 5, page 0: 0b00111100
        0x18,  // column 6, page 0: 0b00011000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0xe,   // column 0, page 1: 0b00001110
        0xf,   // column 1, page 1: 0b00001111
        0x9,   // column 2, page 1: 0b00001001
        0x8,   // column 3, page 1: 0b00001000
        0x8,   // column 4, page 1: 0b00001000
        0xc,   // column 5, page 1: 0b00001100
        0xc,   // column 6, page 1: 0b00001100
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x33
    {
        0x8,   // column 0, page 0: 0b00001000
        0xc,   // column 1, page 0: 0b00001100
        0x44,  // column 2, page 0: 0b01000100
        0x44,  // column 3, page 0: 0b01000100
        0x44,  // column 4, page 0: 0b01000100
        0xfc,  // column 5, page 0: 0b11111100
        0xb8,  // column 6, page 0: 0b10111000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x4,   // column 0, page 1: 0b00000100
        0xc,   // column 1, page 1: 0b00001100
        0x8,   // column 2, page 1: 0b00001000
        0x8,   // column 3, page 1: 0b00001000
        0x8,   // column 4, page 1: 0b00001000
        0xf,   // column 5, page 1: 0b00001111
        0x7,   // column 6, page 1: 0b00000111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x34
    {
        0xc0,  // column 0, page 0: 0b11000000
        0xe0,  // column 1, page 0: 0b11100000
        0xb0,  // column 2, page 0: 0b10110000
        0x98,  // column 3, page 0: 0b10011000
        0xfc,  // column 4, page 0: 0b11111100
        0xfc,  // column 5, page 0: 0b11111100
        0x80,  // column 6, page 0: 0b10000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x8,   // column 3, page 1: 0b00001000
        0xf,   // column 4, page 1: 0b00001111
        0xf,   // column 5, page 1: 0b00001111
        0x8,   // column 6, page 1: 0b00001000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x35
    {
        0x7c,  // column 0, page 0: 0b01111100
        0x7c,  // column 1, page 0: 0b01111100
        0x44,  // column 2, page 0: 0b01000100
        0x44,  // column 3, page 0: 0b01000100
        0x44,  // column 4, page 0: 0b01000100
        0xc4,  // column 5, page 0: 0b11000100
        0x84,  // column 6, page 0: 0b10000100
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x4,   // column 0, page 1: 0b00000100
        0xc,   // column 1, page 1: 0b00001100
        0x8,   // column 2, page 1: 0b00001000
        0x8,   // column 3, page 1: 0b00001000
        0x8,   // column 4, page 1: 0b00001000
        0xf,   // column 5, page 1: 0b00001111
        0x7,   // column 6, page 1: 0b00000111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x36
    {
        0xf0,  // column 0, page 0: 0b11110000
        0xf8,  // column 1, page 0: 0b11111000
        0x4c,  // column 2, page 0: 0b01001100
        0x44,  // column 3, page 0: 0b01000100
        0x44,  // column 4, page 0: 0b01000100
        0xc0,  // column 5, page 0: 0b11000000
        0x80,  // column 6, page 0: 0b10000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0x8,   // column 3, page 1: 0b00001000
        0x8,   // column 4, page 1: 0b00001000
        0xf,   // column 5, page 1: 0b00001111
        0x7,   // column 6, page 1: 0b00000111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x37
    {
        0xc,   // column 0, page 0: 0b00001100
        0xc,   // column 1, page 0: 0b00001100
        0x4,   // column 2, page 0: 0b00000100
        0x84,  // column 3, page 0: 0b10000100
        0xc4,  // column 4, page 0: 0b11000100
        0x7c,  // column 5, page 0: 0b01111100
        0x3c,  // column 6, page 0: 0b00111100
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0xf,   // column 2, page 1: 0b00001111
        0xf,   // column 3, page 1: 0b00001111
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x38
    {
        0xb8,  // column 0, page 0: 0b10111000
        0xfc,  // column 1, page 0: 0b11111100
        0x44,  // column 2, page 0: 0b01000100
        0x44,  // column 3, page 0: 0b01000100
        0x44,  // column 4, page 0: 0b01000100
        0xfc,  // column 5, page 0: 0b11111100
        0xb8,  // column 6, page 0: 0b10111000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0x8,   // column 3, page 1: 0b00001000
        0x8,   // column 4, page 1: 0b00001000
        0xf,   // column 5, page 1: 0b00001111
        0x7,   // column 6, page 1: 0b00000111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x39
    {
        0x38,  // column 0, page 0: 0b00111000
        0x7c,  // column 1, page 0: 0b01111100
        0x44,  // column 2, page 0: 0b01000100
        0x44,  // column 3, page 0: 0b01000100
        0x44,  // column 4, page 0: 0b01000100
        0xfc,  // column 5, page 0: 0b11111100
        0xf8,  // column 6, page 0: 0b11111000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x8,   // column 1, page 1: 0b00001000
        0x8,   // column 2, page 1: 0b00001000
        0x8,   // column 3, page 1: 0b00001000
        0xc,   // column 4, page 1: 0b00001100
        0x7,   // column 5, page 1: 0b00000111
        0x3,   // column 6, page 1: 0b00000011
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x3a
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0x0,   // column 2, page 0: 0b00000000
        0x30,  // column 3, page 0: 0b00110000
        0x30,  // column 4, page 0: 0b00110000
        0x0,   // column 5, page 0: 0b00000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x6,   // column 3, page 1: 0b00000110
        0x6,   // column 4, page 1: 0b00000110
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x3b
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0x0,   // column 2, page 0: 0b00000000
        0x30,  // column 3, page 0: 0b00110000
        0x30,  // column 4, page 0: 0b00110000
        0x0,   // column 5, page 0: 0b00000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x8,   // column 2, page 1: 0b00001000
        0xe,   // column 3, page 1: 0b00001110
        0x6,   // column 4, page 1: 0b00000110
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x3c
    {
        0x0,   // column 0, page 0: 0b00000000
        0x80,  // column 1, page 0: 0b10000000
        0xc0,  // column 2, page 0: 0b11000000
        0x60,  // column 3, page 0: 0b01100000
        0x30,  // column 4, page 0: 0b00110000
        0x18,  // column 5, page 0: 0b00011000
        0x8,   // column 6, page 0: 0b00001000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x1,   // column 2, page 1: 0b00000001
        0x3,   // column 3, page 1: 0b00000011
        0x6,   // column 4, page 1: 0b00000110
        0xc,   // column 5, page 1: 0b00001100
        0x8,   // column 6, page 1: 0b00001000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x3d
    {
        0x0,   // column 0, page 0: 0b00000000
        0x20,  // column 1, page 0: 0b00100000
        0x20,  // column 2, page 0: 0b00100000
        0x20,  // column 3, page 0: 0b00100000
        0x20,  // column 4, page 0: 0b00100000
        0x20,  // column 5, page 0: 0b00100000
        0x20,  // column 6, page 0: 0b00100000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x1,   // column 1, page 1: 0b00000001
        0x1,   // column 2, page 1: 0b00000001
        0x1,   // column 3, page 1: 0b00000001
        0x1,   // column 4, page 1: 0b00000001
        0x1,   // column 5, page 1: 0b00000001
        0x1,   // column 6, page 1: 0b00000001
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x3e
    {
        0x0,   // column 0, page 0: 0b00000000
        0x8,   // column 1, page 0: 0b00001000
        0x18,  // column 2, page 0: 0b00011000
        0x30,  // column 3, page 0: 0b00110000
        0x60,  // column 4, page 0: 0b01100000
        0xc0,  // column 5, page 0: 0b11000000
        0x80,  // column 6, page 0: 0b10000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x8,   // column 1, page 1: 0b00001000
        0xc,   // column 2, page 1: 0b00001100
        0x6,   // column 3, page 1: 0b00000110
        0x3,   // column 4, page 1: 0b00000011
        0x1,   // column 5, page 1: 0b00000001
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x3f
    {
        0x18,  // column 0, page 0: 0b00011000
        0x1c,  // column 1, page 0: 0b00011100
        0x4,   // column 2, page 0: 0b00000100
        0xc4,  // column 3, page 0: 0b11000100
        0xe4,  // column 4, page 0: 0b11100100
        0x3c,  // column 5, page 0: 0b00111100
        0x18,  // column 6, page 0: 0b00011000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0xd,   // column 3, page 1: 0b00001101
        0xd,   // column 4, page 1: 0b00001101
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x40
    {
        0xf0,  // column 0, page 0: 0b11110000
        0xf8,  // column 1, page 0: 0b11111000
        0x8,   // column 2, page 0: 0b00001000
        0xc8,  // column 3, page 0: 0b11001000
        0xc8,  // column 4, page 0: 0b11001000
        0xf8,  // column 5, page 0: 0b11111000
        0xf0,  // column 6, page 0: 0b11110000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0xb,   // column 3, page 1: 0b00001011
        0xb,   // column 4, page 1: 0b00001011
        0xb,   // column 5, page 1: 0b00001011
        0x1,   // column 6, page 1: 0b00000001
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x41
    {
        0xe0,  // column 0, page 0: 0b11100000
        0xf0,  // column 1, page 0: 0b11110000
        0x98,  // column 2, page 0: 0b10011000
        0x8c,  // column 3, page 0: 0b10001100
        0x98,  // column 4, page 0: 0b10011000
        0xf0,  // column 5, page 0: 0b11110000
        0xe0,  // column 6, page 0: 0b11100000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0xf,   // column 0, page 1: 0b00001111
        0xf,   // column 1, page 1: 0b00001111
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0xf,   // column 5, page 1: 0b00001111
        0xf,   // column 6, page 1: 0b00001111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x42
    {
        0x4,   // column 0, page 0: 0b00000100
        0xfc,  // column 1, page 0: 0b11111100
        0xfc,  // column 2, page 0: 0b11111100
        0x44,  // column 3, page 0: 0b01000100
        0x44,  // column 4, page 0: 0b01000100
        0xfc,  // column 5, page 0: 0b11111100
        0xb8,  // column 6, page 0: 0b10111000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x8,   // column 0, page 1: 0b00001000
        0xf,   // column 1, page 1: 0b00001111
        0xf,   // column 2, page 1: 0b00001111
        0x8,   // column 3, page 1: 0b00001000
        0x8,   // column 4, page 1: 0b00001000
        0xf,   // column 5, page 1: 0b00001111
        0x7,   // column 6, page 1: 0b00000111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x43
    {
        0xf0,  // column 0, page 0: 0b11110000
        0xf8,  // column 1, page 0: 0b11111000
        0xc,   // column 2, page 0: 0b00001100
        0x4,   // column 3, page 0: 0b00000100
        0x4,   // column 4, page 0: 0b00000100
        0xc,   // column 5, page 0: 0b00001100
        0x18,  // column 6, page 0: 0b00011000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x3,   // column 0, page 1: 0b00000011
        0x7,   // column 1, page 1: 0b00000111
        0xc,   // column 2, page 1: 0b00001100
        0x8,   // column 3, page 1: 0b00001000
        0x8,   // column 4, page 1: 0b00001000
        0xc,   // column 5, page 1: 0b00001100
        0x6,   // column 6, page 1: 0b00000110
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x44
    {
        0x4,   // column 0, page 0: 0b00000100
        0xfc,  // column 1, page 0: 0b11111100
        0xfc,  // column 2, page 0: 0b11111100
        0x4,   // column 3, page 0: 0b00000100
        0xc,   // column 4, page 0: 0b00001100
        0xf8,  // column 5, page 0: 0b11111000
        0xf0,  // column 6, page 0: 0b11110000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x8,   // column 0, page 1: 0b00001000
        0xf,   // column 1, page 1: 0b00001111
        0xf,   // column 2, page 1: 0b00001111
        0x8,   // column 3, page 1: 0b00001000
        0xc,   // column 4, page 1: 0b00001100
        0x7,   // column 5, page 1: 0b00000111
        0x3,   // column 6, page 1: 0b00000011
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x45
    {
        0x4,   // column 0, page 0: 0b00000100
        0xfc,  // column 1, page 0: 0b11111100
        0xfc,  // column 2, page 0: 0b11111100
        0x44,  // column 3, page 0: 0b01000100
        0xe4,  // column 4, page 0: 0b11100100
        0xc,   // column 5, page 0: 0b00001100
        0x1c,  // column 6, page 0: 0b00011100
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x8,   // column 0, page 1: 0b00001000
        0xf,   // column 1, page 1: 0b00001111
        0xf,   // column 2, page 1: 0b00001111
        0x8,   // column 3, page 1: 0b00001000
        0x8,   // column 4, page 1: 0b00001000
        0xc,   // column 5, page 1: 0b00001100
        0xe,   // column 6, page 1: 0b00001110
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x46
    {
        0x4,   // column 0, page 0: 0b00000100
        0xfc,  // column 1, page 0: 0b11111100
        0xfc,  // column 2, page 0: 0b11111100
        0x44,  // column 3, page 0: 0b01000100
        0xe4,  // column 4, page 0: 0b11100100
        0xc,   // column 5, page 0: 0b00001100
        0x1c,  // column 6, page 0: 0b00011100
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x8,   // column 0, page 1: 0b00001000
        0xf,   // column 1, page 1: 0b00001111
        0xf,   // column 2, page 1: 0b00001111
        0x8,   // column 3, page 1: 0b00001000
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x47
    {
        0xf0,  // column 0, page 0: 0b11110000
        0xf8,  // column 1, page 0: 0b11111000
        0xc,   // column 2, page 0: 0b00001100
        0x84,  // column 3, page 0: 0b10000100
        0x84,  // column 4, page 0: 0b10000100
        0x8c,  // column 5, page 0: 0b10001100
        0x98,  // column 6, page 0: 0b10011000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x3,   // column 0, page 1: 0b00000011
        0x7,   // column 1, page 1: 0b00000111
        0xc,   // column 2, page 1: 0b00001100
        0x8,   // column 3, page 1: 0b00001000
        0x8,   // column 4, page 1: 0b00001000
        0x7,   // column 5, page 1: 0b00000111
        0xf,   // column 6, page 1: 0b00001111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x48
    {
        0xfc,  // column 0, page 0: 0b11111100
        0xfc,  // column 1, page 0: 0b11111100
        0x40,  // column 2, page 0: 0b01000000
        0x40,  // column 3, page 0: 0b01000000
        0x40,  // column 4, page 0: 0b01000000
        0xfc,  // column 5, page 0: 0b11111100
        0xfc,  // column 6, page 0: 0b11111100
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0xf,   // column 0, page 1: 0b00001111
        0xf,   // column 1, page 1: 0b00001111
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0xf,   // column 5, page 1: 0b00001111
        0xf,   // column 6, page 1: 0b00001111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x49
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0x4,   // column 2, page 0: 0b00000100
        0xfc,  // column 3, page 0: 0b11111100
        0xfc,  // column 4, page 0: 0b11111100
        0x4,   // column 5, page 0: 0b00000100
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x8,   // column 2, page 1: 0b00001000
        0xf,   // column 3, page 1: 0b00001111
        0xf,   // column 4, page 1: 0b00001111
        0x8,   // column 5, page 1: 0b00001000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x4a
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0x0,   // column 2, page 0: 0b00000000
        0x4,   // column 3, page 0: 0b00000100
        0xfc,  // column 4, page 0: 0b11111100
        0xfc,  // column 5, page 0: 0b11111100
        0x4,   // column 6, page 0: 0b00000100
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0x8,   // column 3, page 1: 0b00001000
        0xf,   // column 4, page 1: 0b00001111
        0x7,   // column 5, page 1: 0b00000111
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x4b
    {
        0x4,   // column 0, page 0: 0b00000100
        0xfc,  // column 1, page 0: 0b11111100
        0xfc,  // column 2, page 0: 0b11111100
        0xc0,  // column 3, page 0: 0b11000000
        0xe0,  // column 4, page 0: 0b11100000
        0x3c,  // column 5, page 0: 0b00111100
        0x1c,  // column 6, page 0: 0b00011100
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x8,   // column 0, page 1: 0b00001000
        0xf,   // column 1, page 1: 0b00001111
        0xf,   // column 2, page 1: 0b00001111
        0x0,   // column 3, page 1: 0b00000000
        0x1,   // column 4, page 1: 0b00000001
        0xf,   // column 5, page 1: 0b00001111
        0xe,   // column 6, page 1: 0b00001110
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x4c
    {
        0x4,   // column 0, page 0: 0b00000100
        0xfc,  // column 1, page 0: 0b11111100
        0xfc,  // column 2, page 0: 0b11111100
        0x4,   // column 3, page 0: 0b00000100
        0x0,   // column 4, page 0: 0b00000000
        0x0,   // column 5, page 0: 0b00000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x8,   // column 0, page 1: 0b00001000
        0xf,   // column 1, page 1: 0b00001111
        0xf,   // column 2, page 1: 0b00001111
        0x8,   // column 3, page 1: 0b00001000
        0x8,   // column 4, page 1: 0b00001000
        0xc,   // column 5, page 1: 0b00001100
        0xe,   // column 6, page 1: 0b00001110
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x4d
    {
        0xfc,  // column 0, page 0: 0b11111100
        0xfc,  // column 1, page 0: 0b11111100
        0x38,  // column 2, page 0: 0b00111000
        0x70,  // column 3, page 0: 0b01110000
        0x70,  // column 4, page 0: 0b01110000
        0x38,  // column 5, page 0: 0b00111000
        0xfc,  // column 6, page 0: 0b11111100
        0xfc,  // column 7, page 0: 0b11111100
        0x0,   // column 8, page 0: 0b00000000
        0xf,   // column 0, page 1: 0b00001111
        0xf,   // column 1, page 1: 0b00001111
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0xf,   // column 6, page 1: 0b00001111
        0xf,   // column 7, page 1: 0b00001111
        0x0    // column 8, page 1: 0b00000000
    },
// 0x4e
    {
        0xfc,  // column 0, page 0: 0b11111100
        0xfc,  // column 1, page 0: 0b11111100
        0x38,  // column 2, page 0: 0b00111000
        0x70,  // column 3, page 0: 0b01110000
        0xe0,  // column 4, page 0: 0b11100000
        0xfc,  // column 5, page 0: 0b11111100
        0xfc,  // column 6, page 0: 0b11111100
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0xf,   // column 0, page 1: 0b00001111
        0xf,   // column 1, page 1: 0b00001111
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0xf,   // column 5, page 1: 0b00001111
        0xf,   // column 6, page 1: 0b00001111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x4f
    {
        0xf8,  // column 0, page 0: 0b11111000
        0xfc,  // column 1, page 0: 0b11111100
        0x4,   // column 2, page 0: 0b00000100
        0x4,   // column 3, page 0: 0b00000100
        0x4,   // column 4, page 0: 0b00000100
        0xfc,  // column 5, page 0: 0b11111100
        0xf8,  // column 6, page 0: 0b11111000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0x8,   // column 3, page 1: 0b00001000
        0x8,   // column 4, page 1: 0b00001000
        0xf,   // column 5, page 1: 0b00001111
        0x7,   // column 6, page 1: 0b00000111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x50
    {
        0x4,   // column 0, page 0: 0b00000100
        0xfc,  // column 1, page 0: 0b11111100
        0xfc,  // column 2, page 0: 0b11111100
        0x44,  // column 3, page 0: 0b01000100
        0x44,  // column 4, page 0: 0b01000100
        0x7c,  // column 5, page 0: 0b01111100
        0x38,  // column 6, page 0: 0b00111000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x8,   // column 0, page 1: 0b00001000
        0xf,   // column 1, page 1: 0b00001111
        0xf,   // column 2, page 1: 0b00001111
        0x8,   // column 3, page 1: 0b00001000
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x51
    {
        0xf8,  // column 0, page 0: 0b11111000
        0xfc,  // column 1, page 0: 0b11111100
        0x4,   // column 2, page 0: 0b00000100
        0x4,   // column 3, page 0: 0b00000100
        0x4,   // column 4, page 0: 0b00000100
        0xfc,  // column 5, page 0: 0b11111100
        0xf8,  // column 6, page 0: 0b11111000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0xe,   // column 3, page 1: 0b00001110
        0x3c,  // column 4, page 1: 0b00111100
        0x3f,  // column 5, page 1: 0b00111111
        0x27,  // column 6, page 1: 0b00100111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x52
    {
        0x4,   // column 0, page 0: 0b00000100
        0xfc,  // column 1, page 0: 0b11111100
        0xfc,  // column 2, page 0: 0b11111100
        0x44,  // column 3, page 0: 0b01000100
        0xc4,  // column 4, page 0: 0b11000100
        0xfc,  // column 5, page 0: 0b11111100
        0x38,  // column 6, page 0: 0b00111000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x8,   // column 0, page 1: 0b00001000
        0xf,   // column 1, page 1: 0b00001111
        0xf,   // column 2, page 1: 0b00001111
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0xf,   // column 5, page 1: 0b00001111
        0xf,   // column 6, page 1: 0b00001111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x53
    {
        0x18,  // column 0, page 0: 0b00011000
        0x3c,  // column 1, page 0: 0b00111100
        0x64,  // column 2, page 0: 0b01100100
        0x44,  // column 3, page 0: 0b01000100
        0xc4,  // column 4, page 0: 0b11000100
        0x9c,  // column 5, page 0: 0b10011100
        0x18,  // column 6, page 0: 0b00011000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x6,   // column 0, page 1: 0b00000110
        0xe,   // column 1, page 1: 0b00001110
        0x8,   // column 2, page 1: 0b00001000
        0x8,   // column 3, page 1: 0b00001000
        0x8,   // column 4, page 1: 0b00001000
        0xf,   // column 5, page 1: 0b00001111
        0x7,   // column 6, page 1: 0b00000111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x54
    {
        0x1c,  // column 0, page 0: 0b00011100
        0xc,   // column 1, page 0: 0b00001100
        0x4,   // column 2, page 0: 0b00000100
        0xfc,  // column 3, page 0: 0b11111100
        0xfc,  // column 4, page 0: 0b11111100
        0x4,   // column 5, page 0: 0b00000100
        0xc,   // column 6, page 0: 0b00001100
        0x1c,  // column 7, page 0: 0b00011100
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x8,   // column 2, page 1: 0b00001000
        0xf,   // column 3, page 1: 0b00001111
        0xf,   // column 4, page 1: 0b00001111
        0x8,   // column 5, page 1: 0b00001000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x55
    {
        0xfc,  // column 0, page 0: 0b11111100
        0xfc,  // column 1, page 0: 0b11111100
        0x0,   // column 2, page 0: 0b00000000
        0x0,   // column 3, page 0: 0b00000000
        0x0,   // column 4, page 0: 0b00000000
        0xfc,  // column 5, page 0: 0b11111100
        0xfc,  // column 6, page 0: 0b11111100
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0x8,   // column 3, page 1: 0b00001000
        0x8,   // column 4, page 1: 0b00001000
        0xf,   // column 5, page 1: 0b00001111
        0x7,   // column 6, page 1: 0b00000111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x56
    {
        0xfc,  // column 0, page 0: 0b11111100
        0xfc,  // column 1, page 0: 0b11111100
        0x0,   // column 2, page 0: 0b00000000
        0x0,   // column 3, page 0: 0b00000000
        0x0,   // column 4, page 0: 0b00000000
        0x0,   // column 5, page 0: 0b00000000
        0xfc,  // column 6, page 0: 0b11111100
        0xfc,  // column 7, page 0: 0b11111100
        0x0,   // column 8, page 0: 0b00000000
        0x1,   // column 0, page 1: 0b00000001
        0x3,   // column 1, page 1: 0b00000011
        0x6,   // column 2, page 1: 0b00000110
        0xc,   // column 3, page 1: 0b00001100
        0xc,   // column 4, page 1: 0b00001100
        0x6,   // column 5, page 1: 0b00000110
        0x3,   // column 6, page 1: 0b00000011
        0x1,   // column 7, page 1: 0b00000001
        0x0    // column 8, page 1: 0b00000000
    },
// 0x57
    {
        0xfc,  // column 0, page 0: 0b11111100
        0xfc,  // column 1, page 0: 0b11111100
        0x0,   // column 2, page 0: 0b00000000
        0x80,  // column 3, page 0: 0b10000000
        0x80,  // column 4, page 0: 0b10000000
        0x0,   // column 5, page 0: 0b00000000
        0xfc,  // column 6, page 0: 0b11111100
        0xfc,  // column 7, page 0: 0b11111100
        0x0,   // column 8, page 0: 0b00000000
        0x3,   // column 0, page 1: 0b00000011
        0xf,   // column 1, page 1: 0b00001111
        0xe,   // column 2, page 1: 0b00001110
        0x3,   // column 3, page 1: 0b00000011
        0x3,   // column 4, page 1: 0b00000011
        0xe,   // column 5, page 1: 0b00001110
        0xf,   // column 6, page 1: 0b00001111
        0x3,   // column 7, page 1: 0b00000011
        0x0    // column 8, page 1: 0b00000000
    },
// 0x58
    {
        0xc,   // column 0, page 0: 0b00001100
        0x1c,  // column 1, page 0: 0b00011100
        0x30,  // column 2, page 0: 0b00110000
        0xe0,  // column 3, page 0: 0b11100000
        0xe0,  // column 4, page 0: 0b11100000
        0x30,  // column 5, page 0: 0b00110000
        0x1c,  // column 6, page 0: 0b00011100
        0xc,   // column 7, page 0: 0b00001100
        0x0,   // column 8, page 0: 0b00000000
        0xc,   // column 0, page 1: 0b00001100
        0xe,   // column 1, page 1: 0b00001110
        0x3,   // column 2, page 1: 0b00000011
        0x1,   // column 3, page 1: 0b00000001
        0x1,   // column 4, page 1: 0b00000001
        0x3,   // column 5, page 1: 0b00000011
        0xe,   // column 6, page 1: 0b00001110
        0xc,   // column 7, page 1: 0b00001100
        0x0    // column 8, page 1: 0b00000000
    },
// 0x59
    {
        0x1c,  // column 0, page 0: 0b00011100
        0x3c,  // column 1, page 0: 0b00111100
        0x60,  // column 2, page 0: 0b01100000
        0xc0,  // column 3, page 0: 0b11000000
        0xc0,  // column 4, page 0: 0b11000000
        0x60,  // column 5, page 0: 0b01100000
        0x3c,  // column 6, page 0: 0b00111100
        0x1c,  // column 7, page 0: 0b00011100
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x8,   // column 2, page 1: 0b00001000
        0xf,   // column 3, page 1: 0b00001111
        0xf,   // column 4, page 1: 0b00001111
        0x8,   // column 5, page 1: 0b00001000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x5a
    {
        0x1c,  // column 0, page 0: 0b00011100
        0xc,   // column 1, page 0: 0b00001100
        0x84,  // column 2, page 0: 0b10000100
        0xc4,  // column 3, page 0: 0b11000100
        0x64,  // column 4, page 0: 0b01100100
        0x34,  // column 5, page 0: 0b00110100
        0x1c,  // column 6, page 0: 0b00011100
        0xc,   // column 7, page 0: 0b00001100
        0x0,   // column 8, page 0: 0b00000000
        0xe,   // column 0, page 1: 0b00001110
        0xf,   // column 1, page 1: 0b00001111
        0x9,   // column 2, page 1: 0b00001001
        0x8,   // column 3, page 1: 0b00001000
        0x8,   // column 4, page 1: 0b00001000
        0x8,   // column 5, page 1: 0b00001000
        0xc,   // column 6, page 1: 0b00001100
        0xe,   // column 7, page 1: 0b00001110
        0x0    // column 8, page 1: 0b00000000
    },
// 0x5b
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0xfc,  // column 2, page 0: 0b11111100
        0xfc,  // column 3, page 0: 0b11111100
        0x4,   // column 4, page 0: 0b00000100
        0x4,   // column 5, page 0: 0b00000100
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0xf,   // column 2, page 1: 0b00001111
        0xf,   // column 3, page 1: 0b00001111
        0x8,   // column 4, page 1: 0b00001000
        0x8,   // column 5, page 1: 0b00001000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x5c
    {
        0x38,  // column 0, page 0: 0b00111000
        0x70,  // column 1, page 0: 0b01110000
        0xe0,  // column 2, page 0: 0b11100000
        0xc0,  // column 3, page 0: 0b11000000
        0x80,  // column 4, page 0: 0b10000000
        0x0,   // column 5, page 0: 0b00000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x1,   // column 3, page 1: 0b00000001
        0x3,   // column 4, page 1: 0b00000011
        0x7,   // column 5, page 1: 0b00000111
        0xe,   // column 6, page 1: 0b00001110
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x5d
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0x4,   // column 2, page 0: 0b00000100
        0x4,   // column 3, page 0: 0b00000100
        0xfc,  // column 4, page 0: 0b11111100
        0xfc,  // column 5, page 0: 0b11111100
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x8,   // column 2, page 1: 0b00001000
        0x8,   // column 3, page 1: 0b00001000
        0xf,   // column 4, page 1: 0b00001111
        0xf,   // column 5, page 1: 0b00001111
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x5e
    {
        0x8,   // column 0, page 0: 0b00001000
        0xc,   // column 1, page 0: 0b00001100
        0x6,   // column 2, page 0: 0b00000110
        0x3,   // column 3, page 0: 0b00000011
        0x6,   // column 4, page 0: 0b00000110
        0xc,   // column 5, page 0: 0b00001100
        0x8,   // column 6, page 0: 0b00001000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x5f
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0x0,   // column 2, page 0: 0b00000000
        0x0,   // column 3, page 0: 0b00000000
        0x0,   // column 4, page 0: 0b00000000
        0x0,   // column 5, page 0: 0b00000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x20,  // column 0, page 1: 0b00100000
        0x20,  // column 1, page 1: 0b00100000
        0x20,  // column 2, page 1: 0b00100000
        0x20,  // column 3, page 1: 0b00100000
        0x20,  // column 4, page 1: 0b00100000
        0x20,  // column 5, page 1: 0b00100000
        0x20,  // column 6, page 1: 0b00100000
        0x20,  // column 7, page 1: 0b00100000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x60
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0x3,   // column 2, page 0: 0b00000011
        0x7,   // column 3, page 0: 0b00000111
        0x4,   // column 4, page 0: 0b00000100
        0x0,   // column 5, page 0: 0b00000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x61
    {
        0x0,   // column 0, page 0: 0b00000000
        0xa0,  // column 1, page 0: 0b10100000
        0xa0,  // column 2, page 0: 0b10100000
        0xa0,  // column 3, page 0: 0b10100000
        0xe0,  // column 4, page 0: 0b11100000
        0xc0,  // column 5, page 0: 0b11000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0x8,   // column 3, page 1: 0b00001000
        0x7,   // column 4, page 1: 0b00000111
        0xf,   // column 5, page 1: 0b00001111
        0x8,   // column 6, page 1: 0b00001000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x62
    {
        0x4,   // column 0, page 0: 0b00000100
        0xfc,  // column 1, page 0: 0b11111100
        0xfc,  // column 2, page 0: 0b11111100
        0x20,  // column 3, page 0: 0b00100000
        0x60,  // column 4, page 0: 0b01100000
        0xc0,  // column 5, page 0: 0b11000000
        0x80,  // column 6, page 0: 0b10000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0xf,   // column 1, page 1: 0b00001111
        0xf,   // column 2, page 1: 0b00001111
        0x8,   // column 3, page 1: 0b00001000
        0x8,   // column 4, page 1: 0b00001000
        0xf,   // column 5, page 1: 0b00001111
        0x7,   // column 6, page 1: 0b00000111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x63
    {
        0xc0,  // column 0, page 0: 0b11000000
        0xe0,  // column 1, page 0: 0b11100000
        0x20,  // column 2, page 0: 0b00100000
        0x20,  // column 3, page 0: 0b00100000
        0x20,  // column 4, page 0: 0b00100000
        0x60,  // column 5, page 0: 0b01100000
        0x40,  // column 6, page 0: 0b01000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0x8,   // column 3, page 1: 0b00001000
        0x8,   // column 4, page 1: 0b00001000
        0xc,   // column 5, page 1: 0b00001100
        0x4,   // column 6, page 1: 0b00000100
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x64
    {
        0x80,  // column 0, page 0: 0b10000000
        0xc0,  // column 1, page 0: 0b11000000
        0x60,  // column 2, page 0: 0b01100000
        0x24,  // column 3, page 0: 0b00100100
        0xfc,  // column 4, page 0: 0b11111100
        0xfc,  // column 5, page 0: 0b11111100
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0x8,   // column 3, page 1: 0b00001000
        0x7,   // column 4, page 1: 0b00000111
        0xf,   // column 5, page 1: 0b00001111
        0x8,   // column 6, page 1: 0b00001000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x65
    {
        0xc0,  // column 0, page 0: 0b11000000
        0xe0,  // column 1, page 0: 0b11100000
        0xa0,  // column 2, page 0: 0b10100000
        0xa0,  // column 3, page 0: 0b10100000
        0xa0,  // column 4, page 0: 0b10100000
        0xe0,  // column 5, page 0: 0b11100000
        0xc0,  // column 6, page 0: 0b11000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0x8,   // column 3, page 1: 0b00001000
        0x8,   // column 4, page 1: 0b00001000
        0xc,   // column 5, page 1: 0b00001100
        0x4,   // column 6, page 1: 0b00000100
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x66
    {
        0x40,  // column 0, page 0: 0b01000000
        0xf8,  // column 1, page 0: 0b11111000
        0xfc,  // column 2, page 0: 0b11111100
        0x44,  // column 3, page 0: 0b01000100
        0xc,   // column 4, page 0: 0b00001100
        0x18,  // column 5, page 0: 0b00011000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x8,   // column 0, page 1: 0b00001000
        0xf,   // column 1, page 1: 0b00001111
        0xf,   // column 2, page 1: 0b00001111
        0x8,   // column 3, page 1: 0b00001000
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x67
    {
        0xc0,  // column 0, page 0: 0b11000000
        0xe0,  // column 1, page 0: 0b11100000
        0x20,  // column 2, page 0: 0b00100000
        0x20,  // column 3, page 0: 0b00100000
        0xc0,  // column 4, page 0: 0b11000000
        0xe0,  // column 5, page 0: 0b11100000
        0x20,  // column 6, page 0: 0b00100000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x27,  // column 0, page 1: 0b00100111
        0x6f,  // column 1, page 1: 0b01101111
        0x48,  // column 2, page 1: 0b01001000
        0x48,  // column 3, page 1: 0b01001000
        0x7f,  // column 4, page 1: 0b01111111
        0x3f,  // column 5, page 1: 0b00111111
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x68
    {
        0x4,   // column 0, page 0: 0b00000100
        0xfc,  // column 1, page 0: 0b11111100
        0xfc,  // column 2, page 0: 0b11111100
        0x40,  // column 3, page 0: 0b01000000
        0x20,  // column 4, page 0: 0b00100000
        0xe0,  // column 5, page 0: 0b11100000
        0xc0,  // column 6, page 0: 0b11000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x8,   // column 0, page 1: 0b00001000
        0xf,   // column 1, page 1: 0b00001111
        0xf,   // column 2, page 1: 0b00001111
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0xf,   // column 5, page 1: 0b00001111
        0xf,   // column 6, page 1: 0b00001111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x69
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0x20,  // column 2, page 0: 0b00100000
        0xec,  // column 3, page 0: 0b11101100
        0xec,  // column 4, page 0: 0b11101100
        0x0,   // column 5, page 0: 0b00000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x8,   // column 2, page 1: 0b00001000
        0xf,   // column 3, page 1: 0b00001111
        0xf,   // column 4, page 1: 0b00001111
        0x8,   // column 5, page 1: 0b00001000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x6a
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0x0,   // column 2, page 0: 0b00000000
        0x0,   // column 3, page 0: 0b00000000
        0x20,  // column 4, page 0: 0b00100000
        0xec,  // column 5, page 0: 0b11101100
        0xec,  // column 6, page 0: 0b11101100
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x30,  // column 1, page 1: 0b00110000
        0x70,  // column 2, page 1: 0b01110000
        0x40,  // column 3, page 1: 0b01000000
        0x40,  // column 4, page 1: 0b01000000
        0x7f,  // column 5, page 1: 0b01111111
        0x3f,  // column 6, page 1: 0b00111111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x6b
    {
        0x4,   // column 0, page 0: 0b00000100
        0xfc,  // column 1, page 0: 0b11111100
        0xfc,  // column 2, page 0: 0b11111100
        0x80,  // column 3, page 0: 0b10000000
        0xc0,  // column 4, page 0: 0b11000000
        0x60,  // column 5, page 0: 0b01100000
        0x20,  // column 6, page 0: 0b00100000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x8,   // column 0, page 1: 0b00001000
        0xf,   // column 1, page 1: 0b00001111
        0xf,   // column 2, page 1: 0b00001111
        0x1,   // column 3, page 1: 0b00000001
        0x3,   // column 4, page 1: 0b00000011
        0xe,   // column 5, page 1: 0b00001110
        0xc,   // column 6, page 1: 0b00001100
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x6c
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0x4,   // column 2, page 0: 0b00000100
        0xfc,  // column 3, page 0: 0b11111100
        0xfc,  // column 4, page 0: 0b11111100
        0x0,   // column 5, page 0: 0b00000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x8,   // column 2, page 1: 0b00001000
        0xf,   // column 3, page 1: 0b00001111
        0xf,   // column 4, page 1: 0b00001111
        0x8,   // column 5, page 1: 0b00001000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x6d
    {
        0xe0,  // column 0, page 0: 0b11100000
        0xe0,  // column 1, page 0: 0b11100000
        0x60,  // column 2, page 0: 0b01100000
        0xc0,  // column 3, page 0: 0b11000000
        0xc0,  // column 4, page 0: 0b11000000
        0x60,  // column 5, page 0: 0b01100000
        0xe0,  // column 6, page 0: 0b11100000
        0xc0,  // column 7, page 0: 0b11000000
        0x0,   // column 8, page 0: 0b00000000
        0xf,   // column 0, page 1: 0b00001111
        0xf,   // column 1, page 1: 0b00001111
        0x0,   // column 2, page 1: 0b00000000
        0xf,   // column 3, page 1: 0b00001111
        0xf,   // column 4, page 1: 0b00001111
        0x0,   // column 5, page 1: 0b00000000
        0xf,   // column 6, page 1: 0b00001111
        0xf,   // column 7, page 1: 0b00001111
        0x0    // column 8, page 1: 0b00000000
    },
// 0x6e
    {
        0x20,  // column 0, page 0: 0b00100000
        0xe0,  // column 1, page 0: 0b11100000
        0xc0,  // column 2, page 0: 0b11000000
        0x20,  // column 3, page 0: 0b00100000
        0x20,  // column 4, page 0: 0b00100000
        0xe0,  // column 5, page 0: 0b11100000
        0xc0,  // column 6, page 0: 0b11000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0xf,   // column 1, page 1: 0b00001111
        0xf,   // column 2, page 1: 0b00001111
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0xf,   // column 5, page 1: 0b00001111
        0xf,   // column 6, page 1: 0b00001111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x6f
    {
        0xc0,  // column 0, page 0: 0b11000000
        0xe0,  // column 1, page 0: 0b11100000
        0x20,  // column 2, page 0: 0b00100000
        0x20,  // column 3, page 0: 0b00100000
        0x20,  // column 4, page 0: 0b00100000
        0xe0,  // column 5, page 0: 0b11100000
        0xc0,  // column 6, page 0: 0b11000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0x8,   // column 3, page 1: 0b00001000
        0x8,   // column 4, page 1: 0b00001000
        0xf,   // column 5, page 1: 0b00001111
        0x7,   // column 6, page 1: 0b00000111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x70
    {
        0x20,  // column 0, page 0: 0b00100000
        0xe0,  // column 1, page 0: 0b11100000
        0xc0,  // column 2, page 0: 0b11000000
        0x20,  // column 3, page 0: 0b00100000
        0x20,  // column 4, page 0: 0b00100000
        0xe0,  // column 5, page 0: 0b11100000
        0xc0,  // column 6, page 0: 0b11000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x40,  // column 0, page 1: 0b01000000
        0x7f,  // column 1, page 1: 0b01111111
        0x7f,  // column 2, page 1: 0b01111111
        0x48,  // column 3, page 1: 0b01001000
        0x8,   // column 4, page 1: 0b00001000
        0xf,   // column 5, page 1: 0b00001111
        0x7,   // column 6, page 1: 0b00000111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x71
    {
        0xc0,  // column 0, page 0: 0b11000000
        0xe0,  // column 1, page 0: 0b11100000
        0x20,  // column 2, page 0: 0b00100000
        0x20,  // column 3, page 0: 0b00100000
        0xc0,  // column 4, page 0: 0b11000000
        0xe0,  // column 5, page 0: 0b11100000
        0x20,  // column 6, page 0: 0b00100000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0x48,  // column 3, page 1: 0b01001000
        0x7f,  // column 4, page 1: 0b01111111
        0x7f,  // column 5, page 1: 0b01111111
        0x40,  // column 6, page 1: 0b01000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x72
    {
        0x20,  // column 0, page 0: 0b00100000
        0xe0,  // column 1, page 0: 0b11100000
        0xc0,  // column 2, page 0: 0b11000000
        0x60,  // column 3, page 0: 0b01100000
        0x20,  // column 4, page 0: 0b00100000
        0xe0,  // column 5, page 0: 0b11100000
        0xc0,  // column 6, page 0: 0b11000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x8,   // column 0, page 1: 0b00001000
        0xf,   // column 1, page 1: 0b00001111
        0xf,   // column 2, page 1: 0b00001111
        0x8,   // column 3, page 1: 0b00001000
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x73
    {
        0x40,  // column 0, page 0: 0b01000000
        0xe0,  // column 1, page 0: 0b11100000
        0xa0,  // column 2, page 0: 0b10100000
        0x20,  // column 3, page 0: 0b00100000
        0x20,  // column 4, page 0: 0b00100000
        0x60,  // column 5, page 0: 0b01100000
        0x40,  // column 6, page 0: 0b01000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x4,   // column 0, page 1: 0b00000100
        0xc,   // column 1, page 1: 0b00001100
        0x9,   // column 2, page 1: 0b00001001
        0x9,   // column 3, page 1: 0b00001001
        0xb,   // column 4, page 1: 0b00001011
        0xe,   // column 5, page 1: 0b00001110
        0x4,   // column 6, page 1: 0b00000100
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x74
    {
        0x20,  // column 0, page 0: 0b00100000
        0x20,  // column 1, page 0: 0b00100000
        0xf8,  // column 2, page 0: 0b11111000
        0xfc,  // column 3, page 0: 0b11111100
        0x20,  // column 4, page 0: 0b00100000
        0x20,  // column 5, page 0: 0b00100000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x7,   // column 2, page 1: 0b00000111
        0xf,   // column 3, page 1: 0b00001111
        0x8,   // column 4, page 1: 0b00001000
        0xc,   // column 5, page 1: 0b00001100
        0x4,   // column 6, page 1: 0b00000100
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x75
    {
        0xe0,  // column 0, page 0: 0b11100000
        0xe0,  // column 1, page 0: 0b11100000
        0x0,   // column 2, page 0: 0b00000000
        0x0,   // column 3, page 0: 0b00000000
        0xe0,  // column 4, page 0: 0b11100000
        0xe0,  // column 5, page 0: 0b11100000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0x8,   // column 3, page 1: 0b00001000
        0x7,   // column 4, page 1: 0b00000111
        0xf,   // column 5, page 1: 0b00001111
        0x8,   // column 6, page 1: 0b00001000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x76
    {
        0xe0,  // column 0, page 0: 0b11100000
        0xe0,  // column 1, page 0: 0b11100000
        0x0,   // column 2, page 0: 0b00000000
        0x0,   // column 3, page 0: 0b00000000
        0x0,   // column 4, page 0: 0b00000000
        0x0,   // column 5, page 0: 0b00000000
        0xe0,  // column 6, page 0: 0b11100000
        0xe0,  // column 7, page 0: 0b11100000
        0x0,   // column 8, page 0: 0b00000000
        0x1,   // column 0, page 1: 0b00000001
        0x3,   // column 1, page 1: 0b00000011
        0x6,   // column 2, page 1: 0b00000110
        0xc,   // column 3, page 1: 0b00001100
        0xc,   // column 4, page 1: 0b00001100
        0x6,   // column 5, page 1: 0b00000110
        0x3,   // column 6, page 1: 0b00000011
        0x1,   // column 7, page 1: 0b00000001
        0x0    // column 8, page 1: 0b00000000
    },
// 0x77
    {
        0xe0,  // column 0, page 0: 0b11100000
        0xe0,  // column 1, page 0: 0b11100000
        0x0,   // column 2, page 0: 0b00000000
        0x0,   // column 3, page 0: 0b00000000
        0x0,   // column 4, page 0: 0b00000000
        0x0,   // column 5, page 0: 0b00000000
        0xe0,  // column 6, page 0: 0b11100000
        0xe0,  // column 7, page 0: 0b11100000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0xc,   // column 2, page 1: 0b00001100
        0x7,   // column 3, page 1: 0b00000111
        0x7,   // column 4, page 1: 0b00000111
        0xc,   // column 5, page 1: 0b00001100
        0xf,   // column 6, page 1: 0b00001111
        0x7,   // column 7, page 1: 0b00000111
        0x0    // column 8, page 1: 0b00000000
    },
// 0x78
    {
        0x20,  // column 0, page 0: 0b00100000
        0x60,  // column 1, page 0: 0b01100000
        0xc0,  // column 2, page 0: 0b11000000
        0x80,  // column 3, page 0: 0b10000000
        0x80,  // column 4, page 0: 0b10000000
        0xc0,  // column 5, page 0: 0b11000000
        0x60,  // column 6, page 0: 0b01100000
        0x20,  // column 7, page 0: 0b00100000
        0x0,   // column 8, page 0: 0b00000000
        0x8,   // column 0, page 1: 0b00001000
        0xc,   // column 1, page 1: 0b00001100
        0x6,   // column 2, page 1: 0b00000110
        0x3,   // column 3, page 1: 0b00000011
        0x3,   // column 4, page 1: 0b00000011
        0x6,   // column 5, page 1: 0b00000110
        0xc,   // column 6, page 1: 0b00001100
        0x8,   // column 7, page 1: 0b00001000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x79
    {
        0xe0,  // column 0, page 0: 0b11100000
        0xe0,  // column 1, page 0: 0b11100000
        0x0,   // column 2, page 0: 0b00000000
        0x0,   // column 3, page 0: 0b00000000
        0x0,   // column 4, page 0: 0b00000000
        0xe0,  // column 5, page 0: 0b11100000
        0xe0,  // column 6, page 0: 0b11100000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x47,  // column 0, page 1: 0b01000111
        0x4f,  // column 1, page 1: 0b01001111
        0x48,  // column 2, page 1: 0b01001000
        0x48,  // column 3, page 1: 0b01001000
        0x68,  // column 4, page 1: 0b01101000
        0x3f,  // column 5, page 1: 0b00111111
        0x1f,  // column 6, page 1: 0b00011111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x7a
    {
        0x60,  // column 0, page 0: 0b01100000
        0x60,  // column 1, page 0: 0b01100000
        0x20,  // column 2, page 0: 0b00100000
        0xa0,  // column 3, page 0: 0b10100000
        0xe0,  // column 4, page 0: 0b11100000
        0x60,  // column 5, page 0: 0b01100000
        0x20,  // column 6, page 0: 0b00100000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0xc,   // column 0, page 1: 0b00001100
        0xe,   // column 1, page 1: 0b00001110
        0xb,   // column 2, page 1: 0b00001011
        0x9,   // column 3, page 1: 0b00001001
        0x8,   // column 4, page 1: 0b00001000
        0xc,   // column 5, page 1: 0b00001100
        0xc,   // column 6, page 1: 0b00001100
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x7b
    {
        0x0,   // column 0, page 0: 0b00000000
        0x40,  // column 1, page 0: 0b01000000
        0x40,  // column 2, page 0: 0b01000000
        0xf8,  // column 3, page 0: 0b11111000
        0xbc,  // column 4, page 0: 0b10111100
        0x4,   // column 5, page 0: 0b00000100
        0x4,   // column 6, page 0: 0b00000100
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x7,   // column 3, page 1: 0b00000111
        0xf,   // column 4, page 1: 0b00001111
        0x8,   // column 5, page 1: 0b00001000
        0x8,   // column 6, page 1: 0b00001000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x7c
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0x0,   // column 2, page 0: 0b00000000
        0xbc,  // column 3, page 0: 0b10111100
        0xbc,  // column 4, page 0: 0b10111100
        0x0,   // column 5, page 0: 0b00000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0xf,   // column 3, page 1: 0b00001111
        0xf,   // column 4, page 1: 0b00001111
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x7d
    {
        0x0,   // column 0, page 0: 0b00000000
        0x4,   // column 1, page 0: 0b00000100
        0x4,   // column 2, page 0: 0b00000100
        0xbc,  // column 3, page 0: 0b10111100
        0xf8,  // column 4, page 0: 0b11111000
        0x40,  // column 5, page 0: 0b01000000
        0x40,  // column 6, page 0: 0b01000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x8,   // column 1, page 1: 0b00001000
        0x8,   // column 2, page 1: 0b00001000
        0xf,   // column 3, page 1: 0b00001111
        0x7,   // column 4, page 1: 0b00000111
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x7e
    {
        0x8,   // column 0, page 0: 0b00001000
        0xc,   // column 1, page 0: 0b00001100
        0x4,   // column 2, page 0: 0b00000100
        0xc,   // column 3, page 0: 0b00001100
        0x8,   // column 4, page 0: 0b00001000
        0xc,   // column 5, page 0: 0b00001100
        0x4,   // column 6, page 0: 0b00000100
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x7f
    {
        0x80,  // column 0, page 0: 0b10000000
        0xc0,  // column 1, page 0: 0b11000000
        0x60,  // column 2, page 0: 0b01100000
        0x30,  // column 3, page 0: 0b00110000
        0x60,  // column 4, page 0: 0b01100000
        0xc0,  // column 5, page 0: 0b11000000
        0x80,  // column 6, page 0: 0b10000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0x7,   // column 1, page 1: 0b00000111
        0x4,   // column 2, page 1: 0b00000100
        0x4,   // column 3, page 1: 0b00000100
        0x4,   // column 4, page 1: 0b00000100
        0x7,   // column 5, page 1: 0b00000111
        0x7,   // column 6, page 1: 0b00000111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x80
    {
        0xf0,  // column 0, page 0: 0b11110000
        0xf8,  // column 1, page 0: 0b11111000
        0xc,   // column 2, page 0: 0b00001100
        0x4,   // column 3, page 0: 0b00000100
        0x4,   // column 4, page 0: 0b00000100
        0xc,   // column 5, page 0: 0b00001100
        0x18,  // column 6, page 0: 0b00011000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x1,   // column 0, page 1: 0b00000001
        0x23,  // column 1, page 1: 0b00100011
        0x26,  // column 2, page 1: 0b00100110
        0x24,  // column 3, page 1: 0b00100100
        0x2c,  // column 4, page 1: 0b00101100
        0x3e,  // column 5, page 1: 0b00111110
        0x13,  // column 6, page 1: 0b00010011
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x81
    {
        0xe4,  // column 0, page 0: 0b11100100
        0xe4,  // column 1, page 0: 0b11100100
        0x0,   // column 2, page 0: 0b00000000
        0x0,   // column 3, page 0: 0b00000000
        0xe4,  // column 4, page 0: 0b11100100
        0xe4,  // column 5, page 0: 0b11100100
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0x8,   // column 3, page 1: 0b00001000
        0x7,   // column 4, page 1: 0b00000111
        0xf,   // column 5, page 1: 0b00001111
        0x8,   // column 6, page 1: 0b00001000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x82
    {
        0xc0,  // column 0, page 0: 0b11000000
        0xe0,  // column 1, page 0: 0b11100000
        0xa8,  // column 2, page 0: 0b10101000
        0xac,  // column 3, page 0: 0b10101100
        0xa6,  // column 4, page 0: 0b10100110
        0xe2,  // column 5, page 0: 0b11100010
        0xc0,  // column 6, page 0: 0b11000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0x8,   // column 3, page 1: 0b00001000
        0x8,   // column 4, page 1: 0b00001000
        0xc,   // column 5, page 1: 0b00001100
        0x4,   // column 6, page 1: 0b00000100
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x83
    {
        0x0,   // column 0, page 0: 0b00000000
        0xa8,  // column 1, page 0: 0b10101000
        0xac,  // column 2, page 0: 0b10101100
        0xa6,  // column 3, page 0: 0b10100110
        0xec,  // column 4, page 0: 0b11101100
        0xc8,  // column 5, page 0: 0b11001000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0x8,   // column 3, page 1: 0b00001000
        0x7,   // column 4, page 1: 0b00000111
        0xf,   // column 5, page 1: 0b00001111
        0x8,   // column 6, page 1: 0b00001000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x84
    {
        0x4,   // column 0, page 0: 0b00000100
        0xa4,  // column 1, page 0: 0b10100100
        0xa0,  // column 2, page 0: 0b10100000
        0xa0,  // column 3, page 0: 0b10100000
        0xe4,  // column 4, page 0: 0b11100100
        0xc4,  // column 5, page 0: 0b11000100
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0x8,   // column 3, page 1: 0b00001000
        0x7,   // column 4, page 1: 0b00000111
        0xf,   // column 5, page 1: 0b00001111
        0x8,   // column 6, page 1: 0b00001000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x85
    {
        0x0,   // column 0, page 0: 0b00000000
        0xa2,  // column 1, page 0: 0b10100010
        0xa6,  // column 2, page 0: 0b10100110
        0xac,  // column 3, page 0: 0b10101100
        0xe8,  // column 4, page 0: 0b11101000
        0xc0,  // column 5, page 0: 0b11000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0x8,   // column 3, page 1: 0b00001000
        0x7,   // column 4, page 1: 0b00000111
        0xf,   // column 5, page 1: 0b00001111
        0x8,   // column 6, page 1: 0b00001000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x86
    {
        0x0,   // column 0, page 0: 0b00000000
        0xa4,  // column 1, page 0: 0b10100100
        0xae,  // column 2, page 0: 0b10101110
        0xaa,  // column 3, page 0: 0b10101010
        0xee,  // column 4, page 0: 0b11101110
        0xc4,  // column 5, page 0: 0b11000100
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0x8,   // column 3, page 1: 0b00001000
        0x7,   // column 4, page 1: 0b00000111
        0xf,   // column 5, page 1: 0b00001111
        0x8,   // column 6, page 1: 0b00001000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x87
    {
        0x0,   // column 0, page 0: 0b00000000
        0xe0,  // column 1, page 0: 0b11100000
        0xf0,  // column 2, page 0: 0b11110000
        0x10,  // column 3, page 0: 0b00010000
        0x10,  // column 4, page 0: 0b00010000
        0x30,  // column 5, page 0: 0b00110000
        0x20,  // column 6, page 0: 0b00100000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x1,   // column 1, page 1: 0b00000001
        0x13,  // column 2, page 1: 0b00010011
        0x12,  // column 3, page 1: 0b00010010
        0x16,  // column 4, page 1: 0b00010110
        0x1f,  // column 5, page 1: 0b00011111
        0x9,   // column 6, page 1: 0b00001001
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x88
    {
        0xc0,  // column 0, page 0: 0b11000000
        0xe8,  // column 1, page 0: 0b11101000
        0xac,  // column 2, page 0: 0b10101100
        0xa6,  // column 3, page 0: 0b10100110
        0xac,  // column 4, page 0: 0b10101100
        0xe8,  // column 5, page 0: 0b11101000
        0xc0,  // column 6, page 0: 0b11000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0x8,   // column 3, page 1: 0b00001000
        0x8,   // column 4, page 1: 0b00001000
        0xc,   // column 5, page 1: 0b00001100
        0x4,   // column 6, page 1: 0b00000100
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x89
    {
        0xc4,  // column 0, page 0: 0b11000100
        0xe4,  // column 1, page 0: 0b11100100
        0xa0,  // column 2, page 0: 0b10100000
        0xa0,  // column 3, page 0: 0b10100000
        0xa0,  // column 4, page 0: 0b10100000
        0xe4,  // column 5, page 0: 0b11100100
        0xc4,  // column 6, page 0: 0b11000100
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0x8,   // column 3, page 1: 0b00001000
        0x8,   // column 4, page 1: 0b00001000
        0xc,   // column 5, page 1: 0b00001100
        0x4,   // column 6, page 1: 0b00000100
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x8a
    {
        0xc0,  // column 0, page 0: 0b11000000
        0xe2,  // column 1, page 0: 0b11100010
        0xa6,  // column 2, page 0: 0b10100110
        0xac,  // column 3, page 0: 0b10101100
        0xa8,  // column 4, page 0: 0b10101000
        0xe0,  // column 5, page 0: 0b11100000
        0xc0,  // column 6, page 0: 0b11000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0x8,   // column 3, page 1: 0b00001000
        0x8,   // column 4, page 1: 0b00001000
        0xc,   // column 5, page 1: 0b00001100
        0x4,   // column 6, page 1: 0b00000100
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x8b
    {
        0x0,   // column 0, page 0: 0b00000000
        0x4,   // column 1, page 0: 0b00000100
        0x24,  // column 2, page 0: 0b00100100
        0xe0,  // column 3, page 0: 0b11100000
        0xe0,  // column 4, page 0: 0b11100000
        0x4,   // column 5, page 0: 0b00000100
        0x4,   // column 6, page 0: 0b00000100
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x8,   // column 2, page 1: 0b00001000
        0xf,   // column 3, page 1: 0b00001111
        0xf,   // column 4, page 1: 0b00001111
        0x8,   // column 5, page 1: 0b00001000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x8c
    {
        0x0,   // column 0, page 0: 0b00000000
        0x8,   // column 1, page 0: 0b00001000
        0x2c,  // column 2, page 0: 0b00101100
        0xe6,  // column 3, page 0: 0b11100110
        0xe6,  // column 4, page 0: 0b11100110
        0xc,   // column 5, page 0: 0b00001100
        0x8,   // column 6, page 0: 0b00001000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x8,   // column 2, page 1: 0b00001000
        0xf,   // column 3, page 1: 0b00001111
        0xf,   // column 4, page 1: 0b00001111
        0x8,   // column 5, page 1: 0b00001000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x8d
    {
        0x0,   // column 0, page 0: 0b00000000
        0x2,   // column 1, page 0: 0b00000010
        0x26,  // column 2, page 0: 0b00100110
        0xec,  // column 3, page 0: 0b11101100
        0xe8,  // column 4, page 0: 0b11101000
        0x0,   // column 5, page 0: 0b00000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x8,   // column 2, page 1: 0b00001000
        0xf,   // column 3, page 1: 0b00001111
        0xf,   // column 4, page 1: 0b00001111
        0x8,   // column 5, page 1: 0b00001000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x8e
    {
        0xc2,  // column 0, page 0: 0b11000010
        0xe2,  // column 1, page 0: 0b11100010
        0x30,  // column 2, page 0: 0b00110000
        0x18,  // column 3, page 0: 0b00011000
        0x30,  // column 4, page 0: 0b00110000
        0xe2,  // column 5, page 0: 0b11100010
        0xc2,  // column 6, page 0: 0b11000010
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0xf,   // column 0, page 1: 0b00001111
        0xf,   // column 1, page 1: 0b00001111
        0x1,   // column 2, page 1: 0b00000001
        0x1,   // column 3, page 1: 0b00000001
        0x1,   // column 4, page 1: 0b00000001
        0xf,   // column 5, page 1: 0b00001111
        0xf,   // column 6, page 1: 0b00001111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x8f
    {
        0xc0,  // column 0, page 0: 0b11000000
        0xe2,  // column 1, page 0: 0b11100010
        0x37,  // column 2, page 0: 0b00110111
        0x15,  // column 3, page 0: 0b00010101
        0x37,  // column 4, page 0: 0b00110111
        0xe2,  // column 5, page 0: 0b11100010
        0xc0,  // column 6, page 0: 0b11000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0xf,   // column 0, page 1: 0b00001111
        0xf,   // column 1, page 1: 0b00001111
        0x1,   // column 2, page 1: 0b00000001
        0x1,   // column 3, page 1: 0b00000001
        0x1,   // column 4, page 1: 0b00000001
        0xf,   // column 5, page 1: 0b00001111
        0xf,   // column 6, page 1: 0b00001111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x90
    {
        0x10,  // column 0, page 0: 0b00010000
        0xf4,  // column 1, page 0: 0b11110100
        0xf6,  // column 2, page 0: 0b11110110
        0x93,  // column 3, page 0: 0b10010011
        0x91,  // column 4, page 0: 0b10010001
        0xb0,  // column 5, page 0: 0b10110000
        0x30,  // column 6, page 0: 0b00110000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x8,   // column 0, page 1: 0b00001000
        0xf,   // column 1, page 1: 0b00001111
        0xf,   // column 2, page 1: 0b00001111
        0x8,   // column 3, page 1: 0b00001000
        0x8,   // column 4, page 1: 0b00001000
        0xc,   // column 5, page 1: 0b00001100
        0xc,   // column 6, page 1: 0b00001100
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x91
    {
        0x0,   // column 0, page 0: 0b00000000
        0x20,  // column 1, page 0: 0b00100000
        0x60,  // column 2, page 0: 0b01100000
        0xc0,  // column 3, page 0: 0b11000000
        0xe0,  // column 4, page 0: 0b11100000
        0x20,  // column 5, page 0: 0b00100000
        0xe0,  // column 6, page 0: 0b11100000
        0xc0,  // column 7, page 0: 0b11000000
        0x0,   // column 8, page 0: 0b00000000
        0x6,   // column 0, page 1: 0b00000110
        0xf,   // column 1, page 1: 0b00001111
        0x9,   // column 2, page 1: 0b00001001
        0xf,   // column 3, page 1: 0b00001111
        0x7,   // column 4, page 1: 0b00000111
        0xd,   // column 5, page 1: 0b00001101
        0x9,   // column 6, page 1: 0b00001001
        0x8,   // column 7, page 1: 0b00001000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x92
    {
        0xf0,  // column 0, page 0: 0b11110000
        0xf8,  // column 1, page 0: 0b11111000
        0x4c,  // column 2, page 0: 0b01001100
        0x44,  // column 3, page 0: 0b01000100
        0xfc,  // column 4, page 0: 0b11111100
        0xfc,  // column 5, page 0: 0b11111100
        0x44,  // column 6, page 0: 0b01000100
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0xf,   // column 0, page 1: 0b00001111
        0xf,   // column 1, page 1: 0b00001111
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0xf,   // column 4, page 1: 0b00001111
        0xf,   // column 5, page 1: 0b00001111
        0x8,   // column 6, page 1: 0b00001000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x93
    {
        0xc0,  // column 0, page 0: 0b11000000
        0xe8,  // column 1, page 0: 0b11101000
        0x2c,  // column 2, page 0: 0b00101100
        0x26,  // column 3, page 0: 0b00100110
        0x2c,  // column 4, page 0: 0b00101100
        0xe8,  // column 5, page 0: 0b11101000
        0xc0,  // column 6, page 0: 0b11000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0x8,   // column 3, page 1: 0b00001000
        0x8,   // column 4, page 1: 0b00001000
        0xf,   // column 5, page 1: 0b00001111
        0x7,   // column 6, page 1: 0b00000111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x94
    {
        0xc4,  // column 0, page 0: 0b11000100
        0xe4,  // column 1, page 0: 0b11100100
        0x20,  // column 2, page 0: 0b00100000
        0x20,  // column 3, page 0: 0b00100000
        0x20,  // column 4, page 0: 0b00100000
        0xe4,  // column 5, page 0: 0b11100100
        0xc4,  // column 6, page 0: 0b11000100
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0x8,   // column 3, page 1: 0b00001000
        0x8,   // column 4, page 1: 0b00001000
        0xf,   // column 5, page 1: 0b00001111
        0x7,   // column 6, page 1: 0b00000111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x95
    {
        0xc0,  // column 0, page 0: 0b11000000
        0xe2,  // column 1, page 0: 0b11100010
        0x26,  // column 2, page 0: 0b00100110
        0x2c,  // column 3, page 0: 0b00101100
        0x28,  // column 4, page 0: 0b00101000
        0xe0,  // column 5, page 0: 0b11100000
        0xc0,  // column 6, page 0: 0b11000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0x8,   // column 3, page 1: 0b00001000
        0x8,   // column 4, page 1: 0b00001000
        0xf,   // column 5, page 1: 0b00001111
        0x7,   // column 6, page 1: 0b00000111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x96
    {
        0xe8,  // column 0, page 0: 0b11101000
        0xec,  // column 1, page 0: 0b11101100
        0x6,   // column 2, page 0: 0b00000110
        0x6,   // column 3, page 0: 0b00000110
        0xec,  // column 4, page 0: 0b11101100
        0xe8,  // column 5, page 0: 0b11101000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0x8,   // column 3, page 1: 0b00001000
        0x7,   // column 4, page 1: 0b00000111
        0xf,   // column 5, page 1: 0b00001111
        0x8,   // column 6, page 1: 0b00001000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x97
    {
        0xe0,  // column 0, page 0: 0b11100000
        0xe2,  // column 1, page 0: 0b11100010
        0x6,   // column 2, page 0: 0b00000110
        0xc,   // column 3, page 0: 0b00001100
        0xe8,  // column 4, page 0: 0b11101000
        0xe0,  // column 5, page 0: 0b11100000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0x8,   // column 3, page 1: 0b00001000
        0x7,   // column 4, page 1: 0b00000111
        0xf,   // column 5, page 1: 0b00001111
        0x8,   // column 6, page 1: 0b00001000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x98
    {
        0xe4,  // column 0, page 0: 0b11100100
        0xe4,  // column 1, page 0: 0b11100100
        0x0,   // column 2, page 0: 0b00000000
        0x0,   // column 3, page 0: 0b00000000
        0x0,   // column 4, page 0: 0b00000000
        0xe4,  // column 5, page 0: 0b11100100
        0xe4,  // column 6, page 0: 0b11100100
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0x4f,  // column 1, page 1: 0b01001111
        0x48,  // column 2, page 1: 0b01001000
        0x48,  // column 3, page 1: 0b01001000
        0x68,  // column 4, page 1: 0b01101000
        0x3f,  // column 5, page 1: 0b00111111
        0x1f,  // column 6, page 1: 0b00011111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x99
    {
        0xf2,  // column 0, page 0: 0b11110010
        0xfa,  // column 1, page 0: 0b11111010
        0x8,   // column 2, page 0: 0b00001000
        0x8,   // column 3, page 0: 0b00001000
        0x8,   // column 4, page 0: 0b00001000
        0xfa,  // column 5, page 0: 0b11111010
        0xf2,  // column 6, page 0: 0b11110010
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0x8,   // column 3, page 1: 0b00001000
        0x8,   // column 4, page 1: 0b00001000
        0xf,   // column 5, page 1: 0b00001111
        0x7,   // column 6, page 1: 0b00000111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x9a
    {
        0xfa,  // column 0, page 0: 0b11111010
        0xfa,  // column 1, page 0: 0b11111010
        0x0,   // column 2, page 0: 0b00000000
        0x0,   // column 3, page 0: 0b00000000
        0x0,   // column 4, page 0: 0b00000000
        0xfa,  // column 5, page 0: 0b11111010
        0xfa,  // column 6, page 0: 0b11111010
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0x8,   // column 3, page 1: 0b00001000
        0x8,   // column 4, page 1: 0b00001000
        0xf,   // column 5, page 1: 0b00001111
        0x7,   // column 6, page 1: 0b00000111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x9b
    {
        0xf0,  // column 0, page 0: 0b11110000
        0xf8,  // column 1, page 0: 0b11111000
        0x8,   // column 2, page 0: 0b00001000
        0xe,   // column 3, page 0: 0b00001110
        0xe,   // column 4, page 0: 0b00001110
        0x8,   // column 5, page 0: 0b00001000
        0x18,  // column 6, page 0: 0b00011000
        0x10,  // column 7, page 0: 0b00010000
        0x0,   // column 8, page 0: 0b00000000
        0x1,   // column 0, page 1: 0b00000001
        0x3,   // column 1, page 1: 0b00000011
        0x2,   // column 2, page 1: 0b00000010
        0xe,   // column 3, page 1: 0b00001110
        0xe,   // column 4, page 1: 0b00001110
        0x2,   // column 5, page 1: 0b00000010
        0x3,   // column 6, page 1: 0b00000011
        0x1,   // column 7, page 1: 0b00000001
        0x0    // column 8, page 1: 0b00000000
    },
// 0x9c
    {
        0x20,  // column 0, page 0: 0b00100000
        0xfc,  // column 1, page 0: 0b11111100
        0xfe,  // column 2, page 0: 0b11111110
        0x22,  // column 3, page 0: 0b00100010
        0x6,   // column 4, page 0: 0b00000110
        0xc,   // column 5, page 0: 0b00001100
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0xc,   // column 0, page 1: 0b00001100
        0xf,   // column 1, page 1: 0b00001111
        0xf,   // column 2, page 1: 0b00001111
        0x8,   // column 3, page 1: 0b00001000
        0x8,   // column 4, page 1: 0b00001000
        0xc,   // column 5, page 1: 0b00001100
        0x4,   // column 6, page 1: 0b00000100
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x9d
    {
        0x44,  // column 0, page 0: 0b01000100
        0x4c,  // column 1, page 0: 0b01001100
        0x58,  // column 2, page 0: 0b01011000
        0xf0,  // column 3, page 0: 0b11110000
        0xf0,  // column 4, page 0: 0b11110000
        0x58,  // column 5, page 0: 0b01011000
        0x4c,  // column 6, page 0: 0b01001100
        0x44,  // column 7, page 0: 0b01000100
        0x0,   // column 8, page 0: 0b00000000
        0x1,   // column 0, page 1: 0b00000001
        0x1,   // column 1, page 1: 0b00000001
        0x1,   // column 2, page 1: 0b00000001
        0xf,   // column 3, page 1: 0b00001111
        0xf,   // column 4, page 1: 0b00001111
        0x1,   // column 5, page 1: 0b00000001
        0x1,   // column 6, page 1: 0b00000001
        0x1,   // column 7, page 1: 0b00000001
        0x0    // column 8, page 1: 0b00000000
    },
// 0x9e
    {
        0x2,   // column 0, page 0: 0b00000010
        0xfe,  // column 1, page 0: 0b11111110
        0xfe,  // column 2, page 0: 0b11111110
        0x12,  // column 3, page 0: 0b00010010
        0x92,  // column 4, page 0: 0b10010010
        0xde,  // column 5, page 0: 0b11011110
        0xec,  // column 6, page 0: 0b11101100
        0x80,  // column 7, page 0: 0b10000000
        0x0,   // column 8, page 0: 0b00000000
        0x8,   // column 0, page 1: 0b00001000
        0xf,   // column 1, page 1: 0b00001111
        0xf,   // column 2, page 1: 0b00001111
        0x8,   // column 3, page 1: 0b00001000
        0x0,   // column 4, page 1: 0b00000000
        0x7,   // column 5, page 1: 0b00000111
        0xf,   // column 6, page 1: 0b00001111
        0x8,   // column 7, page 1: 0b00001000
        0x0    // column 8, page 1: 0b00000000
    },
// 0x9f
    {
        0x0,   // column 0, page 0: 0b00000000
        0x40,  // column 1, page 0: 0b01000000
        0x40,  // column 2, page 0: 0b01000000
        0xfc,  // column 3, page 0: 0b11111100
        0xfe,  // column 4, page 0: 0b11111110
        0x42,  // column 5, page 0: 0b01000010
        0x46,  // column 6, page 0: 0b01000110
        0x4,   // column 7, page 0: 0b00000100
        0x0,   // column 8, page 0: 0b00000000
        0x10,  // column 0, page 1: 0b00010000
        0x30,  // column 1, page 1: 0b00110000
        0x20,  // column 2, page 1: 0b00100000
        0x3f,  // column 3, page 1: 0b00111111
        0x1f,  // column 4, page 1: 0b00011111
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xa0
    {
        0x0,   // column 0, page 0: 0b00000000
        0xa8,  // column 1, page 0: 0b10101000
        0xac,  // column 2, page 0: 0b10101100
        0xa6,  // column 3, page 0: 0b10100110
        0xe2,  // column 4, page 0: 0b11100010
        0xc0,  // column 5, page 0: 0b11000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0x8,   // column 3, page 1: 0b00001000
        0x7,   // column 4, page 1: 0b00000111
        0xf,   // column 5, page 1: 0b00001111
        0x8,   // column 6, page 1: 0b00001000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xa1
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0x28,  // column 2, page 0: 0b00101000
        0xec,  // column 3, page 0: 0b11101100
        0xe6,  // column 4, page 0: 0b11100110
        0x2,   // column 5, page 0: 0b00000010
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x8,   // column 2, page 1: 0b00001000
        0xf,   // column 3, page 1: 0b00001111
        0xf,   // column 4, page 1: 0b00001111
        0x8,   // column 5, page 1: 0b00001000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xa2
    {
        0xc0,  // column 0, page 0: 0b11000000
        0xe8,  // column 1, page 0: 0b11101000
        0x2c,  // column 2, page 0: 0b00101100
        0x26,  // column 3, page 0: 0b00100110
        0x22,  // column 4, page 0: 0b00100010
        0xe0,  // column 5, page 0: 0b11100000
        0xc0,  // column 6, page 0: 0b11000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0x8,   // column 3, page 1: 0b00001000
        0x8,   // column 4, page 1: 0b00001000
        0xf,   // column 5, page 1: 0b00001111
        0x7,   // column 6, page 1: 0b00000111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xa3
    {
        0xe0,  // column 0, page 0: 0b11100000
        0xe8,  // column 1, page 0: 0b11101000
        0xc,   // column 2, page 0: 0b00001100
        0x6,   // column 3, page 0: 0b00000110
        0xe2,  // column 4, page 0: 0b11100010
        0xe0,  // column 5, page 0: 0b11100000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0x8,   // column 3, page 1: 0b00001000
        0x7,   // column 4, page 1: 0b00000111
        0xf,   // column 5, page 1: 0b00001111
        0x8,   // column 6, page 1: 0b00001000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xa4
    {
        0x28,  // column 0, page 0: 0b00101000
        0xec,  // column 1, page 0: 0b11101100
        0xc4,  // column 2, page 0: 0b11000100
        0x2c,  // column 3, page 0: 0b00101100
        0x28,  // column 4, page 0: 0b00101000
        0xec,  // column 5, page 0: 0b11101100
        0xc4,  // column 6, page 0: 0b11000100
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0xf,   // column 1, page 1: 0b00001111
        0xf,   // column 2, page 1: 0b00001111
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0xf,   // column 5, page 1: 0b00001111
        0xf,   // column 6, page 1: 0b00001111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xa5
    {
        0xfa,  // column 0, page 0: 0b11111010
        0xfb,  // column 1, page 0: 0b11111011
        0x71,  // column 2, page 0: 0b01110001
        0xe3,  // column 3, page 0: 0b11100011
        0xc2,  // column 4, page 0: 0b11000010
        0xfb,  // column 5, page 0: 0b11111011
        0xf9,  // column 6, page 0: 0b11111001
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0xf,   // column 0, page 1: 0b00001111
        0xf,   // column 1, page 1: 0b00001111
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x1,   // column 4, page 1: 0b00000001
        0xf,   // column 5, page 1: 0b00001111
        0xf,   // column 6, page 1: 0b00001111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xa6
    {
        0x0,   // column 0, page 0: 0b00000000
        0x4c,  // column 1, page 0: 0b01001100
        0x5e,  // column 2, page 0: 0b01011110
        0x52,  // column 3, page 0: 0b01010010
        0x5e,  // column 4, page 0: 0b01011110
        0x5e,  // column 5, page 0: 0b01011110
        0x50,  // column 6, page 0: 0b01010000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xa7
    {
        0x0,   // column 0, page 0: 0b00000000
        0x4c,  // column 1, page 0: 0b01001100
        0x5e,  // column 2, page 0: 0b01011110
        0x52,  // column 3, page 0: 0b01010010
        0x5e,  // column 4, page 0: 0b01011110
        0x4c,  // column 5, page 0: 0b01001100
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xa8
    {
        0x0,   // column 0, page 0: 0b00000000
        0x80,  // column 1, page 0: 0b10000000
        0xec,  // column 2, page 0: 0b11101100
        0x6c,  // column 3, page 0: 0b01101100
        0x0,   // column 4, page 0: 0b00000000
        0x0,   // column 5, page 0: 0b00000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0x8,   // column 3, page 1: 0b00001000
        0x8,   // column 4, page 1: 0b00001000
        0xe,   // column 5, page 1: 0b00001110
        0x6,   // column 6, page 1: 0b00000110
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xa9
    {
        0xc0,  // column 0, page 0: 0b11000000
        0xc0,  // column 1, page 0: 0b11000000
        0x40,  // column 2, page 0: 0b01000000
        0x40,  // column 3, page 0: 0b01000000
        0x40,  // column 4, page 0: 0b01000000
        0x40,  // column 5, page 0: 0b01000000
        0x40,  // column 6, page 0: 0b01000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0x7,   // column 1, page 1: 0b00000111
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xaa
    {
        0x40,  // column 0, page 0: 0b01000000
        0x40,  // column 1, page 0: 0b01000000
        0x40,  // column 2, page 0: 0b01000000
        0x40,  // column 3, page 0: 0b01000000
        0x40,  // column 4, page 0: 0b01000000
        0xc0,  // column 5, page 0: 0b11000000
        0xc0,  // column 6, page 0: 0b11000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0x7,   // column 5, page 1: 0b00000111
        0x7,   // column 6, page 1: 0b00000111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xab
    {
        0x3e,  // column 0, page 0: 0b00111110
        0x3e,  // column 1, page 0: 0b00111110
        0x80,  // column 2, page 0: 0b10000000
        0xc0,  // column 3, page 0: 0b11000000
        0x60,  // column 4, page 0: 0b01100000
        0x30,  // column 5, page 0: 0b00110000
        0x18,  // column 6, page 0: 0b00011000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x6,   // column 0, page 1: 0b00000110
        0x3,   // column 1, page 1: 0b00000011
        0x1,   // column 2, page 1: 0b00000001
        0x24,  // column 3, page 1: 0b00100100
        0x36,  // column 4, page 1: 0b00110110
        0x3a,  // column 5, page 1: 0b00111010
        0x2e,  // column 6, page 1: 0b00101110
        0x24,  // column 7, page 1: 0b00100100
        0x0    // column 8, page 1: 0b00000000
    },
// 0xac
    {
        0x3e,  // column 0, page 0: 0b00111110
        0x3e,  // column 1, page 0: 0b00111110
        0x80,  // column 2, page 0: 0b10000000
        0xc0,  // column 3, page 0: 0b11000000
        0x60,  // column 4, page 0: 0b01100000
        0x30,  // column 5, page 0: 0b00110000
        0x18,  // column 6, page 0: 0b00011000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x6,   // column 0, page 1: 0b00000110
        0x3,   // column 1, page 1: 0b00000011
        0x9,   // column 2, page 1: 0b00001001
        0xc,   // column 3, page 1: 0b00001100
        0xa,   // column 4, page 1: 0b00001010
        0x3f,  // column 5, page 1: 0b00111111
        0x3f,  // column 6, page 1: 0b00111111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xad
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0x0,   // column 2, page 0: 0b00000000
        0xec,  // column 3, page 0: 0b11101100
        0xec,  // column 4, page 0: 0b11101100
        0x0,   // column 5, page 0: 0b00000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x7,   // column 2, page 1: 0b00000111
        0xf,   // column 3, page 1: 0b00001111
        0xf,   // column 4, page 1: 0b00001111
        0x7,   // column 5, page 1: 0b00000111
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xae
    {
        0x80,  // column 0, page 0: 0b10000000
        0xc0,  // column 1, page 0: 0b11000000
        0x60,  // column 2, page 0: 0b01100000
        0xa0,  // column 3, page 0: 0b10100000
        0xc0,  // column 4, page 0: 0b11000000
        0x60,  // column 5, page 0: 0b01100000
        0x20,  // column 6, page 0: 0b00100000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x1,   // column 1, page 1: 0b00000001
        0x3,   // column 2, page 1: 0b00000011
        0x2,   // column 3, page 1: 0b00000010
        0x1,   // column 4, page 1: 0b00000001
        0x3,   // column 5, page 1: 0b00000011
        0x2,   // column 6, page 1: 0b00000010
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xaf
    {
        0x20,  // column 0, page 0: 0b00100000
        0x60,  // column 1, page 0: 0b01100000
        0xc0,  // column 2, page 0: 0b11000000
        0xa0,  // column 3, page 0: 0b10100000
        0x60,  // column 4, page 0: 0b01100000
        0xc0,  // column 5, page 0: 0b11000000
        0x80,  // column 6, page 0: 0b10000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x2,   // column 0, page 1: 0b00000010
        0x3,   // column 1, page 1: 0b00000011
        0x1,   // column 2, page 1: 0b00000001
        0x2,   // column 3, page 1: 0b00000010
        0x3,   // column 4, page 1: 0b00000011
        0x1,   // column 5, page 1: 0b00000001
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xb0
    {
        0x0,   // column 0, page 0: 0b00000000
        0xaa,  // column 1, page 0: 0b10101010
        0x0,   // column 2, page 0: 0b00000000
        0x55,  // column 3, page 0: 0b01010101
        0x0,   // column 4, page 0: 0b00000000
        0xaa,  // column 5, page 0: 0b10101010
        0x0,   // column 6, page 0: 0b00000000
        0x55,  // column 7, page 0: 0b01010101
        0x55,  // column 8, page 0: 0b01010101
        0x0,   // column 0, page 1: 0b00000000
        0xaa,  // column 1, page 1: 0b10101010
        0x0,   // column 2, page 1: 0b00000000
        0x55,  // column 3, page 1: 0b01010101
        0x0,   // column 4, page 1: 0b00000000
        0xaa,  // column 5, page 1: 0b10101010
        0x0,   // column 6, page 1: 0b00000000
        0x55,  // column 7, page 1: 0b01010101
        0x55   // column 8, page 1: 0b01010101
    },
// 0xb1
    {
        0xaa,  // column 0, page 0: 0b10101010
        0x55,  // column 1, page 0: 0b01010101
        0xaa,  // column 2, page 0: 0b10101010
        0x55,  // column 3, page 0: 0b01010101
        0xaa,  // column 4, page 0: 0b10101010
        0x55,  // column 5, page 0: 0b01010101
        0xaa,  // column 6, page 0: 0b10101010
        0x55,  // column 7, page 0: 0b01010101
        0x55,  // column 8, page 0: 0b01010101
        0xaa,  // column 0, page 1: 0b10101010
        0x55,  // column 1, page 1: 0b01010101
        0xaa,  // column 2, page 1: 0b10101010
        0x55,  // column 3, page 1: 0b01010101
        0xaa,  // column 4, page 1: 0b10101010
        0x55,  // column 5, page 1: 0b01010101
        0xaa,  // column 6, page 1: 0b10101010
        0x55,  // column 7, page 1: 0b01010101
        0x55   // column 8, page 1: 0b01010101
    },
// 0xb2
    {
        0x55,  // column 0, page 0: 0b01010101
        0xff,  // column 1, page 0: 0b11111111
        0xaa,  // column 2, page 0: 0b10101010
        0xff,  // column 3, page 0: 0b11111111
        0x55,  // column 4, page 0: 0b01010101
        0xff,  // column 5, page 0: 0b11111111
        0xaa,  // column 6, page 0: 0b10101010
        0xff,  // column 7, page 0: 0b11111111
        0xff,  // column 8, page 0: 0b11111111
        0x55,  // column 0, page 1: 0b01010101
        0xff,  // column 1, page 1: 0b11111111
        0xaa,  // column 2, page 1: 0b10101010
        0xff,  // column 3, page 1: 0b11111111
        0x55,  // column 4, page 1: 0b01010101
        0xff,  // column 5, page 1: 0b11111111
        0xaa,  // column 6, page 1: 0b10101010
        0xff,  // column 7, page 1: 0b11111111
        0xff   // column 8, page 1: 0b11111111
    },
// 0xb3
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0x0,   // column 2, page 0: 0b00000000
        0xff,  // column 3, page 0: 0b11111111
        0xff,  // column 4, page 0: 0b11111111
        0x0,   // column 5, page 0: 0b00000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0xff,  // column 3, page 1: 0b11111111
        0xff,  // column 4, page 1: 0b11111111
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xb4
    {
        0x80,  // column 0, page 0: 0b10000000
        0x80,  // column 1, page 0: 0b10000000
        0x80,  // column 2, page 0: 0b10000000
        0xff,  // column 3, page 0: 0b11111111
        0xff,  // column 4, page 0: 0b11111111
        0x0,   // column 5, page 0: 0b00000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0xff,  // column 3, page 1: 0b11111111
        0xff,  // column 4, page 1: 0b11111111
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xb5
    {
        0xa0,  // column 0, page 0: 0b10100000
        0xa0,  // column 1, page 0: 0b10100000
        0xa0,  // column 2, page 0: 0b10100000
        0xff,  // column 3, page 0: 0b11111111
        0xff,  // column 4, page 0: 0b11111111
        0x0,   // column 5, page 0: 0b00000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0xff,  // column 3, page 1: 0b11111111
        0xff,  // column 4, page 1: 0b11111111
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xb6
    {
        0x80,  // column 0, page 0: 0b10000000
        0x80,  // column 1, page 0: 0b10000000
        0xff,  // column 2, page 0: 0b11111111
        0xff,  // column 3, page 0: 0b11111111
        0x0,   // column 4, page 0: 0b00000000
        0xff,  // column 5, page 0: 0b11111111
        0xff,  // column 6, page 0: 0b11111111
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0xff,  // column 2, page 1: 0b11111111
        0xff,  // column 3, page 1: 0b11111111
        0x0,   // column 4, page 1: 0b00000000
        0xff,  // column 5, page 1: 0b11111111
        0xff,  // column 6, page 1: 0b11111111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xb7
    {
        0x80,  // column 0, page 0: 0b10000000
        0x80,  // column 1, page 0: 0b10000000
        0x80,  // column 2, page 0: 0b10000000
        0x80,  // column 3, page 0: 0b10000000
        0x80,  // column 4, page 0: 0b10000000
        0x80,  // column 5, page 0: 0b10000000
        0x80,  // column 6, page 0: 0b10000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0xff,  // column 2, page 1: 0b11111111
        0xff,  // column 3, page 1: 0b11111111
        0x0,   // column 4, page 1: 0b00000000
        0xff,  // column 5, page 1: 0b11111111
        0xff,  // column 6, page 1: 0b11111111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xb8
    {
        0xa0,  // column 0, page 0: 0b10100000
        0xa0,  // column 1, page 0: 0b10100000
        0xa0,  // column 2, page 0: 0b10100000
        0xe0,  // column 3, page 0: 0b11100000
        0xe0,  // column 4, page 0: 0b11100000
        0x0,   // column 5, page 0: 0b00000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0xff,  // column 3, page 1: 0b11111111
        0xff,  // column 4, page 1: 0b11111111
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xb9
    {
        0xa0,  // column 0, page 0: 0b10100000
        0xa0,  // column 1, page 0: 0b10100000
        0xbf,  // column 2, page 0: 0b10111111
        0xbf,  // column 3, page 0: 0b10111111
        0x0,   // column 4, page 0: 0b00000000
        0xff,  // column 5, page 0: 0b11111111
        0xff,  // column 6, page 0: 0b11111111
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0xff,  // column 2, page 1: 0b11111111
        0xff,  // column 3, page 1: 0b11111111
        0x0,   // column 4, page 1: 0b00000000
        0xff,  // column 5, page 1: 0b11111111
        0xff,  // column 6, page 1: 0b11111111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xba
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0xff,  // column 2, page 0: 0b11111111
        0xff,  // column 3, page 0: 0b11111111
        0x0,   // column 4, page 0: 0b00000000
        0xff,  // column 5, page 0: 0b11111111
        0xff,  // column 6, page 0: 0b11111111
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0xff,  // column 2, page 1: 0b11111111
        0xff,  // column 3, page 1: 0b11111111
        0x0,   // column 4, page 1: 0b00000000
        0xff,  // column 5, page 1: 0b11111111
        0xff,  // column 6, page 1: 0b11111111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xbb
    {
        0xa0,  // column 0, page 0: 0b10100000
        0xa0,  // column 1, page 0: 0b10100000
        0xa0,  // column 2, page 0: 0b10100000
        0xa0,  // column 3, page 0: 0b10100000
        0x20,  // column 4, page 0: 0b00100000
        0xe0,  // column 5, page 0: 0b11100000
        0xe0,  // column 6, page 0: 0b11100000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0xff,  // column 2, page 1: 0b11111111
        0xff,  // column 3, page 1: 0b11111111
        0x0,   // column 4, page 1: 0b00000000
        0xff,  // column 5, page 1: 0b11111111
        0xff,  // column 6, page 1: 0b11111111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xbc
    {
        0xa0,  // column 0, page 0: 0b10100000
        0xa0,  // column 1, page 0: 0b10100000
        0xbf,  // column 2, page 0: 0b10111111
        0xbf,  // column 3, page 0: 0b10111111
        0x80,  // column 4, page 0: 0b10000000
        0xff,  // column 5, page 0: 0b11111111
        0xff,  // column 6, page 0: 0b11111111
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xbd
    {
        0x80,  // column 0, page 0: 0b10000000
        0x80,  // column 1, page 0: 0b10000000
        0xff,  // column 2, page 0: 0b11111111
        0xff,  // column 3, page 0: 0b11111111
        0x80,  // column 4, page 0: 0b10000000
        0xff,  // column 5, page 0: 0b11111111
        0xff,  // column 6, page 0: 0b11111111
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xbe
    {
        0xa0,  // column 0, page 0: 0b10100000
        0xa0,  // column 1, page 0: 0b10100000
        0xa0,  // column 2, page 0: 0b10100000
        0xff,  // column 3, page 0: 0b11111111
        0xff,  // column 4, page 0: 0b11111111
        0x0,   // column 5, page 0: 0b00000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xbf
    {
        0x80,  // column 0, page 0: 0b10000000
        0x80,  // column 1, page 0: 0b10000000
        0x80,  // column 2, page 0: 0b10000000
        0x80,  // column 3, page 0: 0b10000000
        0x80,  // column 4, page 0: 0b10000000
        0x0,   // column 5, page 0: 0b00000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0xff,  // column 3, page 1: 0b11111111
        0xff,  // column 4, page 1: 0b11111111
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xc0
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0x0,   // column 2, page 0: 0b00000000
        0xff,  // column 3, page 0: 0b11111111
        0xff,  // column 4, page 0: 0b11111111
        0x80,  // column 5, page 0: 0b10000000
        0x80,  // column 6, page 0: 0b10000000
        0x80,  // column 7, page 0: 0b10000000
        0x80,  // column 8, page 0: 0b10000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xc1
    {
        0x80,  // column 0, page 0: 0b10000000
        0x80,  // column 1, page 0: 0b10000000
        0x80,  // column 2, page 0: 0b10000000
        0xff,  // column 3, page 0: 0b11111111
        0xff,  // column 4, page 0: 0b11111111
        0x80,  // column 5, page 0: 0b10000000
        0x80,  // column 6, page 0: 0b10000000
        0x80,  // column 7, page 0: 0b10000000
        0x80,  // column 8, page 0: 0b10000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xc2
    {
        0x80,  // column 0, page 0: 0b10000000
        0x80,  // column 1, page 0: 0b10000000
        0x80,  // column 2, page 0: 0b10000000
        0x80,  // column 3, page 0: 0b10000000
        0x80,  // column 4, page 0: 0b10000000
        0x80,  // column 5, page 0: 0b10000000
        0x80,  // column 6, page 0: 0b10000000
        0x80,  // column 7, page 0: 0b10000000
        0x80,  // column 8, page 0: 0b10000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0xff,  // column 3, page 1: 0b11111111
        0xff,  // column 4, page 1: 0b11111111
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xc3
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0x0,   // column 2, page 0: 0b00000000
        0xff,  // column 3, page 0: 0b11111111
        0xff,  // column 4, page 0: 0b11111111
        0x80,  // column 5, page 0: 0b10000000
        0x80,  // column 6, page 0: 0b10000000
        0x80,  // column 7, page 0: 0b10000000
        0x80,  // column 8, page 0: 0b10000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0xff,  // column 3, page 1: 0b11111111
        0xff,  // column 4, page 1: 0b11111111
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xc4
    {
        0x80,  // column 0, page 0: 0b10000000
        0x80,  // column 1, page 0: 0b10000000
        0x80,  // column 2, page 0: 0b10000000
        0x80,  // column 3, page 0: 0b10000000
        0x80,  // column 4, page 0: 0b10000000
        0x80,  // column 5, page 0: 0b10000000
        0x80,  // column 6, page 0: 0b10000000
        0x80,  // column 7, page 0: 0b10000000
        0x80,  // column 8, page 0: 0b10000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xc5
    {
        0x80,  // column 0, page 0: 0b10000000
        0x80,  // column 1, page 0: 0b10000000
        0x80,  // column 2, page 0: 0b10000000
        0xff,  // column 3, page 0: 0b11111111
        0xff,  // column 4, page 0: 0b11111111
        0x80,  // column 5, page 0: 0b10000000
        0x80,  // column 6, page 0: 0b10000000
        0x80,  // column 7, page 0: 0b10000000
        0x80,  // column 8, page 0: 0b10000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0xff,  // column 3, page 1: 0b11111111
        0xff,  // column 4, page 1: 0b11111111
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xc6
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0x0,   // column 2, page 0: 0b00000000
        0xff,  // column 3, page 0: 0b11111111
        0xff,  // column 4, page 0: 0b11111111
        0xa0,  // column 5, page 0: 0b10100000
        0xa0,  // column 6, page 0: 0b10100000
        0xa0,  // column 7, page 0: 0b10100000
        0xa0,  // column 8, page 0: 0b10100000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0xff,  // column 3, page 1: 0b11111111
        0xff,  // column 4, page 1: 0b11111111
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xc7
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0xff,  // column 2, page 0: 0b11111111
        0xff,  // column 3, page 0: 0b11111111
        0x0,   // column 4, page 0: 0b00000000
        0xff,  // column 5, page 0: 0b11111111
        0xff,  // column 6, page 0: 0b11111111
        0x80,  // column 7, page 0: 0b10000000
        0x80,  // column 8, page 0: 0b10000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0xff,  // column 2, page 1: 0b11111111
        0xff,  // column 3, page 1: 0b11111111
        0x0,   // column 4, page 1: 0b00000000
        0xff,  // column 5, page 1: 0b11111111
        0xff,  // column 6, page 1: 0b11111111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xc8
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0xff,  // column 2, page 0: 0b11111111
        0xff,  // column 3, page 0: 0b11111111
        0x80,  // column 4, page 0: 0b10000000
        0xbf,  // column 5, page 0: 0b10111111
        0xbf,  // column 6, page 0: 0b10111111
        0xa0,  // column 7, page 0: 0b10100000
        0xa0,  // column 8, page 0: 0b10100000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xc9
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0xe0,  // column 2, page 0: 0b11100000
        0xe0,  // column 3, page 0: 0b11100000
        0x20,  // column 4, page 0: 0b00100000
        0xa0,  // column 5, page 0: 0b10100000
        0xa0,  // column 6, page 0: 0b10100000
        0xa0,  // column 7, page 0: 0b10100000
        0xa0,  // column 8, page 0: 0b10100000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0xff,  // column 2, page 1: 0b11111111
        0xff,  // column 3, page 1: 0b11111111
        0x0,   // column 4, page 1: 0b00000000
        0xff,  // column 5, page 1: 0b11111111
        0xff,  // column 6, page 1: 0b11111111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xca
    {
        0xa0,  // column 0, page 0: 0b10100000
        0xa0,  // column 1, page 0: 0b10100000
        0xbf,  // column 2, page 0: 0b10111111
        0xbf,  // column 3, page 0: 0b10111111
        0x80,  // column 4, page 0: 0b10000000
        0xbf,  // column 5, page 0: 0b10111111
        0xbf,  // column 6, page 0: 0b10111111
        0xa0,  // column 7, page 0: 0b10100000
        0xa0,  // column 8, page 0: 0b10100000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xcb
    {
        0xa0,  // column 0, page 0: 0b10100000
        0xa0,  // column 1, page 0: 0b10100000
        0xa0,  // column 2, page 0: 0b10100000
        0xa0,  // column 3, page 0: 0b10100000
        0x20,  // column 4, page 0: 0b00100000
        0xa0,  // column 5, page 0: 0b10100000
        0xa0,  // column 6, page 0: 0b10100000
        0xa0,  // column 7, page 0: 0b10100000
        0xa0,  // column 8, page 0: 0b10100000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0xff,  // column 2, page 1: 0b11111111
        0xff,  // column 3, page 1: 0b11111111
        0x0,   // column 4, page 1: 0b00000000
        0xff,  // column 5, page 1: 0b11111111
        0xff,  // column 6, page 1: 0b11111111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xcc
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0xff,  // column 2, page 0: 0b11111111
        0xff,  // column 3, page 0: 0b11111111
        0x0,   // column 4, page 0: 0b00000000
        0xbf,  // column 5, page 0: 0b10111111
        0xbf,  // column 6, page 0: 0b10111111
        0xa0,  // column 7, page 0: 0b10100000
        0xa0,  // column 8, page 0: 0b10100000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0xff,  // column 2, page 1: 0b11111111
        0xff,  // column 3, page 1: 0b11111111
        0x0,   // column 4, page 1: 0b00000000
        0xff,  // column 5, page 1: 0b11111111
        0xff,  // column 6, page 1: 0b11111111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xcd
    {
        0xa0,  // column 0, page 0: 0b10100000
        0xa0,  // column 1, page 0: 0b10100000
        0xa0,  // column 2, page 0: 0b10100000
        0xa0,  // column 3, page 0: 0b10100000
        0xa0,  // column 4, page 0: 0b10100000
        0xa0,  // column 5, page 0: 0b10100000
        0xa0,  // column 6, page 0: 0b10100000
        0xa0,  // column 7, page 0: 0b10100000
        0xa0,  // column 8, page 0: 0b10100000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xce
    {
        0xa0,  // column 0, page 0: 0b10100000
        0xa0,  // column 1, page 0: 0b10100000
        0xbf,  // column 2, page 0: 0b10111111
        0xbf,  // column 3, page 0: 0b10111111
        0x0,   // column 4, page 0: 0b00000000
        0xbf,  // column 5, page 0: 0b10111111
        0xbf,  // column 6, page 0: 0b10111111
        0xa0,  // column 7, page 0: 0b10100000
        0xa0,  // column 8, page 0: 0b10100000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0xff,  // column 2, page 1: 0b11111111
        0xff,  // column 3, page 1: 0b11111111
        0x0,   // column 4, page 1: 0b00000000
        0xff,  // column 5, page 1: 0b11111111
        0xff,  // column 6, page 1: 0b11111111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xcf
    {
        0xa0,  // column 0, page 0: 0b10100000
        0xa0,  // column 1, page 0: 0b10100000
        0xa0,  // column 2, page 0: 0b10100000
        0xbf,  // column 3, page 0: 0b10111111
        0xbf,  // column 4, page 0: 0b10111111
        0xa0,  // column 5, page 0: 0b10100000
        0xa0,  // column 6, page 0: 0b10100000
        0xa0,  // column 7, page 0: 0b10100000
        0xa0,  // column 8, page 0: 0b10100000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xd0
    {
        0x80,  // column 0, page 0: 0b10000000
        0x80,  // column 1, page 0: 0b10000000
        0xff,  // column 2, page 0: 0b11111111
        0xff,  // column 3, page 0: 0b11111111
        0x80,  // column 4, page 0: 0b10000000
        0xff,  // column 5, page 0: 0b11111111
        0xff,  // column 6, page 0: 0b11111111
        0x80,  // column 7, page 0: 0b10000000
        0x80,  // column 8, page 0: 0b10000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xd1
    {
        0xa0,  // column 0, page 0: 0b10100000
        0xa0,  // column 1, page 0: 0b10100000
        0xa0,  // column 2, page 0: 0b10100000
        0xa0,  // column 3, page 0: 0b10100000
        0xa0,  // column 4, page 0: 0b10100000
        0xa0,  // column 5, page 0: 0b10100000
        0xa0,  // column 6, page 0: 0b10100000
        0xa0,  // column 7, page 0: 0b10100000
        0xa0,  // column 8, page 0: 0b10100000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0xff,  // column 3, page 1: 0b11111111
        0xff,  // column 4, page 1: 0b11111111
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xd2
    {
        0x80,  // column 0, page 0: 0b10000000
        0x80,  // column 1, page 0: 0b10000000
        0x80,  // column 2, page 0: 0b10000000
        0x80,  // column 3, page 0: 0b10000000
        0x80,  // column 4, page 0: 0b10000000
        0x80,  // column 5, page 0: 0b10000000
        0x80,  // column 6, page 0: 0b10000000
        0x80,  // column 7, page 0: 0b10000000
        0x80,  // column 8, page 0: 0b10000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0xff,  // column 2, page 1: 0b11111111
        0xff,  // column 3, page 1: 0b11111111
        0x0,   // column 4, page 1: 0b00000000
        0xff,  // column 5, page 1: 0b11111111
        0xff,  // column 6, page 1: 0b11111111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xd3
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0xff,  // column 2, page 0: 0b11111111
        0xff,  // column 3, page 0: 0b11111111
        0x80,  // column 4, page 0: 0b10000000
        0xff,  // column 5, page 0: 0b11111111
        0xff,  // column 6, page 0: 0b11111111
        0x80,  // column 7, page 0: 0b10000000
        0x80,  // column 8, page 0: 0b10000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xd4
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0x0,   // column 2, page 0: 0b00000000
        0xff,  // column 3, page 0: 0b11111111
        0xff,  // column 4, page 0: 0b11111111
        0xa0,  // column 5, page 0: 0b10100000
        0xa0,  // column 6, page 0: 0b10100000
        0xa0,  // column 7, page 0: 0b10100000
        0xa0,  // column 8, page 0: 0b10100000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xd5
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0x0,   // column 2, page 0: 0b00000000
        0xe0,  // column 3, page 0: 0b11100000
        0xe0,  // column 4, page 0: 0b11100000
        0xa0,  // column 5, page 0: 0b10100000
        0xa0,  // column 6, page 0: 0b10100000
        0xa0,  // column 7, page 0: 0b10100000
        0xa0,  // column 8, page 0: 0b10100000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0xff,  // column 3, page 1: 0b11111111
        0xff,  // column 4, page 1: 0b11111111
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xd6
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0x80,  // column 2, page 0: 0b10000000
        0x80,  // column 3, page 0: 0b10000000
        0x80,  // column 4, page 0: 0b10000000
        0x80,  // column 5, page 0: 0b10000000
        0x80,  // column 6, page 0: 0b10000000
        0x80,  // column 7, page 0: 0b10000000
        0x80,  // column 8, page 0: 0b10000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0xff,  // column 2, page 1: 0b11111111
        0xff,  // column 3, page 1: 0b11111111
        0x0,   // column 4, page 1: 0b00000000
        0xff,  // column 5, page 1: 0b11111111
        0xff,  // column 6, page 1: 0b11111111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xd7
    {
        0x80,  // column 0, page 0: 0b10000000
        0x80,  // column 1, page 0: 0b10000000
        0xff,  // column 2, page 0: 0b11111111
        0xff,  // column 3, page 0: 0b11111111
        0x80,  // column 4, page 0: 0b10000000
        0xff,  // column 5, page 0: 0b11111111
        0xff,  // column 6, page 0: 0b11111111
        0x80,  // column 7, page 0: 0b10000000
        0x80,  // column 8, page 0: 0b10000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0xff,  // column 2, page 1: 0b11111111
        0xff,  // column 3, page 1: 0b11111111
        0x0,   // column 4, page 1: 0b00000000
        0xff,  // column 5, page 1: 0b11111111
        0xff,  // column 6, page 1: 0b11111111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xd8
    {
        0xa0,  // column 0, page 0: 0b10100000
        0xa0,  // column 1, page 0: 0b10100000
        0xa0,  // column 2, page 0: 0b10100000
        0xff,  // column 3, page 0: 0b11111111
        0xff,  // column 4, page 0: 0b11111111
        0xa0,  // column 5, page 0: 0b10100000
        0xa0,  // column 6, page 0: 0b10100000
        0xa0,  // column 7, page 0: 0b10100000
        0xa0,  // column 8, page 0: 0b10100000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0xff,  // column 3, page 1: 0b11111111
        0xff,  // column 4, page 1: 0b11111111
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xd9
    {
        0x80,  // column 0, page 0: 0b10000000
        0x80,  // column 1, page 0: 0b10000000
        0x80,  // column 2, page 0: 0b10000000
        0xff,  // column 3, page 0: 0b11111111
        0xff,  // column 4, page 0: 0b11111111
        0x0,   // column 5, page 0: 0b00000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xda
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0x0,   // column 2, page 0: 0b00000000
        0x80,  // column 3, page 0: 0b10000000
        0x80,  // column 4, page 0: 0b10000000
        0x80,  // column 5, page 0: 0b10000000
        0x80,  // column 6, page 0: 0b10000000
        0x80,  // column 7, page 0: 0b10000000
        0x80,  // column 8, page 0: 0b10000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0xff,  // column 3, page 1: 0b11111111
        0xff,  // column 4, page 1: 0b11111111
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xdb
    {
        0xff,  // column 0, page 0: 0b11111111
        0xff,  // column 1, page 0: 0b11111111
        0xff,  // column 2, page 0: 0b11111111
        0xff,  // column 3, page 0: 0b11111111
        0xff,  // column 4, page 0: 0b11111111
        0xff,  // column 5, page 0: 0b11111111
        0xff,  // column 6, page 0: 0b11111111
        0xff,  // column 7, page 0: 0b11111111
        0xff,  // column 8, page 0: 0b11111111
        0xff,  // column 0, page 1: 0b11111111
        0xff,  // column 1, page 1: 0b11111111
        0xff,  // column 2, page 1: 0b11111111
        0xff,  // column 3, page 1: 0b11111111
        0xff,  // column 4, page 1: 0b11111111
        0xff,  // column 5, page 1: 0b11111111
        0xff,  // column 6, page 1: 0b11111111
        0xff,  // column 7, page 1: 0b11111111
        0xff   // column 8, page 1: 0b11111111
    },
// 0xdc
    {
        0x80,  // column 0, page 0: 0b10000000
        0x80,  // column 1, page 0: 0b10000000
        0x80,  // column 2, page 0: 0b10000000
        0x80,  // column 3, page 0: 0b10000000
        0x80,  // column 4, page 0: 0b10000000
        0x80,  // column 5, page 0: 0b10000000
        0x80,  // column 6, page 0: 0b10000000
        0x80,  // column 7, page 0: 0b10000000
        0x80,  // column 8, page 0: 0b10000000
        0xff,  // column 0, page 1: 0b11111111
        0xff,  // column 1, page 1: 0b11111111
        0xff,  // column 2, page 1: 0b11111111
        0xff,  // column 3, page 1: 0b11111111
        0xff,  // column 4, page 1: 0b11111111
        0xff,  // column 5, page 1: 0b11111111
        0xff,  // column 6, page 1: 0b11111111
        0xff,  // column 7, page 1: 0b11111111
        0xff   // column 8, page 1: 0b11111111
    },
// 0xdd
    {
        0xff,  // column 0, page 0: 0b11111111
        0xff,  // column 1, page 0: 0b11111111
        0xff,  // column 2, page 0: 0b11111111
        0xff,  // column 3, page 0: 0b11111111
        0x0,   // column 4, page 0: 0b00000000
        0x0,   // column 5, page 0: 0b00000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0xff,  // column 0, page 1: 0b11111111
        0xff,  // column 1, page 1: 0b11111111
        0xff,  // column 2, page 1: 0b11111111
        0xff,  // column 3, page 1: 0b11111111
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xde
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0x0,   // column 2, page 0: 0b00000000
        0x0,   // column 3, page 0: 0b00000000
        0xff,  // column 4, page 0: 0b11111111
        0xff,  // column 5, page 0: 0b11111111
        0xff,  // column 6, page 0: 0b11111111
        0xff,  // column 7, page 0: 0b11111111
        0xff,  // column 8, page 0: 0b11111111
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0xff,  // column 4, page 1: 0b11111111
        0xff,  // column 5, page 1: 0b11111111
        0xff,  // column 6, page 1: 0b11111111
        0xff,  // column 7, page 1: 0b11111111
        0xff   // column 8, page 1: 0b11111111
    },
// 0xdf
    {
        0x7f,  // column 0, page 0: 0b01111111
        0x7f,  // column 1, page 0: 0b01111111
        0x7f,  // column 2, page 0: 0b01111111
        0x7f,  // column 3, page 0: 0b01111111
        0x7f,  // column 4, page 0: 0b01111111
        0x7f,  // column 5, page 0: 0b01111111
        0x7f,  // column 6, page 0: 0b01111111
        0x7f,  // column 7, page 0: 0b01111111
        0x7f,  // column 8, page 0: 0b01111111
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xe0
    {
        0xc0,  // column 0, page 0: 0b11000000
        0xe0,  // column 1, page 0: 0b11100000
        0x20,  // column 2, page 0: 0b00100000
        0xe0,  // column 3, page 0: 0b11100000
        0xc0,  // column 4, page 0: 0b11000000
        0x60,  // column 5, page 0: 0b01100000
        0x20,  // column 6, page 0: 0b00100000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0xf,   // column 3, page 1: 0b00001111
        0x7,   // column 4, page 1: 0b00000111
        0xc,   // column 5, page 1: 0b00001100
        0x8,   // column 6, page 1: 0b00001000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xe1
    {
        0xf8,  // column 0, page 0: 0b11111000
        0xfc,  // column 1, page 0: 0b11111100
        0x4,   // column 2, page 0: 0b00000100
        0x44,  // column 3, page 0: 0b01000100
        0xfc,  // column 4, page 0: 0b11111100
        0xb8,  // column 5, page 0: 0b10111000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0xf,   // column 0, page 1: 0b00001111
        0xf,   // column 1, page 1: 0b00001111
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x8,   // column 4, page 1: 0b00001000
        0xf,   // column 5, page 1: 0b00001111
        0x7,   // column 6, page 1: 0b00000111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xe2
    {
        0xfc,  // column 0, page 0: 0b11111100
        0xfc,  // column 1, page 0: 0b11111100
        0x4,   // column 2, page 0: 0b00000100
        0x4,   // column 3, page 0: 0b00000100
        0x4,   // column 4, page 0: 0b00000100
        0x1c,  // column 5, page 0: 0b00011100
        0x1c,  // column 6, page 0: 0b00011100
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0xf,   // column 0, page 1: 0b00001111
        0xf,   // column 1, page 1: 0b00001111
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xe3
    {
        0x10,  // column 0, page 0: 0b00010000
        0xf0,  // column 1, page 0: 0b11110000
        0xf0,  // column 2, page 0: 0b11110000
        0x10,  // column 3, page 0: 0b00010000
        0xf0,  // column 4, page 0: 0b11110000
        0xf0,  // column 5, page 0: 0b11110000
        0x10,  // column 6, page 0: 0b00010000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0xf,   // column 1, page 1: 0b00001111
        0xf,   // column 2, page 1: 0b00001111
        0x0,   // column 3, page 1: 0b00000000
        0xf,   // column 4, page 1: 0b00001111
        0xf,   // column 5, page 1: 0b00001111
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xe4
    {
        0x18,  // column 0, page 0: 0b00011000
        0x38,  // column 1, page 0: 0b00111000
        0x68,  // column 2, page 0: 0b01101000
        0xc8,  // column 3, page 0: 0b11001000
        0x88,  // column 4, page 0: 0b10001000
        0x18,  // column 5, page 0: 0b00011000
        0x18,  // column 6, page 0: 0b00011000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0xc,   // column 0, page 1: 0b00001100
        0xe,   // column 1, page 1: 0b00001110
        0xb,   // column 2, page 1: 0b00001011
        0x9,   // column 3, page 1: 0b00001001
        0x8,   // column 4, page 1: 0b00001000
        0xc,   // column 5, page 1: 0b00001100
        0xc,   // column 6, page 1: 0b00001100
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xe5
    {
        0xc0,  // column 0, page 0: 0b11000000
        0xe0,  // column 1, page 0: 0b11100000
        0x20,  // column 2, page 0: 0b00100000
        0xe0,  // column 3, page 0: 0b11100000
        0xe0,  // column 4, page 0: 0b11100000
        0x20,  // column 5, page 0: 0b00100000
        0x20,  // column 6, page 0: 0b00100000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0xf,   // column 3, page 1: 0b00001111
        0x7,   // column 4, page 1: 0b00000111
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xe6
    {
        0x0,   // column 0, page 0: 0b00000000
        0xf0,  // column 1, page 0: 0b11110000
        0xf0,  // column 2, page 0: 0b11110000
        0x0,   // column 3, page 0: 0b00000000
        0x0,   // column 4, page 0: 0b00000000
        0xf0,  // column 5, page 0: 0b11110000
        0xf0,  // column 6, page 0: 0b11110000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x10,  // column 0, page 1: 0b00010000
        0x1f,  // column 1, page 1: 0b00011111
        0xf,   // column 2, page 1: 0b00001111
        0x2,   // column 3, page 1: 0b00000010
        0x2,   // column 4, page 1: 0b00000010
        0x3,   // column 5, page 1: 0b00000011
        0x1,   // column 6, page 1: 0b00000001
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xe7
    {
        0x20,  // column 0, page 0: 0b00100000
        0x30,  // column 1, page 0: 0b00110000
        0x10,  // column 2, page 0: 0b00010000
        0xf0,  // column 3, page 0: 0b11110000
        0xe0,  // column 4, page 0: 0b11100000
        0x30,  // column 5, page 0: 0b00110000
        0x10,  // column 6, page 0: 0b00010000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0xf,   // column 3, page 1: 0b00001111
        0xf,   // column 4, page 1: 0b00001111
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xe8
    {
        0x0,   // column 0, page 0: 0b00000000
        0xc8,  // column 1, page 0: 0b11001000
        0xe8,  // column 2, page 0: 0b11101000
        0x38,  // column 3, page 0: 0b00111000
        0x38,  // column 4, page 0: 0b00111000
        0xe8,  // column 5, page 0: 0b11101000
        0xc8,  // column 6, page 0: 0b11001000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x9,   // column 1, page 1: 0b00001001
        0xb,   // column 2, page 1: 0b00001011
        0xe,   // column 3, page 1: 0b00001110
        0xe,   // column 4, page 1: 0b00001110
        0xb,   // column 5, page 1: 0b00001011
        0x9,   // column 6, page 1: 0b00001001
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xe9
    {
        0xe0,  // column 0, page 0: 0b11100000
        0xf0,  // column 1, page 0: 0b11110000
        0x98,  // column 2, page 0: 0b10011000
        0x88,  // column 3, page 0: 0b10001000
        0x98,  // column 4, page 0: 0b10011000
        0xf0,  // column 5, page 0: 0b11110000
        0xe0,  // column 6, page 0: 0b11100000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x3,   // column 0, page 1: 0b00000011
        0x7,   // column 1, page 1: 0b00000111
        0xc,   // column 2, page 1: 0b00001100
        0x8,   // column 3, page 1: 0b00001000
        0xc,   // column 4, page 1: 0b00001100
        0x7,   // column 5, page 1: 0b00000111
        0x3,   // column 6, page 1: 0b00000011
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xea
    {
        0x70,  // column 0, page 0: 0b01110000
        0xf8,  // column 1, page 0: 0b11111000
        0x8c,  // column 2, page 0: 0b10001100
        0x4,   // column 3, page 0: 0b00000100
        0x8c,  // column 4, page 0: 0b10001100
        0xf8,  // column 5, page 0: 0b11111000
        0x70,  // column 6, page 0: 0b01110000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x8,   // column 0, page 1: 0b00001000
        0xf,   // column 1, page 1: 0b00001111
        0xf,   // column 2, page 1: 0b00001111
        0x0,   // column 3, page 1: 0b00000000
        0xf,   // column 4, page 1: 0b00001111
        0xf,   // column 5, page 1: 0b00001111
        0x8,   // column 6, page 1: 0b00001000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xeb
    {
        0x0,   // column 0, page 0: 0b00000000
        0x80,  // column 1, page 0: 0b10000000
        0xc8,  // column 2, page 0: 0b11001000
        0x5c,  // column 3, page 0: 0b01011100
        0x74,  // column 4, page 0: 0b01110100
        0xe4,  // column 5, page 0: 0b11100100
        0xc4,  // column 6, page 0: 0b11000100
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x7,   // column 1, page 1: 0b00000111
        0xf,   // column 2, page 1: 0b00001111
        0x8,   // column 3, page 1: 0b00001000
        0x8,   // column 4, page 1: 0b00001000
        0xf,   // column 5, page 1: 0b00001111
        0x7,   // column 6, page 1: 0b00000111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xec
    {
        0xc0,  // column 0, page 0: 0b11000000
        0xe0,  // column 1, page 0: 0b11100000
        0x20,  // column 2, page 0: 0b00100000
        0xe0,  // column 3, page 0: 0b11100000
        0xe0,  // column 4, page 0: 0b11100000
        0x20,  // column 5, page 0: 0b00100000
        0xe0,  // column 6, page 0: 0b11100000
        0xc0,  // column 7, page 0: 0b11000000
        0x0,   // column 8, page 0: 0b00000000
        0x1,   // column 0, page 1: 0b00000001
        0x3,   // column 1, page 1: 0b00000011
        0x2,   // column 2, page 1: 0b00000010
        0x3,   // column 3, page 1: 0b00000011
        0x3,   // column 4, page 1: 0b00000011
        0x2,   // column 5, page 1: 0b00000010
        0x3,   // column 6, page 1: 0b00000011
        0x1,   // column 7, page 1: 0b00000001
        0x0    // column 8, page 1: 0b00000000
    },
// 0xed
    {
        0xc0,  // column 0, page 0: 0b11000000
        0xe0,  // column 1, page 0: 0b11100000
        0x20,  // column 2, page 0: 0b00100000
        0xe0,  // column 3, page 0: 0b11100000
        0xe0,  // column 4, page 0: 0b11100000
        0x30,  // column 5, page 0: 0b00110000
        0xf8,  // column 6, page 0: 0b11111000
        0xc8,  // column 7, page 0: 0b11001000
        0x0,   // column 8, page 0: 0b00000000
        0x9,   // column 0, page 1: 0b00001001
        0xf,   // column 1, page 1: 0b00001111
        0x7,   // column 2, page 1: 0b00000111
        0x3,   // column 3, page 1: 0b00000011
        0x2,   // column 4, page 1: 0b00000010
        0x2,   // column 5, page 1: 0b00000010
        0x3,   // column 6, page 1: 0b00000011
        0x1,   // column 7, page 1: 0b00000001
        0x0    // column 8, page 1: 0b00000000
    },
// 0xee
    {
        0x0,   // column 0, page 0: 0b00000000
        0xf0,  // column 1, page 0: 0b11110000
        0xf8,  // column 2, page 0: 0b11111000
        0x4c,  // column 3, page 0: 0b01001100
        0x44,  // column 4, page 0: 0b01000100
        0x44,  // column 5, page 0: 0b01000100
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x3,   // column 1, page 1: 0b00000011
        0x7,   // column 2, page 1: 0b00000111
        0xc,   // column 3, page 1: 0b00001100
        0x8,   // column 4, page 1: 0b00001000
        0x8,   // column 5, page 1: 0b00001000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xef
    {
        0xf0,  // column 0, page 0: 0b11110000
        0xf8,  // column 1, page 0: 0b11111000
        0x8,   // column 2, page 0: 0b00001000
        0x8,   // column 3, page 0: 0b00001000
        0x8,   // column 4, page 0: 0b00001000
        0xf8,  // column 5, page 0: 0b11111000
        0xf0,  // column 6, page 0: 0b11110000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0xf,   // column 0, page 1: 0b00001111
        0xf,   // column 1, page 1: 0b00001111
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0xf,   // column 5, page 1: 0b00001111
        0xf,   // column 6, page 1: 0b00001111
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xf0
    {
        0x90,  // column 0, page 0: 0b10010000
        0x90,  // column 1, page 0: 0b10010000
        0x90,  // column 2, page 0: 0b10010000
        0x90,  // column 3, page 0: 0b10010000
        0x90,  // column 4, page 0: 0b10010000
        0x90,  // column 5, page 0: 0b10010000
        0x90,  // column 6, page 0: 0b10010000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x4,   // column 0, page 1: 0b00000100
        0x4,   // column 1, page 1: 0b00000100
        0x4,   // column 2, page 1: 0b00000100
        0x4,   // column 3, page 1: 0b00000100
        0x4,   // column 4, page 1: 0b00000100
        0x4,   // column 5, page 1: 0b00000100
        0x4,   // column 6, page 1: 0b00000100
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xf1
    {
        0x0,   // column 0, page 0: 0b00000000
        0x40,  // column 1, page 0: 0b01000000
        0x40,  // column 2, page 0: 0b01000000
        0xf0,  // column 3, page 0: 0b11110000
        0xf0,  // column 4, page 0: 0b11110000
        0x40,  // column 5, page 0: 0b01000000
        0x40,  // column 6, page 0: 0b01000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x8,   // column 0, page 1: 0b00001000
        0x8,   // column 1, page 1: 0b00001000
        0x8,   // column 2, page 1: 0b00001000
        0x9,   // column 3, page 1: 0b00001001
        0x9,   // column 4, page 1: 0b00001001
        0x8,   // column 5, page 1: 0b00001000
        0x8,   // column 6, page 1: 0b00001000
        0x8,   // column 7, page 1: 0b00001000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xf2
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0x8,   // column 2, page 0: 0b00001000
        0x18,  // column 3, page 0: 0b00011000
        0xb0,  // column 4, page 0: 0b10110000
        0xe0,  // column 5, page 0: 0b11100000
        0x40,  // column 6, page 0: 0b01000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x8,   // column 1, page 1: 0b00001000
        0xa,   // column 2, page 1: 0b00001010
        0xb,   // column 3, page 1: 0b00001011
        0x9,   // column 4, page 1: 0b00001001
        0x8,   // column 5, page 1: 0b00001000
        0x8,   // column 6, page 1: 0b00001000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xf3
    {
        0x0,   // column 0, page 0: 0b00000000
        0x40,  // column 1, page 0: 0b01000000
        0xe0,  // column 2, page 0: 0b11100000
        0xb0,  // column 3, page 0: 0b10110000
        0x18,  // column 4, page 0: 0b00011000
        0x8,   // column 5, page 0: 0b00001000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x8,   // column 1, page 1: 0b00001000
        0x8,   // column 2, page 1: 0b00001000
        0x9,   // column 3, page 1: 0b00001001
        0xb,   // column 4, page 1: 0b00001011
        0xa,   // column 5, page 1: 0b00001010
        0x8,   // column 6, page 1: 0b00001000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xf4
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0x0,   // column 2, page 0: 0b00000000
        0xf8,  // column 3, page 0: 0b11111000
        0xfc,  // column 4, page 0: 0b11111100
        0x4,   // column 5, page 0: 0b00000100
        0x1c,  // column 6, page 0: 0b00011100
        0x18,  // column 7, page 0: 0b00011000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0xff,  // column 3, page 1: 0b11111111
        0xff,  // column 4, page 1: 0b11111111
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xf5
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0x0,   // column 2, page 0: 0b00000000
        0xff,  // column 3, page 0: 0b11111111
        0xff,  // column 4, page 0: 0b11111111
        0x0,   // column 5, page 0: 0b00000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x7,   // column 0, page 1: 0b00000111
        0xf,   // column 1, page 1: 0b00001111
        0x8,   // column 2, page 1: 0b00001000
        0xf,   // column 3, page 1: 0b00001111
        0x7,   // column 4, page 1: 0b00000111
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xf6
    {
        0x0,   // column 0, page 0: 0b00000000
        0x80,  // column 1, page 0: 0b10000000
        0x80,  // column 2, page 0: 0b10000000
        0xb0,  // column 3, page 0: 0b10110000
        0xb0,  // column 4, page 0: 0b10110000
        0x80,  // column 5, page 0: 0b10000000
        0x80,  // column 6, page 0: 0b10000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x6,   // column 3, page 1: 0b00000110
        0x6,   // column 4, page 1: 0b00000110
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xf7
    {
        0x40,  // column 0, page 0: 0b01000000
        0x60,  // column 1, page 0: 0b01100000
        0x20,  // column 2, page 0: 0b00100000
        0x60,  // column 3, page 0: 0b01100000
        0x40,  // column 4, page 0: 0b01000000
        0x60,  // column 5, page 0: 0b01100000
        0x20,  // column 6, page 0: 0b00100000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x2,   // column 0, page 1: 0b00000010
        0x3,   // column 1, page 1: 0b00000011
        0x1,   // column 2, page 1: 0b00000001
        0x3,   // column 3, page 1: 0b00000011
        0x2,   // column 4, page 1: 0b00000010
        0x3,   // column 5, page 1: 0b00000011
        0x1,   // column 6, page 1: 0b00000001
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xf8
    {
        0x0,   // column 0, page 0: 0b00000000
        0xc,   // column 1, page 0: 0b00001100
        0x1e,  // column 2, page 0: 0b00011110
        0x12,  // column 3, page 0: 0b00010010
        0x1e,  // column 4, page 0: 0b00011110
        0xc,   // column 5, page 0: 0b00001100
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xf9
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0x0,   // column 2, page 0: 0b00000000
        0x80,  // column 3, page 0: 0b10000000
        0x80,  // column 4, page 0: 0b10000000
        0x0,   // column 5, page 0: 0b00000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x1,   // column 3, page 1: 0b00000001
        0x1,   // column 4, page 1: 0b00000001
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xfa
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0x0,   // column 2, page 0: 0b00000000
        0x0,   // column 3, page 0: 0b00000000
        0x0,   // column 4, page 0: 0b00000000
        0x0,   // column 5, page 0: 0b00000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x1,   // column 3, page 1: 0b00000001
        0x1,   // column 4, page 1: 0b00000001
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xfb
    {
        0x80,  // column 0, page 0: 0b10000000
        0x80,  // column 1, page 0: 0b10000000
        0x80,  // column 2, page 0: 0b10000000
        0x0,   // column 3, page 0: 0b00000000
        0xfe,  // column 4, page 0: 0b11111110
        0xfe,  // column 5, page 0: 0b11111110
        0x2,   // column 6, page 0: 0b00000010
        0x2,   // column 7, page 0: 0b00000010
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x3,   // column 1, page 1: 0b00000011
        0x7,   // column 2, page 1: 0b00000111
        0xc,   // column 3, page 1: 0b00001100
        0xf,   // column 4, page 1: 0b00001111
        0xf,   // column 5, page 1: 0b00001111
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xfc
    {
        0x2,   // column 0, page 0: 0b00000010
        0x7e,  // column 1, page 0: 0b01111110
        0x7c,  // column 2, page 0: 0b01111100
        0x2,   // column 3, page 0: 0b00000010
        0x7e,  // column 4, page 0: 0b01111110
        0x7c,  // column 5, page 0: 0b01111100
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xfd
    {
        0x64,  // column 0, page 0: 0b01100100
        0x76,  // column 1, page 0: 0b01110110
        0x5a,  // column 2, page 0: 0b01011010
        0x4e,  // column 3, page 0: 0b01001110
        0x64,  // column 4, page 0: 0b01100100
        0x0,   // column 5, page 0: 0b00000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xfe
    {
        0x0,   // column 0, page 0: 0b00000000
        0xf0,  // column 1, page 0: 0b11110000
        0xf0,  // column 2, page 0: 0b11110000
        0xf0,  // column 3, page 0: 0b11110000
        0xf0,  // column 4, page 0: 0b11110000
        0xf0,  // column 5, page 0: 0b11110000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x7,   // column 1, page 1: 0b00000111
        0x7,   // column 2, page 1: 0b00000111
        0x7,   // column 3, page 1: 0b00000111
        0x7,   // column 4, page 1: 0b00000111
        0x7,   // column 5, page 1: 0b00000111
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    },
// 0xff
    {
        0x0,   // column 0, page 0: 0b00000000
        0x0,   // column 1, page 0: 0b00000000
        0x0,   // column 2, page 0: 0b00000000
        0x0,   // column 3, page 0: 0b00000000
        0x0,   // column 4, page 0: 0b00000000
        0x0,   // column 5, page 0: 0b00000000
        0x0,   // column 6, page 0: 0b00000000
        0x0,   // column 7, page 0: 0b00000000
        0x0,   // column 8, page 0: 0b00000000
        0x0,   // column 0, page 1: 0b00000000
        0x0,   // column 1, page 1: 0b00000000
        0x0,   // column 2, page 1: 0b00000000
        0x0,   // column 3, page 1: 0b00000000
        0x0,   // column 4, page 1: 0b00000000
        0x0,   // column 5, page 1: 0b00000000
        0x0,   // column 6, page 1: 0b00000000
        0x0,   // column 7, page 1: 0b00000000
        0x0    // column 8, page 1: 0b00000000
    }
};