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
	
	/* write image and check if it was successful */
	if (png_write(image, filename) != SPNG_OK)
	{
		fprintf(stderr, "Error writing file '%s': %s\n", filename, spngErrorStr(SPNG_ERRNO));
	}
	/* free allocated data */
	png_free(image);
	return 0;
}