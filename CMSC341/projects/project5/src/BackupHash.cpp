/* File:    BackupHash.cpp
 * Project: CMSC 341: Project 5, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    5/11/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * Implementation of the BackupHash class.
 */

#include "BackupHash.h"


/* ******************** Constructors ******************** */

/* BackupHash() - Default constructor
 * Initializes member variables and the hash generator */

BackupHash::BackupHash() :
        generator(new HashGen()),
        tries(0),
        m_size(0),
        bucketSize(0) { Rehash(); }


/* ******************** Destructors ******************** */

/* ~BackupHash() - Default destructor
 * Frees memory allocated by the containers and hash generator objects */

BackupHash::~BackupHash() {

    for (unsigned int i = 0; i < m_size; i++) {
        delete temp[i];
    }

    c = a = b = 0;
    m_size = bucketSize = tries = 0;

    delete generator;
    generator = NULL;

}


/* ******************** Public methods ******************** */

/* Enqueue()
 * Appends to the temporary vector of Pair objects waiting to be mapped */

void BackupHash::Enqueue(Pair *city) { temp.push_back(city); }


/* Dump()
 * Prints out the current values stored in the container */

void BackupHash::Dump() {

    for (unsigned int i = 0; i < temp.size(); i++) {
        std::cout << temp[i];
    }

}


/* InitTable()
 * Initialize the secondary table with the number of buckets and other member
   variables */

void BackupHash::InitTable() {

    // update size and bucketSize as the temporary container expands
    m_size = temp.size();
    bucketSize = m_size * m_size;
    backupTable.reserve(bucketSize);

    // while all the buckets have not been filled yet
    while (!Map()) {

        for (unsigned int i = 0; i < bucketSize; i++) {
            backupTable[i] = NULL;
        }

        // try a different hash function
        Rehash();

    }

}


/* Size()
 * Returns size of the temporary vector of all the Pairs passed */

unsigned int BackupHash::Size() { return m_size; }


/* Tries()
 * Returns number of hash functions attempted */

unsigned int BackupHash::Tries() { return tries; }


/* Value()
 * Prints and returns the coordinates mapped with the inputted city */

std::string BackupHash::Value(std::string city) {

    // hash the input string
    big_int key = generator->Hash(city);

    // if value not found
    if (backupTable[key]->m_city != city || backupTable[key] == NULL) {

        std::cout << "None found";
        return "";

        // return value found
    } else {
        std::cout << backupTable[key];
        return backupTable[key]->m_coords;
    }

}


/* ******************** Private methods ******************** */

/* Rehash()
 * Increments seed and hash values */

void BackupHash::Rehash() {

    // pass in the incremented seed
    generator->Seed(tries);

    // generate the random hash values
    c = generator->RandomInt(1, PRIME1);
    a = generator->RandomInt(1, PRIME2);
    b = generator->RandomInt(0, PRIME2);
    generator->SetHashValues(a, b, c);

}


/* Map()
 * Maps cities with their locations in the custom hash table containers, and
   returns true if mapped without collisions */

bool BackupHash::Map() {

    // pass in final size of the buckets in the secondary table to initialize
    // the hash generator
    generator->SetSize(bucketSize);

    for (unsigned int i = 0; i < m_size; i++) {

        big_int key = generator->Hash(temp[i]->m_city);

        // collision
        if (backupTable[key] != NULL) {

            tries++;
            return false;

            // map the value
        } else {

            backupTable[key] = temp[i];

        }
    }

    return true;

}
