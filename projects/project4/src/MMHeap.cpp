/**
 * @file MMHeap.hpp
 * @author John Sullivan (jsull003 at ucr.edu)
 * @date December 28, 2010
 *
 * @brief Definition and implementation for class @ref MMHeap.
 *
 * @see Paper Introducing the Min-Max Heap (http://www.cs.otago.ac.nz/staffpriv/mike/Papers/MinMaxHeaps/MinMaxHeaps.pdf)
 * @see Alternative Implementation (http://www.coldbrains.com/code/code/C++/Data_Structures/Min-Max_Heap/MMHeap.C.html,
 *                                  http://www.coldbrains.com/code/code/C++/Data_Structures/Min-Max_Heap/MMHeap.H.html)
 **/

#ifndef MMHEAP_CPP
#define MMHEAP_CPP

#include <vector>
#include <stdexcept>
#include <iostream>

#include "MMHeap.h"


template<typename DataType, typename Compare>
MMHeap<DataType, Compare>::~MMHeap() {

//    destroy_tree(m_root);

//    for (unsigned int i = 0; i < heap_.size(); i++) {
//        delete heap_[i];
//    }

    heap_.clear();
    heap_.resize(0);

}

template<class DataType, class Compare>
unsigned int MMHeap<DataType, Compare>::log2(unsigned int zvalue) {
    // log2(0) is undefined so error
    if (zvalue == 0) throw std::domain_error("Log base 2 of 0 is undefined.");

    unsigned int result = 0;

    // Loop until zvalue equals 0
    while (zvalue) {
        zvalue >>= 1;
        ++result;
    }

    return result - 1;
}

template<class DataType, class Compare>
unsigned int MMHeap<DataType, Compare>::parent(unsigned int zindex) {
    return (zindex - 1) / 2;
}


template<class DataType, class Compare>
unsigned int MMHeap<DataType, Compare>::leftChild(unsigned int zindex) {
    return 2 * zindex + 1;
}

/**
 * @brief Returns the index of the right child of the node specified by
 *        @c zindex.
 **/
template<class DataType, class Compare>
unsigned int MMHeap<DataType, Compare>::rightChild(unsigned int zindex) {
    return 2 * zindex + 2;
}

/**
 * @brief Returns @c true if the node specified by @c zindex is on a
 *        @e min-level.
 **/
template<class DataType, class Compare>
bool MMHeap<DataType, Compare>::isOnMinLevel(unsigned int zindex) {
    return log2(zindex + 1) % 2 == 1;
}


template<class DataType, class Compare>
bool MMHeap<DataType, Compare>::isOnMaxLevel(unsigned int zindex) {
    return !isOnMinLevel(zindex);
}


template<class DataType, class Compare>
template<bool MaxLevel>
void MMHeap<DataType, Compare>::percolate_(unsigned int zindex) {
    // Can't bring the root any farther up
    if (zindex == 0) return;

    // Find the parent of the passed node first
    unsigned int zindex_grandparent = parent(zindex);

    // If there is no grandparent, return
    if (zindex_grandparent == 0) return;

    // Find the grandparent
    zindex_grandparent = parent(zindex_grandparent);

    // Check to see if we should swap with the grandparent
    if (compare_(heap_[zindex], heap_[zindex_grandparent]) ^ MaxLevel) {
        std::swap(heap_[zindex_grandparent], heap_[zindex]);
        percolate_<MaxLevel>(zindex_grandparent);
    }
}


template<class DataType, class Compare>
void MMHeap<DataType, Compare>::percolate(unsigned int zindex) {
    // Can't bring the root any farther up
    if (zindex == 0) return;

    // Find the parent of the passed node
    unsigned int zindex_parent = parent(zindex);

    if (isOnMinLevel(zindex)) {
        // Check to see if we should swap with the parent
        if (compare_(heap_[zindex_parent], heap_[zindex])) {
            std::swap(heap_[zindex_parent], heap_[zindex]);
            percolate_<true>(zindex_parent);
        }
        else {
            percolate_<false>(zindex);
        }
    }
    else {
        // Check to see if we should swap with the parent
        if (compare_(heap_[zindex], heap_[zindex_parent])) {
            std::swap(heap_[zindex_parent], heap_[zindex]);
            percolate_<false>(zindex_parent);
        }
        else {
            percolate_<true>(zindex);
        }
    }
}


template<class DataType, class Compare>
template<bool MaxLevel>
void MMHeap<DataType, Compare>::trickle_(unsigned int zindex) {
    /* In the following comments, substitute the word "less" with the word
     * "more" and the word "smallest" with the word "greatest" when MaxLevel
     * equals true. */

    // Ensure the element exists.
    if (zindex >= heap_.size())
        throw std::invalid_argument("Element specified by zindex does not "
                                            "exist");

    /* This will hold the index of the smallest node among the children,
     * grandchildren of the current node, and the current node itself. */
    unsigned int smallestNode = zindex;

    /* Get the left child, all other children and grandchildren can be found
     * from this value. */
    unsigned int left = leftChild(zindex);

    // Check the left and right child
    if (left < heap_.size() && (compare_(heap_[left], heap_[smallestNode]) ^ MaxLevel))
        smallestNode = left;
    if (left + 1 < heap_.size() && (compare_(heap_[left + 1], heap_[smallestNode]) ^ MaxLevel))
        smallestNode = left + 1;

    /* Check the grandchildren which are guarenteed to be in consecutive
     * positions in memory. */
    unsigned int leftGrandchild = leftChild(left);
    for (unsigned int i = 0; i < 4 && leftGrandchild + i < heap_.size(); ++i)
        if (compare_(heap_[leftGrandchild + i], heap_[smallestNode]) ^ MaxLevel)
            smallestNode = leftGrandchild + i;

    // The current node was the smallest node, don't do anything.
    if (zindex == smallestNode) return;

    // Swap the current node with the smallest node
    std::swap(heap_[zindex], heap_[smallestNode]);

    // If the smallest node was a grandchild...
    if (smallestNode - left > 1) {
        // If the smallest node's parent is bigger than it, swap them
        if (compare_(heap_[parent(smallestNode)], heap_[smallestNode]) ^ MaxLevel)
            std::swap(heap_[parent(smallestNode)], heap_[smallestNode]);

        trickle_<MaxLevel>(smallestNode);
    }
}


