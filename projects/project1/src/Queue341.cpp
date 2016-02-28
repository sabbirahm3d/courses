#ifndef QUEUE341_CPP
#define QUEUE341_CPP

#include "Queue341.h"
#include "Exceptions341.h"

#include <iostream>

using namespace std;


template <class datatype>
Queue341<datatype>::Queue341() : List341<datatype>::List341() {;

    m_front = m_back = NULL;
    m_size = List341<datatype>::m_size;

}


template <class datatype>
Queue341<datatype>::~Queue341() {

    Node341<datatype>* cursor = List341<datatype>::m_head;

    while (cursor != NULL) {
        Node341<datatype>* next = cursor->next;
        delete cursor;
        cursor = next;
    }

    delete cursor;
    cursor = NULL;

    List341<datatype>::m_head = List341<datatype>::m_tail = NULL;

    Clear();

}


template <class datatype>
int Queue341<datatype>::Size() const {

    return List341<datatype>::m_size;

}


template <class datatype>
bool Queue341<datatype>::Empty() const {

    if (List341<datatype>::m_head == NULL) {
        return true;
    }

    else {
        return false;
    }

}


template <class datatype>
bool Queue341<datatype>::Pop() {

    if (List341<datatype>::m_head == NULL) {
        return false;
    }

    else {
        Node341<datatype>* cursor = List341<datatype>::m_head;
        List341<datatype>::m_head = List341<datatype>::m_head->next;
        List341<datatype>::m_size--;
        cout << "Popped " << cursor->data << " from the list." << endl;
        delete(cursor);
        return true;
    }

}


template <class datatype>
datatype Queue341<datatype>::Front() {

    try {

        if ( Empty() ) {
            throw Exceptions341("Queue is empty.");
        }

        else {
            return List341<datatype>::m_head->data;
        }

    }

    catch (Exceptions341 &E) { 
        return E.GetMessage();
    }

}


template <class datatype>
datatype Queue341<datatype>::Back() {

    try {

        if ( Empty() ) {
            throw Exceptions341("Queue is empty.");
        }

        else {
            return List341<datatype>::m_tail->data;
        }

    }

    catch (Exceptions341 &E) { 
        return E.GetMessage();
    }

}


template <class datatype>
bool Queue341<datatype>::Push(datatype value) {

    Node341<datatype>* temp = new Node341<datatype>();

    temp->data = value;
    temp->next = NULL;

    if (List341<datatype>::m_head == NULL) {
        temp->prev = NULL;
        List341<datatype>::m_head = temp;
        List341<datatype>::m_size++;
        List341<datatype>::m_tail = temp;
        return true;
    }

    else if (List341<datatype>::m_tail != NULL) {
        List341<datatype>::m_tail->next = temp;
        List341<datatype>::m_size++;
        List341<datatype>::m_tail = temp;
        return true;
    }

    else {
        return false;
    }

}
 

template <class datatype>
bool Queue341<datatype>::Clear() {

    if (List341<datatype>::m_head == NULL){
        return false;
    }

    else {

        Node341<datatype> *cursor = List341<datatype>::m_head;
        
        /* Traverse the list and delete the node one by one from the List341<datatype>::m_head */
        while (cursor != NULL) {
            /* take out the List341<datatype>::m_head node */
            List341<datatype>::m_head = List341<datatype>::m_head->next;
            delete cursor;
            /* update the List341<datatype>::m_head node */
            cursor = List341<datatype>::m_head;
        }
        /* Reset the List341<datatype>::m_head and List341<datatype>::m_tail node */
        List341<datatype>::m_head = NULL;

        List341<datatype>::m_size = 0;

        return true;
    }

}


template <class datatype>
void Queue341<datatype>::Print() {

    Node341<datatype> *q = new Node341<datatype>();
    if (List341<datatype>::m_head == NULL) {
        cout<<"List empty,nothing to display"<<endl;
        return;
    }

    q = List341<datatype>::m_head;
    cout << "The Doubly Link List is :"<<endl;
    while (q != NULL) {
        cout<<q->data<<" <-> ";
        q = q->next;
    }

    cout<<"NULL"<<endl;

}

#endif