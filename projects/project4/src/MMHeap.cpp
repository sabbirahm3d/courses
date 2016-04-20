#ifndef MMHEAP_CPP
#define MMHEAP_CPP

#include <stdexcept>
#include <math.h>

#include "MMHeap.h"
#include "MyException.h"


template<typename DataType, typename Compare>
MMHeap<DataType, Compare>::MMHeap() { }


template<typename DataType, typename Compare>
MMHeap<DataType, Compare>::~MMHeap() {

    heap.clear();
    heap.resize(0);

}


template<class DataType, class Compare>
unsigned int MMHeap<DataType, Compare>::parent(unsigned int index) {
    return ((index - 1) / 2);
}


template<class DataType, class Compare>
unsigned int MMHeap<DataType, Compare>::leftChild(unsigned int index) {
    return (2 * index + 1);
}


///**
// * @brief Returns the index of the right child of the node specified by
// *        @c index.
// **/
//template<class DataType, class Compare>
//unsigned int MMHeap<DataType, Compare>::rightChild(unsigned int index) {
//    return (2 * index + 2);
//}


/**
 * @brief Returns @c true if the node specified by @c index is on a
 *        @e min-level.
 **/
template<class DataType, class Compare>
bool MMHeap<DataType, Compare>::isOnMinLevel(unsigned int index) {
    return (((int) log2(index + 1) % 2) == 0);
}


//template<class DataType, class Compare>
//bool MMHeap<DataType, Compare>::isOnMaxLevel(unsigned int index) {
//    return !isOnMinLevel(index);
//}


template<class DataType, class Compare>
void MMHeap<DataType, Compare>::percolate(unsigned int index, bool max_level) {

    // Can't bring the root any farther up
    if (!index) return;

    // Find the parent of the passed node first
    unsigned int grandparent_index = parent(index);

    // If there is no grandparent_index, return
    if (!grandparent_index) return;

    // Find the grandparent_index
    grandparent_index = parent(grandparent_index);

    // Check to see if we should swap with the grandparent_index
    if (less(heap[index], heap[grandparent_index]) ^ max_level) {
        std::swap(heap[grandparent_index], heap[index]);
        percolate(grandparent_index, max_level);
    }
}


template<class DataType, class Compare>
void MMHeap<DataType, Compare>::percolate(unsigned int index) {

    // Can't bring the root any farther up
    if (!index) return;

    // Find the parent of the passed node
    unsigned int parent_index = parent(index);

    if (isOnMinLevel(index)) {

        // Check to see if we should swap with the parent
        if (less(heap[parent_index], heap[index])) {
            std::swap(heap[parent_index], heap[index]);
            percolate(parent_index, true);
        }

        else {
            percolate(index, false);
        }

    }

    else {

        // Check to see if we should swap with the parent
        if (less(heap[index], heap[parent_index])) {
            std::swap(heap[parent_index], heap[index]);
            percolate(parent_index, false);
        }

        else {
            percolate(index, true);
        }

    }
}


