#ifndef NODE_H
#define NODE_H


/* Node structure for use in 2-3 trees */

template <typename DataType>
struct Node {

	// DataType keys[2];
	Node *left, *middle, *right, *parent;


	Node() : left(NULL), middle(NULL), right(NULL), parent(NULL) {}

	bool is_leaf() {

		return (left == NULL && middle == NULL && right == NULL);

	}

    // Insert into a node with 2 children
	void insert2Siblings(Node *newChild, DataType newSmallest) {

		int newKey = newChild->key[0];
		newChild->parent = this;

		if (newKey < child[0]->key[0]) {
			child[2] = child[1];
			child[1] = child[0];
			child[0] = newChild;

			key[1] = key[0];
			key[0] = child[1]->getSmallest();
			updateParentSmallest(newSmallest);
		}
		else if (newKey < child[1]->key[0]) {
			child[2] = child[1];
			child[1] = newChild;

			key[1] = key[0];
			key[0] = newSmallest;
		}
		else {
			child[2] = newChild;

			key[1] = newSmallest;
		}
	}

        // Insert into a node with 3 children
	// void insert3Siblings(Node *newChild, int newSmallest) {
	// 	int newKey = newChild->key[0];

	// 	int splitSmallest = -1;
	// 	Node *splitNode = new Node();
	// 	splitNode->parent = parent;

	// 	if (newKey < child[0]->key[0] || newKey < child[1]->key[0]) {
 //                // newChild is inserted in current node
	// 		splitSmallest = key[0];
	// 		splitNode->child[0] = child[1];
	// 		splitNode->child[1] = child[2];
	// 		splitNode->key[0] = key[1];

	// 		child[1]->parent = splitNode;
	// 		child[2]->parent = splitNode;
	// 		newChild->parent = this;

	// 		if (newKey < child[0]->key[0]) {
 //                    // newChild is inserted as first child
	// 			child[1] = child[0];
	// 			child[0] = newChild;

	// 			key[0] = child[1]->getSmallest();
	// 			updateParentSmallest(newSmallest);
	// 		}
	// 		else {
 //                    // newChild is inserted as second child
	// 			child[1] = newChild;

	// 			key[0] = newSmallest;
	// 		}
	// 	}
	// 	else {
 //                // newChild is inserted in split node
	// 		child[2]->parent = splitNode;
	// 		newChild->parent = splitNode;

	// 		if (newKey < child[2]->key[0]) {
 //                    // newChild is inserted as first child
	// 			splitSmallest = newSmallest;
	// 			splitNode->child[0] = newChild;
	// 			splitNode->child[1] = child[2];
	// 			splitNode->key[0] = key[1];
	// 		}
	// 		else {
 //                    // newChild is inserted as second child
	// 			splitSmallest = key[1];
	// 			splitNode->child[0] = child[2];
	// 			splitNode->child[1] = newChild;
	// 			splitNode->key[0] = newSmallest;
	// 		}
	// 	}

	// 	child[2] = NULL;
	// 	key[1] = -1;

	// 	if (parent->parent == NULL) {
 //                // At root, so new root needs to be created
	// 		Node *newNode = new Node();

	// 		parent->child[0] = newNode;
	// 		newNode->parent = parent;
	// 		newNode->child[0] = this;
	// 		parent = newNode;
	// 	}

	// 	parent->insert(splitNode, splitSmallest);
	// }


};


#endif
