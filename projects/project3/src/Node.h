#ifndef NODE_H
#define NODE_H


#include <stddef.h>
#include <iostream>

/* Node structure for use in 2-3 trees */

template < typename DataType >
struct Node {

	DataType *key;
	int m_degree;
	Node< DataType > **m_children;
	int numKeys;
	bool m_leaf;

	Node() { }

	// Constructor for Node<DataType> class
	Node(int degree, bool m_leaf) {
		// Copy the given minimum degree and m_leaf property
		m_degree = degree;
		m_leaf = m_leaf;

		// Allocate memory for maximum number of possible key
		// and child pointers
		key = new DataType[2 * m_degree - 1];
		m_children = new Node< DataType > *[2 * m_degree];

		// Initialize the number of key as 0
		numKeys = 0;
	}

	~Node() {


		delete[] m_children;
		m_children = NULL;

//        if (key != NULL) {
//            delete key;
		key = NULL;
//        }
	}

	// Function to traverse all nodes in a subtree rooted with this node
	void traverse() {
		// There are numKeys key and numKeys+1 children, travers through numKeys key
		// and first numKeys children
		int i;
		for (i = 0; i < numKeys; i++) {
			// If this is not m_leaf, then before printing key[i],
			// traverse the subtree rooted with child m_children[i].
			if (!m_leaf)
				m_children[i] -> traverse();
			std::cout << " " << key[i];
		}

		// Print the subtree rooted with last child
		if (!m_leaf)
			m_children[i] -> traverse();
	}

// Function to search key data in subtree rooted with this node
//    Node<DataType> *search(DataType data) {
//        // Find the first key greater than or equal to data
//        int i = 0;
//        while (i < numKeys && data > key[i])
//            i++;
//
//        // If the found key is equal to data, return this node
//        if (key[i] == data)
//            return this;
//
//        // If key is not found here and this is a m_leaf node
//        if (!m_leaf)
//            return NULL;
//
//        // Go to the appropriate child
//        return m_children[i]->search(data);
//    }


	void insert_up(DataType data) {
		// Initialize index as index of rightmost element
		int i = numKeys - 1;

		// If this is a m_leaf node
		if (!m_leaf) {
			// The following loop does two things
			// a) Finds the location of new key to be inserted
			// b) Moves all greater key to one place ahead
			while (i >= 0 && key[i] > data) {
				key[i + 1] = key[i];
				i--;
			}

			// Insert the new key at found location
			key[i + 1] = data;
			numKeys++;

		} else { // If this node is not m_leaf
			// Find the child which is going to have the new key
			while (i >= 0 && key[i] > data)
				i--;

			// See if the found child is full
			if (m_children[i + 1] -> numKeys == 2 * m_degree - 1) {
				// If the child is full, then split it
				splitChild(i + 1, m_children[i + 1]);

				// After split, the middle key of m_children[i] goes up and
				// m_children[i] is splitted into two. See which of the two
				// is going to have the new key
				if (key[i + 1] < data)
					i++;
			}
			m_children[i + 1] -> insert_up(data);
		}
	}

// A utility function to split the child y of this node
// Note that y must be full when this function is called
	void splitChild(int i, Node< DataType > *y) {
		// Create a new node which is going to store (m_degree-1) key
		// of y
		Node< DataType > *z = new Node< DataType >(y -> m_degree, y -> m_leaf);
		z -> numKeys = m_degree - 1;

		// Copy the last (m_degree-1) key of y to z
		for (int j = 0; j < m_degree - 1; j++)
			z -> key[j] = y -> key[j + m_degree];

		// Copy the last m_degree children of y to z
		if (!y -> m_leaf) {
			for (int j = 0; j < m_degree; j++)
				z -> m_children[j] = y -> m_children[j + m_degree];
		}

		// Reduce the number of key in y
		y -> numKeys = m_degree - 1;

		// Since this node is going to have a new child,
		// create space of new child
		for (int j = numKeys; j >= i + 1; j--)
			m_children[j + 1] = m_children[j];

		// Link the new child to this node
		m_children[i + 1] = z;

		// A key of y will move to this node. Find location of
		// new key and move all greater key one space ahead
		for (int j = numKeys - 1; j >= i; j--)
			key[j + 1] = key[j];

		// Copy the middle key of y to this node
		key[i] = y -> key[m_degree - 1];

		// Increment count of key in this node
		numKeys++;
	}

};


#endif
