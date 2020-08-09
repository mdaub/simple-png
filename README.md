# Simple PNG
A simple way to generate and modify PNG images in C

## Why use Simple PNG?

Well quite frankly if you already have another way to create images, there is no reason to switch. The main reason I started this project is to abstract some of the complexity found in other open source software such as libpng, while maintaining a C only interface. If that's what you need then great. If not there are many better options. This project is mostly just a formalization of code I have used for personal projects for simplicity and learning purposes. 

The source code has been well commented and should be fairly straightforward to follow along and customize provided you have read the PNG standard.

## Dependencies

simple-png requires cmake, zlib along with standard system build tools for C.
zlib can be found in most Linux distribution's package managers but will have to be built from source in Windows, and is included as a submodule.
https://github.com/madler/zlib

## Building

To generate the build files run:
```sh
cmake .
```
in the root directory of the project. Then, depending on your build platform either open the generated project files or run GNU make.

### CMake Build options

- BUILD_EXAMPLES: builds example files
- BUILD_ZLIB: build zlib from source (on by default in windows)
- LINK_ZLIB_RUNTIME: Windows only, builds spng with the zlib dll symbols

### Build notes

Although cmake will generate a shared library version of libspng, it is not recommended to use it at this time. Simple PNG is still a fairly new project and changes to the png_s struct can break your code if you do not rebuild with the correct header.

## Usage

To use the base simple-png functions, include the spng/png.h file in your source code and link zlib and spng to your executable.
To use the drawing functions include spng/drawing.h.
To use colour channel bitmasks, channel positions or conversion functions include spng/colour.h.
Before including png.h, drawing.h or colour.h define SPNG_STATIC or SPNG_RUNTIME according to which version of the library you will be using.

Normally in PNG images (0, 0) is the top left hand corner of the screen. By default Simple PNG inverts the y axis so that (0, 0) is the bottom left hand corner when using png_setp or png_getp. To switch it back set the \_invert_y field inside the png_s struct to 0. The x axis can also be flipped by setting \_invert_x to 1.

If using C++ all Simple PNG functions will be under the namespace spng. The namespace can be disabled by defining SPNG_NO_NAMESPACE before including any spng header.

### Creating a simple PNG image

Include the headers located in the include directory
```c
#define SPNG_STATIC
#include "spng/spng.h"
#include "spng/drawing.h"
```
Create a png_s pointer and check for errors. For information about the colour formats PNG images support, see the section about colours.
```c
png_s* image = png_create(width, height, color_format_enum);
if(image == NULL){
  puts(spngErrorStr(SPNG_ERRNO));
  return 0;
}
```
You can modify the image data by accessing the data member inside png_s, by using the png_setp function and by using the drawing.h functions to draw strings and shapes.
```c
png_setp(image, x, y, colour);
prints(image, "Hello World!", x, y, scale, colour);
```
After modifying the image write it with png_write and free the png_s with png_free, remembering to check for errors
```c
int ret = png_write(image, output_file);
if(ret != SPNG_OK){
  puts(spngErrorStr(SPNG_ERRNO));
}
png_free(image);
```
For more info on creating simple PNG images, see examples/example.c and examples/mandelbrot.cpp.

### Opening an existing image

png_open creates a new png_s from an existing file. To use png_open, simply pass it the file path and check for errors
```c
png_s* image = png_open("existingImage.png");
if(image == NULL){
  puts(spngErrorStr(SPNG_ERRNO);
}
```
After opening the image you can write any changes you want, or read pixel data with png_getp
```c
uint64_t colour;
png_getp(image, x, y, &colour);
```
Then, like described above, write it and free it using png_write and png_free
```c
int ret = png_write(image, output_file);
if(ret != SPNG_OK){
  puts(spngErrorStr(SPNG_ERRNO));
}
png_free(image);
```
### Drawing functions

