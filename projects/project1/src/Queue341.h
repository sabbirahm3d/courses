#ifndef QUEUE341_H
#define QUEUE341_H


#include "List341.cpp"

template <class datatype>
class Queue341 : public List341<datatype> {

public:

Queue341();
~Queue341();

datatype Front();
datatype Back();

virtual int Size() const;
virtual bool Empty() const;
virtual bool Push(datatype value);
virtual bool Pop();
virtual bool Clear();


private:

Node341<datatype>* m_head;
Node341<datatype>* m_tail;
datatype *m_front;
datatype *m_back;
int m_size;

};


#include "Queue341.cpp"
#endif