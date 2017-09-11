/* File:    BackupHash.h
 * Project: CMSC 341: Project 5, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    5/11/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * Declaration of the BackupHash class. This class implements the secondary
 * hash tables that stores and values after collisions in the primary hash
 * table in the perfect hashing scheme.
 */

#ifndef BACKUPHASH_H
#define BACKUPHASH_H

#include <vector>

#include "Pair.h"
#include "HashGen.h"

class BackupHash {
public:

    /* ******************** Constructors ******************** */

    /* BackupHash() - Default constructor
     * Preconditions: None
     * Postconditions: Initializes member variables and the hash generator */

    BackupHash();

    /* ******************** Destructors ******************** */

    /* ~BackupHash() - Default destructor
     * Preconditions: None
     * Postconditions: Frees memory allocated by the containers and hash
       generator objects */

    ~BackupHash();

    /* ******************** Public methods ******************** */

    /* Enqueue()
     * Preconditions: None
     * Postconditions: Appends to the temporary vector of Pair objects waiting
       to be mapped */

    void Enqueue(Pair *);

    /* InitTable()
     * Preconditions: None
     * Postconditions: Initialize the secondary table with the number of
       buckets and other member variables */

    void InitTable();

    /* Dump()
     * Preconditions: None
     * Postconditions: Prints out the current values stored in the container */

    void Dump();

    /* Value()
     * Preconditions: None
     * Postconditions: Prints and returns the coordinates mapped with the
       inputted city */

    std::string Value(std::string);

    /* Size()
     * Preconditions: None
     * Postconditions: Returns size of the temporary vector of all the Pairs
       passed */

    unsigned int Size();

    /* Tries()
     * Preconditions: None
     * Postconditions: Returns number of hash functions attempted */

    unsigned int Tries();

private:

    /* ******************** Private methods ******************** */

    /* Map()
     * Preconditions: None
     * Postconditions: Maps cities with their locations in the custom hash
       table containers, and returns true if mapped without collisions */

    bool Map();

    /* Rehash()
     * Preconditions: None
     * Postconditions: Increments seed and hash values */

    void Rehash();

    /* ******************** Private attributes ******************** */

    HashGen *generator;
    std::vector<Pair *> temp, backupTable;

    big_int c, a, b;
    unsigned int tries, m_size, bucketSize;

};

#endif