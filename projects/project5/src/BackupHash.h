#ifndef BACKUPHASH_H
#define BACKUPHASH_H

#include <cstdlib>
#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <vector>

#include "Pair.h"
//#include "PerfectHash.h"

#define PRIME1 16890581
#define PRIME2 17027399

typedef unsigned long big_int;

class BackupHash {
public:

/* ******************** Constructors ******************** */

/* MMheap() - Default constructor
 * Initializes the heap vector */

    BackupHash(int size) : m_size(size), tries(0) {

        for (int i = 0; i < m_size; i++) {
            table.push_back(NULL);
        }

    }


    ~BackupHash() {

        for (unsigned int i = 0; i < table.size(); i++)
            if (table[i] != NULL) {
                delete table[i];
            }

        table.resize(0);

    }

    static unsigned long Hash(std::string, int);

    static big_int RandomInt(int, big_int);

    static unsigned long HashFunc(int, int);

//    big_int Hash(std::string city) {
//
//        big_int c = RandomInt(1, PRIME2);
//        int sum = 0;
//
//        for (unsigned int i = 0; i < city.size(); ++i) {
//            sum += (int) (pow(c, i) * city[i]);
//        }
//
//        return HashFunc(sum % PRIME2);
//
//    }
//
//
//    big_int RandomInt(int lower, big_int upper) {
//
//        srand(tries);
////    tries++;
//        return rand() % upper + lower;
//
//    }
//
//
//    big_int HashFunc(int value) {
//
//        big_int a = RandomInt(1, PRIME1);
//        big_int b = RandomInt(0, PRIME1 - 1);
//
//        return ((big_int) (a * value + b) % PRIME1) % m_size;
//
//    }

    std::string Value(std::string city) {

        big_int hash = Hash(city, m_size);

        while (table[hash] != NULL && (table[hash])->GetCity() != city) {
            hash = Hash(city, m_size);
        }

        if (table[hash] == NULL)
            return "";

        else
            return table[hash]->GetCoords();

    }


    void Map(std::string city, std::string coords) {

        big_int hash = Hash(city, m_size);

        if (table[hash] != NULL && table[hash]->GetCity() != city) {
            hash = Hash(city, m_size);
        }

        if (table[hash] != NULL)
            delete table[hash];

        table[hash] = new Pair(city, coords);

        std::cout << "backup used" << std::endl;

    }

private:

    std::vector<Pair *> table;
    int m_size;
    unsigned int tries;


};


#endif