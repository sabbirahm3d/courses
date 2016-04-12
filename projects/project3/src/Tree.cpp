#ifndef TREE_CPP
#define TREE_CPP

#include <iostream>
#include "Tree.h"


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

    destroy_tree(m_root);

    for (unsigned int i = 0; i < m_leaves.size(); i++) {
        delete m_leaves[i];
    }

    m_leaves.resize(0);

}


template<typename DataType, typename Compare>
void Tree<DataType, Compare>::destroy_tree(Node<DataType> *leaf) {

    if (leaf != NULL) {
        destroy_tree(leaf->left);
        destroy_tree(leaf->middle);
        destroy_tree(leaf->right);
        delete leaf;
    }

}


template<typename DataType, typename Compare>
void Tree<DataType, Compare>::insert(DataType data) {

    if (m_root == NULL) {
        m_root = new Node<DataType>(data);
        m_leaves.push_back(m_root);
        m_size++;


    //if has only 1 node
    } else if (m_root->is_leaf()) {

        if (m_root->num_keys == 1) {    //if it's a 2-node

            insertSecondItem(m_root, data);

        } else {    //it's a 3-node

            m_root = split_node(m_root, new Node<DataType>(data), 0);
            m_leaves.push_back(m_root);

        }

        m_size++;

    } else {

        m_size++;
        insert(m_root, data);

    }

}


template<typename DataType, typename Compare>
DataType *Tree<DataType, Compare>::insert_up(DataType left,
                                             DataType middle,
                                             DataType right) {

    DataType *cache = new DataType[3];
    if (Compare()(right, left)) { //left is the median

        cache[0] = right;
        cache[1] = left;
        cache[2] = middle;

    } else if (Compare()(middle, right)) {  //middle is the median

        cache[0] = left;
        cache[1] = middle;
        cache[2] = right;

    } else { //right is the median

        cache[0] = left;
        cache[1] = right;
        cache[2] = middle;

    }

    return cache;

}


template<typename DataType, typename Compare>
bool Tree<DataType, Compare>::empty() const { return (m_root == NULL); }


template<typename DataType, typename Compare>
size_t Tree<DataType, Compare>::size() const { return m_size; }


template<typename DataType, typename Compare>
Node<DataType> *Tree<DataType, Compare>::root() { return m_root; };

template<typename DataType, typename Compare>
void Tree<DataType, Compare>::insert(Node<DataType> *node, DataType data) {

    //pre: a pointer to the node to start with, the value to insert
    //post: value is inserted to the tree
    if (node->is_leaf()) { //base case; if node is a leaf

        if (node->num_keys == 1) {   //leaf has empty space

            insertSecondItem(node, data);

        } else {    //leaf is full; split it; insert_up the node to parent

            int pos = search(node->parent, node);

            //split the node
            Node<DataType> *promo = split_node(node,
                                               new Node<DataType>(data),
                                               pos);

            //if parent is not m_root
            while (node->parent != m_root) {
                //the parent is not full
                if (node->parent->num_keys == 1) {
                    //insert value to parent
                    insertSecondItem(node->parent, promo->left_key);

                    //rearrange leftover's linking
                    pos = search(node->parent, node);

                    if (!pos) { //if node is left child

                        node->parent->left = promo->left;
                        node->parent->middle = promo->right;

                    } else if (pos == 2) {   //if node is right child

                        node->parent->middle = promo->left;
                        node->parent->right = promo->right;

                    }

                    promo->left->parent = promo->right->parent = node->parent;
                    m_leaves.push_back(promo);

                    return;  //insertion complete


                } else {    //continue to split parent's parent and so on

                    //direction the split request comes from
                    pos = search(node->parent, node);
                    node = node->parent;  //go one level up
                    //split parent's parent
                    promo = split_node(node, promo, pos);
                }
            }

            if (node->parent == m_root) { //when trace to m_root
                //direction the split request comes from
                pos = search(node->parent, node);
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
                    //m_root will be updated
                    m_root = split_node(node, promo, pos);
                }
            }

            m_leaves.push_back(promo);
        }

    } else {    //non-base case
        if (node->num_keys == 1) {   //2-node
            if (Compare()(data, node->left_key)) {
                insert(node->left, data);
            }  //go left subtree
            else {
                insert(node->right, data);
            }   //go right subtree
        } else {    //3-node
            if (Compare()(data, node->left_key)) {
                insert(node->left, data);
            }  //go left subtree
            else if (Compare()(node->right_key, data)) {
                insert(node->right, data);
            }  //go left subtree
            else {
                insert(node->middle, data);
            }    //go middle subtree
        }
    }

}

