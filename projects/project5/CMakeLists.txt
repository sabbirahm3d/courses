cmake_minimum_required(VERSION 3.5)
project(project5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98")

set(SOURCE_FILES
        src/main.cpp
        src/Hashtable.cpp
        src/Hashtable.h
        )
add_executable(project5 ${SOURCE_FILES} src/input.txt)