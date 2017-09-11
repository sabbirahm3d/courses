/* File:    HashGen.h
 * Project: CMSC 341: Project 5, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    5/11/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * Declaration of the HashGen class. This class initializes the numerical
 * constants and performs all the computations required for hashing values by
 * the Perfect Hashing schemes.
 */

#ifndef HASHGEN_H
#define HASHGEN_H

#include <iostream>
#include <stdlib.h> // for rand, srand
#include <string>

// constant primes for universal hashing functions
const int PRIME1 = 16890581;
const int PRIME2 = 17027399;

typedef unsigned long long big_int;

class HashGen {

public:

    /* ******************** Constructors ******************** */

    /* HashGen() - Default constructor
     * Preconditions: None
     * Postconditions: Initializes hash values and container sizes */

    HashGen();

    /* ******************** Destructors ******************** */

    /* ~HashGen() - Default destructor
     * Preconditions: None
     * Postconditions: Resets hash values and container sizes */

    ~HashGen();

    /* ******************** Public methods ******************** */

    /* SetSize()
     * Preconditions: None
     * Postconditions: Sets the size of the container */

    void SetSize(int);

    /* SetHashValues()
     * Preconditions: None
     * Postconditions: Sets the hash values */

    void SetHashValues(big_int, big_int, big_int);

    /* Seed()
     * Preconditions: None
     * Postconditions: Seeds the pseudo-random number generator */

    void Seed(unsigned int);

    /* RandomInt()
     * Preconditions: None
     * Postconditions: Generates a random number in the given range */

    big_int RandomInt(int, big_int);

    /* Hash()
     * Preconditions: The string has to be unique
     * Postconditions: Hashes string values and returns the key to it */

    big_int Hash(std::string);

    /* HashValues()
     * Preconditions: None
     * Postconditions: Prints out the values and constants used for the hash
       functions */

    void HashValues();

private:

    /* ******************** Private hashing methods ******************** */

    /* HashStr()
     * Preconditions: None
     * Postconditions: Converts string value to a number using the hashing
       function */

    big_int HashStr(std::string);

    /* ******************** Private attributes ******************** */

    int m_size;
    big_int m_a, m_b, m_c;

};

#endif