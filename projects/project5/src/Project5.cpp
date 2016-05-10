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

    if (argc == EXPECTED_ARGC) {
        fileName = argv[1];
    } else {
        std::cout << "Not enough command line arguments." << std::endl;
        return 0;
    }

    std::ifstream file(fileName.c_str());
    int numCities = 0;

    if (file.good()) {
        std::string data;
        std::vector<std::string> *fileData = new std::vector<std::string>;
        std::string coords;

        while (getline(file, data)) {
            fileData->push_back(data);
            numCities++;
        }

        numCities = numCities / 2;

        PerfectHash *table = new PerfectHash(numCities);

        for (int i = 0; i < fileData->size() - 1; i++) {
            table->Map((*fileData)[i], (*fileData)[i + 1]);
//            std::cout << table->Value((*fileData)[i]) << std::endl;
        }

//        for (int i = 0; i < fileData->size() - 1; i++) {
////            table->Map((*fileData)[i], (*fileData)[i + 1]);
//            std::cout << table->Value((*fileData)[i]) << std::endl;
//        }
        std::cout << table->GetCollisions() << std::endl;
        std::cout << table->Value("Williamsburg, FL") << std::endl;

        delete table;
        table = NULL;
        delete fileData;
        fileData = NULL;

    } else {

        std::cout << "File was not opened." << std::endl;
        return 0;

    }


    std::cout << numCities << " cities found" << std::endl;

    return 0;
}