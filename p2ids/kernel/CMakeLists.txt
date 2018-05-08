cmake_minimum_required(VERSION 3.9)
project(p2ids)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES local_logger.c local_miniptrace.h local_logger.h)
add_executable(p2ids ${SOURCE_FILES})
