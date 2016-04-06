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

    for (unsigned int i = 0; i < leaves.size(); i++) {
        delete leaves[i];
        leaves[i] = NULL;
    }

    leaves.resize(0);
}

//create a new node, initialize all crucial values
template<typename DataType, typename Compare>
Node<DataType> *Tree<DataType, Compare>::instantiate(const DataType data) {
    //pre: the initial value the node holds
    //post: a pointer to the newly created node
    Node<DataType> *node = new Node<DataType>;
    node->left_key = data;
    node->num_keys = 1;
    node->left = node->middle = node->right = node->parent = NULL;
    return node;
}


template<typename DataType, typename Compare>
void Tree<DataType, Compare>::insert(DataType data) {

    if (m_root == NULL) {
        m_root = instantiate(data);
        m_size++;
        //if has only 1 node
    } else if (m_root->is_leaf()) {
        m_size++;
        if (m_root->num_keys == 1) {    //if it's a 2-node
            insertSecondItem(m_root, data);
        } else {    //it's a 3-node
            m_root = split_node(m_root, instantiate(data), 0);
        }
        //other conditions
    } else {
        m_size++;
        insert(m_root, data);
    }

}


template<typename DataType, typename Compare>
DataType *Tree<DataType, Compare>::insert_up(const DataType m, const DataType node, const DataType data) {
    //pre: the three elements; m, node should be old node's values, data should be new value
    //post: a pointer to the sorted array
    DataType *middle = new DataType[3];
    if (Compare()(data, m)) { //m is the median
        middle[0] = data;
        middle[1] = m;
        middle[2] = node;
    } else if (Compare()(node, data)) {  //node is the median
        middle[0] = m;
        middle[1] = node;
        middle[2] = data;
    } else { //data is the median
        middle[0] = m;
        middle[1] = data;
        middle[2] = node;
    }
    return middle;
}


template<typename DataType, typename Compare>
bool Tree<DataType, Compare>::empty() const { return (m_root == NULL); }


template<typename DataType, typename Compare>
size_t Tree<DataType, Compare>::size() const { return m_size; }


template<typename DataType, typename Compare>
void Tree<DataType, Compare>::insert(Node<DataType> *node, DataType data) {

    //pre: a pointer to the node to start with, the value to insert
    //post: value is inserted to the tree
    if (node->is_leaf()) { //base case; if node is a leaf
        if (node->num_keys == 1) {   //leaf has empty space
            insertSecondItem(node, data);
        } else {    //leaf is full; split it; insert_up the node to parent
            int pos = search(node->parent, node);
            Node<DataType> *promo = split_node(node, instantiate(data), pos);  //split the node
            while (node->parent != m_root) {    //if parent is not m_root
                if (node->parent->num_keys == 1) { //the parent is not full
                    insertSecondItem(node->parent, promo->left_key);   //insert value to parent
                    //rearrange leftover's linking
                    int pos = search(node->parent, node);
                    if (pos == 0) { //if node is left child
                        node->parent->left = promo->left;
                        node->parent->middle = promo->right;
                    } else if (pos == 2) {   //if node is right child
                        node->parent->middle = promo->left;
                        node->parent->right = promo->right;
                    }
                    promo->left->parent = promo->right->parent = node->parent;
                    break;  //insertion complete
                } else {    //continue to split parent's parent and so on
                    pos = search(node->parent, node);   //direction the split request comes from
                    node = node->parent;  //go one level up
                    promo = split_node(node, promo, pos);   //split parent's parent
                }
            }
            if (node->parent == m_root) { //when trace to m_root
                pos = search(node->parent, node);   //direction the split request comes from
                if (node->parent->num_keys == 1) {   //the m_root is not full
                    insertSecondItem(node->parent, promo->left_key);
                    if (pos == 0) { //if node is left child
                        node->parent->left = promo->left;
                        node->parent->middle = promo->right;
                    } else if (pos == 2) {   //if node is right child
                        node->parent->middle = promo->left;
                        node->parent->right = promo->right;
                    }
                    promo->left->parent = promo->right->parent = node->parent;
                } else {    //split the m_root
                    pos = search(node->parent, node);
                    node = node->parent;
                    m_root = split_node(node, promo, pos);    //m_root will be updated
                }
            }
        }
    } else {    //non-base case
        if (node->num_keys == 1) {   //2-node
            if (Compare()(data, node->left_key)) insert(node->left, data);  //go left subtree
            else insert(node->right, data);   //go right subtree
        } else {    //3-node
            if (Compare()(data, node->left_key)) insert(node->left, data);  //go left subtree
            else if (Compare()(node->right_key, data)) insert(node->right, data);  //go left subtree
            else insert(node->middle, data);    //go middle subtree
        }
    }

}

