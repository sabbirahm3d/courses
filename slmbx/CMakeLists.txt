cmake_minimum_required(VERSION 3.9)
project(slmbx)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c extmath.h mbx.c msgsl.c msgq.c msgq.h)
add_executable(slmbx ${SOURCE_FILES})
