/* File:    MMheap.cpp
 * Project: CMSC 341: Project 4, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    4/23/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * The implementation file for the MMheap class
 */

#ifndef MMHEAP_CPP
#define MMHEAP_CPP

#include <math.h>

#include "MMheap.h"
#include "MyException.h"


/* ******************** Constructors ******************** */

/* MMheap() - Default constructor
 * Initializes the heap vector */

template<typename DataType, typename Compare>
MMheap<DataType, Compare>::MMheap() {
    heap = new std::vector<DataType>;
}


/* ******************** Destructors ******************** */

/* MMheap() - Default destructor
 * Empties and deletes the heap vector */

template<typename DataType, typename Compare>
MMheap<DataType, Compare>::~MMheap() {

    for (unsigned int i = 0; i < heap->size(); i++) {
        (*heap)[0] = (*heap)[i];
    }

    heap->clear();
    heap->resize(0);
    delete heap;
}


/* ******************** Public methods ******************** */

/* size()
 * Returns the size of the heap vector */

template<class DataType, class Compare>
unsigned int MMheap<DataType, Compare>::size() const {

    // size of the vector is the size of the heap structure
    return (heap->size());
}


/* insert()
 * Insert data into the heap */

template<class DataType, class Compare>
void MMheap<DataType, Compare>::insert(const DataType &value) {

    // push the value onto the end of the heap
    heap->push_back(value);

    // reorder the heap so that the min-max heap property holds true
    percolate((unsigned int) heap->size() - 1);
}


/* getMin()
 * Finds the minimum value of the heap */

template<class DataType, class Compare>
const DataType &MMheap<DataType, Compare>::getMin() const {

    // throw an exception if heap is empty
    try {
        if (!(heap->size()))
            throw MyException("Empty heaps don't have minimums");
    }

    catch (MyException &no_min) {
        std::cout << no_min.GetMessage() << std::endl;
    }

    return (*heap)[0];
}


/* getMax()
 * Finds the maximum value of the heap */

template<class DataType, class Compare>
const DataType &MMheap<DataType, Compare>::getMax() const {

    // returns the value stored at findMaxIndex
    return ((*heap)[findMaxIndex()]);
}


/* deleteMax()
 * Pops the maximum value off the heap */

template<class DataType, class Compare>
DataType MMheap<DataType, Compare>::deleteMax() {

    // throw an exception if the heap is empty
    try {
        if (!(heap->size()))
            throw MyException("No maximum element exists because there are no "
                                      "elements in the heap");
    }

    catch (MyException &emptyHeap) {
        std::cout << emptyHeap.GetMessage() << std::endl;
    }

    // save the maximum value's index
    unsigned int max = findMaxIndex();

    // save the maximum value
    DataType tempMax = (*heap)[max];

    deleteElement(max);

    return tempMax;
}


/* deleteMin()
 * Pops the minimum value off the heap */

template<class DataType, class Compare>
DataType MMheap<DataType, Compare>::deleteMin() {

    // throw an exception if the heap is empty
    try {
        if (!(heap->size()))
            throw MyException("No minimum element exists because there are no "
                                      "elements in the heap");
    }

    catch (MyException &emptyHeap) {
        std::cout << emptyHeap.GetMessage() << std::endl;
    }


    // Save the minimum value
    DataType tempMin = (*heap)[0];

    deleteElement(0);

    return tempMin;
}


/* dump()
 * Outputs statistics on the heap and also the heap itself in level-order
   printing */

template<class DataType, class Compare>
void MMheap<DataType, Compare>::dump() const {

    try {

        // throw exception if there is nothing to dump
        if (!(heap->size())) {
            throw MyException("Can't dump empty heap");
        }

        else {

            int level = 0;

            std::cout << "Size = " << size() << std::endl;
            std::cout << "Minimum = " << getMin() << std::endl;
            std::cout << "Maximum = " << getMax() << std::endl;

            // prints 'odd' when the log<base>2 of the size of the heap isn't
            // divisible by 2, and 'even' otherwise
            std::cout << "Last level is " <<
            (((int) (log2(size() - 1)) % 2) ? "odd" : "even")
            << std::endl << std::endl;

            for (unsigned int nodes = 0; nodes < heap->size(); ++nodes) {

                // print level after every 2^nodes iterations
                if (!((nodes + 1) % ((int) pow(2, level)))) {
                    std::cout << "------------------- Level " << level <<
                    " -------------------" << std::endl;
                    level++;
                }

                std::cout << "H[" << nodes << "] : " << (*heap)[nodes] <<
                std::endl;

            }
        }
    }

    catch (MyException &emptyHeap) {
        std::cout << emptyHeap.GetMessage() << std::endl;
    }

    std::cout << std::endl;
}


template<class DataType, class Compare>
unsigned int MMheap<DataType, Compare>::parent(unsigned int index) {
    return ((index - 1) / 2);
}


template<class DataType, class Compare>
unsigned int MMheap<DataType, Compare>::leftChild(unsigned int index) {
    return (2 * index + 1);
}


/**
 * @brief Returns @c true if the node specified by @c index is on a
 *        @e min-level.
 **/
