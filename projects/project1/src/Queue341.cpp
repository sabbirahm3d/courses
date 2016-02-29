#ifndef QUEUE341_CPP
#define QUEUE341_CPP


#include <iostream>

#include "Queue341.h"

using namespace std;


template < class datatype >
Queue341< datatype >::Queue341() {

    m_front = m_back = NULL;
    m_head = m_tail = NULL;
    m_size = 0;

}


template < class datatype >
Queue341< datatype >::~Queue341() {

    Clear();

}


template < class datatype >
int Queue341< datatype >::Size() const { return m_size; }

template < class datatype >
bool Queue341< datatype >::Empty() const {

    return (m_head == NULL && m_tail == NULL); 

}


template < class datatype >
bool Queue341< datatype >::Pop() {

    if (m_head == NULL) {
        return false;
    }

    else {
        Node341< datatype > *cursor = m_head;
        m_head = m_head -> next;
        m_size--;
        cout << "Popped " << cursor -> data << " from the list." << endl;
        delete (cursor);
        return true;
    }

}


template < class datatype >
datatype Queue341< datatype >::Front() {

    try {

        if (Empty()) {
            throw Exceptions341("Queue is empty.");
        }

        else {
            return m_head -> data;
        }

    }

    catch (Exceptions341 &E) {
        cout << E.GetMessage();
    }

}


template < class datatype >
datatype Queue341< datatype >::Back() {

    try {

        if (Empty()) {
            throw Exceptions341("Queue is empty.");
        }

        else {
            return m_tail -> data;
        }

    }

    catch (Exceptions341 &E) {
        cout << E.GetMessage();
    }

}


template < class datatype >
bool Queue341< datatype >::Push(datatype value) {

    Node341< datatype > *temp = new Node341< datatype >();

    temp -> data = value;
    temp -> next = NULL;

    if (m_head == NULL) {
        temp -> prev = NULL;
        m_head = temp;
        m_tail = temp;
        m_size++;
        return true;
    }

    else if (m_tail != NULL) {
        m_tail -> next = temp;
        m_tail = temp;
        m_size++;
        return true;
    }

    else {
        return false;
    }

}


template < class datatype >
bool Queue341< datatype >::Clear() {

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