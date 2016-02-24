#ifndef NODE341_H
#define NODE341_H

#include <iostream>

using namespace std;

template <class datatype>
class node {

public:

    Node341();
    Node341(const Node& orig);
    virtual ~Node341();
    bool hasNext();
    Node341* getNext();
    void setNext(Node341* newNext);
    Node341* getPrev();
    void setPrev(Node341* newPrev);
    datatype getValue();
    void setValue(datatype val);

private:

    datatype data;
    node *next;
    node *prev;

};

#include "Node341.cpp"
#endif