/* File:    Tree.cpp
 * Project: CMSC 341: Project 3, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    4/11/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu

 * Implementation of the 2-3 Tree class
 */


#ifndef TREE_CPP
#define TREE_CPP

#include <iostream>
#include "Tree.h"


/* ******************** Constructors ******************** */

/* Tree()
 * Default constructor */

template<typename DataType, typename Compare>
Tree<DataType, Compare>::Tree() : m_root(NULL), m_size(0) { }


/* ******************** Copy constructors ******************** */

/* Copies over all member attributes to new instantiations */

template<typename DataType, typename Compare>
Tree<DataType, Compare>::Tree(const Tree<DataType, Compare> &other) :
        m_root(other.m_root), m_size(other.m_size) { };


/* ******************** Assignment operator ******************** */

/* Assigns tree object to another */

template<typename DataType, typename Compare>
Tree<DataType, Compare> &
Tree<DataType, Compare>::operator=(const Tree<DataType, Compare> &other) {

    if (this != &other) {
        m_root = other.m_root;
        m_size = other.m_size;
    }

    return *this;

}


/* ******************** Destructors ******************** */

/* Destroys the object along with its leaves and data */

template<typename DataType, typename Compare>
Tree<DataType, Compare>::~Tree() {

    destroy_tree(m_root);

    for (unsigned int i = 0; i < m_leaves.size(); i++) {
        delete m_leaves[i];
    }

    m_leaves.resize(0);

}


/* destroy_tree()
 * Helper recursive function for destructor */

template<typename DataType, typename Compare>
void Tree<DataType, Compare>::destroy_tree(Node<DataType> *leaf) {

    if (leaf != NULL) {

        destroy_tree(leaf->left);
        destroy_tree(leaf->middle);
        destroy_tree(leaf->right);

        delete leaf;

    }

}


/* ******************** Public methods ******************** */

/* insert()
 * bootstrap for inserting data into the tree */

template<typename DataType, typename Compare>
void Tree<DataType, Compare>::insert(DataType data) {

    // if node is the root
    if (m_root == NULL) {

        m_root = new Node<DataType>(data);

        // stores root to be deleted in the destructor
        m_leaves.push_back(m_root);
        m_size++;

        // if tree has only one node
    } else if (m_root->is_leaf()) {

        // if it's a two-node
        if (m_root->num_keys == 1) {

            insert_second_item(m_root, data);

            // if it's a three-node
        } else {

            m_root = split_node(m_root, new Node<DataType>(data), 0);
            m_leaves.push_back(m_root);

        }

        m_size++;

        // find the next available position
    } else {

        m_size++;
        insert(m_root, data);

    }

}


/* empty()
 * returns true if tree is empty */

template<typename DataType, typename Compare>
bool Tree<DataType, Compare>::empty() const { return (m_root == NULL); }


/* size()
 * returns number of nodes in tree */

template<typename DataType, typename Compare>
size_t Tree<DataType, Compare>::size() const { return m_size; }


/* root()
 * returns root of the tree */

template<typename DataType, typename Compare>
Node<DataType> *Tree<DataType, Compare>::root() { return m_root; };


/* ******************** Private methods ******************** */

/* insert()
 * overloaded insert function, requires location of data to be placed and
 * implement the actual insertion */

