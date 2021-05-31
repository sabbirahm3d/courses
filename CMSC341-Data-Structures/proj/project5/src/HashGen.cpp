/* File:    HashGen.cpp
 * Project: CMSC 341: Project 5, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    5/11/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * Implementation of the HashGen class.
 */

#include "HashGen.h"


/* ******************** Constructors ******************** */

/* HashGen()
 * Initializes hash values and container sizes */

HashGen::HashGen() : m_size(0), m_a(0), m_b(0), m_c(0) { }


/* ******************** Destructors ******************** */

/* ~HashGen()
 * Resets hash values and container sizes */

HashGen::~HashGen() {

    m_size = 0;
    m_a = m_b = m_c = 0;

}


/* ******************** Public methods ******************** */

/* SetSize()
 * Sets the size of the container */

void HashGen::SetSize(int size) { m_size = size; }


/* SetHashValues()
 * Sets the hash values */

void HashGen::SetHashValues(big_int a, big_int b, big_int c) {

    m_a = a;
    m_b = b;
    m_c = c;

}


/* Seed()
 * Seeds the pseudo-random number generator */

void HashGen::Seed(unsigned int seed) { srand(seed); }


/* RandomInt()
 * Generates a random number in the given range */

big_int HashGen::RandomInt(int lower, big_int upper) {

    return rand() % upper + lower;

}


/* Hash()
 * Hashes string values and returns the key to it */

big_int HashGen::Hash(std::string value) {

    return (((m_a * HashStr(value)) + m_b) % PRIME2) % m_size;

}


/* HashStr()
 * Converts string value to a number using the hashing function */

big_int HashGen::HashStr(std::string city) {

    big_int sum = 0;

    for (big_int i = 0; i < city.size(); i++) {
        sum = ((sum * m_c) + city[i]) % PRIME1;
    }

    return sum;

}


/* HashValues()
 * Prints out the values and constants used for the hash functions */

void HashGen::HashValues() {

    std::cout << "PRIME1: " << PRIME1 << std::endl;
    std::cout << "PRIME2: " << PRIME2 << std::endl;
    std::cout << "a: " << m_a << std::endl;
    std::cout << "b: " << m_b << std::endl;
    std::cout << "c: " << m_c << std::endl;

}