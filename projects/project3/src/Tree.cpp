#ifndef TREE_CPP
#define TREE_CPP

#include <iostream>
#include "Tree.h"

/* Stubs for the tree'newNode methods */

template<typename DataType, typename Compare>
Tree<DataType, Compare>::Tree() : m_root(NULL), m_size(0) { }


template<typename DataType, typename Compare>
Tree<DataType, Compare>::Tree(const Tree<DataType, Compare> &other) :
        m_root(other.m_root),
        m_size(other.m_size) { };


template<typename DataType, typename Compare>
Tree<DataType, Compare> &
Tree<DataType, Compare>::operator=(const Tree<DataType, Compare> &other) {

    if (this != &other) {
        m_root = other.m_root;
        m_size = other.m_size;
    }

    return *this;

}


template<typename DataType, typename Compare>
Tree<DataType, Compare>::~Tree() {

    while (m_root != NULL) {
        delete m_root;
        m_root = NULL;
    }

    std::cout << leaves.size() << std::endl;

    for (unsigned int i = 0; i < leaves.size(); i++) {
        delete leaves[i];
        leaves[i] = NULL;
    }

    leaves.resize(0);
}


template<typename DataType, typename Compare>
void Tree<DataType, Compare>::insert(DataType data) {


    if (m_root == NULL) {

        m_root = new Node<DataType>;
        m_root->key[0] = data;

//        std::cout << "first insert" << std::endl;
        m_size++;
        leaves.push_back(m_root);

    } else {

        m_size++;

        std::stack<Node<DataType> *> s = search(m_root, data);

        std::stack<Node<DataType> *> butts(s);

        while (!butts.empty()) {

//            std::cout << butts.top() << std::endl;
            butts.pop();

        } // while

        int dir = 0;
        struct Node<DataType> *node = new Node<DataType>;

        leaves.push_back(node);

        node = s.top();
        s.pop();

        if ((node->key[0] == data) || (node->key[1] == data)) return;

        int count = 0;

        while (count < (s.size() + 1)) {

            struct Node<DataType> *node1 = new Node<DataType>;
            struct Node<DataType> *node2 = new Node<DataType>;
            struct Node<DataType> *parent = new Node<DataType>;

            node1->key[0] = minimum(node->key[0], node->key[1], data);
            node2->key[0] = maximum(node->key[0], node->key[1], data);
            DataType temp = middle_node(node->key[0], node->key[1], data);

            if (!s.empty()) {

                parent = s.top();
                s.pop();

            } //if

            if (node->is_two_node()) {

//                std::cout << "isTwoNode(node)" << std::endl;

                if (Compare()(node->key[0], data)) {
                    node->key[1] = data;
                } else {
                    node->key[0] = data;
                }

                return;

            } else {  // current node is a 3 node


                if (node == parent->left) dir = 0;
                if (node == parent->middle) dir = 1;
                if (node == parent->right) dir = 2;

                if (parent->is_two_node()) {

//                    std::cout << "isTwoNode(parent)" << std::endl;

                    switch (dir) {

                        case 0:

                            parent->key[1] = parent->key[0];
                            parent->key[0] = temp;
                            parent->left = node1;
                            parent->right = parent->middle;
                            parent->middle = node2;
                            break;

                        case 1:

                            parent->key[1] = temp;
                            parent->middle = node1;
                            parent->right = node2;
                            break;

                    } // switch

                } else if (s.empty()) {

//                    std::cout << "m_root node!" << std::endl;

                    Node<DataType> *newRoot = new Node<DataType>;
                    newRoot->key[0] = temp;
                    newRoot->left = node1;
                    newRoot->middle = node2;
                    m_root = newRoot;

                } else {

//                    std::cout << "isThreeNode(parent)" << std::endl;

                    switch (dir) {

                        case 0:

//                            parent->temp = parent->right;
                            parent->right = parent->middle;
                            parent->middle = node2;
                            parent->left = node1;
                            break;

                        case 1:

//                            parent->temp = parent->right;
                            parent->right = node2;
                            parent->middle = node1;
                            break;

                        case 2:

                            parent->right = node1;
//                            parent->temp = node2;
                            break;

                    } // switch

                } // if else

            } // else

            data = temp;
            node = parent;
            count++;

        } // while

    } // if tree is empty

} // ttTreeInsert


