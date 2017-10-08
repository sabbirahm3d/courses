cmake_minimum_required(VERSION 3.8)
project(hw02)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        code/music.c
        code/music.h
        code/Makefile code/music.h)

add_executable(hw02 ${SOURCE_FILES})