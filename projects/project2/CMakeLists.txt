cmake_minimum_required(VERSION 3.3)
project(project2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/Driver.cpp
    src/Makefile
    src/testfilenames.txt
    src/testgame1.txt
    src/testgame2.txt
    src/testgame3.txt
    src/TicTacNode.cpp
    src/TicTacNode.h
    src/TicTacToe.cpp
    src/TicTacToe.h
    src/TicTacTrie.cpp
    src/TicTacTrie.h
    yo.cpp)

add_executable(project2 ${SOURCE_FILES})