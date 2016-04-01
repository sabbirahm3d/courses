#ifndef TREE_CPP
#define TREE_CPP

#include <iostream>
#include "Tree.h"

/* Stubs for the tree'newNode methods */

template<typename DataType, typename Compare>
Tree<DataType, Compare>::Tree() {

    m_root = NULL;
    m_degree = 3;
    m_size = 0;

}


template<typename DataType, typename Compare>
Tree<DataType, Compare>::Tree(const Tree<DataType, Compare> &other) {
    /* Your code here... */
}


template<typename DataType, typename Compare>
Tree<DataType, Compare> &
Tree<DataType, Compare>::operator=(const Tree<DataType, Compare> &other) {
    /* Your code here... */
}


template<typename DataType, typename Compare>
Tree<DataType, Compare>::~Tree() {

    while (m_root != NULL) {
        delete m_root;
        m_root = NULL;
    }

    for (unsigned int i = 0; i < leaves.size(); i++) {
        delete leaves[i];
        leaves[i] = NULL;
    }

    leaves.resize(0);
}


template<typename DataType, typename Compare>
void Tree<DataType, Compare>::insert(DataType data) {

    // If tree is empty
    if (m_root == NULL) {
        // Allocate memory for m_root
        m_root = new Node<DataType>(m_degree, true);
        m_root->key[0] = data; // Insert key
        m_root->numKeys = 1; // Update number of key in m_root
        m_size++;
        leaves.push_back(m_root);

    } else { // If tree is not empty
        // If m_root is full, then tree grows in height
        if (m_root->numKeys == 2 * m_degree - 1) {
            // Allocate memory for new m_root
            Node<DataType>* newNode = new Node<DataType>(m_degree, false);

            // Make old m_root as child of new m_root
            newNode->m_children[0] = m_root;

            // Split the old m_root and move 1 key to the new m_root
            newNode->splitChild(0, m_root);

            // New m_root has two children now. Decide which of the
            // two children is going to have new key

            if (Compare()(newNode->key[0], data)) {

                newNode->m_children[1]->insert_up(data);

            } else {

                newNode->m_children[0]->insert_up(data);
            }

            leaves.push_back(newNode);

            // Change m_root
            m_root = newNode;

            // If m_root is not full, call insert_up for m_root
        } else {
            m_root->insert_up(data);
        }

        m_size++;
    }

}


template<typename DataType, typename Compare>
bool Tree<DataType, Compare>::empty() const {
    /* Your code here... */
    return false;
}


template<typename DataType, typename Compare>
size_t Tree<DataType, Compare>::size() const { return m_size; }


template<typename DataType, typename Compare>
typename Tree<DataType, Compare>::iterator Tree<DataType, Compare>::begin() {

    if (m_root == NULL) {
        return iterator(NULL);
    }

    Node<DataType>* current = m_root;

    while (current->m_children[0] != NULL) {
        current = current->m_children[0];
    }

    return iterator(current);

}


template<typename DataType, typename Compare>
typename Tree<DataType, Compare>::iterator Tree<DataType, Compare>::end() {

    return iterator(NULL);

}


template<typename DataType, typename Compare>
template<typename KeyType>
typename Tree<DataType, Compare>::iterator
Tree<DataType, Compare>::find_first(KeyType key) {
    /* Your code here... */
    return iterator();

}


template<typename DataType, typename Compare>
template<typename KeyType>
typename Tree<DataType, Compare>::iterator
Tree<DataType, Compare>::find_last(KeyType key) {
    /* Your code here... */
    return iterator();
}


template<typename DataType, typename Compare>
template<typename KeyType>
std::pair<typename Tree<DataType, Compare>::iterator,
        typename Tree<DataType, Compare>::iterator>
Tree<DataType, Compare>::find_range(KeyType key) {
    /* Your code here... */
    return std::make_pair(iterator(), iterator());

}

template<typename DataType, typename Compare>
void Tree<DataType, Compare>::traverse() {

    if (m_root != NULL)
        m_root->traverse();
}


template<typename DataType, typename Compare>
std::ostream &operator<<(std::ostream &stream,
                         const Tree<DataType, Compare> &tree) {

    return stream;

}


//template<typename DataType, typename Compare>
//void Tree<DataType, Compare>::insert(Node<DataType> *node, DataType data) {
//
//    if (node->is_leaf()) {
////        node->left = new Node<DataType>;
//        node->key[0] = data;
//        node->left = NULL;
//        node->right = NULL;
//        m_size++;
//
//    }
//
//    else if ((Compare()(data, node->key[0])) && (node->is_two_node())) {
//
//        insert(node->left, data);
//
//    } else if (Compare()(data, node->key[0])) {
//
//        node->left = new Node<DataType>;
//        node->left->key[0] = data;
//        node->left->parent = node;
//        m_size++;
//
//    } else if (node->right != NULL) {
//
//        insert(node->right, data);
//
//    } else if (node->is_three_node()) {
//
//        if (Compare()(data, node->key[0])) {
//            insert(node->left, data);
//        } else if (Compare()(data, node->key[1])) {
//            insert(node->middle, data);
//        } else {
//            insert(node->right, data);
//        }
//
//    } else {
//
//        node->right = new Node<DataType>;
//        node->right->key[0] = data;
//        node->right->parent = node;
//        m_size++;
//    }
//
//
//}

//template<typename DataType, typename Compare>
//std::stack<Node<DataType> *> Tree<DataType, Compare>::search(
//    Node<DataType> *node, DataType data) {
//
//    std::stack<Node<DataType> *> newNode;
//
//    while (node != NULL) {
//
//        newNode.push(node);
//
//        if (node->is_two_node()) {
//
//            if (data == node->key[0]) {
//
//            } else if (data < node->key[0]) {
//
//                node = node->left;
//
//            } else {
//
//                node = node->middle;
//
//            } // if else
//
//        } else {
//
//            // if ((data == node->key[0]) || (data == node->key[1])) {
//
//            //   break;
//
//            // }
//
//            if (data < node->key[0]) {
//
//                node = node->left;
//
//            } else if (data < node->key[1]) {
//
//                node = node->middle;
//
//            } else {
//
//                node = node->right;
//
//            } // if else
//
//        } // if else
//
//    } // while
//
//    // std::cout << "search works!" << std::endl;
//
//    return newNode;
//
//}


//template<typename DataType, typename Compare>
//DataType Tree<DataType, Compare>::middle_node(DataType x, DataType y, DataType z) {
//
//    DataType mid = 0;
//
//    if ((z < x && y > x) || (y < x && z > x)) mid = x;
//    if ((x < y && z > y) || (z < y && x > y)) mid = y;
//    if ((y < z && x > z) || (x < z && y > z)) mid = z;
//    return mid;
//
//}
//
//
//template<typename DataType, typename Compare>
//DataType Tree<DataType, Compare>::maximum(DataType x, DataType y, DataType z) {
//
//    DataType max = x;
//
//    if (y > max) max = y;
//    if (z > max) max = z;
//    return max;
//
//} // max
//
//
//template<typename DataType, typename Compare>
//DataType Tree<DataType, Compare>::minimum(DataType x, DataType y, DataType z) {
//
//    DataType min = x;
//
//    if (y < min) min = y;
//    if (z < min) min = z;
//    return min;
//
//} // min

#endif