#ifndef NODE_H
#define NODE_H


#include <stddef.h>
#include <iostream>

/* Node structure for use in 2-3 trees */

template<typename DataType>
struct Node {

    DataType key[2];
    Node *left, *middle, *right, *parent;


     Node() : left(NULL), middle(NULL), right(NULL), parent(NULL) {}


     Node(DataType data) : left(NULL), middle(NULL), right(NULL), parent(NULL) {

         key[0] = data;
         key[1] = NULL;

     }

    ~Node() {

        if (key[0] != NULL){
//            delete key[0];
            key[0] = NULL;
        }
//        delete key[1];
        key[1] = NULL;

    }

    bool is_leaf() {

        return (left == NULL && middle == NULL && right == NULL);

    }


    bool is_two_node() { return (key[1] == NULL); }

    bool is_three_node() { return (key[1] != NULL); }

    //  DataType minimum() {

    //      Node<DataType> *node = this;
    //      while (!node->isLeaf()) node = node->left;
    //      return node->key[0];

    //  }


    //      // Insert into a node with 1 child
    //  void insert1Siblings(Node<DataType> *newChild, DataType newSmallest) {

    //      DataType newKey = newChild->key[0];
    //      newChild->parent = this;

    //      if (newKey < left->key[0]) {
    //              // newNode is inserted as first child of root
    //          middle = left;
    //          left = newChild;
    //          key[0] = middle->minimum();

    //      } else {
    //              // newNode is iserted as second child of root
    //          middle = newChild;
    //          key[0] = newSmallest;
    //      }
    //  }


    //  // Insert into a node with 2 children
    //  void insert2Siblings(Node<DataType> *newChild, DataType newSmallest) {

    //      DataType newKey = newChild->key[0];
    //      newChild->parent = this;

    //      if (newKey < left->key[0]) {
    //          right = middle;
    //          middle = left;
    //          left = newChild;

    //          key[1] = key[0];
    //          key[0] = middle->minimum();
    //          updateParentSmallest(newSmallest);
    //      }

    //      else if (newKey < middle->key[0]) {
    //          right = middle;
    //          middle = newChild;

    //          key[1] = key[0];
    //          key[0] = newSmallest;

    //      } else {

    //          right = newChild;
    //          key[1] = newSmallest;

    //      }

    //  }


    //  // Insert into a node with 3 children
    //  void insert3Siblings(Node<DataType> *newChild, DataType newSmallest) {
    //     DataType newKey = newChild->key[0];

    //     DataType splitSmallest = NULL;
    //     Node *splitNode = new Node();
    //     splitNode->parent = parent;

    //     if (newKey < left->key[0] || newKey < middle->key[0]) {
    //              // newChild is inserted in current node
    //         splitSmallest = key[0];
    //         splitNode->left = middle;
    //         splitNode->middle = right;
    //         splitNode->key[0] = key[1];

    //         middle->parent = splitNode;
    //         right->parent = splitNode;
    //         newChild->parent = this;

    //         if (newKey < left->key[0]) {
    //                  // newChild is inserted as first child
    //             middle = left;
    //             left = newChild;

    //             key[0] = middle->minimum();
    //             updateParentSmallest(newSmallest);
    //         }
    //         else {
    //                  // newChild is inserted as second child
    //             middle = newChild;

    //             key[0] = newSmallest;
    //         }
    //     }
    //     else {
    //              // newChild is inserted in split node
    //         right->parent = splitNode;
    //         newChild->parent = splitNode;

    //         if (newKey < right->key[0]) {
    //                  // newChild is inserted as first child
    //             splitSmallest = newSmallest;
    //             splitNode->left = newChild;
    //             splitNode->middle = right;
    //             splitNode->key[0] = key[1];
    //         }
    //         else {
    //                  // newChild is inserted as second child
    //             splitSmallest = key[1];
    //             splitNode->left = right;
    //             splitNode->middle = newChild;
    //             splitNode->key[0] = newSmallest;
    //         }
    //     }

    //     right = NULL;
    //     key[1] = NULL;

    //     if (parent->parent == NULL) {
    //              // At root, so new root needs to be created
    //         Node *newNode = new Node();

    //         parent->left = newNode;
    //         newNode->parent = parent;
    //         newNode->left = this;
    //         parent = newNode;
    //     }

    //     parent->insert(splitNode, splitSmallest);
    // }

// A utility function to insert a new key in this node
// The assumption is, the node must be non-full when this
// function is called
//    void insertNonFull(DataType k) {
//        // Initialize index as index of rightmost element
//        int i = n - 1;
//
//        // If this is a leaf node
//        if (leaf) {
//            // The following loop does two things
//            // a) Finds the location of new key to be inserted
//            // b) Moves all greater keys to one place ahead
//            while (i >= 0 && keys[i] > k) {
//                keys[i + 1] = keys[i];
//                i--;
//            }
//
//            // Insert the new key at found location
//            keys[i + 1] = k;
//            n = n + 1;
//        }
//        else // If this node is not leaf
//        {
//            // Find the child which is going to have the new key
//            while (i >= 0 && keys[i] > k)
//                i--;
//
//            // See if the found child is full
//            if (C[i + 1]->n == 2 * t - 1) {
//                // If the child is full, then split it
//                splitChild(i + 1, C[i + 1]);
//
//                // After split, the middle key of C[i] goes up and
//                // C[i] is splitted into two. See which of the two
//                // is going to have the new key
//                if (keys[i + 1] < k)
//                    i++;
//            }
//            C[i + 1]->insertNonFull(k);
//        }
//    }
//
//// A utility function to split the child y of this node
//// Note that y must be full when this function is called
//    void splitChild(int i, Node<DataType> *y) {
//        // Create a new node which is going to store (t-1) keys
//        // of y
//        Node<DataType> *z = new Node<DataType>(y->t, y->leaf);
//        z->n = t - 1;
//
//        // Copy the last (t-1) keys of y to z
//        for (int j = 0; j < t - 1; j++)
//            z->keys[j] = y->keys[j + t];
//
//        // Copy the last t children of y to z
//        if (!y->leaf) {
//            for (int j = 0; j < t; j++)
//                z->C[j] = y->C[j + t];
//        }
//
//        // Reduce the number of keys in y
//        y->n = t - 1;
//
//        // Since this node is going to have a new child,
//        // create space of new child
//        for (int j = n; j >= i + 1; j--)
//            C[j + 1] = C[j];
//
//        // Link the new child to this node
//        C[i + 1] = z;
//
//        // A key of y will move to this node. Find location of
//        // new key and move all greater keys one space ahead
//        for (int j = n - 1; j >= i; j--)
//            keys[j + 1] = keys[j];
//
//        // Copy the middle key of y to this node
//        keys[i] = y->keys[t - 1];
//
//        // Increment count of keys in this node
//        n = n + 1;
//    }

};

#endif
