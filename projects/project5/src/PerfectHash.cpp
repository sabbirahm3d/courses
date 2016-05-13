/* File:    PerfectHash.cpp
 * Project: CMSC 341: Project 5, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    5/11/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * Implementation of the PerfectHash class.
 */

#include "PerfectHash.h"


/* ******************** Constructors ******************** */

/* PerfectHash()
 * Initializes the containers for the hash tables, its member variables and
   the hash generator, and maps the inputted vector of file data */

PerfectHash::PerfectHash(std::vector<Pair *> cities) :
        generator(new HashGen()), m_size((int) cities.size()) {

    // generate random hash values in the range to initialize hashing functions
    InitHash();

    // initialize the containers' sizes
    primaryTable.resize(m_size);
    backupTable.resize(m_size);

    // fill up primaryTable with the file data
    for (int i = 0; i < m_size; i++) {
        Map(cities[i]);
    }

    // begin creating secondary containers
    for (int i = 0; i < m_size; i++) {
        if (backupTable[i] != NULL) {
            backupTable[i]->InitTable();
        }
    }

}


/* ******************** Destructors ******************** */

/* ~PerfectHash()
 * Frees memory allocated by the containers and hash generator objects */

PerfectHash::~PerfectHash() {

    for (int i = 0; i < m_size; i++) {

        // if the primary table contains a secondary table
        if (backupTable[i] != NULL) {

            delete backupTable[i];
            backupTable[i] = NULL;

        } else {

            if (primaryTable[i] != NULL) {

                delete primaryTable[i];
                primaryTable[i] = NULL;

            }

        }
    }

    // reset member variables
    c = a = b = 0;
    m_size = 0;

    delete generator;
    generator = NULL;

}


/* ******************** Public methods ******************** */

/* Stats()
 * Prints out the statistics on the hash tables */

void PerfectHash::Stats() {

    // print out the constants and hash values used for the structure
    generator->HashValues();

    std::cout << std::endl << "Number of cities: " << m_size << std::endl;

    // number of primary table slots with hashTries
    int filledSlots[10] = {0};

    // number of number of secondary hash tables that tried hash functions
    int hashTries[10] = {0};

    int maxIndex, secondaryCount;
    double totalBins;
    maxIndex = secondaryCount = totalBins = 0;

    // iterate through the primary table
    for (int i = 0; i < m_size; i++) {

        if (primaryTable[i] == NULL) {

            filledSlots[0]++;

        } else {

            // if filled
            if (backupTable[i] != NULL) {

                if (backupTable[i]->Size() < 10)
                    filledSlots[backupTable[i]->Size()]++;

            } else {

                filledSlots[1]++;

            }

        }

        // move on to the backup hash tables
        if (backupTable[i] != NULL) {

            if (backupTable[i]->Tries() < 11)
                hashTries[backupTable[i]->Tries()]++;

            // to avoid segfaults, swap out the outlying indices if empty
            if (backupTable[maxIndex] == NULL) { maxIndex = i; }
            else if (backupTable[maxIndex]->Size()
                     < backupTable[i]->Size()) { maxIndex = i; }

            // count all secondary hash tables
            secondaryCount++;
            totalBins += backupTable[i]->Tries();

        }

    }

    // begin printing the statistics after the arrays have been filled
    std::cout << "Maximum collisions: " <<
    backupTable[maxIndex]->Size() << std::endl;

    for (unsigned int i = 0; i < 10; i++) {
        std::cout << "# Primary slots with " << i << " cities: " <<
        filledSlots[i] << std::endl;
    }

    std::cout << "\n** Cities in the slot with most collisions **" << std::endl;
    backupTable[maxIndex]->Dump();

    for (unsigned int i = 1; i < 11; i++) {
        std::cout << "# Secondary hash tables trying " << i <<
        " hash functions: " << hashTries[i - 1] << std::endl;
    }

    std::cout << "Number of secondary hash tables with more than one item: " <<
    secondaryCount << std::endl << "Average # of hash functions tried: " <<
    (totalBins / secondaryCount) + 1 << std::endl;

}


/* Value()
 * Prints and returns the coordinates mapped with the inputted city */

std::string PerfectHash::Value(std::string city) {

    // get the key
    big_int key = generator->Hash(city);

    // see if we can find the place
    if (primaryTable[key] == NULL) {

        return "";

    } else {

        // if found
        if (primaryTable[key]->m_city == city) {

            std::cout << "Key = " << key << std::endl;
            std::cout << primaryTable[key];
            return primaryTable[key]->m_coords;

            // look for the secondary table if it exists
        } else if (backupTable[key] != NULL) {

            return backupTable[key]->Value(city);

            // value does not exist
        } else {

            std::cout << "None found";
            return "";

        }
    }

}


/* ******************** Private methods ******************** */

/* InitHash()
 * Generates initial seed and hash values */

void PerfectHash::InitHash() {

    // initial seed of 0
    generator->Seed(0);

    // pass in size of the container to prevent overflows
    generator->SetSize(m_size);

    // generate the random hash values
    c = generator->RandomInt(1, PRIME1);
    a = generator->RandomInt(1, PRIME2);
    b = generator->RandomInt(0, PRIME2);
    generator->SetHashValues(a, b, c);

}


/* Map()
 * Maps cities with their locations in the custom hash table containers */

void PerfectHash::Map(Pair *city) {

    big_int index = generator->Hash(city->m_city);

    // no collisions, emtpy bucket
    if (primaryTable[index] == NULL) {
        primaryTable[index] = city;

        // a collision
    } else {

        // check if the secondary slot bucket is empty
        if (backupTable[index] == NULL) {

            // create a new secondary table
            backupTable[index] = new BackupHash();

            // append both the value and the collided one
            backupTable[index]->Enqueue(primaryTable[index]);
            backupTable[index]->Enqueue(city);

            // if collision on a secondary slot
        } else {

            // append the collided value
            backupTable[index]->Enqueue(city);

        }
    }

}
