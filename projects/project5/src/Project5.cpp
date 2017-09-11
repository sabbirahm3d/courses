/* File:    Project5.cpp
 * Project: CMSC 341: Project 5, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    5/11/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * Driver script to test the PerfectHash class.
 */

#include <fstream>  // for file IO

#include "Pair.h"
#include "PerfectHash.h"

// for testing the lookup of Value()
const std::string SEARCH_FOR_CITY = "Ringgold, GA";
const int EXPECTED_ARGC = 2;


int main(int argc, char **argv) {

    std::string filename;
    // temporary vector to hold all file data
    std::vector<Pair *> *cities = new std::vector<Pair *>;

    if (argc == EXPECTED_ARGC) {

        filename = argv[1];

    } else {

        std::cout << "Not enough command line arguments." << std::endl;
        return 1;

    }

    std::ifstream file(filename.c_str());

    if (file.good()) {

        std::string city, coords;

        while (getline(file, city) && getline(file, coords)) {
            cities->push_back(new Pair(city, coords));
        }

    }

    // instantiate PerfectHash object
    PerfectHash *primaryHash = new PerfectHash(*cities);

    // print out statistics on the table
    primaryHash->Stats();

    // look up the value mapped to the key
    primaryHash->Value(SEARCH_FOR_CITY);

    delete cities;
    cities = NULL;
    delete primaryHash;
    primaryHash = NULL;

}
