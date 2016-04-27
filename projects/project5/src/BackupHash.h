#include <cstdlib>

#include "Pair.h"

const int TABLE_SIZE = 128;

class BackupHash {
private:
    Pair **table;
public:
    BackupHash() {
        table = new Pair *[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = NULL;
    }

    int ascii(std::string city) {
        int sum = 0;
        for (unsigned int i = 0; i < city.size(); i++) {
            sum += city[i];
        }
        return sum;
    }

    int get(std::string city) {
        int hash = (ascii(city) % TABLE_SIZE);
        while (table[hash] != NULL && table[hash]->getCity() != city)
            hash = (hash + 1) % TABLE_SIZE;
        if (table[hash] == NULL)
            return -1;
        else
            return table[hash]->getCoords();
    }

    void put(std::string city, int coords) {
        int hash = (ascii(city) % TABLE_SIZE);
        while (table[hash] != NULL && table[hash]->getCity() != city)
            hash = (hash + 1) % TABLE_SIZE;
        if (table[hash] != NULL)
            delete table[hash];
        table[hash] = new Pair(city, coords);
    }

    ~BackupHash() {
        for (int i = 0; i < TABLE_SIZE; i++)
            if (table[i] != NULL)
                delete table[i];
        delete[] table;
    }
};