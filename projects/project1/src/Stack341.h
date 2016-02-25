#ifndef STACK341_H
#define STACK341_H

#include "List341.h"
#include "List341.cpp"
#include <iostream>
using namespace std;

template <class datatype>
class Stack341 : public List341<datatype> {

private:

datatype *s; // this is the array portion of the stack341
datatype top;
datatype maxelem;

public:

    Stack341() : List341<datatype>::List341() {
      top = -1;
      // maxelem = num;
      // s = new T[maxelem];
    }

    virtual int Size() const;
    virtual bool Empty() const;
    virtual bool Push(datatype value);
    virtual bool Pop();
    virtual bool Clear();

    void Print();

    // friend ostream &operator << (ostream &os, const Stack341<datatype> &x) {

    //     if (x.top == -1) { os << "(empty)\n";  return os; }
    //         for (int t=x.top; t > -1 ; t--)
    //         { os << "[" << t << "] ->" << x.s[t] << " " << endl; }
    //         os << "\n";
    //         return os;
    //     }

    };

#include "Stack341.cpp"
#endif