CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

project(simple-png LANGUAGES C CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# build zlib by defualt on windows
if(MSVC)
    set(BUILD_ZLIB_DEFAULT ON)
else()
    set(BUILD_ZLIB_DEFAULT OFF)
endif()

option(LINK_ZLIB_RUNTIME "Windows Only | uses runtime version of zlib" OFF)
option(BUILD_EXAMPLES "Builds the example files" OFF)
option(BUILD_ZLIB "Build from zlib source or link from system" ${BUILD_ZLIB_DEFAULT})



# system specific ZLIB naming
if(MSVC)
    set(ZLIB_STATIC zlib.lib)
    set(ZLIB_SHARED zlib.dll)
    set(MSVC_DEFINES _CRT_SECURE_NO_WARNINGS)
else()
    set(ZLIB_STATIC z)
    set(ZLIB_SHARED z)
endif()

# output paths
set(LIBRARY_OUTPUT_PATH bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin) 
set(EXECUTABLE_OUTPUT_PATH bin)

# source files
set(SPNG_SRC 
            include/spng/png.h
            include/spng/drawing.h
            include/spng/colour.h
            src/crc32.h 
            src/crc32table.h 
            src/codepage-437.h 
            src/crc32.c 
            src/colour.c
            src/png.c 
            src/drawing.c )

# create libs
add_library(spng_static STATIC ${SPNG_SRC})
add_library(spng_runtime SHARED ${SPNG_SRC})

# add zlib to the project and change lib names
if(BUILD_ZLIB)
    add_subdirectory(zlib)    
    set_property(TARGET zlib PROPERTY FOLDER zlib)
    set_property(TARGET zlibstatic PROPERTY FOLDER zlib)
    set_property(TARGET example PROPERTY FOLDER zlib)
    set_property(TARGET minigzip PROPERTY FOLDER zlib)
    set(ZLIB_STATIC zlibstatic)
    set(ZLIB_SHARED zlib)
    target_include_directories(spng_static PRIVATE ./zlib/)
    target_include_directories(spng_runtime PRIVATE ./zlib/)
endif()

if(LINK_ZLIB_RUNTIME)    
    set(ZLIB_LIB ${ZLIB_SHARED})
    target_compile_definitions(spng_static PRIVATE ZLIB_DLL)
    target_compile_definitions(spng_runtime PRIVATE ZLIB_DLL)
else()
    set(ZLIB_LIB ${ZLIB_STATIC})
endif()

# system specific links, names and defines
if(MSVC)
    # to prevent naming conflicts at different output stages
    set_target_properties(spng_static PROPERTIES OUTPUT_NAME spng)
    set_target_properties(spng_runtime PROPERTIES OUTPUT_NAME spngs)
    target_link_libraries(spng_runtime ${ZLIB_LIB})
else()
    set_target_properties(spng_static spng_runtime PROPERTIES OUTPUT_NAME spng)
endif()

target_compile_definitions(spng_static PRIVATE SPNG_BUILD_STATIC ${MSVC_DEFINES})
target_compile_definitions(spng_runtime PRIVATE SPNG_BUILD_SHARED ${MSVC_DEFINES})
# example program.
if(BUILD_EXAMPLES)
    set(EXECUTABLE_OUTPUT_PATH bin/)
    add_executable(spng_example examples/example.c)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT spng_example)
    set_property(TARGET spng_example PROPERTY FOLDER examples)
    set_target_properties(spng_example PROPERTIES OUTPUT_NAME example)
    set_target_properties(spng_example PROPERTIES PROJECT_LABEL example)
    target_link_libraries(spng_example spng_static ${ZLIB_LIB})

    add_executable(open_example examples/open_example.c)
    set_property(TARGET open_example PROPERTY FOLDER examples)
    target_link_libraries(open_example spng_static ${ZLIB_LIB})

    add_executable(spng_mandelbrot examples/mandelbrot.cpp )
    set(CMAKE_CXX_STANDARD 14)
    set_property(TARGET spng_mandelbrot PROPERTY FOLDER examples)
    set_target_properties(spng_mandelbrot PROPERTIES OUTPUT_NAME mandelbrot)
    set_target_properties(spng_mandelbrot PROPERTIES PROJECT_LABEL mandelbrot)
    target_link_libraries(spng_mandelbrot spng_static ${ZLIB_LIB})
endif()