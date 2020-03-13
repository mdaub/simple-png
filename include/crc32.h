/*
 * crc32.h is part of simple-png
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

#ifndef __crc32
#define __crc32

#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
#include <stddef.h>
#define _CRC32_DEFAULT_POLY 0x04c11db7

/**
 * @brief computes the crc32 of a block of data
 * 
 * @param ptr a pointer to the data 
 * @param size the number of bytes of data
 * @param init the number to initialize the crc to
 * @return uint32_t 
 */
uint32_t _crc32(const void* ptr, size_t size);

/**
 * @brief computes the crc32 without doing the final inversion
 * This is useful if the crc32 needs to operate on non consecutive blocks of memory
 * @param ptr a pointer to a block of data
 * @param size the size of the block in bytes
 * @param init the init value for the crc32
 * @return uint32_t 
 */
uint32_t part_crc32(const void* ptr, size_t size, uint32_t init);


#ifdef __cplusplus
}
#endif

#endif /* ifndef __crc32 */