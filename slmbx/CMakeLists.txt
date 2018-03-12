cmake_minimum_required(VERSION 3.9)
project(slmbx)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c rand.h util.c)
add_executable(slmbx ${SOURCE_FILES})
