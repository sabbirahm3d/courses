#ifndef NODE_H
#define NODE_H


/* Node structure for use in 2-3 trees */

template <typename DataType>
struct Node {

    DataType key[2];
    Node *left, *middle, *right, *parent;


    // Node() : left(NULL), middle(NULL), right(NULL), parent(NULL) {}


    // Node(DataType data) : left(NULL), middle(NULL), right(NULL), parent(NULL) {

    //     key[0] = data;
    //     key[1] = NULL;

    // }


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


};


#endif
