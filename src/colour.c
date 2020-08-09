/*
 * colour.c is part of simple-png
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

#include "../include/spng/png.h"
#include "../include/spng/colour.h"

/* conversions to RGBA16 */
uint64_t GS1ToRGBA16(uint64_t colour)
{
	colour = (colour & 1) * 0xFFFF;
	return (colour << 48) | (colour << 32) | (colour << 16) | 0xffff;
}
uint64_t GS2ToRGBA16(uint64_t colour)
{
	colour = (colour & 0b11) * 0x5555;
	return (colour << 48) | (colour << 32) | (colour << 16) | 0xffff;
}
uint64_t GS4ToRGBA16(uint64_t colour)
{
	colour = (colour & 0xf) * 0x1111;
	return (colour << 48) | (colour << 32) | (colour << 16) | 0xffff;
}
uint64_t GS8ToRGBA16(uint64_t colour)
{
	colour = (colour & 0xff) * 0x101;
	return (colour << 48) | (colour << 32) | (colour << 16) | 0xffff;
}
uint64_t GS16ToRGBA16(uint64_t colour)
{
	colour = (colour & 0xffff);
	return (colour << 48) | (colour << 32) | (colour << 16) | 0xffff;
}

uint64_t GSA8ToRGBA16(uint64_t colour)
{
	uint64_t brightness = ((colour >> 8) & 0xff) * 0x101,
		alpha = (colour & 0xff) * 0x101;
	return (brightness << 48) | (brightness << 32) | (brightness << 16) | alpha;
}
uint64_t GSA16ToRGBA16(uint64_t colour)
{
	uint64_t brightness = (colour >> 16) & 0xffffff,
		alpha = colour & 0xfffff;
	return (brightness << 48) | (brightness << 32) | (brightness << 16) | alpha;
}

uint64_t RGB8ToRGBA16(uint64_t colour)
{
	uint64_t 
		r = ((colour >> 16) & 0xff) * 0x101, 
		g = ((colour >> 8) & 0xff) * 0x101, 
		b = (colour & 0xff) * 0x101;
	return (r << 48) | (g << 32) | (b << 16) | 0xffff;
}
uint64_t RGB16ToRGBA16(uint64_t colour)
{
	uint64_t 
		r = (colour >> 32) & 0xffff,
		g = (colour >> 16) & 0xffff,
		b = colour & 0xffff;
	return (r << 48) | (g << 32) | (b << 16) | 0xffff;
}

uint64_t RGBA8ToRGBA16(uint64_t colour)
{
	uint64_t 
		r = ((colour >> 24) & 0xff) * 0x101,
		g = ((colour >> 16) & 0xff) * 0x101,
		b = ((colour >> 8 ) & 0xff) * 0x101,
		a = ((colour      ) & 0xff) * 0x101;
	return (r << 48) | (g << 32) | (b << 16) | a;
}

/* conversions to RGBA8 */

uint64_t GS1ToRGBA8(uint64_t colour)
{
	colour = (colour & 1) * 0xFF;
	return (colour << 24) | (colour << 16) | (colour << 8) | 0xff;
}
uint64_t GS2ToRGBA8(uint64_t colour)
{
	colour = (colour & 0x3) * 0x55;
	return (colour << 24) | (colour << 16) | (colour << 8) | 0xff;
}
uint64_t GS4ToRGBA8(uint64_t colour)
{
	colour = (colour & 0xf) * 0x11;
	return (colour << 24) | (colour << 16) | (colour << 8) | 0xff;
}
uint64_t GS8ToRGBA8(uint64_t colour)
{
	colour = (colour & 0xff);
	return (colour << 24) | (colour << 16) | (colour << 8) | 0xff;
}
uint64_t GS16ToRGBA8(uint64_t colour)
{
	colour = (colour & 0xffff) / 0x101;
	return (colour << 24) | (colour << 16) | (colour << 8) | 0xff;
}

uint64_t GSA8ToRGBA8(uint64_t colour)
{
	uint64_t brightness = (colour >> 8) & 0xff, alpha = colour & 0xff;
	return (brightness << 24) | (brightness << 16) | (brightness << 8) | alpha;
}
uint64_t GSA16ToRGBA8(uint64_t colour)
{
	uint64_t brightness = ((colour >> 16) & 0xffff) / 0x101, alpha = (colour & 0xffff) / 0x101;
	return (brightness << 24) | (brightness << 16) | (brightness << 8) | alpha;
}

uint64_t RGB8ToRGBA8(uint64_t colour)
{
	return ((colour & 0xffffff) << 8) | 0xff;
}
uint64_t RGB16ToRGBA8(uint64_t colour)
{
	uint64_t r = ((colour >> 32) & 0xffff) / 0x101;
	uint64_t g = ((colour >> 16) & 0xffff) / 0x101;
	uint64_t b = ((colour      ) & 0xffff) / 0x101;
	return (r << 24) | (g << 16) | (b << 8) | 0xff;
}

uint64_t RGBA16ToRGBA8(uint64_t colour)
{
	uint64_t r = ((colour >> 48) & 0xffff) / 0x101;
	uint64_t g = ((colour >> 32) & 0xffff) / 0x101;
	uint64_t b = ((colour >> 16) & 0xffff) / 0x101;
	uint64_t a = ((colour      ) & 0xffff) / 0x101;
	return (r << 24) | (g << 16) | (b << 8) | a;
}

