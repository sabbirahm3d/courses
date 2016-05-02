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


#define PRIME1 16890581
#define PRIME2 = 17027399

/* ******************** Constructors ******************** */

/* MMheap() - Default constructor
 * Initializes the heap vector */

PerfectHash::PerfectHash() {

    for (int i = 0; i < (bigN); i++) {
        table.push_back(NULL);
    }

}

PerfectHash::~PerfectHash() {

    for (unsigned int i = 0; i < table.size(); i++)
        if (table[i] != NULL) {
            delete table[i];
        }

    for (unsigned int i = 0; i < backups.size(); i++)
        if (backups[i] != NULL)
            delete backups[i];

    table.resize(0);
    backups.resize(0);

}


int PerfectHash::ASCII(std::string city) {

    int c = RandomInt();
    int sum = 0;

    for (unsigned int i = 0; i < city.size(); ++i) {
        sum += (int) (pow(c, i) * city[i]);
    }

    return HashFunc(sum % PRIME1);

}


int PerfectHash::RandomInt() { return rand() % (PRIME1 - 1) + 1; }


int PerfectHash::HashFunc(int value) {

    int a = RandomInt();
    int b = RandomInt();

    return ((a * value + b) % PRIME1) % bigN;

}

std::string PerfectHash::Value(std::string city) {

    int hash = (ASCII(city) % bigN);

    BackupHash *newTable = new BackupHash;

    while (table[hash] != NULL && (table[hash])->GetCity() != city) {
        newTable->Value(city);
        hash = (hash + 1);
    }

    backups.push_back(newTable);

    if (table[hash] == NULL)
        return "";

    else
        return table[hash]->GetCoords();

}


void PerfectHash::Map(std::string city, std::string coords) {

    int hash = (ASCII(city) % bigN);

    BackupHash *newTable = new BackupHash;

    while (table[hash] != NULL && table[hash]->GetCity() != city) {
        newTable->Map(city, coords);
        hash = (hash + 1);
    }

    backups.push_back(newTable);

    if (table[hash] != NULL)
        delete table[hash];

    table[hash] = new Pair(city, coords);

    std::cout << city << std::endl;

}
