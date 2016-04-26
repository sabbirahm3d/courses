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

    for (unsigned int i = 0; i < size(); i++) {
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
    percolate(size() - 1);
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

    catch (MyException &noMin) {
        std::cout << noMin.getMessage() << std::endl;
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
        std::cout << emptyHeap.getMessage() << std::endl;
        throw;
    }

    // save the maximum value
    DataType tempMax = (*heap)[findMaxIndex()];

    deleteElement(findMaxIndex());

    return tempMax;
}


/* deleteMin()
 * Pops the minimum value off the heap */

template<class DataType, class Compare>
DataType MMheap<DataType, Compare>::deleteMin() {

    // throw an exception if the heap is empty
    try {
        if (!size())
            throw MyException("No minimum element exists because there are no "
                                      "elements in the heap");
    }

    catch (MyException &emptyHeap) {
        std::cout << emptyHeap.getMessage() << std::endl;
        throw;
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
        if (!size()) {
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

            for (unsigned int nodes = 0; nodes < size(); ++nodes) {

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
        std::cout << emptyHeap.getMessage() << std::endl;
    }

    std::cout << std::endl;
}


/* ******************** Private helper methods ******************** */

/* parent()
 * Returns the parent of the index specified */

template<class DataType, class Compare>
unsigned int MMheap<DataType, Compare>::parent(unsigned int index) {

    // the index of a node's parent is the index divided by 2
    return ((index - 1) / 2);

}


/* isOnMinLevel()
 * Returns if the node is on an even level */

template<class DataType, class Compare>
bool MMheap<DataType, Compare>::isOnMinLevel(unsigned int index) {

    // the min levels in a min-max heap are determined if
    // log<base>2(index) is divisible by 2
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
void MMheap<DataType, Compare>::percolate(unsigned int index, bool minLevel) {

    // 0th index is the root
    if (!index) return;

    // if there is no grandparent, return
    if (!parent(index)) return;

    // find the grandparent index
    unsigned int grandparentIndex = parent(parent(index));

    /* check to see if we should swap with the grandparentIndex the node will
        only percolate up the heap if:
        node < grandparent(node) and node != odd level or
        node > grandparent(node) and node == odd level */
    if ((less((*heap)[index], (*heap)[grandparentIndex]) && !minLevel) ||
        (less((*heap)[grandparentIndex], (*heap)[index]) && minLevel)) {
        std::swap((*heap)[grandparentIndex], (*heap)[index]);
        percolate(grandparentIndex, minLevel);
    }

}


/* trickle()
 * Bootstrap for trickle nodes down the heap */

template<class DataType, class Compare>
void MMheap<DataType, Compare>::trickle(unsigned int index) {
    trickle(index, !isOnMinLevel(index));
}


/* trickle() - overloaded trickling function
 * Trickles nodes down the heap */

template<class DataType, class Compare>
void MMheap<DataType, Compare>::trickle(unsigned int index, bool minLevel) {

    // make sure the element exists
    try {
        if (index >= size())
            throw MyException("Element specified by index does not exist");
    }

    catch (MyException &bounds) {
        std::cout << bounds.getMessage() << std::endl;
        return;
    }


    // will store the smallest node out of the left, right, and the
    // grandchildren nodes
    unsigned int smallestNode = index;

    // find the left and right children of the node
    unsigned int left = 2 * index + 1;
    unsigned int right = 2 * index + 2;

    // the XOR caret is used to minimize logic:
    // one or the other is true, but not both

    // if left < index xor index == minLevel, and left isn't the last node
    if (less((*heap)[left], (*heap)[smallestNode]) ^ minLevel) {
        if (left < size()) {
            smallestNode = left;
        }
    }

    // if right < index xor index == minLevel, and right isn't the last node
    if (less((*heap)[right], (*heap)[smallestNode]) ^ minLevel) {
        if (right < size()) {
            smallestNode = right;
        }
    }

    // the grandchildren nodes
    unsigned int leftGrandchild = 2 * left + 1;

    // check that the 4 grandchildren nodes are sorted
    for (int i = 0; ((i < 4) &&
                     ((leftGrandchild + i) < size())); ++i)
        if (less((*heap)[leftGrandchild + i], (*heap)[smallestNode])
            ^ minLevel)
            smallestNode = leftGrandchild + i;

    // the current node was the smallest node, break out of function
    if (index == smallestNode) {
        return;
    }

    // swap the current node with the smallest node
    std::swap((*heap)[index], (*heap)[smallestNode]);

    // if the smallest node was a grandchild
    if ((smallestNode - left) > 1) {
        // if the smallest node's parent is bigger than it, swap them
        if (less((*heap)[parent(smallestNode)], (*heap)[smallestNode])
            ^ minLevel) {
            std::swap((*heap)[parent(smallestNode)], (*heap)[smallestNode]);
        }

        trickle(smallestNode, minLevel);
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

    // make sure the element exists
    try {
        if (index >= size())
            throw MyException("Element specified does not exist");
    }

    catch (MyException &noMin) {
        std::cout << noMin.getMessage() << std::endl;
    }


    // deleting the last element
    if (index == (size() - 1)) {
        heap->pop_back();
        return;
    }

    // else, replace the element with the last element in the heap, then delete
    std::swap((*heap)[index], (*heap)[(size() - 1)]);
    heap->pop_back();

    // let it trickle down the heap
    trickle(index);

}


#endif