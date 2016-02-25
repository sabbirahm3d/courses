#ifndef LIST341_H
#define LIST341_H

#include "Node341.h"

using namespace std;

template <class datatype>
class List341 {

public:

    List341();
    virtual ~List341();

    virtual int Size() const = 0;
    virtual bool Empty() const = 0;
    virtual bool Push(datatype value) = 0;
    virtual bool Pop() = 0;
    virtual bool Clear() = 0;

    // void Print();

protected:

    Node341<datatype>* head;
    Node341<datatype>* tail;
    int m_size;

};

#include "List341.cpp"
#endif