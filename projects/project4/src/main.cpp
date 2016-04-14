#include "MMHeap.h"
#include <fstream>

#include <cstdlib>

int main(int argc, char **argv) {

    MMHeap<std::string> *int_heap = new MMHeap<std::string>;
    MMHeap<std::string> *test_heap = new MMHeap<std::string>;
    std::string filename;

    test_heap->dump();

    if (argc == 2) {
        filename = argv[1];
    } else {
        std::cout << "Not enough command line arguments." << std::endl;
        return 0;
    }

    std::ifstream file(filename.c_str());

    if (file.is_open()) {
        std::string line;

        while (getline(file, line)) {
            int_heap->insert((line));
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

    delete int_heap;

    return 0;
}