cmake_minimum_required(VERSION 3.8)
project(project1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    CMakeLists.txt
    main.cpp
    main.h)

add_executable(project1 ${SOURCE_FILES})