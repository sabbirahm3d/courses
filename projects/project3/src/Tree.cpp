#ifndef TREE_CPP
#define TREE_CPP

/* Stubs for the tree's methods */

template <typename DataType, typename Compare>
Tree<DataType, Compare>::Tree() {

    root = new Node<DataType>();
    root->left = new Node<DataType>();
    root->left->parent = root;

}


template <typename DataType, typename Compare>
Tree<DataType, Compare>::Tree(const Tree<DataType, Compare> &other) {
    /* Your code here... */    
}


template <typename DataType, typename Compare>
Tree<DataType, Compare> &
Tree<DataType, Compare>::operator=(const Tree<DataType, Compare> &other) {
    /* Your code here... */    
}


template <typename DataType, typename Compare>
Tree<DataType, Compare>::~Tree() {
    /* Your code here... */    
}


template <typename DataType, typename Compare>
void Tree<DataType, Compare>::insert(DataType data) {

    Node<DataType>* newNode = new Node<DataType>(data);
    Node<DataType>* cursor = root->left;

    if (cursor->left == NULL) {

        // First insertion
        newNode->parent = cursor;
        cursor->left = newNode;

    }

    else {

        cursor = find_position(cursor, data);
        if (cursor == NULL) return;

        if (cursor->middle == NULL) cursor->insert1Siblings(new Node<DataType>(data), data);
        else if (cursor->right == NULL) cursor->insert2Siblings(new Node<DataType>(data), data);
        else cursor->insert3Siblings(new Node<DataType>(data), data);

        // cursor->insert(new Node<DataType>(data), data);
    }
    
}


template <typename DataType, typename Compare>
bool Tree<DataType, Compare>::empty() const {
    /* Your code here... */    
    return false;
}


template <typename DataType, typename Compare>
size_t Tree<DataType, Compare>::size() const {
    /* Your code here... */    
    return 0;
}


template <typename DataType, typename Compare>
typename Tree<DataType, Compare>::iterator Tree<DataType, Compare>::begin() {
    /* Your code here... */    
    return iterator();
}


template <typename DataType, typename Compare>
typename Tree<DataType, Compare>::iterator Tree<DataType, Compare>::end() {
    /* Your code here... */    
    return iterator();

}


template <typename DataType, typename Compare>
template <typename KeyType>
typename Tree<DataType, Compare>::iterator 
Tree<DataType, Compare>::find_first(KeyType key) {
    /* Your code here... */    
    return iterator();

}


template <typename DataType, typename Compare>
template <typename KeyType>
typename Tree<DataType, Compare>::iterator 
Tree<DataType, Compare>::find_last(KeyType key) {
    /* Your code here... */    
    return iterator();
}


template <typename DataType, typename Compare>
template <typename KeyType>
std::pair<typename Tree<DataType, Compare>::iterator,
typename Tree<DataType, Compare>::iterator>
Tree<DataType, Compare>::find_range(KeyType key) {
    /* Your code here... */
    return std::make_pair(iterator(), iterator());

}


template <typename DataType, typename Compare>
std::ostream &operator<<(std::ostream &stream,
    const Tree<DataType, Compare> &tree) {
    /* Your code here... */
    return stream;

}


template <typename DataType, typename Compare>
Node<DataType>* find_position(Node<DataType>* node, DataType data) {

    if (node == NULL) return NULL;

    while (!node->isLeaf()) {

        if (node->key[0] == data || node->key[1] == data)
            return NULL;

        if (node->key[0] == -1 || data < node->key[0])
            node = node->child[0];

        else if (node->key[1] == -1 || data < node->key[1])
            node = node->middle;

        else
            node = node->right;

    }

    if (node->key[0] == data) return NULL;
    return node->parent;
}


#endif