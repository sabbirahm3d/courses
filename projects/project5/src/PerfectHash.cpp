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

PerfectHash::PerfectHash(int size) : m_size(size), tries(0) {

    for (int i = 0; i < m_size; i++) {
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


//big_int PerfectHash::Hash(std::string city) {
//
//    big_int c = RandomInt(1, PRIME2);
//    int sum = 0;
//
//    for (unsigned int i = 0; i < city.size(); ++i) {
//        sum += (int) (pow(c, i) * city[i]);
//    }
//
//    return HashFunc(sum % PRIME2);
//
//}
//
//
//big_int PerfectHash::RandomInt(int lower, big_int upper) {
//
//    srand(tries);
////    tries++;
//    return rand() % upper + lower;
//
//}
//
//
//big_int PerfectHash::HashFunc(int value) {
//
//    big_int a = RandomInt(1, PRIME1);
//    big_int b = RandomInt(0, PRIME1 - 1);
////    std::cout << a << " " << b << std::endl;
//
//    return ((big_int) (a * value + b) % PRIME1) % m_size;
//
//}

std::string PerfectHash::Value(std::string city) {

    big_int hash = BackupHash::Hash(city, m_size);

    BackupHash *newTable = new BackupHash(10);

    while (table[hash] != NULL && (table[hash])->GetCity() != city) {
        newTable->Value(city);
        tries++;
        hash = BackupHash::Hash(city, m_size);
    }

    backups.push_back(newTable);

    if (table[hash] == NULL)
        return "";

    else
        return table[hash]->GetCoords();

}


void PerfectHash::Map(std::string city, std::string coords) {

    big_int hash = BackupHash::Hash(city, m_size);

    std::cout << hash << std::endl;
    
    BackupHash *newTable = new BackupHash(10);

    if (table[hash] != NULL && table[hash]->GetCity() != city) {
        newTable->Map(city, coords);
        tries++;
        hash = BackupHash::Hash(city, m_size);
        collisions++;
    }

    backups.push_back(newTable);

    if (table[hash] != NULL)
        delete table[hash];

    table[hash] = new Pair(city, coords);


}
