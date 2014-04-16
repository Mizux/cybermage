cmake_minimum_required(VERSION 2.8)
project(minizip)

include_directories(zlib_INCLUDE_DIRS)

file(GLOB _HDRS *.h)
file(GLOB _SRCS *.c)

include_directories(".")
set(${PROJECT_NAME}_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}" CACHE PATH "${PROJECT_NAME} include path")

add_library(${PROJECT_NAME} ${_HDRS} ${_SRCS})
target_link_libraries(${PROJECT_NAME} zlib)
