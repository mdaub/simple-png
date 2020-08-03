# Simple PNG
A simple way to generate and draw PNG images in C

## Dependencies

simple-png requires cmake, zlib along with standard system build tools.
zlib can be found in most Linux distribution's package managers but will have to be built from source in Windows, and is included as a submodule.
https://github.com/madler/zlib

## Building

To generate the build files run:
```
cmake .
```
in the root directory of the project.

### CMake Build options

- BUILD_EXAMPLES: builds example files
- BUILD_ZLIB: build zlib from source (on by default in windows)
- LINK_ZLIB_RUNTIME: Windows only, builds spng with the zlib dll symbols

## Usage

To use the bare simple-png functions, include the spng/png.h file in your source code and link zlib and spng to your executable
To use the drawing functions include spng/drawing.h.
Before including png.h or drawing.h define SPNG_STATIC or SPNG_RUNTIME according to which version of the library you will be using.

### Usage example

Include the headers located in the include directory
```
#define SPNG_STATIC
#include "spng/spng.h"
#include "spng/drawing.h"
```
Note: if using C++ all simple png functions will be under the namespace spng. The namespace can be disabled by defining SPNG_NO_NAMESPACE before including the headers.

Create a png_s pointer 
```
png_s* image = png_create(width, height, color_format_enum, bit_depth_enum);
```
You can modify the raw image data by accessing the data member inside png_s, by using the png_setp function and by using the drawing.h functions to draw strings and shapes.
```
png_setp(image, x, y, 0xffffffff);
prints(image, "Hello World!", x, y, scale, color);
```
After modifying the image write it with png_write and free the png_s with png_free
```
png_write(image, output_file);
png_free(image);
```
