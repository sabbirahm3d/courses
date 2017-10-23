cmake_minimum_required(VERSION 3.8)
project(project)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        project1/cmake-build-debug/cmake_install.cmake
        project1/cmake-build-debug/CMakeCache.txt
        project1/cmake-build-debug/divide_and_conquer.cbp
        project1/cmake-build-debug/main
        project1/cmake-build-debug/Makefile
        project1/cmake-build-debug/Project.cbp
        project1/main.cpp
        project1/main.h)

add_executable(project ${SOURCE_FILES})