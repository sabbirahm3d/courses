/* File:    main.cpp
 * Project: CMSC 341: Project 5, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    4/23/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * Driver script to test the MMheap class
 */

#include "Hashtable.h"

#include <fstream>
#include <cstdlib>
#include <iostream>

#define EXPECTED_ARGC 2

int main(int argc, char **argv) {

    std::string fileName;

    Hashtable* table = new Hashtable;

    if (argc == EXPECTED_ARGC) {
        fileName = argv[1];
    } else {
        std::cout << "Not enough command line arguments." << std::endl;
        return 0;
    }

    std::ifstream file(fileName.c_str());

    if (file.good()) {
        std::string line;

        while (getline(file, line)) {
            int_heap->insert(atoi(line.c_str()));
        }

    } else {

        std::cout << "File was not opened." << std::endl;
        return 0;

    }

    return 0;
}