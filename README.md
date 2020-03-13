# Simple PNG
A simple way to generate and draw PNG images in C

## Dependencies

simple-png requires make, gcc and zlib.
It can also be built with Visual Studio build tools if that is preffered.
zlib can be found in most Linux distribution's package managers but will have to be built from source in Windows:
https://github.com/madler/zlib

## Building

### Linux

Install zlib (Debian / Ubuntu):

```
# apt install zlib1g-dev
```

Install make and gcc, then cd into the simple-png download directory simply run make.

```
$ make
```

And it should create libspng.a in your current directory

### Windows

Precompiled libraries are included for 64 bit GCC (libspng.a) and x86 MSVC (spng.lib)

Download zlib and follow the build instructions for WIN32
If you plan to use zlib with gcc make sure you build it with the gcc makefile, and vice versa for MSVC

To build spng.lib (MSVC):
```
set LIB=%LIB%;path_to_zlib_dir;
set INCLUDE=%INCLUDE%;path_to_zlib_dir;
nmake -f Makefile.win
```
for libspng.a (gcc) put a copy of libz.a in simple-png/ and then copy zlib.h and zconf.h to simple-png/include and run make

## Usage

To use the bare simple-png functions, include the png.h file in your source code and link zlib and libspng to your executable
To use the drawing functions include drawing.h as well.

## example

An example program using Simple PNG is included in example.c and will be built by defualt in Makefile and Makefile.win to example.exe. example.exe is included as a precompiled binary for Windows x86