/* File:    MMheap.cpp
 * Project: CMSC 341: Project 4, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    4/23/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * The implementation file for the MMheap class
 */

#include "PerfectHash.h"
#include "HashException.h"


/* ******************** Constructors ******************** */

/* MMheap() - Default constructor
 * Initializes the heap vector */

PerfectHash::PerfectHash() { table.reserve(PRIME1 * PRIME1); }

PerfectHash::~PerfectHash() {

    for (int i = 0; i < PRIME1; i++)
        if (table[i] != NULL)
            delete table[i];

    table.resize(0);

}


int PerfectHash::ASCII(std::string city) {

    int sum = 0;

    for (unsigned int i = 0; i < city.size(); i++) {
        sum += city[i];

    }

    return sum;

}


std::string PerfectHash::Value(std::string city) {

    int hash = (ASCII(city) % PRIME1);

    while (table[hash] != NULL && (table[hash])->GetCity() != city)
        hash = (hash + 1);

    if (table[hash] == NULL)
        return "";

    else
        return table[hash]->GetCoords();

}


void PerfectHash::Map(std::string city, std::string coords) {

    int hash = (ASCII(city) % PRIME1);

    while (table[hash] != NULL && table[hash]->GetCity() != city) {
//        std::cout << "COLLISION AT " << hash << std::endl;
        hash = (hash + 1);
    }
    if (table[hash] != NULL)
        delete table[hash];

    table[hash] = new Pair(city, coords);

//    std::cout << hash << std::endl;

}
