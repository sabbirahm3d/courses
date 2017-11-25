cmake_minimum_required(VERSION 3.8)
project(multithread_lcs)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(main ${SOURCE_FILES})

include_directories(main "/usr/local/include")
