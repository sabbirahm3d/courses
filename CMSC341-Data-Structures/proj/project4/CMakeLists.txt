cmake_minimum_required(VERSION 3.5)
project(project4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98")

set(SOURCE_FILES
        src/main.cpp
        src/MyException.h
        src/MMheap.h
        src/MMheap.cpp)

add_executable(project4 ${SOURCE_FILES} src/integers.txt)