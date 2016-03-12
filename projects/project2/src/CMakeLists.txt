cmake_minimum_required(VERSION 3.3)
project(src)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98")

set(SOURCE_FILES
    Driver.cpp
    testfilenames.txt
    testgame1.txt
    testgame2.txt
    testgame3.txt
    TicTacNode.cpp
    TicTacNode.h
    TicTacToe.cpp
    TicTacToe.h
    TicTacTrie.cpp
    TicTacTrie.h)

BUILD_COMMAND(variable testfilenames.txt)

add_executable(src ${SOURCE_FILES})