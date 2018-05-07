cmake_minimum_required(VERSION 3.9)
project(p2ids)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES cptrace.c logger.c)
add_executable(p2ids ${SOURCE_FILES})
