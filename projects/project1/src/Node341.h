#ifndef NODE341_H
#define NODE341_H

using namespace std;

template <class datatype>
class Node341 {

public:

    datatype data;
    Node341 *next;
    Node341 *prev;

};

#include "Node341.cpp"
#endif