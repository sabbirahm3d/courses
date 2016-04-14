#ifndef MMHEAP_H
#define MMHEAP_H

#include <iostream>
#include <vector>

template<typename DataType, typename Compare = std::less<DataType> >
class MMHeap {

public:

    MMHeap();

    ~MMHeap();

    bool empty() const;

    /* Returns the number of elements in the heap.
     */
    unsigned int size() const;

    void insert(const DataType &);

    const DataType &getMax() const;

    const DataType &getMin() const;

    DataType deleteMax();

    DataType pop();

    DataType deleteMin();

    void dump() const;


private:

    unsigned int parent(unsigned int);

    unsigned int leftChild(unsigned int);

    unsigned int rightChild(unsigned int);

    bool isOnMinLevel(unsigned int);

    bool isOnMaxLevel(unsigned int);

    void percolate(unsigned int, bool);

    void percolate(unsigned int);

    void trickle(unsigned int, bool);

    void trickle(unsigned int);

    unsigned int findMinIndex() const;

    void deleteElement(unsigned int);

    std::vector<DataType> m_nodes;
    Compare compare_;

};

#include "MMHeap.cpp"

#endif