The drawing functions are included in spng/drawing.h and the source code is located in src/drawing.c. These functions were originally written for creating graphs in bitmap images, but have been modified for use in PNG images. Because of this, the drawing functions expect (0, 0) to be the bottom left corner of the screen. Thus the \_invert_y field of the png_s struct defaults to 1 and can be changed if you don't mind upside down text.

Drawing.c can draw simple shapes such as circles and lines, as well as text in PNG images. For descriptions and usage information see include/spng/drawing.h.

If you wish to modify drawing.c for your own purposes, you need only change the png_setp to whatever your colour setting function is, and change the typedef for image_s in drawing.h to whatever you use to hold the state of your output. 

## About PNG colour formats

There are 5 different colour types, all of which can have various bit depths. The total size of the format is the bit depth multiplied by the number of channels. The valid formats of colour type and bit depth are listed in table 1.

|       Colour Type       | Channels | 1 bit | 2 bit | 4 bit | 8 bit | 16 bit |
|-------------------------|----------|-------|-------|-------|-------|--------|
|    palette / indexed    |    1     |  yes  |  yes  |  yes  |  yes  |   no   |
|        greyscale        |    1     |  yes  |  yes  |  yes  |  yes  |   yes  |
|     greyscale alpha     |    2     |  no   |  no   |  no   |  yes  |   yes  |
|    truecolour (RGB)     |    3     |  no   |  no   |  no   |  yes  |   yes  |
| truecolour alpha (RGBA) |    4     |  no   |  no   |  no   |  yes  |   yes  |

table 1: represents the valid combinations of colour types and bit depths in a png image.

### Colour palette

The colour palette (sometimes called indexed colour) is created by storing RGB8 colours in a table, and referencing the index of that colour in the image data rather than the colour itself. There are 2^bitdepth colours in a colour palette. The table is created automatically when png_create is called with an indexed colour format and can be accessed by the colours field inside the png_s struct. Usage example:
```c
/* create a new png_s struct with a 256 colour indexed mode */
png_s* image = png_create(width, height, png_256colour);
uint64_t index = 0;
/* set colour 0 to red (RGB8 format) */
image->colours[index] = 0xff0000;
png_setp(image, x, y, index);
```
The enumerations for indexed colouring are:
 - png_2colour (bit depth of 1)
 - png_4colour (bit depth of 2)
 - png_16colour (bit depth of 4)
 - png_256colour (bit depth of 8)

### Greyscale

Greyscale simply represents the colour as a greyscale with 0 being black and the max number being white. The max number is 2^bitdepth - 1. So for 8 bit greyscale the max value is 255. Greyscale with alpha adds an alpha channel to the greyscale value at the lsb. So an 8 bit greyscale with alpha would be 2 bytes with the greyscale being the MSB.
The valid greyscale enumerations are:
 - png_GS1 - 1 bit greyscale
 - png_GS2 - 2 bit greyscale
 - png_GS4 - 4 bit greyscale
 - png_GS8 / png_GSA8 - 8 bit greyscale / greyscale with alpha
 - png_GS16 / png_GSA16 - 1 bit greyscale / greyscale with alpha
 
### Truecolour

Truecolour is the PNG name for RGB colours. There are two valid bit depths for RGB and RGBA: 8 and 16 bit. The formatting of the numbers is consitent with the order of the lettering with R being the msb and B/A being the lsb. In 8 bit each channel has a maximimum value of 255 and 65535 in 16 bit.
The valid truecolour enumerations are:
 - png_RGB8 / png_RGBA8 - 8 bit RGB / RGBA
 - png_RGB16 / png_RGBA16 - 16 bit RGB / RGBA

### spng/colour.h

colour.h contains functions and macros useful for manipulating colours. The macros contain position and bitmask data for the different channels in greyscale and truecolour colour types. The file also contains function prototypes for converting between the different formats (mostly from / to RGBA8 and RGBA16). All functions fall under the spng namespace in C++ unless you define SPNG_NO_NAMESPACE, as noted above.
