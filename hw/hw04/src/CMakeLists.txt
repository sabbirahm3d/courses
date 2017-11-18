cmake_minimum_required(VERSION 3.8)
project(src)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c adc_controller.c lcd_driver.h lcd_driver.c)
add_executable(src ${SOURCE_FILES})