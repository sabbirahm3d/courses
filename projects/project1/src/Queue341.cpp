#ifndef QUEUE341_CPP
#define QUEUE341_CPP


#include <iostream>

#include "Queue341.h"

using namespace std;


template <class datatype>
Queue341<datatype>::Queue341() {

    m_front = m_back = NULL;
    m_size = 0;

}


template <class datatype>
Queue341<datatype>::~Queue341() {

    // Clear();
    // Node341<datatype> *cursor = m_head;

    /* Traverse the list and delete the node one by one from the m_head */
    // while (cursor != NULL) {
    //     /* take out the m_head node */
    //     m_head = m_head->next;
    //     delete cursor;
    //     /* update the m_head node */
    //     cursor = m_head;
    // }
    /* Reset the m_head and List341<datatype>::m_tail node */
    m_head = m_tail = NULL;

    m_size = 0;

}


template <class datatype>
int Queue341<datatype>::Size() const {

    return m_size;

}


template <class datatype>
bool Queue341<datatype>::Empty() const {

    if (m_head == NULL) {
        return true;
    }

    else {
        return false;
    }

}


template <class datatype>
bool Queue341<datatype>::Pop() {

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
datatype Queue341<datatype>::Front() {

    try {

        if ( Empty() ) {
            throw Exceptions341("Queue is empty.");
        }

        else {
            return m_head->data;
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

    if (m_head == NULL) {
        temp->prev = NULL;
        m_head = temp;
        List341<datatype>::m_tail = temp;
        m_size++;
        return true;
    }

    else if (List341<datatype>::m_tail != NULL) {
        List341<datatype>::m_tail->next = temp;
        List341<datatype>::m_tail = temp;
        m_size++;
        return true;
    }

    else {
        return false;
    }

}
 

template <class datatype>
bool Queue341<datatype>::Clear() {

    if (m_head == NULL) {
        return false;
    }

    else {

        Node341<datatype> *cursor = m_head;

        /* Traverse the list and delete the node one by one from the m_head */
        while (cursor != NULL) {
            /* take out the m_head node */
            m_head = m_head->next;
            delete cursor;
            /* update the m_head node */
            cursor = m_head;
        }
        /* Reset the m_head and List341<datatype>::m_tail node */
        m_head = NULL;

        m_size = 0;

        return true;
    }

}


#endif