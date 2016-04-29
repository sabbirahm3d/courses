#include <cstdlib>
#include <iostream>

#include "Pair.h"

const int PRIME1 = 1000;

class BackupHash {
private:
    Pair **table;
public:
    BackupHash() {
        table = new Pair *[PRIME1];
        for (int i = 0; i < PRIME1; i++)
            table[i] = NULL;
    }

    ~BackupHash() {
        for (int i = 0; i < PRIME1; i++)
            if (table[i] != NULL)
                delete table[i];
        delete[] table;
    }

    int ascii(std::string city) {
        int sum = 0;
        for (unsigned int i = 0; i < city.size(); i++) {
            sum += city[i];
        }
        return sum;
    }

    int get(std::string city) {
        int hash = (ascii(city) % PRIME1);
        while (table[hash] != NULL && table[hash]->getCity() != city)
            hash = (hash + 1) % PRIME1;
        if (table[hash] == NULL)
            return -1;
        else
            return table[hash]->getCoords();
    }

    void put(std::string city, int coords) {
        int hash = (ascii(city) % PRIME1);
        while (table[hash] != NULL && table[hash]->getCity() != city)
            hash = (hash + 1) % PRIME1;
        if (table[hash] != NULL)
            delete table[hash];
        table[hash] = new Pair(city, coords);
        std::cout << hash << std::endl;
    }

};