template<typename DataType, typename Compare>
void Tree<DataType, Compare>::insert(Node<DataType> *node, DataType data) {

    //pre: a pointer to the node to start with, the value to insert
    //post: value is inserted to the tree

    // if node is a leaf
    if (node->is_leaf()) {

        // leaf has an empty spot
        if (node->num_keys == 1) {

            insert_second_item(node, data);

            // leaf is full; split it; insert_up the node to parent
        } else {

            // new location of data
            int pos = find_position(node->parent, node);

            // split the node
            Node<DataType> *new_node = split_node(node,
                                                  new Node<DataType>(data),
                                                  pos);

            //if parent is not root
            while (node->parent != m_root) {

                // the parent is not full
                if (node->parent->num_keys == 1) {

                    // insert value to parent
                    insert_second_item(node->parent, new_node->left_key);

                    // rearrange leftover's linking
                    pos = find_position(node->parent, node);

                    // if node is left child
                    if (!pos) {

                        node->parent->left = new_node->left;
                        node->parent->middle = new_node->right;

                        //if node is right child
                    } else if (pos == 2) {

                        node->parent->middle = new_node->left;
                        node->parent->right = new_node->right;

                    }

                    new_node->left->parent = new_node->right->parent = node->parent;

                    // the promoted node is then deleted
                    m_leaves.push_back(new_node);

                    return;  //insertion complete


                    // if parent is full, split it as well
                } else {

                    // find position to split
                    pos = find_position(node->parent, node);

                    // move node up one level
                    node = node->parent;

                    // split grandparent
                    new_node = split_node(node, new_node, pos);

                }

            }

            // if parent is root
            if (node->parent == m_root) {

                // direction the split request comes from
                pos = find_position(node->parent, node);

                // root is not full
                if (node->parent->num_keys == 1) {

                    insert_second_item(node->parent, new_node->left_key);

                    // if node is left child
                    if (!pos) {

                        node->parent->left = new_node->left;
                        node->parent->middle = new_node->right;

                        // if node is right child
                    } else if (pos == 2) {

                        node->parent->middle = new_node->left;
                        node->parent->right = new_node->right;

                    }

                    new_node->left->parent = new_node->right->parent = node->parent;

                    // if parent is full, split it
                } else {

                    pos = find_position(node->parent, node);
                    node = node->parent;

                    // root will be updated
                    m_root = split_node(node, new_node, pos);

                }
            }

            m_leaves.push_back(new_node);
        }

        // if node is not leaf
    } else {

        // if it's a two-node
        if (node->num_keys == 1) {

            // traverse to the left subtree
            if (Compare()(data, node->left_key)) {

                insert(node->left, data);

                // traverse to the left subtree
            } else {

                insert(node->right, data);

            }

            // if it's a three-node
        } else {

            // traverse to the left subtree
            if (Compare()(data, node->left_key)) {

                insert(node->left, data);

                // traverse to the right subtree
            } else if (Compare()(node->right_key, data)) {

                insert(node->right, data);

                // traverse to the middle subtree
            } else {

                insert(node->middle, data);

            }
        }

    }

}


/* insert_up()
 * helper function for insert, assists in moving nodes up the branches */

template<typename DataType, typename Compare>
DataType *Tree<DataType, Compare>::insert_up(DataType left,
                                             DataType middle,
                                             DataType right) {

    // temporary array of data being passed in to rearrange its children
    DataType *cache = new DataType[3];

    // left becomes the middle node
    if (Compare()(right, left)) {

        cache[0] = right;
        cache[1] = left;
        cache[2] = middle;

        // middle stays the middle node
    } else if (Compare()(middle, right)) {

        cache[0] = left;
        cache[1] = middle;
        cache[2] = right;

        // right becomes the middle node
    } else {

        cache[0] = left;
        cache[1] = right;
        cache[2] = middle;

    }

    return cache;

}


/* split_node()
 * helper function for insert, assists in splitting nodes when data is 
 * attempted to be inserted into three-nodes */

template<typename DataType, typename Compare>
Node<DataType> *Tree<DataType, Compare>::split_node(
        Node<DataType> *first_node,
        Node<DataType> *second_node,
        const int pos) {

    // temporary array of children being passed in to be rearranged
    Node<DataType> *node_cache[4];

    // parent->left == node
    if (!pos) {

        node_cache[0] = second_node->left;
        node_cache[1] = second_node->right;
        node_cache[2] = first_node->middle;
        node_cache[3] = first_node->right;

        // parent->middle == node
    } else if (pos == 2) {

        node_cache[0] = first_node->left;
        node_cache[1] = first_node->middle;
        node_cache[2] = second_node->left;
        node_cache[3] = second_node->right;

        // parent->right == node
    } else {

        node_cache[0] = first_node->left;
        node_cache[1] = second_node->left;
        node_cache[2] = second_node->right;
        node_cache[3] = first_node->right;

    }

    // rearrange the passed nodes' values
    DataType *middle = insert_up(first_node->left_key, first_node->right_key,
                                 second_node->left_key);

    // new promoted node
    Node<DataType> *new_node = new Node<DataType>(middle[1]);

    // left child
    Node<DataType> *left = new Node<DataType>(middle[0]);

    // right child
    Node<DataType> *right = new Node<DataType>(middle[2]);

    // parental relationship of first relative level
    new_node->left = left;
    new_node->right = right;
    left->parent = new_node;
    right->parent = new_node;

    // parental relationship of second relative level, connect back to cache
    if (node_cache[0] != NULL) {

        left->left = node_cache[0];
        left->right = node_cache[1];
        node_cache[0]->parent = node_cache[1]->parent = left;

        right->left = node_cache[2];
        right->right = node_cache[3];
        node_cache[2]->parent = node_cache[3]->parent = right;

    }

    delete middle;
    m_leaves.push_back(second_node);
    m_leaves.push_back(left);
    m_leaves.push_back(right);

    return new_node;

}


