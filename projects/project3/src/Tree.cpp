#ifndef TREE_CPP
#define TREE_CPP

#include <iostream>
#include "Tree.h"

/* Stubs for the tree'newNode methods */

template < typename DataType, typename Compare >
Tree< DataType, Compare >::Tree() : m_root(NULL), m_degree(3), m_size(0) { }


template < typename DataType, typename Compare >
Tree< DataType, Compare >::Tree(const Tree< DataType, Compare > &other) :
	m_root(other . m_root),
	m_degree(other . m_degree),
	m_size(other . m_size) { };


template < typename DataType, typename Compare >
Tree< DataType, Compare > &
Tree< DataType, Compare >::operator=(const Tree< DataType, Compare > &other) {

	if (this != & other) {
		m_root = other . m_root;
		m_degree = other . m_degree;
		m_size = other . m_size;
	}

	return * this;

}


template < typename DataType, typename Compare >
Tree< DataType, Compare >::~Tree() {

	while (m_root != NULL) {
		delete m_root;
		m_root = NULL;
	}

	for (unsigned int i = 0; i < leaves . size(); i++) {
		delete leaves[i];
		leaves[i] = NULL;
	}

	leaves . resize(0);
}


template < typename DataType, typename Compare >
void Tree< DataType, Compare >::insert(DataType data) {

	// If tree is empty
	if (m_root == NULL) {
		// Allocate memory for m_root
		m_root = new Node< DataType >(m_degree, true);
		m_root -> key[0] = data; // Insert key
		m_root -> numKeys = 1; // Update number of key in m_root
		m_size++;
		leaves . push_back(m_root);

	} else { // If tree is not empty
		// If m_root is full, then tree grows in height
		if (m_root -> numKeys == 2 * m_degree - 1) {
			// Allocate memory for new m_root
			Node< DataType > *newNode = new Node< DataType >(m_degree, false);

			// Make old m_root as child of new m_root
			newNode -> m_children[0] = m_root;

			// Split the old m_root and move 1 key to the new m_root
			newNode -> splitChild(0, m_root);

			// New m_root has two children now. Decide which of the
			// two children is going to have new key

			if (Compare()(newNode -> key[0], data)) {

				newNode -> m_children[1] -> insert_up(data);

			} else {

				newNode -> m_children[0] -> insert_up(data);
			}

//            std::cout << newNode->key[0] << std::endl;
			leaves . push_back(newNode);

			// Change m_root
			m_root = newNode;

			// If m_root is not full, call insert_up for m_root
		} else {
			m_root -> insert_up(data);
		}

		m_size++;
	}

}


template < typename DataType, typename Compare >
bool Tree< DataType, Compare >::empty() const {
	/* Your code here... */
	return false;
}


template < typename DataType, typename Compare >
size_t Tree< DataType, Compare >::size() const { return m_size; }


template < typename DataType, typename Compare >
typename Tree< DataType, Compare >::iterator Tree< DataType, Compare >::begin() {

	if (m_root == NULL) {
		return iterator(NULL);
	}

	Node< DataType > *current = m_root;

	while (current -> m_children[0] != NULL) {
		current = current -> m_children[0];
	}

	return iterator(current);

}


template < typename DataType, typename Compare >
typename Tree< DataType, Compare >::iterator Tree< DataType, Compare >::end() {

	return iterator(NULL);

}


template < typename DataType, typename Compare >
template < typename KeyType >
typename Tree< DataType, Compare >::iterator
Tree< DataType, Compare >::find_first(KeyType key) {
	/* Your code here... */
	return iterator();

}


template < typename DataType, typename Compare >
template < typename KeyType >
typename Tree< DataType, Compare >::iterator
Tree< DataType, Compare >::find_last(KeyType key) {
	/* Your code here... */
	return iterator();
}


template < typename DataType, typename Compare >
template < typename KeyType >
std::pair< typename Tree< DataType, Compare >::iterator,
	typename Tree< DataType, Compare >::iterator >
Tree< DataType, Compare >::find_range(KeyType key) {
	/* Your code here... */
	return std::make_pair(iterator(), iterator());

}

template < typename DataType, typename Compare >
void Tree< DataType, Compare >::traverse() {

	if (m_root != NULL)
		m_root -> traverse();
}


template < typename DataType, typename Compare >
std::ostream &operator<<(std::ostream &stream,
												 const Tree< DataType, Compare > &tree) {

	while (tree . m_root != NULL) {
		stream << tree . m_root -> key[0] << std::endl;
//        tree.m_root = tree.m_root->key[0];
	}

	return stream;

}


#endif