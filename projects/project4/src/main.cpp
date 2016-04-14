#include "MMHeap.h"
#include <fstream>

#include <cstdlib>

int main(int argc, char **argv) {

    MMHeap<int> *theHeap3 = new MMHeap<int>;
    MMHeap<int> theHeap;
    std::string filename;

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
            theHeap3->insert(atoi(line.c_str()));
        }

    } else {

        std::cout << "File was not opened." << std::endl;
        return 0;

    }

    theHeap3->dump();

    std::cout << "*** Insert 18, 94, 74. ***" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    theHeap.insert(18);
    theHeap.insert(94);
    theHeap.insert(74);
    theHeap.dump();

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "*** Then deleteMax. ***" << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    theHeap.deleteMax();
    theHeap.dump();


    std::cout << "----------------------------------------" << std::endl;
    std::cout << "*** Make the min-max heap in Figure 6.57. ***" << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    theHeap.dump();

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "*** Then insert 53, 57, 13, 12, 9, 10. ***" << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    theHeap.insert(53);
    theHeap.insert(57);
    theHeap.insert(13);
    theHeap.insert(12);
    theHeap.insert(9);
    theHeap.insert(10);
    theHeap.dump();

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "*** Then call deleteMin 3 times. ***" << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    theHeap.deleteMin();
    theHeap.deleteMin();
    theHeap.deleteMin();
    theHeap.dump();

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "*** Then call deleteMax 3 times. ***" << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    theHeap.deleteMax();
    theHeap.deleteMax();
    theHeap.deleteMax();
    theHeap.dump();

    delete theHeap3;

    return 0;
}