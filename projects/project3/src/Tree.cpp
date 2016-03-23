#ifndef TREE_CPP
#define TREE_CPP

/* Stubs for the tree's methods */

template <typename DataType, typename Compare>
Tree<DataType, Compare>::Tree()
{
    /* Your code here... */    
}

template <typename DataType, typename Compare>
Tree<DataType, Compare>::Tree(const Tree<DataType, Compare> &other)
{
    /* Your code here... */    
}

template <typename DataType, typename Compare>
Tree<DataType, Compare> &
Tree<DataType, Compare>::operator=(const Tree<DataType, Compare> &other)
{
    /* Your code here... */    
}

template <typename DataType, typename Compare>
Tree<DataType, Compare>::~Tree()
{
    /* Your code here... */    
}

template <typename DataType, typename Compare>
void Tree<DataType, Compare>::insert(DataType data)
{
    /* Your code here... */    
}

template <typename DataType, typename Compare>
bool Tree<DataType, Compare>::empty() const
{
    /* Your code here... */    
    return false;
}

template <typename DataType, typename Compare>
size_t Tree<DataType, Compare>::size() const
{
    /* Your code here... */    
    return 0;
}

template <typename DataType, typename Compare>
typename Tree<DataType, Compare>::iterator Tree<DataType, Compare>::begin()
{
    /* Your code here... */    
    return iterator();
}

template <typename DataType, typename Compare>
typename Tree<DataType, Compare>::iterator Tree<DataType, Compare>::end()
{
    /* Your code here... */    
    return iterator();
}

template <typename DataType, typename Compare>
template <typename KeyType>
typename Tree<DataType, Compare>::iterator 
Tree<DataType, Compare>::find_first(KeyType key)
{
    /* Your code here... */    
    return iterator();
}

template <typename DataType, typename Compare>
template <typename KeyType>
typename Tree<DataType, Compare>::iterator 
Tree<DataType, Compare>::find_last(KeyType key)
{
    /* Your code here... */    
    return iterator();
}

template <typename DataType, typename Compare>
template <typename KeyType>
std::pair<typename Tree<DataType, Compare>::iterator,
          typename Tree<DataType, Compare>::iterator>
Tree<DataType, Compare>::find_range(KeyType key)
{
    /* Your code here... */
    return std::make_pair(iterator(), iterator());
}

template <typename DataType, typename Compare>
std::ostream &operator<<(std::ostream &stream,
                         const Tree<DataType, Compare> &tree)
{
    /* Your code here... */
    return stream;
}

#endif
