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

/* get rid of fprintf_s suggestion on windows */
#ifdef _WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif

#define SPNG_STATIC
#include "../include/spng/png.h"
#include "../include/spng/drawing.h"
#include <stdio.h>
#include <string.h>

/* the graph is simply to avoid any copyright issues
 * the colour format of graph.png is RGB8 
 */

int main(void)
{
	/* open the png file by providing the path */
	const char* filename = "examples/graph.png";
	png_s* image = png_open(filename);

	/* check if image was opened and report errors */
	if (image == NULL)
	{
		fprintf(stderr, "Error opening file '%s': %s\n", filename, spngErrorStr(SPNG_ERRNO));
		return 0;
	}
	else printf("Opened file '%s' successfully.\n", filename);
	for (unsigned int y = 0; y < image->height; y++)
	{
		for (unsigned int x = 0; x < image->width; x++)
		{
			uint64_t colour_no_red;
			/* get the colour at x and y */
			png_getp(image, x, y, &colour_no_red);
			/* remove the red from the RGB8 colour */
			colour_no_red &= 0x00ffff;
			/* set the colour to the red removed colour */
			png_setp(image, x, y, colour_no_red);
		}
	}
	/* print a string onto the screen in roughly the middle */
	int msg_len = strlen("red removed from image");
	prints(image, "red removed from image", (image->width - msg_len * 2 * SPNG_CHARACTER_WIDTH) / 2, image->height/2, 2, 0xff0000);
	
	const char* filename_out = "examples/graph_modified.png";
	/* write image and check if it was successful */
	if (png_write(image, filename_out) != SPNG_OK)
	{
		fprintf(stderr, "Error writing file '%s': %s\n", "examples/graph_modified.png", spngErrorStr(SPNG_ERRNO));
	}
	else printf("Sent image to '%s'\n", filename_out);
	/* free allocated data */
	png_free(image);
	return 0;
}
