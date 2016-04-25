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

    // the root is the min
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


/* ******************** Private helper methods ******************** */

/* parent()
 * Returns the parent of the index specified */

template<class DataType, class Compare>
unsigned int MMheap<DataType, Compare>::parent(unsigned int index) {
    return ((index - 1) / 2);
}


/* isOnMinLevel()
 * Returns if the node is on an even level */

template<class DataType, class Compare>
bool MMheap<DataType, Compare>::isOnMinLevel(unsigned int index) {
    return !((int) log2(index + 1) % 2);
}


/* percolate()
 * Bootstrap for percolating nodes up the heap */

template<class DataType, class Compare>
void MMheap<DataType, Compare>::percolate(unsigned int index) {

    // 0th index is the root
    if (!index) return;

    // find the index of the parent of the passed node
    unsigned int parentIndex = parent(index);

    /* to preserve the structure of the heap:
     1. if the parent < node and node == onMinLevel, swap and percolate the
        parent up the heap
     2. if the parent < node and node != onMinLevel, percolate the node up
        the heap
     3. if the parent > node and node == onMinLevel, percolate the node up
        the heap
     4. if the parent > node and node != onMinLevel, swap and percolate the
        parent up the heap */
    if (less((*heap)[parentIndex], (*heap)[index])) {
        if (isOnMinLevel(index)) {
            std::swap((*heap)[parentIndex], (*heap)[index]);
            percolate(parentIndex, isOnMinLevel(index));
        } else {
            percolate(index, !isOnMinLevel(index));
        }
    } else if (less((*heap)[index], (*heap)[parentIndex])) {
        if (isOnMinLevel(index)) {
            percolate(index, !isOnMinLevel(index));
        } else {
            std::swap((*heap)[parentIndex], (*heap)[index]);
            percolate(parentIndex, isOnMinLevel(index));
        }
    }

}


/* percolate() - overloaded percolate()
 * Percolates nodes up the heap */

template<class DataType, class Compare>
void MMheap<DataType, Compare>::percolate(unsigned int index, bool maxLevel) {

    // 0th index is the root
    if (!index) return;

    // if there is no grandparent, return
    if (!parent(index)) return;

    // find the grandparent index
    unsigned int grandparent_index = parent(parent(index));

    /* check to see if we should swap with the grandparent_index the node will
        only percolate up the heap if:
        node < grandparent(node) and node != odd level or
        node > grandparent(node) and node == odd level */
    if ((less((*heap)[index], (*heap)[grandparent_index]) && !maxLevel) ||
        (less((*heap)[grandparent_index], (*heap)[index]) && maxLevel)) {
        std::swap((*heap)[grandparent_index], (*heap)[index]);
        percolate(grandparent_index, maxLevel);
    }

}


/* trickle()
 * Bootstrap for trickle nodes down the heap */

template<class DataType, class Compare>
void MMheap<DataType, Compare>::trickle(unsigned int index) {
    trickle(index, !isOnMinLevel(index));
}


template<class DataType, class Compare>
void MMheap<DataType, Compare>::trickle(unsigned int index, bool maxLevel) {

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
    unsigned int left = 2 * index + 1;
    unsigned int right = 2 * index + 2;

    // Check the left and right child
    if (less((*heap)[left], (*heap)[smallestNode]) ^ maxLevel) {
        if (left < heap->size()) {
            smallestNode = left;
        }
    }

    if (less((*heap)[right], (*heap)[smallestNode]) ^ maxLevel) {
        if (right < heap->size()) {
            smallestNode = right;
        }
    }

    /* Check the grandchildren which are guaranteed to be in consecutive
     * positions in memory. */
    unsigned int leftGrandchild = 2 * left + 1;

    for (unsigned int i = 0; (i < 4 && leftGrandchild + i < heap->size()); ++i)
        if (less((*heap)[leftGrandchild + i], (*heap)[smallestNode]) ^ maxLevel)
            smallestNode = leftGrandchild + i;

    // The current node was the smallest node, don't do anything.
    if (index == smallestNode) return;

    // Swap the current node with the smallest node
    std::swap((*heap)[index], (*heap)[smallestNode]);

    // If the smallest node was a grandchild...
    if (smallestNode - left > 1) {
        // If the smallest node's parent is bigger than it, swap them
        if (less((*heap)[parent(smallestNode)], (*heap)[smallestNode]) ^ maxLevel)
            std::swap((*heap)[parent(smallestNode)], (*heap)[smallestNode]);

        trickle(smallestNode, maxLevel);
    }

}


/* findMaxIndex()
 * Finds the index of the maximum value in the heap*/

template<class DataType, class Compare>
unsigned int MMheap<DataType, Compare>::findMaxIndex() const {

    // the maximum value is on the 1st level of the min-max heap
    // test difference cases depending on the size of the heap
    switch (size()) {

        // empty heap
        case 0:
            std::cout << "Empty heaps don't have maximums" << std::endl;

        // the only one element in the heap, return that element
        case 1:
            return 0;

        // there are two nodes, and the maximum would be non-root
        case 2:
            return 1;

        // there are more than two nodes in the heap, find the maximum in
        // level 1, heap[1] and heap[2]
        default:
            return (less((*heap)[1], (*heap)[2]) ? 2 : 1);

    }

}


/* deleteElement()
 * Deletes a node at a specified index */

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