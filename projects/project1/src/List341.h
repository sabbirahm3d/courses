#ifndef LIST341_H
#define LIST341_H

#include "Node341.h"

using namespace std;

template <class datatype>
class List341 {

public:

    List341();
    virtual ~List341();
    virtual bool Push(datatype value);
    virtual bool Empty() const;
    // void add_after(datatype value, datatype position);
    virtual bool Clear();
    // void search_element(datatype value);
    void display_dlist();
    virtual int Size() const;
    // void reverse();

    Node341<datatype>* head;


};

#include "List341.cpp"
#endif