/* File:    MMheap.h
 * Project: CMSC 341: Project 4, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    4/23/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * The header file for the MMheap class
 */

#ifndef MMHEAP_H
#define MMHEAP_H

#include <iostream>
#include <vector>

template<typename DataType, typename Compare = std::less<DataType> >
class MMheap {

public:

    /* ******************** Constructors ******************** */

    /* MMheap() - Default constructor
     * Preconditions: None
     * Postconditions: None */

    MMheap();


    /* ******************** Destructors ******************** */

    /* MMheap() - Default destructor
     * Preconditions: None
     * Postconditions: Clears the vector containing the  */

    ~MMheap();


    /* ******************** Public methods ******************** */

    /* size()
     * Preconditions: None
     * Postconditions: Returns the size of the heap */

    unsigned int size() const;

    /* insert()
     * Preconditions: None
     * Postconditions: Inserts node into the heap */

    void insert(const DataType &);

    /* getMax()
     * Preconditions: None
     * Postconditions: Returns the maximum value of the heap */

    const DataType &getMax() const;

    /* getMin()
     * Preconditions: None
     * Postconditions: Returns the minimum value of the heap */

    const DataType &getMin() const;

    /* deleteMax()
     * Preconditions: None
     * Postconditions: Pops the maximum value of the heap */

    DataType deleteMax();

    /* deleteMin()
     * Preconditions: None
     * Postconditions: Pops the minimum value of the heap */

    DataType deleteMin();

    /* dump()
     * Preconditions: None
     * Postconditions: Iterates through and prints the heap in level order */

    void dump() const;


private:

    /* ******************** Private helper methods ******************** */

    /* parent()
     * Preconditions: None
     * Postconditions: Stores the index of the parent node */

    unsigned int parent(unsigned int);

    /* isOnMinLevel()
     * Preconditions: None
     * Postconditions: Determines if node is on an even level */

    bool isOnMinLevel(unsigned int);

    /* percolate()
     * Preconditions: None
     * Postconditions: Bootstrap for percolating nodes up through the
       minimum or maximum levels */

    void percolate(unsigned int);

    /* percolate() - overloaded percolating function
     * Preconditions: None
     * Postconditions: Percolates nodes up through the minimum or maximum
       levels */

    void percolate(unsigned int, bool);

    /* trickle()
     * Preconditions: None
     * Postconditions: Bootstrap for trickling nodes down through the minimum
       or maximum levels */

    void trickle(unsigned int);

    /* trickle() - overloaded trickling function
     * Preconditions: None
     * Postconditions: Trickles nodes down through the minimum or maximum
       levels */

    void trickle(unsigned int, bool);

    /* findMaxIndex()
     * Preconditions: None
     * Postconditions: Finds the index for the maximum value of the heap */

    unsigned int findMaxIndex() const;

    /* findMaxIndex()
     * Preconditions: None
     * Postconditions: Finds the index for the maximum value of the heap */

    void deleteElement(unsigned int);


    /* ******************** Private attributes ******************** */

    std::vector<DataType> *heap;
    Compare less;

};


#include "MMheap.cpp"

#endif