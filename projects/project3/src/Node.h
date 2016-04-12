#ifndef NODE_H
#define NODE_H

#include <iostream>

/* Node structure for use in 2-3 trees */

template<typename DataType>
struct Node {

    // stores the data being passed in corresponding to the children
    DataType left_key, right_key;

    // number of keys for node:
    // 1 determines two-node
    // 2 determines three-node
    int num_keys;

    // children and parent nodes to the current node
    Node<DataType> *left, *middle, *right, *parent;


    /* ******************** Constructors ******************** */

    /* Node()
     * Default constructor */

    Node() : num_keys(0),
             left(NULL), middle(NULL), right(NULL), parent(NULL) { }


    /* Node()
     * Overloaded constructor */

    Node(DataType data) : left_key(data), num_keys(1), left(NULL),
                          middle(NULL), right(NULL), parent(NULL) { }


    /* ******************** Destructors ******************** */

    /* ~Node()
     * Default destructor */

    ~Node() { }


    /* ******************** Public methods ******************** */

    /* is_leaf()
     * returns true if the node is a leaf */

    bool is_leaf() { return (left == NULL && middle == NULL && right == NULL); }

};

#endif
