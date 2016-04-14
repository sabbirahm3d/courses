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

//    unsigned int log2(unsigned int zvalue);

    unsigned int parent(unsigned int zindex);

    unsigned int leftChild(unsigned int zindex);

    unsigned int rightChild(unsigned int zindex);

    bool isOnMinLevel(unsigned int zindex);

    bool isOnMaxLevel(unsigned int zindex);

    template<bool MaxLevel>
    void percolate_(unsigned int zindex);

    void percolate(unsigned int zindex);

    template<bool MaxLevel>
    void trickle_(unsigned int zindex);

    void trickle(unsigned int zindex);

    unsigned int findMinIndex() const;

    void deleteElement(unsigned int zindex);

    std::vector<DataType> m_nodes;
    Compare compare_;

};

#include "MMHeap.cpp"

#endif