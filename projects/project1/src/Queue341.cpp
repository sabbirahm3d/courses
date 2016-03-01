/* File:    Queue341.cpp
 * Project: CMSC 341: Project 1, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    2/27/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * The implementation file for the Queue341 class. This file inherits from the
 * List341 class implements the methods as per the project description to 
 * simulate a queue linked list.
 */

#ifndef QUEUE341_CPP
#define QUEUE341_CPP


#include "Queue341.h"


/* ******************** Constructors ******************** */

/* Queue341()
 * Default constructor; creates a List341 object and initializes its
   attributes to NULL and 0 */

template <class datatype>
Queue341< datatype >::Queue341() {

    m_front = m_back = NULL;
    m_head = m_tail = NULL;
    m_size = 0;

}


/* ******************** Destructors ******************** */

/* ~Queue341()
 * Default destructor; calls the Clear method */

template <class datatype>
Queue341< datatype >::~Queue341() { Clear(); }


/* ******************** Stack341 methods ******************** */

/* Size()
 * Returns the size of the queue */

template <class datatype>
int Queue341< datatype >::Size() const { return m_size; }


/* Empty()
 * Returns true if the stack is empty, false otherwise */

template <class datatype>
bool Queue341< datatype >::Empty() const {

    return (m_head == NULL && m_tail == NULL); 

}


/* Pop()
 * Pops the first element of the queue to implement a pop_front method */

template <class datatype>
bool Queue341< datatype >::Pop() {

    if ( Empty() ) {
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


/* Push()
 * Pushes data into the stack, and returns true if success */

template <class datatype>
bool Queue341<datatype>::Push(datatype value) {

    // create a cursor pointer to move all the elements
    Node341<datatype>* cursor = new Node341<datatype>();

    cursor->data = value;
    cursor->next = NULL;

    // If list is empty, value is the only element
    if ( Empty() ) {
        cursor->prev = NULL;
        m_head = cursor;
        m_tail = cursor;
        m_size++;
        return true;
    }

    // If list is not empty, all the elements get pushed
    else if ( !Empty() ) {
        m_tail->next = cursor;
        m_tail = cursor;
        m_size++;
        return true;
    }

    else {
        return false;
    }

    delete cursor;
    cursor = NULL;

}


/* Clear()
 * Clears the Stack341 object */

template <class datatype>
bool Queue341< datatype >::Clear() {

    if ( Empty() ) {
        return false;
    }

    else {

        // Temporary pointers to Node341 objects
        Node341< datatype > *temp;
        Node341< datatype > *cursor = m_head;

        // Traverse the list and delete the nodes one by one from the m_head
        while (cursor != NULL) {

            // iterate the cursor through
            temp = cursor;
            cursor = cursor -> next;

            // take out the pointer to the cursor 
            delete temp;
            temp = NULL;
        }

        /* Reset the m_head and m_tail node */
        delete cursor;
        m_head = m_tail = NULL;
        m_size = 0;

        return true;
    }

}


/* Front()
 * Returns the front element of the queue */

template <class datatype>
datatype Queue341< datatype >::Front() {

    try {

        // Throws an exception if queue is empty
        if ( Empty() ) {
            throw Exceptions341("Queue is empty, cannot call Front()\n");
        }

        else {
            return m_head -> data;
        }

    }

    catch (Exceptions341 &E) {
        cout << E.GetMessage();
    }

}


/* Back()
 * Returns the back element of the queue */

template <class datatype>
datatype Queue341< datatype >::Back() {

    try {

        // Throws an exception if queue is empty
        if ( Empty() ) {
            throw Exceptions341("Queue is empty, cannot call Back()\n");
        }

        else {
            return m_tail -> data;
        }

    }

    catch (Exceptions341 &E) {
        cout << E.GetMessage();
    }

}


#endif