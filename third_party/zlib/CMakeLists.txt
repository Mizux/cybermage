cmake_minimum_required(VERSION 2.8)
project(zlib)

file(GLOB _HDRS include/*.h)
file(GLOB _SRCS src/*.c)

include_directories("include")
set(${PROJECT_NAME}_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}" CACHE PATH "${PROJECT_NAME} include path")

add_library(${PROJECT_NAME} ${_HDRS} ${_SRCS})
