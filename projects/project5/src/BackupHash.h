#include <cstdlib>
#include <iostream>
#include <time.h>
#include <vector>

#include "Pair.h"

const int PRIME1 = 1000;
const int PRIME2 = 5435;

class BackupHash {
public:

/* ******************** Constructors ******************** */

/* MMheap() - Default constructor
 * Initializes the heap vector */

    BackupHash() {

        for (int i = 0; i < PRIME2; i++) {
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

        int hash = (ASCII(city) % PRIME2);

        while (table[hash] != NULL && (table[hash])->GetCity() != city)
            hash = (hash + 1);

        if (table[hash] == NULL)
            return "";

        else
            return table[hash]->GetCoords();

    }


    void Map(std::string city, std::string coords) {

        int hash = (ASCII(city) % PRIME2);
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