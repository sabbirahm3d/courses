cmake_minimum_required(VERSION 3.8)
project(code)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c database.c list_of_grades.h list_of_grades.c grade_t.h)
add_executable(code ${SOURCE_FILES})