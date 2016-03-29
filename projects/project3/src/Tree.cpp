#ifndef TREE_CPP
#define TREE_CPP

#include "Tree.h"

/* Stubs for the tree's methods */

template < typename DataType, typename Compare >
Tree< DataType, Compare >::Tree() {

	// root = new Node<DataType>();
	// root->left = new Node<DataType>();
	// root->left->parent = root;

	root = NULL;

}


template < typename DataType, typename Compare >
Tree< DataType, Compare >::Tree(const Tree< DataType, Compare > &other) {
	/* Your code here... */
}


template < typename DataType, typename Compare >
Tree< DataType, Compare > &
Tree< DataType, Compare >::operator=(const Tree< DataType, Compare > &other) {
	/* Your code here... */
}


template < typename DataType, typename Compare >
Tree< DataType, Compare >::~Tree() {

	root = NULL;

}


template < typename DataType, typename Compare >
void Tree< DataType, Compare >::insert(DataType data) {

//    if (root == NULL) {
//
//        root = new Node<DataType>;
//        root->key[0] = data;
//
//    } else {
//
//        std::stack<Node<DataType>* > s = search(root, data);
//        std::stack<Node<DataType>* > butts(s);
//
//        while (!butts.empty()) {
//
//            std::cout << butts.top() << std::endl;
//            butts.pop();
//
//        }
//    }

}


template < typename DataType, typename Compare >
bool Tree< DataType, Compare >::empty() const {
	/* Your code here... */
	return false;
}


template < typename DataType, typename Compare >
size_t Tree< DataType, Compare >::size() const {
	/* Your code here... */
	return 0;
}


template < typename DataType, typename Compare >
typename Tree< DataType, Compare >::iterator Tree< DataType, Compare >::begin() {
	/* Your code here... */
	return iterator();
}


template < typename DataType, typename Compare >
typename Tree< DataType, Compare >::iterator Tree< DataType, Compare >::end() {
	/* Your code here... */
	return iterator();

}


template < typename DataType, typename Compare >
template < typename KeyType >
typename Tree< DataType, Compare >::iterator
Tree< DataType, Compare >::find_first(KeyType key) {
	/* Your code here... */
	return iterator();

}


template < typename DataType, typename Compare >
template < typename KeyType >
typename Tree< DataType, Compare >::iterator
Tree< DataType, Compare >::find_last(KeyType key) {
	/* Your code here... */
	return iterator();
}


template < typename DataType, typename Compare >
template < typename KeyType >
std::pair< typename Tree< DataType, Compare >::iterator,
	typename Tree< DataType, Compare >::iterator >
Tree< DataType, Compare >::find_range(KeyType key) {
	/* Your code here... */
	return std::make_pair(iterator(), iterator());

}


template < typename DataType, typename Compare >
std::ostream &operator<<(std::ostream &stream,
												 const Tree< DataType, Compare > &tree) {
	/* Your code here... */
	return stream;

}


template < typename DataType, typename Compare >
std::stack< Node< DataType > * > search(Node< DataType > *node, DataType data) {

	// Searches the tree for the data and returns an
	// inorder stack of node pointers

	std::stack< Node< DataType > * > s;

	while (node != NULL) {

		s . push(node);

		if (is_two_node(node)) {

			if (data == node -> key[0]) {

			} else if (data < node -> key[0]) {

				node = node -> left;

			} else {

				node = node -> middle;

			} // if else

		} else {

			// if ((data == node->key[0]) || (data == node->key[1])) {

			//   break;

			// }

			if (data < node -> key[0]) {

				node = node -> left;

			} else if (data < node -> key[1]) {

				node = node -> middle;

			} else {

				node = node -> right;

			} // if else

		} // if else

	} // while

	// cout << "search works!" << endl;

	return s;

}

#endif