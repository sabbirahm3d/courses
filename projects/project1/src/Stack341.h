#ifndef STACK341_H
#define STACK341_H

#include "List341.h"

#include <iostream>
using namespace std;

template <class datatype>
class Stack341 : public List341<datatype> {

private:

    datatype *m_top;
    int m_size;

public:


    Stack341();
    ~Stack341();

    virtual int Size() const;
    virtual bool Empty() const;
    virtual bool Push(datatype value);
    virtual bool Pop();
    virtual bool Clear();

    datatype Top();
    void Print();

    };

#include "Stack341.cpp"
#endif