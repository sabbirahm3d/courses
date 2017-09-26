cmake_minimum_required(VERSION 3.6)
project(divide_and_conquer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98")
set(CMAKE_C_FLAGS "-lgmp")

set(SOURCE_FILES main.cpp)
add_executable(main ${SOURCE_FILES})

include_directories(main "/usr/local/include")
target_link_libraries(main gmp)