template<class DataType, class Compare>
bool MMheap<DataType, Compare>::isOnMinLevel(unsigned int index) {
    return !((int) log2(index + 1) % 2);
}


template<class DataType, class Compare>
void MMheap<DataType, Compare>::percolate(unsigned int index) {

    // Can't bring the root any farther up
    if (!index) return;

    // Find the parent of the passed node
    unsigned int parent_index = parent(index);

    if (isOnMinLevel(index)) {

        // Check to see if we should swap with the parent
        if (less((*heap)[parent_index], (*heap)[index])) {
            std::swap((*heap)[parent_index], (*heap)[index]);
            percolate(parent_index, true);
        }

        else {
            percolate(index, false);
        }

    }

    else {

        // Check to see if we should swap with the parent
        if (less((*heap)[index], (*heap)[parent_index])) {
            std::swap((*heap)[parent_index], (*heap)[index]);
            percolate(parent_index, false);
        }

        else {
            percolate(index, true);
        }

    }
}


template<class DataType, class Compare>
void MMheap<DataType, Compare>::percolate(unsigned int index, bool max_level) {

    // Can't bring the root any farther up
    if (!index) return;

    // Find the parent of the passed node first
    unsigned int grandparent_index = parent(index);

    // If there is no grandparent_index, return
    if (!grandparent_index) return;

    // Find the grandparent_index
    grandparent_index = parent(grandparent_index);

    // Check to see if we should swap with the grandparent_index
    if (less((*heap)[index], (*heap)[grandparent_index]) ^ max_level) {
        std::swap((*heap)[grandparent_index], (*heap)[index]);
        percolate(grandparent_index, max_level);
    }
}


template<class DataType, class Compare>
void MMheap<DataType, Compare>::trickle(unsigned int index) {
    trickle(index, !isOnMinLevel(index));
}


template<class DataType, class Compare>
void MMheap<DataType, Compare>::trickle(unsigned int index, bool max_level) {

    /* In the following comments, substitute the word "less" with the word
     * "more" and the word "smallest" with the word "greatest" when MaxLevel
     * equals true. */

    // Ensure the element exists.
    try {
        if (index >= heap->size())
            throw MyException("Element specified by index does not exist");
    }

    catch (MyException &bounds) {
        std::cout << bounds.GetMessage() << std::endl;
    }


    /* This will hold the index of the smallest node among the children,
     * grandchildren of the current node, and the current node itself. */
    unsigned int smallestNode = index;

    /* Get the left child, all other children and grandchildren can be found
     * from this value. */
    unsigned int left = leftChild(index);

    // Check the left and right child
    if ((left < heap->size()) &&
        (less((*heap)[left], (*heap)[smallestNode]) ^ max_level))
        smallestNode = left;

    if ((left + 1 < heap->size()) &&
        (less((*heap)[left + 1], (*heap)[smallestNode]) ^ max_level))
        smallestNode = left + 1;

    /* Check the grandchildren which are guaranteed to be in consecutive
     * positions in memory. */
    unsigned int leftGrandchild = leftChild(left);
    for (unsigned int i = 0; i < 4 && leftGrandchild + i < heap->size(); ++i)
        if (less((*heap)[leftGrandchild + i], (*heap)[smallestNode]) ^ max_level)
            smallestNode = leftGrandchild + i;

    // The current node was the smallest node, don't do anything.
    if (index == smallestNode) return;

    // Swap the current node with the smallest node
    std::swap((*heap)[index], (*heap)[smallestNode]);

    // If the smallest node was a grandchild...
    if (smallestNode - left > 1) {
        // If the smallest node's parent is bigger than it, swap them
        if (less((*heap)[parent(smallestNode)], (*heap)[smallestNode]) ^ max_level)
            std::swap((*heap)[parent(smallestNode)], (*heap)[smallestNode]);

        trickle(smallestNode, max_level);
    }
}


/**
 * @brief Finds the smallest element in the Min-Max Heap and return its
 *        index.
 *
 * @exception std::underflow_error
 **/
template<class DataType, class Compare>
unsigned int MMheap<DataType, Compare>::findMaxIndex() const {

    // There are four cases

    switch (heap->size()) {

        case 0:
            std::cout << "Empty heaps don't have maximums" << std::endl;

        case 1:
            // There is only one element in the heap, return that element
            return 0;

        case 2:
            // There are two elements in the heap, the child must be the min
            return 1;

        default:
            /* There are three or more elements in the heap, return the
             * smallest child */
            return (less((*heap)[1], (*heap)[2]) ? 2 : 1);

    }

}


template<class DataType, class Compare>
void MMheap<DataType, Compare>::deleteElement(unsigned int index) {

    // Ensure the element exists
    try {
        if (index >= (unsigned int) heap->size())
            throw MyException("No min");
    }

    catch (MyException &no_min) {
        std::cout << no_min.GetMessage() << std::endl;
    }


    // If we're deleting the last element in the heap, just delete it
    if (index == heap->size() - 1) {
        heap->pop_back();
        return;
    }

    // Replace the element with the last element in the heap
    std::swap((*heap)[index], (*heap)[heap->size() - 1]);

    // Delete the last element in the heap
    heap->pop_back();

    /* Let the element trickle down so that the min-max heap property is
     * preserved */
    trickle(index);

}


#endif