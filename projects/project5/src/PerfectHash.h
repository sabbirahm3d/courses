/* File:    PerfectHash.h
 * Project: CMSC 341: Project 5, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    5/11/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * Declaration of the PerfectHash class. This class initializes the primary
 * hash tables using the hashing methods provided by the HashGen class and
 * creates secondary back up tables in case of collisions.
 */

#ifndef PERFECTHASH_H
#define PERFECTHASH_H

#include "BackupHash.h"


class PerfectHash {
public:

    /* ******************** Constructors ******************** */

    /* PerfectHash() - Default constructor
     * Preconditions: None
     * Postconditions: Initializes the containers for the hash tables, its
       member variables and the hash generator, and maps the inputted vector
       of file data */

    PerfectHash(std::vector<Pair *>);

    /* ******************** Constructors ******************** */

    /* PerfectHash() - Default destructor
     * Preconditions: None
     * Postconditions: Frees memory allocated by the containers and hash
       generator objects */

    ~PerfectHash();

    /* ******************** Public methods ******************** */

    /* Stats()
     * Preconditions: None
     * Postconditions: Prints out the statistics on the hash tables */

    void Stats();

    /* Value()
     * Preconditions: None
     * Postconditions: Prints and returns the coordinates mapped with the
       inputted city */

    std::string Value(std::string);

private:

    /* ******************** Private methods ******************** */

    /* Map()
     * Preconditions: None
     * Postconditions: Maps cities with their locations in the custom hash
       table containers */

    void Map(Pair *);

    /* InitHash()
     * Preconditions: None
     * Postconditions: Generates initial seed and hash values */

    void InitHash();

    /* ******************** Private attributes ******************** */

    HashGen *generator;
    std::vector<Pair *> primaryTable;
    std::vector<BackupHash *> backupTable;

    int m_size;
    big_int c, a, b;

};

#endif