template<typename DataType, typename Compare>
Node<DataType> *Tree<DataType, Compare>::split_node(Node<DataType> *first_node,
                                                    Node<DataType> *second_node,
                                                    const int pos) {

    Node<DataType> *nodeCache[4];    //cache children of nodes passed in
    //rearrange the position of these children for later hook up

    //second_node left, second_node right, first_node middle, first_node right
    if (pos == 0) {

        nodeCache[0] = second_node->left;
        nodeCache[1] = second_node->right;
        nodeCache[2] = first_node->middle;
        nodeCache[3] = first_node->right;

    //first_node left, first_node middle, second_node left, second_node right
    } else if (pos == 2) {

        nodeCache[0] = first_node->left;
        nodeCache[1] = first_node->middle;
        nodeCache[2] = second_node->left;
        nodeCache[3] = second_node->right;

    //first_node left, second_node left, second_node right, first_node right
    } else {

        nodeCache[0] = first_node->left;
        nodeCache[1] = second_node->left;
        nodeCache[2] = second_node->right;
        nodeCache[3] = first_node->right;
    }

    //sort the passed nodes' values
    DataType *middle = insert_up(first_node->left_key, first_node->right_key,
                                 second_node->left_key);

    //reuse nodes to prevent memory leak

    //new promoted node
    Node<DataType> *promo = new Node<DataType>(middle[1]);
    Node<DataType> *l = new Node<DataType>(middle[0]); //left child
    Node<DataType> *r = new Node<DataType>(middle[2]); //right child

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

    delete middle;
    m_leaves.push_back(second_node);
    m_leaves.push_back(l);
    m_leaves.push_back(r);

    return promo;
}


template<typename DataType, typename Compare>
void Tree<DataType, Compare>::insertSecondItem(Node<DataType> *node,
                                               const DataType data) {
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
int Tree<DataType, Compare>::search(Node<DataType> *parent,
                                    Node<DataType> *node) {

    //pre: a pointer to the parent, and a pointer to the node itself
    //post: return 0 for left, 1 for middle, 2 for right child
    if (parent->left == node) return 0;    //if left child
    else if (parent->middle == node) return 1; //if middle child
    else return 2;  //if right child

}


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


    if (tree.root() == NULL) {

        stream << "Empty tree.";

    } else {

        std::vector<Node<DataType> *> level;  //list to print

        //list to hold children of level, for later use
        std::vector<Node<DataType> *> children;
        level.push_back(tree.root());  //first level

        while (!level.empty()) {
            //print all nodes
            for (unsigned int i = 0; i < level.size(); i++) {
                if (level[i] != NULL) {  //print guard
                    if (level[i]->num_keys == 1) {
                        stream << level[i]->left_key << " ";
                    } else {
                        stream << level[i]->left_key << std::endl <<
                                level[i]->right_key << " ";
                    }
                }

                stream << std::endl;
            }

            stream << std::endl;   //end this level

            //find children of nodes in level
            for (int i = 0; i < level.size(); i++) {
                if (level[i]->left) children.push_back(level[i]->left);
                if (level[i]->middle) children.push_back(level[i]->middle);
                if (level[i]->right) children.push_back(level[i]->right);
            }

            level.clear();
            level.swap(children);
            children.clear();    //clear level, make children print-ready
        }

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