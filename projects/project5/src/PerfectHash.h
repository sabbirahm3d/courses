/* File:    MMheap.h
 * Project: CMSC 341: Project 4, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    4/23/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * The header file for the MMheap class. MMheap is a templated class with its
 * data type templated as DataType and std::less is used to determine
 * relationships between nodes in the structure
 */

#ifndef PERFECTHASH_H
#define PERFECTHASH_H

#include <iostream>
#include <vector>

#include "BackupHash.h"

class PerfectHash {

public:

    /* ******************** Constructors ******************** */

    /* MMheap() - Default constructor
     * Preconditions: None
     * Postconditions: None */

    PerfectHash();


    /* MMheap() - Default constructor
     * Preconditions: None
     * Postconditions: None */

    ~PerfectHash();

    int ASCII(std::string);

    std::string Value(std::string);

    void Map(std::string, std::string);

private:

    std::vector<Pair *> table;

};


#endif