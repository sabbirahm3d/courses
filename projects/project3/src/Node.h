#ifndef NODE_H
#define NODE_H

#include <iostream>

/* Node structure for use in 2-3 trees */

template<typename DataType>
struct Node {

    DataType left_key, right_key;
    int num_keys;
    Node<DataType> *left, *middle, *right, *parent;


    Node() : left(NULL), middle(NULL), right(NULL), parent(NULL),
             num_keys(0) {  }


//    Node(DataType data) : left(NULL), middle(NULL), right(NULL), parent(NULL) {
//
//        key[0] = data;
//        key[1] = NULL;
//
//    }

    ~Node() {

//        if (key[0] != NULL) {
////            delete key[0];
//            key[0] = NULL;
//        }
////        delete key[1];
//        key[1] = NULL;

    }

    bool is_leaf() { return (left == NULL); }

//    bool is_two_node() { return (key[1] == NULL); }
//
//    bool is_three_node() { return (key[1] != NULL); }

};

#endif
