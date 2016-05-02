#include <cstdlib>
#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <vector>

#include "Pair.h"

const int bigN = 1000;
const int bigM = 5435;

class BackupHash {
public:

/* ******************** Constructors ******************** */

/* MMheap() - Default constructor
 * Initializes the heap vector */

    BackupHash() {

        for (int i = 0; i < bigM; i++) {
            table.push_back(NULL);
        }
    }

    ~BackupHash() {

        for (unsigned int i = 0; i < table.size(); i++)
            if (table[i] != NULL)
                delete table[i];

        table.resize(0);

    }


    int ASCII(std::string city) {

        int sum = 0;

        for (unsigned int i = 0; i < city.size(); i++) {
            sum += city[i];

        }

        return sum;

    }


    std::string Value(std::string city) {

        int hash = (ASCII(city) % bigM);

        while (table[hash] != NULL && (table[hash])->GetCity() != city)
            hash = (hash + 1);

        if (table[hash] == NULL)
            return "";

        else
            return table[hash]->GetCoords();

    }


    void Map(std::string city, std::string coords) {

        int hash = (ASCII(city) % bigM);
//        std::cout << "BACK USED " << hash << std::endl;


        while (table[hash] != NULL && table[hash]->GetCity() != city) {
            hash = (hash + 1);
        }
        if (table[hash] != NULL)
            delete table[hash];

        table[hash] = new Pair(city, coords);

//    std::cout << hash << std::endl;

    }

private:

    std::vector<Pair *> table;


};