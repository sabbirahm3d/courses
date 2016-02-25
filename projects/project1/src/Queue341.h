#ifndef QUEUE341_H
#define QUEUE341_H

#include "List341.h"
#include "List341.cpp"
#include <iostream>

using namespace std;

template <class datatype>
class Queue341 : public List341<datatype> {

private:

    datatype *m_front;
    datatype *m_back;

public:

    Queue341() : List341<datatype>::List341() {

        m_front = m_back = NULL;

    }

    datatype Front();
    datatype Back();

    virtual int Size() const;
    virtual bool Empty() const;
    virtual bool Push(datatype value);
    virtual bool Pop();
    virtual bool Clear();

    void Print();

    };


#include "Queue341.cpp"
#endif