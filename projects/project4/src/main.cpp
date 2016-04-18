#include "MMHeap.h"

#include <fstream>
#include <cstdlib>

#define EXPECTED_ARGC 2

int main(int argc, char **argv) {

    MMHeap<int> *int_heap = new MMHeap<int>;
    MMHeap<std::string> *test_heap = new MMHeap<std::string>;
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

    for (int ii = 0; ii < 10; ii++) {
        int_heap->deleteMax();
    }

    int_heap->dump();

//    std::cout << "Attempt to remove from empty heap" << std::endl;
//
//    for (int ii = 0; ii < 580; ii++) {
//        int_heap->deleteMin();
//    }
//
//    int_heap->dump();

    delete int_heap;

    return 0;
}