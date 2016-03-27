#ifndef TREE_ITERATOR_CPP
#define TREE_ITERATOR_CPP


template <typename DataType, typename Compare>
Tree<DataType, Compare>::iterator::iterator() {
    /* Your code here... */
}


template <typename DataType, typename Compare>
Tree<DataType, Compare>::iterator::iterator(const iterator &other) {
    /* Your code here... */
}


template <typename DataType, typename Compare>
typename Tree<DataType, Compare>::iterator &
Tree<DataType, Compare>::iterator::operator=(const iterator &other) {
    /* Your code here... */
    return *this;

}


template <typename DataType, typename Compare>
bool Tree<DataType, Compare>::iterator::operator==(
      const iterator &other) const {

    /* Your code here... */
    return false;

}


template <typename DataType, typename Compare>
bool Tree<DataType, Compare>::iterator::operator!=(
      const iterator &other) const {
    /* Your code here... */
    return false;
}


template <typename DataType, typename Compare>
DataType Tree<DataType, Compare>::iterator::operator*() const {
    /* Your code here... */
    return DataType();

}


template <typename DataType, typename Compare>
typename Tree<DataType, Compare>::iterator &
Tree<DataType, Compare>::iterator::operator++() {
    /* Your code here... */   
    return *this;

}


template <typename DataType, typename Compare>
typename Tree<DataType, Compare>::iterator
Tree<DataType, Compare>::iterator::operator++(int unused) {
    /* Your code here... */
    return *this;

}


#endif