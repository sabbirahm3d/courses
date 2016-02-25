#ifndef STACK341_CPP
#define STACK341_CPP

#include "Stack341.h"
#include <iostream>

using namespace std;

// template <class datatype>
// Stack341<datatype>::Stack341() : List341<datatype>::List341() {
//   top = -1;
//   // maxelem = num;
//   // s = new T[maxelem];
// }

template <class datatype>
int Stack341<datatype>::Size() const {

    return List341<datatype>::m_size;

}


template <class datatype>
bool Stack341<datatype>::Empty() const {

    if (head == NULL) {
        return true;
    }

    else {
        return false;
    }

}


template <class datatype>
bool Stack341<datatype>::Pop() {

    if (head == NULL) {
        return false;
    }

    else {
        Node341<datatype>* cursor = head;
        head = head->next;
        m_size--;
        cout << "Popped " << cursor->data << " from the list." << endl;
        delete(cursor);
        return true;
    }

}


template <class datatype>
bool Stack341<datatype>::Push(datatype value) {

    Node341<datatype>* temp = new Node341<datatype>();

    temp->data = value;
    temp->next = NULL;

    if (head == NULL) {
        temp->prev = NULL;
        head = temp;
        m_size++;
        tail = temp;
        return true;
    }

    else if (tail != NULL) {
        tail->next = temp;
        m_size++;
        tail = temp;
        return true;
    }

    else {
        return false;
    }

}
 

template <class datatype>
bool Stack341<datatype>::Clear() {

    if (head == NULL){
        return false;
    }

    else {

        Node341<datatype> *cursor = head;
        
        /* Traverse the list and delete the node one by one from the head */
        while (cursor != NULL) {
            /* take out the head node */
            head = head->next;
            delete cursor;
            /* update the head node */
            cursor = head;
        }
        /* Reset the head and tail node */
        head = NULL;

        m_size = 0;

        return true;
    }

}
 
/*
 * Display elements of Doubly Link List
 */
template <class datatype>
void Stack341<datatype>::Print() {

    Node341<datatype> *q = new Node341<datatype>();
    if (head == NULL) {
        cout<<"List empty,nothing to display"<<endl;
        return;
    }

    q = head;
    cout<<"The Doubly Link List is :"<<endl;
    while (q != NULL) {
        cout<<q->data<<" <-> ";
        q = q->next;
    }

    cout<<"NULL"<<endl;

}


// template <class T>
// Stack341<T>::Stack341(const int num)
// {
//   top = -1;
//   maxelem = num;
//   s = new T[maxelem];
// }

// template <class T>
// void Stack341<T>::push(const T t)
// {
//   if (top == maxelem) { return; }
//   s[++top] = t;
// }

// template <class T>
// T Stack341<T>::pop()
// {
//   if (top == -1) { return -1; }
//   return s[--top];
// }

// template <class T>
// T Stack341<T>::peek()
// {
//   if (top == -1) { return -1; }
//   return s[top];
// }

// template <class T>
// void Stack341<T>::display()
// {
//   if (top == -1) { cout << "(empty)\n";  return; }
//   for (int t=0; t <= top; t++) { cout << s[t] << " "; }
//   cout << "\n";
// }

// template <class T>
// T Stack341<T>::empty() {  return top == -1;  }

#endif