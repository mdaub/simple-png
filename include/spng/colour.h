/*
 * colour.h is part of simple-png
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

#ifndef _COLOUR_H
#define _COLOUR_H

 /* included up here to avoid namespace issues */
#include <stdint.h>

#ifdef __cplusplus
#ifndef SPNG_NO_NAMESPACE
namespace spng {
#endif
    extern "C" {
#endif

#include "png.h"

#ifndef SPNG_NO_COLOUR_DEFINES

#define GS1_MASK          0x1
#define GS2_MASK          0x3
#define GS4_MASK          0xf
#define GS8_MASK          0xff
#define GS16_MASK         0xffff
#define GSA8_MASK         0xffff
#define GSA16_MASK        0xffffffff

#define RGB8_MASK         0xffffff
#define RGB8_RED_MASK     0xff0000
#define RGB8_RED_POS      16
#define RGB8_GREEN_MASK   0x00ff00
#define RGB8_GREEN_POS    8
#define RGB8_BLUE_MASK    0x0000ff
#define RGB8_BLUE_POS     0

#define RGBA8_MASK        0xffffffff
#define RGBA8_RED_MASK    0xff000000
#define RGBA8_RED_POS     24
#define RGBA8_GREEN_MASK  0x00ff0000
#define RGBA8_GREEN_POS   16
#define RGBA8_BLUE_MASK   0x0000ff00
#define RGBA8_BLUE_POS    8
#define RGBA8_ALPHA_MASK  0x000000ff
#define RGBA8_ALPHA_POS   0

#define RGB16_MASK        0xffffffffffff
#define RGB16_RED_MASK    0xffff00000000
#define RGB16_RED_POS     32
#define RGB16_GREEN_MASK  0x0000ffff0000
#define RGB16_GREEN_POS   16
#define RGB16_BLUE_MASK   0x00000000ffff
#define RGB16_BLUE_POS    0

#define RGBA16_MASK       0xffffffffffffffff
#define RGBA16_RED_MASK   0xffff000000000000
#define RGBA16_RED_POS    48
#define RGBA16_GREEN_MASK 0x0000ffff00000000
#define RGBA16_GREEN_POS  32
#define RGBA16_BLUE_MASK  0x00000000ffff0000
#define RGBA16_BLUE_POS   16
#define RGBA16_ALPHA_MASK 0x000000000000ffff
#define RGBA16_ALPHA_POS  0

#endif /* ifndef SPNG_NO_COLOUR_DEFINES */

#include <stdint.h> 

/******************** conversions to RGBA16 ********************/

/**
 * @brief Converts 1 bit greyscale to RGBA16
 * @param colour the raw colour to convert
 * @return uint64_t returns the converted colour
 */
uint64_t GS1ToRGBA16(uint64_t colour);
/**
 * @brief Converts 2 bit greyscale to RGBA16
 * @param colour the raw colour to convert
 * @return uint64_t returns the converted colour
 */
uint64_t GS2ToRGBA16(uint64_t colour);
/**
 * @brief Converts 4 bit greyscale to RGBA16
 * @param colour the raw colour to convert
 * @return uint64_t returns the converted colour
 */
uint64_t GS4ToRGBA16(uint64_t colour);
/**
 * @brief Converts 8 bit greyscale to RGBA16
 * @param colour the raw colour to convert
 * @return uint64_t returns the converted colour
 */
uint64_t GS8ToRGBA16(uint64_t colour);
/**
 * @brief Converts 16 bit greyscale to RGBA16
 * @param colour the raw colour to convert
 * @return uint64_t returns the converted colour
 */
uint64_t GS16ToRGBA16(uint64_t colour);

/**
 * @brief Converts 8 bit greyscale with alpha to RGBA16
 * @param colour the raw colour to convert
 * @return uint64_t returns the converted colour
 */
uint64_t GSA8ToRGBA16(uint64_t colour);
/**
 * @brief Converts 16 bit greyscale with alpha to RGBA16
 * @param colour the raw colour to convert
 * @return uint64_t returns the converted colour
 */
uint64_t GSA16ToRGBA16(uint64_t colour);

/**
 * @brief Converts RGB8 to RGBA16
 * @param colour the raw colour to convert
 * @return uint64_t returns the converted colour
 */
uint64_t RGB8ToRGBA16(uint64_t colour);
/**
 * @brief Converts RGB16 to RGBA16
 * @param colour the raw colour to convert
 * @return uint64_t returns the converted colour
 */
uint64_t RGB16ToRGBA16(uint64_t colour);

/**
 * @brief Converts RGBA8 to RGBA16
 * @param colour the raw colour to convert
 * @return uint64_t returns the converted colour
 */
uint64_t RGBA8ToRGBA16(uint64_t colour);

/******************** conversions to RGBA8 ********************/

/**
 * @brief Converts 1 bit greyscale to RGBA8
 * @param colour the raw colour to convert
 * @return uint64_t returns the converted colour
 */
uint64_t GS1ToRGBA8(uint64_t colour);
/**
 * @brief Converts 2 bit greyscale to RGBA8
 * @param colour the raw colour to convert
 * @return uint64_t returns the converted colour
 */
uint64_t GS2ToRGBA8(uint64_t colour);
/**
 * @brief Converts 4 bit greyscale to RGBA8
 * @param colour the raw colour to convert
 * @return uint64_t returns the converted colour
 */
uint64_t GS4ToRGBA8(uint64_t colour);
/**
 * @brief Converts 8 bit greyscale to RGBA8
 * @param colour the raw colour to convert
 * @return uint64_t returns the converted colour
 */
uint64_t GS8ToRGBA8(uint64_t colour);
/**
 * @brief Converts 16 bit greyscale to RGBA8
 * @param colour the raw colour to convert
 * @return uint64_t returns the converted colour
 */
uint64_t GS16ToRGBA8(uint64_t colour);

/**
 * @brief Converts 8 bit greyscale with alpha to RGBA8
 * @param colour the raw colour to convert
 * @return uint64_t returns the converted colour
 */
uint64_t GSA8ToRGBA8(uint64_t colour);
/**
 * @brief Converts 16 bit greyscale with alpha to RGBA8
 * @param colour the raw colour to convert
 * @return uint64_t returns the converted colour
 */
uint64_t GSA16ToRGBA8(uint64_t colour);

/**
 * @brief Converts RGB8 to RGBA8
 * @param colour the raw colour to convert
 * @return uint64_t returns the converted colour
 */
uint64_t RGB8ToRGBA8(uint64_t colour);
/**
 * @brief Converts RGB16 to RGBA8
 * @param colour the raw colour to convert
 * @return uint64_t returns the converted colour
 */
uint64_t RGB16ToRGBA8(uint64_t colour);

/**
 * @brief Converts RGBA16 to RGBA8
 * @param colour the raw colour to convert
 * @return uint64_t returns the converted colour
 */
uint64_t RGBA16ToRGBA8(uint64_t colour);

/* conversions from RGBA16 */

/**
 * @brief Converts RGBA16 to 1 bit greyscale
 * @param colour the raw colour to convert
 * @return uint64_t returns the converted colour
 */
uint64_t RGBA16ToGS1(uint64_t colour);
/**
 * @brief Converts RGBA16 to 2 bit greyscale
 * @param colour the raw colour to convert
 * @return uint64_t returns the converted colour
 */
uint64_t RGBA16ToGS2(uint64_t colour);
/**
 * @brief Converts RGBA16 to 4 bit greyscale
 * @param colour the raw colour to convert
 * @return uint64_t returns the converted colour
 */
uint64_t RGBA16ToGS4(uint64_t colour);
/**
 * @brief Converts RGBA16 to 8 bit greyscale
 * @param colour the raw colour to convert
 * @return uint64_t returns the converted colour
 */
uint64_t RGBA16ToGS8(uint64_t colour);
/**
 * @brief Converts RGBA16 to 16 bit greyscale
 * @param colour the raw colour to convert
 * @return uint64_t returns the converted colour
 */
uint64_t RGBA16ToGS16(uint64_t colour);

/**
 * @brief Converts RGBA16 to 8 bit greyscale with alpha
 * @param colour the raw colour to convert
 * @return uint64_t returns the converted colour
 */
uint64_t RGBA16ToGSA8(uint64_t colour);
/**
 * @brief Converts RGBA16 to 16 bit greyscale with alpha
 * @param colour the raw colour to convert
 * @return uint64_t returns the converted colour
 */
uint64_t RGBA16ToGSA16(uint64_t colour);

/**
 * @brief Converts RGBA16 to RGB8
 * @param colour the raw colour to convert
 * @return uint64_t returns the converted colour
 */
uint64_t RGBA16ToRGB8(uint64_t colour);
/**
 * @brief Converts RGBA16 to 1 RGB16
 * @param colour the raw colour to convert
 * @return uint64_t returns the converted colour
 */
uint64_t RGBA16ToRGB16(uint64_t colour);

/******************** conversions from RGBA8 ********************/

uint64_t RGBA8ToGS1(uint64_t colour);
uint64_t RGBA8ToGS2(uint64_t colour);
uint64_t RGBA8ToGS4(uint64_t colour);
uint64_t RGBA8ToGS8(uint64_t colour);
uint64_t RGBA8ToGS16(uint64_t colour);

uint64_t RGBA8ToGSA8(uint64_t colour);
uint64_t RGBA8ToGSA16(uint64_t colour);

uint64_t RGBA8ToRGB8(uint64_t colour);
uint64_t RGBA8ToRGB16(uint64_t colour);

#ifdef __cplusplus
#ifndef SPNG_NO_NAMESPACE
}
#endif
}
#endif

#endif