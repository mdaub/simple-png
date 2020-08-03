CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

project(simple-png LANGUAGES C)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

option(LINK_ZLIB_STATIC "Windows Only | Links zlibstatic directly into spng" ON)
option(BUILD_EXAMPLES "Builds the example files" ON)
option(BUILD_ZLIB "Build from zlib source or link from system" ON)



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
            src/png.h 
            src/crc32.h 
            src/crc32table.h 
            src/codepage-437.h
            src/drawing.h 
            src/crc32.c 
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

if(LINK_ZLIB_STATIC)
    set(ZLIB_LIB ${ZLIB_STATIC})
else()
    set(ZLIB_LIB ${ZLIB_SHARED})
    target_compile_definitions(spng_static PRIVATE ZLIB_DLL)
    target_compile_definitions(spng_runtime PRIVATE ZLIB_DLL)
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
    set_target_properties(spng_example PROPERTIES OUTPUT_NAME example)
    set_target_properties(spng_example PROPERTIES PROJECT_LABEL example)
    target_include_directories(spng_example PUBLIC ../include)
    target_link_libraries(spng_example spng_static ${ZLIB_LIB})
endif()