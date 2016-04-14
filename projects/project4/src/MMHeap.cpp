#ifndef MMHEAP_CPP
#define MMHEAP_CPP

#include <stdexcept>
#include <math.h>

#include "MMHeap.h"


template<typename DataType, typename Compare>
MMHeap<DataType, Compare>::MMHeap() {

//    std::vector<DataType> m_nodes;

}


template<typename DataType, typename Compare>
MMHeap<DataType, Compare>::~MMHeap() {

//    destroy_tree(m_root);

//    for (unsigned int i = 0; i < m_nodes.size(); i++) {
//        delete m_nodes[i];
//    }

    m_nodes.clear();
    m_nodes.resize(0);

}


//template<class DataType, class Compare>
//unsigned int MMHeap<DataType, Compare>::log2(unsigned int zvalue) {
//    // log2(0) is undefined so error
//    if (zvalue == 0) throw std::domain_error("Log base 2 of 0 is undefined.");
//
//    unsigned int result = 0;
//
//    // Loop until zvalue equals 0
//    while (zvalue) {
//        zvalue >>= 1;
//        ++result;
//    }
//
//    return (result - 1);
//}


template<class DataType, class Compare>
unsigned int MMHeap<DataType, Compare>::parent(unsigned int index) {
    return ((index - 1) / 2);
}


template<class DataType, class Compare>
unsigned int MMHeap<DataType, Compare>::leftChild(unsigned int index) {
    return (2 * index + 1);
}

/**
 * @brief Returns the index of the right child of the node specified by
 *        @c index.
 **/
template<class DataType, class Compare>
unsigned int MMHeap<DataType, Compare>::rightChild(unsigned int index) {
    return (2 * index + 2);
}

/**
 * @brief Returns @c true if the node specified by @c index is on a
 *        @e min-level.
 **/
template<class DataType, class Compare>
bool MMHeap<DataType, Compare>::isOnMinLevel(unsigned int index) {
    return ((int)log2(index + 1) % 2 == 1);
}


template<class DataType, class Compare>
bool MMHeap<DataType, Compare>::isOnMaxLevel(unsigned int index) {
    return !isOnMinLevel(index);
}


template<class DataType, class Compare>
template<bool MaxLevel>
void MMHeap<DataType, Compare>::percolate_(unsigned int index) {
    // Can't bring the root any farther up
    if (index == 0) return;

    // Find the parent of the passed node first
    unsigned int zindex_grandparent = parent(index);

    // If there is no grandparent, return
    if (zindex_grandparent == 0) return;

    // Find the grandparent
    zindex_grandparent = parent(zindex_grandparent);

    // Check to see if we should swap with the grandparent
    if (compare_(m_nodes[index], m_nodes[zindex_grandparent]) ^ MaxLevel) {
        std::swap(m_nodes[zindex_grandparent], m_nodes[index]);
        percolate_<MaxLevel>(zindex_grandparent);
    }
}


template<class DataType, class Compare>
void MMHeap<DataType, Compare>::percolate(unsigned int index) {
    // Can't bring the root any farther up
    if (index == 0) return;

    // Find the parent of the passed node
    unsigned int zindex_parent = parent(index);

    if (isOnMinLevel(index)) {
        // Check to see if we should swap with the parent
        if (compare_(m_nodes[zindex_parent], m_nodes[index])) {
            std::swap(m_nodes[zindex_parent], m_nodes[index]);
            percolate_<true>(zindex_parent);
        }
        else {
            percolate_<false>(index);
        }
    }
    else {
        // Check to see if we should swap with the parent
        if (compare_(m_nodes[index], m_nodes[zindex_parent])) {
            std::swap(m_nodes[zindex_parent], m_nodes[index]);
            percolate_<false>(zindex_parent);
        }
        else {
            percolate_<true>(index);
        }
    }
}


