cmake_minimum_required(VERSION 3.9)
project(sabbash)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c config.h util.c util.h proc.c proc.h)
add_executable(sabbash ${SOURCE_FILES})
