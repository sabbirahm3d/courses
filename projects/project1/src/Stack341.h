#ifndef STACK341_H
#define STACK341_H


#include "List341.cpp"

template <class datatype>
class Stack341 : public List341<datatype> {

public:

Stack341();
~Stack341();

virtual int Size() const;
virtual bool Empty() const;
virtual bool Push(datatype value);
virtual bool Pop();
virtual bool Clear();
datatype Top();

private:

Node341<datatype>* m_head;
Node341<datatype>* m_tail;
datatype *m_top;
int m_size;

};


#include "Stack341.cpp"
#endif