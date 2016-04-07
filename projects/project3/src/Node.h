#ifndef NODE_H
#define NODE_H

#include <iostream>

/* Node structure for use in 2-3 trees */

template<typename DataType>
struct Node {

    DataType left_key, right_key;
    int num_keys;
    Node<DataType> *left, *middle, *right, *parent;


    Node() : num_keys(0),
             left(NULL), middle(NULL), right(NULL), parent(NULL) { }

    Node(DataType data) : left_key(data), num_keys(1),
                          left(NULL), middle(NULL), right(NULL),
                          parent(NULL) { }

    ~Node() { }

    bool is_leaf() { return (left == NULL && middle == NULL && right == NULL); }

};

#endif
