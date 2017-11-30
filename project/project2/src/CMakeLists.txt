cmake_minimum_required(VERSION 3.8)
project(multithread_lcs)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -fopenmp")

set(SOURCE_FILES lcs_length.c)
add_executable(main ${SOURCE_FILES})

include_directories(main "/usr/local/include")