template<class DataType, class Compare>
void MMHeap<DataType, Compare>::trickle(unsigned int index, bool max_level) {

    /* In the following comments, substitute the word "less" with the word
     * "more" and the word "smallest" with the word "greatest" when MaxLevel
     * equals true. */

    // Ensure the element exists.
    try {
        if (index >= heap.size())
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
    if ((left < heap.size()) &&
        (less(heap[left], heap[smallestNode]) ^ max_level))
        smallestNode = left;

    if ((left + 1 < heap.size()) &&
        (less(heap[left + 1], heap[smallestNode]) ^ max_level))
        smallestNode = left + 1;

    /* Check the grandchildren which are guaranteed to be in consecutive
     * positions in memory. */
    unsigned int leftGrandchild = leftChild(left);
    for (unsigned int i = 0; i < 4 && leftGrandchild + i < heap.size(); ++i)
        if (less(heap[leftGrandchild + i], heap[smallestNode]) ^ max_level)
            smallestNode = leftGrandchild + i;

    // The current node was the smallest node, don't do anything.
    if (index == smallestNode) return;

    // Swap the current node with the smallest node
    std::swap(heap[index], heap[smallestNode]);

    // If the smallest node was a grandchild...
    if (smallestNode - left > 1) {
        // If the smallest node's parent is bigger than it, swap them
        if (less(heap[parent(smallestNode)], heap[smallestNode]) ^ max_level)
            std::swap(heap[parent(smallestNode)], heap[smallestNode]);

        trickle(smallestNode, max_level);
    }
}


template<class DataType, class Compare>
void MMHeap<DataType, Compare>::trickle(unsigned int index) {
    trickle(index, !isOnMinLevel(index));
}

/**
 * @brief Finds the smallest element in the Min-Max Heap and return its
 *        index.
 *
 * @exception std::underflow_error
 **/
template<class DataType, class Compare>
unsigned int MMHeap<DataType, Compare>::findMaxIndex() const {

    // There are four cases

    switch (heap.size()) {

        case 0:
            std::cout << "No max" << std::endl;

        case 1:
            // There is only one element in the heap, return that element
            return 0;

        case 2:
            // There are two elements in the heap, the child must be the min
            return 1;

        default:
            /* There are three or more elements in the heap, return the
             * smallest child */
            return less(heap[1], heap[2]) ? 2 : 1;

    }

}


template<class DataType, class Compare>
void MMHeap<DataType, Compare>::deleteElement(unsigned int index) {

    // Ensure the element exists
    try {
        if (index >= (unsigned int) heap.size())
            throw MyException("No min");
    }

    catch (MyException &no_min) {
        std::cout << no_min.GetMessage() << std::endl;
    }


    // If we're deleting the last element in the heap, just delete it
    if (index == heap.size() - 1) {
        heap.pop_back();
        return;
    }

    // Replace the element with the last element in the heap
    std::swap(heap[index], heap[heap.size() - 1]);

    // Delete the last element in the heap
    heap.pop_back();

    /* Let the element trickle down so that the min-max heap property is
     * preserved */
    trickle(index);

}

template<class DataType, class Compare>
bool MMHeap<DataType, Compare>::empty() const {
    return (heap.size() == 0);
}

/**
 * @brief Returns the number of elements in the heap.
 **/
template<class DataType, class Compare>
unsigned int MMHeap<DataType, Compare>::size() const {
    return (heap.size());
}


template<class DataType, class Compare>
void MMHeap<DataType, Compare>::insert(const DataType &value) {

    // Push the value onto the end of the heap
    heap.push_back(value);

    // Reorder the heap so that the min-max heap property holds true
    percolate((unsigned int) heap.size() - 1);

}

/**
 * @brief Returns the element with the greatest value in the heap.
 *
 * @exception std::underflow_error
 **/
template<class DataType, class Compare>
const DataType &MMHeap<DataType, Compare>::getMin() const {

    // If the heap is empty throw an error
    try {
        if (empty())
            throw MyException("Empty heaps don't have a maximum");
    }

    catch (MyException &no_max) {
        std::cout << no_max.GetMessage() << std::endl;
    }

    return heap[0];
}

/**
 * @brief Returns the element with the least value in the heap.
 *
 * @exception std::underflow_error
 **/
template<class DataType, class Compare>
const DataType &MMHeap<DataType, Compare>::getMax() const {
    // findMaxIndex() will through an underflow_error if no min exists
    return (heap[findMaxIndex()]);
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
    try {
        if (empty())
            throw MyException("No max element exists because there are no "
                                      "elements in the heap.");
    }

    catch (MyException &empty_heap) {
        std::cout << empty_heap.GetMessage() << std::endl;
    }


    // Save the max value
    DataType temp = heap[0];

    deleteElement(0);

    return temp;
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
    try {
        if (empty())
            throw MyException("No max element exists because there "
                                      "are no elements in the heap.");
    }

    catch (MyException &empty_heap) {
        std::cout << empty_heap.GetMessage() << std::endl;
    }

    // Save the min's index
    unsigned int smallest = findMaxIndex();

    // Save the min value
    DataType temp = heap[smallest];

    deleteElement(smallest);

    return temp;
}


/**
 * @brief Outputs the heap, as layed out in memory, into the given output
 *        stream.
 **/
template<class DataType, class Compare>
void MMHeap<DataType, Compare>::dump() const {

    try {

        if (empty()) {
            throw MyException("Can't dump empty heap");
        }

        else {

            int level = 0;

            std::cout << "Size = " << size() << std::endl;
            std::cout << "Minimum = " << getMin() << std::endl;
            std::cout << "Maximum = " << getMax() << std::endl << std::endl;

            for (unsigned int nodes = 0; nodes < heap.size(); ++nodes) {

                // print level after every 2^n iterations
                if (!((nodes + 1) % ((int) pow(2, level)))) {
                    std::cout << "------------------- Level " << level <<
                    " -------------------" << std::endl;
                    level++;
                }

                std::cout << "H[" << nodes << "] : " << heap[nodes] <<
                std::endl;

            }
        }
    }

    catch (MyException &empty_heap) {
        std::cout << empty_heap.GetMessage() << std::endl;
    }

    std::cout << std::endl;
}


#endif