template<typename DataType, typename Compare>
Node<DataType> *Tree<DataType, Compare>::split_node(Node<DataType> *n, Node<DataType> *x, const int pos) {
    //pre: a pointer to the node to split, the node that causes the split, and where the split causer comes from (left, middle, right = 0, 1, 2)
    //post: a pointer to the top-most node of manipulated subtree
    Node<DataType> *nodeCache[4];    //cache children of nodes passed in
    //rearrange the position of these children for later hook up
    if (pos == 0) {   //x left, x right, n middle, n right
        nodeCache[0] = x->left;
        nodeCache[1] = x->right;
        nodeCache[2] = n->middle;
        nodeCache[3] = n->right;
    } else if (pos == 2) {   //n left, n middle, x left, x right
        nodeCache[0] = n->left;
        nodeCache[1] = n->middle;
        nodeCache[2] = x->left;
        nodeCache[3] = x->right;
    } else {    //n left, x left, x right, n right
        nodeCache[0] = n->left;
        nodeCache[1] = x->left;
        nodeCache[2] = x->right;
        nodeCache[3] = n->right;
    }
    DataType *middle = insert_up(n->left_key, n->right_key, x->left_key); //sort the passed nodes' values
    //reuse nodes to prevent memory leak
    Node<DataType> *promo = instantiate(middle[1]);   //new promoted node
    Node<DataType> *l = instantiate(middle[0]); //left child
    Node<DataType> *r = instantiate(middle[2]); //right child
    //parental relationship of first relative level
    promo->left = l;
    promo->right = r;
    l->parent = promo;
    r->parent = promo;
    //parental relationship of second relative level; hook up cached nodes
    if (nodeCache[0] != NULL) {
        l->left = nodeCache[0];
        l->right = nodeCache[1];
        nodeCache[0]->parent = nodeCache[1]->parent = l;
        r->left = nodeCache[2];
        r->right = nodeCache[3];
        nodeCache[2]->parent = nodeCache[3]->parent = r;
    }
    return promo;
}


template<typename DataType, typename Compare>
void Tree<DataType, Compare>::insertSecondItem(Node<DataType> *node, const DataType data) {
    //pre: a pointer to the 2-node, and the value to be inserted
    //post: value is inserted
    if (Compare()(data, node->left_key)) {   //data should be on left
        node->right_key = node->left_key;
        node->left_key = data;
    } else {    //data should be on right
        node->right_key = data;
    }
    node->num_keys = 2;
}


template<typename DataType, typename Compare>
int Tree<DataType, Compare>::search(Node<DataType> *parent, Node<DataType> *node) {

    //pre: a pointer to the parent, and a pointer to the node itself
    //post: return 0 for left, 1 for middle, 2 for right child
    if (parent->left == node) return 0;    //if left child
    else if (parent->middle == node) return 1; //if middle child
    else return 2;  //if right child

}


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
template<typename KeyType>
std::pair<typename Tree<DataType, Compare>::iterator,
        typename Tree<DataType, Compare>::iterator>
Tree<DataType, Compare>::find_range(KeyType key) {
    /* Your code here... */
    return std::make_pair(iterator(), iterator());

}

template<typename DataType, typename Compare>
std::ostream &operator<<(std::ostream &stream,
                         Tree<DataType, Compare> &tree) {

    return stream;

}


#endif