/* conversions from RGBA16 */

uint64_t RGBA16ToGS1(uint64_t colour)
{
	if (!(colour & 0xffff)) return 0;
	return (((colour >> 48) & 0xffff) + ((colour >> 32) & 0xffff) + ((colour >> 16) & 0xffff)) / (3 * 0xffff);
}
uint64_t RGBA16ToGS2(uint64_t colour)
{
	if (!(colour & 0xffff)) return 0;
	return (((colour >> 48) & 0xffff) + ((colour >> 32) & 0xffff) + ((colour >> 16) & 0xffff)) / (3 * 0x5555);
}
uint64_t RGBA16ToGS4(uint64_t colour)
{
	if (!(colour & 0xffff)) return 0;
	return (((colour >> 48) & 0xffff) + ((colour >> 32) & 0xffff) + ((colour >> 16) & 0xffff)) / (3 * 0x1111);
}
uint64_t RGBA16ToGS8(uint64_t colour)
{
	if (!(colour & 0xffff)) return 0;
	return (((colour >> 48) & 0xffff) + ((colour >> 32) & 0xffff) + ((colour >> 16) & 0xffff)) / (3 * 0x101);
}
uint64_t RGBA16ToGS16(uint64_t colour)
{
	if (!(colour & 0xffff)) return 0;
	return (((colour >> 48) & 0xffff) + ((colour >> 32) & 0xffff) + ((colour >> 16) & 0xffff)) / 3;
}

uint64_t RGBA16ToGSA8(uint64_t colour)
{
	if (!(colour & 0xffff)) return 0;
	return (((((colour >> 48) & 0xffff) + ((colour >> 32) & 0xffff) + ((colour >> 16) & 0xffff)) / (3 * 0x101)) << 8) | ((colour & 0xffff) / 0x101);
}
uint64_t RGBA16ToGSA16(uint64_t colour)
{
	if (!(colour & 0xffff)) return 0;
	return (((((colour >> 48) & 0xffff) + ((colour >> 32) & 0xffff) + ((colour >> 16) & 0xffff)) / (3)) << 16) |  (colour & 0xffff);
}

uint64_t RGBA16ToRGB8(uint64_t colour)
{
	if (!(colour & 0xffff)) return 0;
	uint64_t
		r = ((colour >> 48) & 0xffff) / 0x101,
		g = ((colour >> 32) & 0xffff) / 0x101,
		b = ((colour >> 16) & 0xffff) / 0x101;
	return (r << 16) | (g << 8) | b;
}
uint64_t RGBA16ToRGB16(uint64_t colour)
{
	if (!(colour & 0xffff)) return 0;
	return (colour >> 16) & 0xffff;
}

/* conversions from RGBA8 */

uint64_t RGBA8ToGS1(uint64_t colour)
{
	if (!(colour & 0xff)) return 0;
	return (((colour >> 24) & 0xff) + ((colour >> 16) & 0xff) + ((colour >> 8) & 0xff)) / (3 * 0xff);
}
uint64_t RGBA8ToGS2(uint64_t colour)
{
	if (!(colour & 0xff)) return 0;
	return (((colour >> 24) & 0xff) + ((colour >> 16) & 0xff) + ((colour >> 8) & 0xff)) / (3 * 0x55);
}
uint64_t RGBA8ToGS4(uint64_t colour)\
{
	if (!(colour & 0xff)) return 0;
	return (((colour >> 24) & 0xff) + ((colour >> 16) & 0xff) + ((colour >> 8) & 0xff)) / (3 * 0x11);
}
uint64_t RGBA8ToGS8(uint64_t colour)
{
	if (!(colour & 0xff)) return 0;
	return (((colour >> 24) & 0xff) + ((colour >> 16) & 0xff) + ((colour >> 8) & 0xff)) / 3;
}
uint64_t RGBA8ToGS16(uint64_t colour)
{
	if (!(colour & 0xff)) return 0;
	return (((colour >> 24) & 0xff) + ((colour >> 16) & 0xff) + ((colour >> 8) & 0xff)) * 0x101 / 3;
}

uint64_t RGBA8ToGSA8(uint64_t colour)
{
	if (!(colour & 0xff)) return 0;
	return (((((colour >> 24) & 0xff) + ((colour >> 16) & 0xff) + ((colour >> 8) & 0xff)) / 3) << 8) | (colour & 0xff);
}
uint64_t RGBA8ToGSA16(uint64_t colour)
{
	if (!(colour & 0xff)) return 0;
	return (((((colour >> 24) & 0xff) + ((colour >> 16) & 0xff) + ((colour >> 8) & 0xff)) * 0x101 / 3) << 16) | ((colour & 0xff) * 0x101);
}

uint64_t RGBA8ToRGB8(uint64_t colour)
{
	return (colour >> 8) & 0xffffff;
}
uint64_t RGBA8ToRGB16(uint64_t colour)
{
	uint64_t
		r = ((colour >> 24) & 0xff) * 0x101,
		g = ((colour >> 16) & 0xff) * 0x101,
		b = ((colour >> 8) & 0xff) * 0x101;
	return (r << 32) | (g << 16) | b;
}