template<typename DataType, typename Compare>
bool Tree<DataType, Compare>::empty() const { return (m_root == NULL); }


template<typename DataType, typename Compare>
size_t Tree<DataType, Compare>::size() const { return m_size; }


template<typename DataType, typename Compare>
typename Tree<DataType, Compare>::iterator Tree<DataType, Compare>::begin() {

    if (m_root == NULL) {
        return iterator(NULL);
    }

    Node<DataType> *current = m_root;

    while (current->is_leaf()) {
        current = current->left;
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
void Tree<DataType, Compare>::insert(Node<DataType> *node, DataType data) {

    if (node->is_leaf()) {
        node->left = new Node<DataType>;
        node->key[0] = data;
        node->left = NULL;
        node->right = NULL;
        m_size++;

        delete node;
    }

    else if ((Compare()(data, node->key[0])) && (node->is_two_node())) {

        insert(node->left, data);

    } else if (Compare()(data, node->key[0])) {

        node->left = new Node<DataType>;
        node->left->key[0] = data;
        node->left->parent = node;
        m_size++;

    } else if (node->right != NULL) {

        insert(node->right, data);

    } else if (node->is_three_node()) {

        if (Compare()(data, node->key[0])) {
            insert(node->left, data);
        } else if (Compare()(data, node->key[1])) {
            insert(node->middle, data);
        } else {
            insert(node->right, data);
        }

    } else {

        node->right = new Node<DataType>;
        node->right->key[0] = data;
        node->right->parent = node;
        m_size++;
    }


}

template<typename DataType, typename Compare>
std::stack<Node<DataType> *> Tree<DataType, Compare>::search(
        Node<DataType> *node, DataType data) {

    std::stack<Node<DataType> *> newNode;

    while (node != NULL) {

        newNode.push(node);

        if (node->is_two_node()) {

            if (data == node->key[0]) {

            } else if (data < node->key[0]) {

                node = node->left;

            } else {

                node = node->middle;

            } // if else

        } else {

            // if ((data == node->key[0]) || (data == node->key[1])) {

            //   break;

            // }

            if (data < node->key[0]) {

                node = node->left;

            } else if (data < node->key[1]) {

                node = node->middle;

            } else {

                node = node->right;

            } // if else

        } // if else

    } // while

//    std::cout << "search works!" << std::endl;

    return newNode;

}


template<typename DataType, typename Compare>
DataType Tree<DataType, Compare>::middle_node(DataType x, DataType y, DataType z) {

    DataType mid = 0;

    if ((z < x && y > x) || (y < x && z > x)) mid = x;
    if ((x < y && z > y) || (z < y && x > y)) mid = y;
    if ((y < z && x > z) || (x < z && y > z)) mid = z;
    return mid;

}


template<typename DataType, typename Compare>
DataType Tree<DataType, Compare>::maximum(DataType x, DataType y, DataType z) {

    DataType max = x;

    if (y > max) max = y;
    if (z > max) max = z;
    return max;

} // max


template<typename DataType, typename Compare>
DataType Tree<DataType, Compare>::minimum(DataType x, DataType y, DataType z) {

    DataType min = x;

    if (y < min) min = y;
    if (z < min) min = z;
    return min;

} // min

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
//    if (m_root != NULL) m_root->traverse();
}


template<typename DataType, typename Compare>
std::ostream &operator<<(std::ostream &stream,
                         Tree<DataType, Compare> &tree) {

//    while (tree.m_root != NULL) {
//        stream << tree.m_root->key[0] << std::endl;
////        tree.m_root = tree.m_root->key[0];
//    }

//    tree.traverse();

    return stream;

}


#endif