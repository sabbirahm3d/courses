#ifndef STACK341_CPP
#define STACK341_CPP


#include <iostream>

#include "Stack341.h"

using namespace std;


template <class datatype>
Stack341<datatype>::Stack341() {

    m_top = NULL;
    m_head = m_tail = NULL;
    m_size = 0;

}


template <class datatype>
Stack341<datatype>::~Stack341() {

    Clear();

}


template <class datatype>
int Stack341<datatype>::Size() const {

    return m_size;

}


template <class datatype>
bool Stack341<datatype>::Empty() const {

    if (m_head == NULL) {
        return true;
    }

    else {
        return false;
    }

}


template <class datatype>
bool Stack341<datatype>::Pop() {

    if (m_head == NULL) {
        return false;
    }

    else {
        Node341<datatype>* cursor = m_head;
        m_head = m_head->next;
        m_size--;
        cout << "Popped " << cursor->data << " from the list." << endl;
        delete(cursor);
        return true;
    }

}


template <class datatype>
datatype Stack341<datatype>::Top() {

    try {

        if ( Empty() ) {
            throw Exceptions341("Stack is empty.");
        }

        else {
            return m_tail->data;
        }

    }

    catch (Exceptions341 &E) { 
        cout << E.GetMessage();
    }

}


template <class datatype>
bool Stack341<datatype>::Push(datatype value) {

    Node341<datatype>* temp = new Node341<datatype>();

    temp->data = value;
    temp->next = NULL;

    if (m_head == NULL) {
        temp->prev = NULL;
        m_head = temp;
        m_tail = temp;
        m_size++;
        return true;
    }

    else if (m_tail != NULL) {
        m_tail->next = temp;
        m_tail = temp;
        m_size++;
        return true;
    }

    else {
        return false;
    }

    delete temp;
    temp = NULL;

}
 

template <class datatype>
bool Stack341<datatype>::Clear() {

    if (Empty()) {
        return false;
    }

    else {

        Node341< datatype > *store;
        Node341< datatype > *cursor = m_head;

        /* Traverse the list and delete the node one by one from the m_head */
        while (cursor != NULL) {

            /* update the m_head node */
            store = cursor;
            cursor = cursor -> next;

            /* take out the m_head node */
            delete store;
            store = NULL;
        }

        /* Reset the m_head and List341<datatype>::m_tail node */
        delete cursor;
        m_head = m_tail = NULL;
        m_size = 0;

        return true;
    }

}


#endif