/* File:    Tree.cpp
 * Project: CMSC 341: Project 3, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    4/11/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu

 * Implementation of the 2-3 TreeIterator class
 */

#ifndef TREE_ITERATOR_CPP
#define TREE_ITERATOR_CPP

#include "Tree.h"


/* ******************** Constructors ******************** */


/* Tree::iterator()
 * Default constructor */

template<typename DataType, typename Compare>
Tree<DataType, Compare>::iterator::iterator() : m_cursor(NULL) { }


/* Tree::iterator()
 * Overloaded constructor */

template<typename DataType, typename Compare>
Tree<DataType, Compare>::iterator::iterator(Node<DataType> *cursor) :
        m_cursor(cursor) { }


/* ******************** Copy constructors ******************** */


/* Tree::iterator()
 * Copy constructor */

template<typename DataType, typename Compare>
Tree<DataType, Compare>::iterator::iterator(const iterator &other) :
        m_cursor(other.m_cursor) { }


/* ******************** Overloaded operator ******************** */


/* Tree::iterator::iterator=()
 * Assignment operator */

template<typename DataType, typename Compare>
typename Tree<DataType, Compare>::iterator &
Tree<DataType, Compare>::iterator::operator=(const iterator &other) {

    if (this != &other) {
        m_cursor = other.m_cursor;
    }

    return *this;

}


/* Tree::iterator::iterator==()
 * Comparison operator */

template<typename DataType, typename Compare>
bool Tree<DataType, Compare>::iterator::operator==(
        const iterator &other) const {

    return (m_cursor == other.m_cursor);

}


/* Tree::iterator::iterator!=()
 * Comparison operator */

template<typename DataType, typename Compare>
bool Tree<DataType, Compare>::iterator::operator!=(
        const iterator &other) const {

    return !(*this == other);

}


/* Tree::iterator::iterator*()
 * Reference operator, returns the data of the node */

template<typename DataType, typename Compare>
DataType Tree<DataType, Compare>::iterator::operator*() const {

    return m_cursor->left_key;

}


/* Tree::iterator::iterator++()
 * Increment operator */

template<typename DataType, typename Compare>
typename Tree<DataType, Compare>::iterator &
Tree<DataType, Compare>::iterator::operator++() {

    if (m_cursor == NULL) {

        return *this;

    } else if (m_cursor->right != NULL) {

        m_cursor = m_cursor->right;

        while (m_cursor->left != NULL) {

            m_cursor = m_cursor->left;

        }

    } else {

        while (m_cursor->parent != NULL

               && m_cursor->parent->left != m_cursor) {
            m_cursor = m_cursor->parent;

        }

        m_cursor = m_cursor->parent;

    }

    return *this;

}


/* Tree::iterator::iterator++()
 * Overloaded increment operator */

template<typename DataType, typename Compare>
typename Tree<DataType, Compare>::iterator
Tree<DataType, Compare>::iterator::operator++(int unused) {

    Tree<DataType, Compare>::iterator temp(*this);

    operator++();

    return temp;

}


#endif