template<class DataType, class Compare>
void MMHeap<DataType, Compare>::trickle(unsigned int zindex) {
    if (isOnMinLevel(zindex))
        trickle_<false>(zindex);
    else
        trickle_<true>(zindex);
}

/**
 * @brief Finds the smallest element in the Min-Max Heap and return its
 *        index.
 *
 * @exception std::underflow_error
 **/
template<class DataType, class Compare>
unsigned int MMHeap<DataType, Compare>::findMinIndex() const {
    // There are four cases
    switch (heap_.size()) {
        case 0:
            // The heap is empty so throw an error
            throw std::underflow_error("No min element exists because "
                                               "there are no elements in the "
                                               "heap.");
        case 1:
            // There is only one element in the heap, return that element
            return 0;
        case 2:
            // There are two elements in the heap, the child must be the min
            return 1;
        default:
            /* There are three or more elements in the heap, return the
             * smallest child */
            return compare_(heap_[1], heap_[2]) ? 1 : 2;
    }
}


template<class DataType, class Compare>
void MMHeap<DataType, Compare>::deleteElement(unsigned int zindex) {
    // Ensure the element exists
    if (zindex >= (unsigned int) heap_.size())
        throw std::underflow_error("Cannot delete specified element from "
                                           "the heap because it does not exist.");

    // If we're deleting the last element in the heap, just delete it
    if (zindex == heap_.size() - 1) {
        heap_.pop_back();
        return;
    }

    // Replace the element with the last element in the heap
    std::swap(heap_[zindex], heap_[heap_.size() - 1]);

    // Delete the last element in the heap
    heap_.pop_back();

    /* Let the element trickle down so that the min-max heap property is
     * preserved */
    trickle(zindex);
}

template<class DataType, class Compare>
bool MMHeap<DataType, Compare>::empty() const {
    return heap_.size() == 0;
}

/**
 * @brief Returns the number of elements in the heap.
 **/
template<class DataType, class Compare>
unsigned int MMHeap<DataType, Compare>::size() const {
    return (unsigned int) heap_.size();
}


template<class DataType, class Compare>
void MMHeap<DataType, Compare>::insert(const DataType &zvalue) {
    // Push the value onto the end of the heap
    heap_.push_back(zvalue);

    // Reorder the heap so that the min-max heap property holds true
    percolate(heap_.size() - 1);
}

/**
 * @brief Returns the element with the greatest value in the heap.
 *
 * @exception std::underflow_error
 **/
template<class DataType, class Compare>
const DataType &MMHeap<DataType, Compare>::getMax() const {
    // If the heap is empty throw an error
    if (empty())
        throw std::underflow_error("No max element exists because there "
                                           "are no elements in the heap.");

    return heap_[0];
}

/**
 * @brief Returns the element with the least value in the heap.
 *
 * @exception std::underflow_error
 **/
template<class DataType, class Compare>
const DataType &MMHeap<DataType, Compare>::getMin() const {
    // findMinIndex() will throgh an underflow_error if no min exists
    return heap_[findMinIndex()];
}

/**
 * @brief Removes the element with the greatest value from the heap and
 *        returns its value.
 *
 * @exception std::underflow_error
 **/
template<class DataType, class Compare>
DataType MMHeap<DataType, Compare>::deleteMax() {
    // If the heap is empty throw an error
    if (heap_.size() == 0)
        throw std::underflow_error("No max element exists because there "
                                           "are no elements in the heap.");

    // Save the max value
    DataType temp = heap_[0];

    deleteElement(0);

    return temp;
}

/**
 * @brief Convenience function that calls deleteMax().
 **/
template<class DataType, class Compare>
DataType MMHeap<DataType, Compare>::pop() {
    return deleteMax();
}

/**
 * @brief Removes the element with the least value from the heap and returns
 *        its value.
 *
 * @exception std::underflow_error
 **/
template<class DataType, class Compare>
DataType MMHeap<DataType, Compare>::deleteMin() {
    // If the heap is empty throw an error
    if (heap_.size() == 0)
        throw std::underflow_error("No max element exists because there "
                                           "are no elements in the heap.");

    // Save the min's index
    unsigned int smallest = findMinIndex();

    // Save the min value
    DataType temp = heap_[smallest];

    deleteElement(smallest);

    return temp;
}

/**
 * @brief Outputs the heap, as layed out in memory, into the given output
 *        stream.
 **/
template<class DataType, class Compare>
void MMHeap<DataType, Compare>::dump() const {
    // std::cout << "{";
    if (empty())
        std::cout << "Heap is Empty";
    else {

        std::cout << "Size = " << size() << std::endl;
        std::cout << "Minimum = " << getMin() << std::endl;
        std::cout << "Maximum = " << getMax() << std::endl << std::endl;

        for (unsigned int i = 0; i < heap_.size(); ++i)
            std::cout << "H[" << i << "] = " << heap_[i] << (i != heap_.size() - 1 ? "\n" : "");

    }
    // std::cout << "}";

    std::cout << std::endl;
}
//    };

//} // namespace minmax
#endif