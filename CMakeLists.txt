cmake_minimum_required(VERSION 2.8)
project(ArcomageTribute)

# Include some CMake functions
INCLUDE(CheckLibraryExists)
INCLUDE(CheckIncludeFile)
INCLUDE(CheckIncludeFileCXX)
INCLUDE(CheckCCompilerFlag)
INCLUDE(CheckCSourceCompiles)

set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(thirdparty)
add_subdirectory(game)
#add_subdirectory(tools)
