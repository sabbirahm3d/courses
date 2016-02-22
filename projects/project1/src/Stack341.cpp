#ifndef STACK341_CPP
#define STACK341_CPP

#include "Stack341.h"
#include <iostream>

using namespace std;

template <class T>
Stack341<T>::Stack341(const int num)
{
  top = -1;
  maxelem = num;
  s = new T[maxelem];
}

template <class T>
void Stack341<T>::push(const T t)
{
  if (top == maxelem) { return; }
  s[++top] = t;
}

template <class T>
T Stack341<T>::pop()
{
  if (top == -1) { return -1; }
  return s[--top];
}

template <class T>
T Stack341<T>::peek()
{
  if (top == -1) { return -1; }
  return s[top];
}

template <class T>
void Stack341<T>::display()
{
  if (top == -1) { cout << "(empty)\n";  return; }
  for (int t=0; t <= top; t++) { cout << s[t] << " "; }
  cout << "\n";
}

template <class T>
T Stack341<T>::empty() {  return top == -1;  }

#endif