template<class DataType, class Compare>
template<bool MaxLevel>
void MMHeap<DataType, Compare>::trickle_(unsigned int index) {
    /* In the following comments, substitute the word "less" with the word
     * "more" and the word "smallest" with the word "greatest" when MaxLevel
     * equals true. */

    // Ensure the element exists.
    if (index >= m_nodes.size())
        throw std::invalid_argument("Element specified by index does not "
                                            "exist");

    /* This will hold the index of the smallest node among the children,
     * grandchildren of the current node, and the current node itself. */
    unsigned int smallestNode = index;

    /* Get the left child, all other children and grandchildren can be found
     * from this value. */
    unsigned int left = leftChild(index);

    // Check the left and right child
    if (left < m_nodes.size() && (compare_(m_nodes[left], m_nodes[smallestNode]) ^ MaxLevel))
        smallestNode = left;
    if (left + 1 < m_nodes.size() && (compare_(m_nodes[left + 1], m_nodes[smallestNode]) ^ MaxLevel))
        smallestNode = left + 1;

    /* Check the grandchildren which are guarenteed to be in consecutive
     * positions in memory. */
    unsigned int leftGrandchild = leftChild(left);
    for (unsigned int i = 0; i < 4 && leftGrandchild + i < m_nodes.size(); ++i)
        if (compare_(m_nodes[leftGrandchild + i], m_nodes[smallestNode]) ^ MaxLevel)
            smallestNode = leftGrandchild + i;

    // The current node was the smallest node, don't do anything.
    if (index == smallestNode) return;

    // Swap the current node with the smallest node
    std::swap(m_nodes[index], m_nodes[smallestNode]);

    // If the smallest node was a grandchild...
    if (smallestNode - left > 1) {
        // If the smallest node's parent is bigger than it, swap them
        if (compare_(m_nodes[parent(smallestNode)], m_nodes[smallestNode]) ^ MaxLevel)
            std::swap(m_nodes[parent(smallestNode)], m_nodes[smallestNode]);

        trickle_<MaxLevel>(smallestNode);
    }
}


template<class DataType, class Compare>
void MMHeap<DataType, Compare>::trickle(unsigned int index) {
    if (isOnMinLevel(index))
        trickle_<false>(index);
    else
        trickle_<true>(index);
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
    switch (m_nodes.size()) {
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
            return compare_(m_nodes[1], m_nodes[2]) ? 1 : 2;
    }
}


template<class DataType, class Compare>
void MMHeap<DataType, Compare>::deleteElement(unsigned int index) {
    // Ensure the element exists
    if (index >= (unsigned int) m_nodes.size())
        throw std::underflow_error("Cannot delete specified element from "
                                           "the heap because it does not exist.");

    // If we're deleting the last element in the heap, just delete it
    if (index == m_nodes.size() - 1) {
        m_nodes.pop_back();
        return;
    }

    // Replace the element with the last element in the heap
    std::swap(m_nodes[index], m_nodes[m_nodes.size() - 1]);

    // Delete the last element in the heap
    m_nodes.pop_back();

    /* Let the element trickle down so that the min-max heap property is
     * preserved */
    trickle(index);
}

template<class DataType, class Compare>
bool MMHeap<DataType, Compare>::empty() const {
    return m_nodes.size() == 0;
}

/**
 * @brief Returns the number of elements in the heap.
 **/
template<class DataType, class Compare>
unsigned int MMHeap<DataType, Compare>::size() const {
    return (unsigned int) m_nodes.size();
}


template<class DataType, class Compare>
void MMHeap<DataType, Compare>::insert(const DataType &zvalue) {
    // Push the value onto the end of the heap
    m_nodes.push_back(zvalue);

    // Reorder the heap so that the min-max heap property holds true
    percolate(m_nodes.size() - 1);

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

    return m_nodes[0];
}

/**
 * @brief Returns the element with the least value in the heap.
 *
 * @exception std::underflow_error
 **/
template<class DataType, class Compare>
const DataType &MMHeap<DataType, Compare>::getMin() const {
    // findMinIndex() will throgh an underflow_error if no min exists
    return m_nodes[findMinIndex()];
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
    if (m_nodes.size() == 0)
        throw std::underflow_error("No max element exists because there "
                                           "are no elements in the heap.");

    // Save the max value
    DataType temp = m_nodes[0];

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
    if (m_nodes.size() == 0)
        throw std::underflow_error("No max element exists because there "
                                           "are no elements in the heap.");

    // Save the min's index
    unsigned int smallest = findMinIndex();

    // Save the min value
    DataType temp = m_nodes[smallest];

    deleteElement(smallest);

    return temp;
}

/**
 * @brief Outputs the heap, as layed out in memory, into the given output
 *        stream.
 **/
template<class DataType, class Compare>
void MMHeap<DataType, Compare>::dump() const {

    if (empty()) {
        std::cout << "Heap is Empty";
    }

    else {

        int level = 0;

        std::cout << "Size = " << size() << std::endl;
        std::cout << "Minimum = " << getMin() << std::endl;
        std::cout << "Maximum = " << getMax() << std::endl << std::endl;

        for (unsigned int nodes = 0; nodes < m_nodes.size(); ++nodes) {

            if (!(nodes % ((int) pow(2, level)))) {
                std::cout << "--------------- Level " << level <<
                " ---------------" << std::endl;
                level++;
            }

            std::cout << "H[" << nodes << "] = " << m_nodes[nodes] << std::endl;

        }
    }

    std::cout << std::endl;
}


#endif