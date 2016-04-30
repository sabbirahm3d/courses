/* File:    main.cpp
 * Project: CMSC 341: Project 5, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    4/23/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * Driver script to test the MMheap class
 */

//#include "BackupHash.h"
#include "PerfectHash.h"

#include <fstream>

#define EXPECTED_ARGC 2

int main(int argc, char **argv) {

    std::string fileName;

    PerfectHash* table = new PerfectHash;

    if (argc == EXPECTED_ARGC) {
        fileName = argv[1];
    } else {
        std::cout << "Not enough command line arguments." << std::endl;
        return 0;
    }

    std::ifstream file(fileName.c_str());
    int numCities = 0;

    if (file.good()) {
        std::string city;
        std::string coords;

        while (getline(file, city)) {
            getline(file, coords);
            table->Map(city, coords);
            std::cout << table->Value(city) << std::endl;
            numCities++;
        }

    } else {

        std::cout << "File was not opened." << std::endl;
        return 0;

    }

    delete table;
    table = NULL;

    std::cout << numCities << " cities found" << std::endl;

    return 0;
}