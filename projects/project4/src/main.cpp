/* File:    main.cpp
 * Project: CMSC 341: Project 4, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    4/23/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * Driver script to test the MMheap class
 */

#include "MMheap.h"

#include <fstream>
#include <cstdlib>

#define EXPECTED_ARGC 2

int main(int argc, char **argv) {

    MMheap<int> *int_heap = new MMheap<int>;
    MMheap<std::string> *test_heap = new MMheap<std::string>;
    std::string filename;

    test_heap->dump();

    if (argc == EXPECTED_ARGC) {
        filename = argv[1];
    } else {
        std::cout << "Not enough command line arguments." << std::endl;
        return 0;
    }

    std::ifstream file(filename.c_str());

    if (file.good()) {
        std::string line;

        while (getline(file, line)) {
            int_heap->insert(atoi(line.c_str()));
        }

    } else {

        std::cout << "File was not opened." << std::endl;
        return 0;

    }

    int_heap->dump();

    std::cout << "Call delete_min 10 times" << std::endl;

    for (int ii = 0; ii < 10; ii++) {
        int_heap->deleteMin();
    }


    int_heap->dump();

    std::cout << "Call delete_max 10 times" << std::endl;

    for (int ii = 0; ii < 30; ii++) {
        int_heap->deleteMax();
    }

    int_heap->dump();

    std::cout << "Deleting the heaps..." << std::endl;

    delete int_heap;
    delete test_heap;

    return 0;
}