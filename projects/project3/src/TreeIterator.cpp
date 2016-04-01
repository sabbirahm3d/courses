#ifndef TREE_ITERATOR_CPP
#define TREE_ITERATOR_CPP

#include "Tree.h"


template<typename DataType, typename Compare>
Tree<DataType, Compare>::iterator::iterator() : m_cursor(NULL) { }

template<typename DataType, typename Compare>
Tree<DataType, Compare>::iterator::iterator(Node<DataType> *cursor) :
        m_cursor(cursor) { }


template<typename DataType, typename Compare>
Tree<DataType, Compare>::iterator::iterator(const iterator &other) :
        m_cursor(other.m_cursor) { }


template<typename DataType, typename Compare>
typename Tree<DataType, Compare>::iterator &
Tree<DataType, Compare>::iterator::operator=(const iterator &other) {

    if (this != &other) {
        m_cursor = other.m_cursor;
    }

    return *this;

}


template<typename DataType, typename Compare>
bool Tree<DataType, Compare>::iterator::operator==(
        const iterator &other) const {

    return (m_cursor == other.m_cursor);

}


template<typename DataType, typename Compare>
bool Tree<DataType, Compare>::iterator::operator!=(
        const iterator &other) const {

    return !(*this == other);

}


template<typename DataType, typename Compare>
DataType Tree<DataType, Compare>::iterator::operator*() const {

   return m_cursor->key[0];

}


template<typename DataType, typename Compare>
typename Tree<DataType, Compare>::iterator &
Tree<DataType, Compare>::iterator::operator++() {

    // if (m_cursor == NULL) {

    //     return *this;

    // } else if (m_cursor->right != NULL) {

    //     m_cursor = m_cursor->right;

    //     while (m_cursor->left != NULL) {
    //         m_cursor = m_cursor->left;
    //     }

    // } else {

    //     while (m_cursor->parent != NULL
    //            && m_cursor->parent->left != m_cursor) {
    //         m_cursor = m_cursor->parent;
    //     }

    //     m_cursor = m_cursor->parent;

    // }

    // return *this;

}


template<typename DataType, typename Compare>
typename Tree<DataType, Compare>::iterator
Tree<DataType, Compare>::iterator::operator++(int unused) {

    Tree<DataType, Compare>::iterator temp(*this);

    operator++();

    return temp;

}


#endif