/* insert_second_item()
 * helper function for insert, assists in inserting values to two-nodes */

template<typename DataType, typename Compare>
void Tree<DataType, Compare>::insert_second_item(Node<DataType> *node,
                                                 const DataType data) {
    //pre: a pointer to the 2-node, and the value to be inserted
    //post: value is inserted

    //data should be on left
    if (Compare()(data, node->left_key)) {

        node->right_key = node->left_key;
        node->left_key = data;

        //data should be on right
    } else {

        node->right_key = data;

    }

    // update number of keys
    node->num_keys = 2;

}


/* find_position()
 * helper function for insert, returns position of the node for the data to be
 * placed. 0 for left, 1 for middle, and 2 for right child */

template<typename DataType, typename Compare>
int Tree<DataType, Compare>::find_position(Node<DataType> *parent,
                                           Node<DataType> *node) {

    //pre: a pointer to the parent, and a pointer to the node itself
    //post: return 0 for left, 1 for middle, 2 for right child

    // if left child
    if (parent->left == node) return 0;

        // if middle child
    else if (parent->middle == node) return 1;

        //if right child
    else return 2;

}


/* ******************** Iterator functions ******************** */

/* begin()
 * points to the beginning of the tree */

template<typename DataType, typename Compare>
typename Tree<DataType, Compare>::iterator Tree<DataType, Compare>::begin() {

    if (m_root == NULL) {
        return iterator();
    }

    Node<DataType> *current = m_root;

    while (current->is_leaf()) {
        current = current->left;
    }

    return iterator(current);

}


/* end()
 * points to the ending of the tree */

template<typename DataType, typename Compare>
typename Tree<DataType, Compare>::iterator Tree<DataType, Compare>::end() {

    return iterator();

}


/* find_first()
 * finds first instance of the key */

template<typename DataType, typename Compare>
template<typename KeyType>
typename Tree<DataType, Compare>::iterator
Tree<DataType, Compare>::find_first(KeyType key) {
    /* Your code here... */
    return iterator();

}


/* find_last()
 * finds last instance of the key */

template<typename DataType, typename Compare>
template<typename KeyType>
typename Tree<DataType, Compare>::iterator
Tree<DataType, Compare>::find_last(KeyType key) {
    /* Your code here... */
    return iterator();
}


/* find_range()
 * Return a pair of iterators pointing to the first item in the tree equal
 * to key, and past the last item in the tree equal to key */

template<typename DataType, typename Compare>
template<typename KeyType>
std::pair<typename Tree<DataType, Compare>::iterator,
        typename Tree<DataType, Compare>::iterator>
Tree<DataType, Compare>::find_range(KeyType key) {
    /* Your code here... */
    return std::make_pair(iterator(), iterator());

}


/* ******************** Overloaded operators ******************** */


/* operator<<()
 * prints out the content of the tree in level order */

template<typename DataType, typename Compare>
std::ostream &operator<<(std::ostream &stream,
                         Tree<DataType, Compare> &tree) {


    if (tree.root() == NULL) {

        stream << "Empty tree.";

    } else {

        // vector to print
        std::vector<Node<DataType> *> level;

        // list to hold children of level
        std::vector<Node<DataType> *> children;

        // 0th level of tree
        level.push_back(tree.root());

        while (!level.empty()) {

            // print all nodes
            for (unsigned int i = 0; i < level.size(); i++) {

                if (level[i] != NULL) {

                    // if node is a two-node
                    if (level[i]->num_keys == 1) {

                        stream << level[i]->left_key << " ";

                        // if node is a three-node
                    } else {

                        stream << level[i]->left_key << std::endl <<
                        level[i]->right_key << " ";

                    }

                }

                stream << std::endl;
            }

            // end this level
            stream << std::endl;

            // find children of nodes in level to push into children vector
            for (unsigned int i = 0; i < level.size(); i++) {

                if (level[i]->left) { children.push_back(level[i]->left); }
                if (level[i]->middle) { children.push_back(level[i]->middle); }
                if (level[i]->right) { children.push_back(level[i]->right); }

            }

            // clear out the vector
            level.clear();

            // the children are next in queue to be level-order printed
            level.swap(children);

            // clear out the children
            children.clear();

        }

        // delete the vectors after use
        for (unsigned int i = 0; i < level.size(); i++) {
            delete level[i];
        }

        level.resize(0);

        for (unsigned int i = 0; i < children.size(); i++) {
            delete children[i];
        }

        children.resize(0);

    }

    stream << std::endl;

    return stream;

}


#endif