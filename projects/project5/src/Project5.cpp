/* File:    main.cpp
 * Project: CMSC 341: Project 5, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    4/23/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * Driver script to test the MMheap class
 */

#include "BackupHash.h"

#include <fstream>
#include <cstdlib>
#include <iostream>

#define EXPECTED_ARGC 2

int main(int argc, char **argv) {

    std::string fileName;

    BackupHash* table = new BackupHash;

    if (argc == EXPECTED_ARGC) {
        fileName = argv[1];
    } else {
        std::cout << "Not enough command line arguments." << std::endl;
        return 0;
    }

    std::ifstream file(fileName.c_str());

    if (file.good()) {
        std::string city;
        std::string coords;

        while (getline(file, city)) {
            std::cout << city << std::endl;
            getline(file, coords);
            table->put(city, atoi(coords.c_str()));
//            table->get(city);
        }

    } else {

        std::cout << "File was not opened." << std::endl;
        return 0;

    }

    delete table;
//    table = NULL;

    return 0;
}