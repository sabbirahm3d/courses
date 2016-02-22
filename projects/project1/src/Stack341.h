#ifndef STACK_H_
#define STACK_H_

#include <iostream>
using namespace std;

template <class T>
class Stack
{
 private:
  T *s; // this is the array portion of the stack
  int top;
  int maxelem;

 public:
  Stack(const int num);
  void push(const T t);
  T pop();
  T peek();
  void display();
  T empty();

  friend ostream &operator << (ostream &os, const Stack<T> &x)
  {
    if (x.top == -1) { os << "(empty)\n";  return os; }
    for (int t=x.top; t > -1 ; t--)
    { os << "[" << t << "] ->" << x.s[t] << " " << endl; }
    os << "\n";
    return os;
  }
};
// this is needed in order to work with template (reason later)
#include "Stack.cpp"
#endif