cmake_minimum_required(VERSION 3.9)
project(slmbx)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES utilmath.h msgsl.c msgq.c mbx.c main.c utilstr.c)
add_executable(slmbx ${SOURCE_FILES})
