#ifndef STACK341_CPP
#define STACK341_CPP

#include "Stack341.h"
#include <iostream>

using namespace std;


template <class datatype>
Stack341<datatype>::Stack341() : List341<datatype>::List341() {;

    m_top = NULL;
    m_size = List341<datatype>::m_size;

}


template <class datatype>
int Stack341<datatype>::Size() const {

    return m_size;

}


template <class datatype>
bool Stack341<datatype>::Empty() const {

    if (List341<datatype>::head == NULL) {
        return true;
    }

    else {
        return false;
    }

}


template <class datatype>
bool Stack341<datatype>::Pop() {

    if (List341<datatype>::head == NULL) {
        return false;
    }

    else {
        Node341<datatype>* cursor = List341<datatype>::head;
        List341<datatype>::head = List341<datatype>::head->next;
        m_size--;
        cout << "Popped " << cursor->data << " from the list." << endl;
        delete(cursor);
        return true;
    }

}


template <class datatype>
datatype Stack341<datatype>::Top() {

    return List341<datatype>::tail->data;

}


template <class datatype>
bool Stack341<datatype>::Push(datatype value) {

    Node341<datatype>* temp = new Node341<datatype>();

    temp->data = value;
    temp->next = NULL;

    if (List341<datatype>::head == NULL) {
        temp->prev = NULL;
        List341<datatype>::head = temp;
        m_size++;
        List341<datatype>::tail = temp;
        return true;
    }

    else if (List341<datatype>::tail != NULL) {
        List341<datatype>::tail->next = temp;
        m_size++;
        List341<datatype>::tail = temp;
        return true;
    }

    else {
        return false;
    }

}
 

template <class datatype>
bool Stack341<datatype>::Clear() {

    if (List341<datatype>::head == NULL){
        return false;
    }

    else {

        Node341<datatype> *cursor = List341<datatype>::head;
        
        /* Traverse the list and delete the node one by one from the List341<datatype>::head */
        while (cursor != NULL) {
            /* take out the List341<datatype>::head node */
            List341<datatype>::head = List341<datatype>::head->next;
            delete cursor;
            /* update the List341<datatype>::head node */
            cursor = List341<datatype>::head;
        }
        /* Reset the List341<datatype>::head and List341<datatype>::tail node */
        List341<datatype>::head = NULL;

        m_size = 0;

        return true;
    }

}


template <class datatype>
void Stack341<datatype>::Print() {

    Node341<datatype> *q = new Node341<datatype>();
    if (List341<datatype>::head == NULL) {
        cout<<"List empty,nothing to display"<<endl;
        return;
    }

    q = List341<datatype>::head;
    cout << "The Doubly Link List is :"<<endl;
    while (q != NULL) {
        cout<<q->data<<" <-> ";
        q = q->next;
    }

    cout<<"NULL"<<endl;

}

#endif