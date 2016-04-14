cmake_minimum_required(VERSION 3.5)
project(project4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98")

set(SOURCE_FILES
        src/main.cpp
        src/MMHeap.h
        src/MMHeap.cpp)

add_executable(project4 ${SOURCE_FILES} src/integers.txt)