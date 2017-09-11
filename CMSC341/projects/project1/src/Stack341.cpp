/* File:    Stack341.cpp
 * Project: CMSC 341: Project 1, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    2/27/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * The implementation file for the Stack341 class. This file inherits from the
 * List341 class implements the methods as per the project description to 
 * simulate a stack linked list.
 */

#ifndef STACK341_CPP
#define STACK341_CPP


#include "Stack341.h"


/* ******************** Constructors ******************** */

/* Stack341()
 * Default constructor; creates a List341 object and initializes its
   attributes to NULL and 0 */

template <class datatype>
Stack341<datatype>::Stack341() {

    m_top = NULL;
    m_head = m_tail = NULL;
    m_size = 0;

}


/* ******************** Destructors ******************** */

/* ~Stack341()
 * Default destructor; calls the Clear method */

template <class datatype>
Stack341<datatype>::~Stack341() { Clear(); }


/* ******************** Stack341 methods ******************** */

/* Size()
 * Returns the size of the stack */

template <class datatype>
int Stack341<datatype>::Size() const { return m_size; }


/* Empty()
 * Returns true if the stack is empty, false otherwise */

template <class datatype>
bool Stack341<datatype>::Empty() const {

    return (m_head == NULL && m_tail == NULL); 

}


/* Pop()
 * Pops the first element of the stack to implement a pop_front method */

template <class datatype>
bool Stack341<datatype>::Pop() {

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
bool Stack341<datatype>::Push(datatype value) {

    // create a cursoror pointer to move all the elements
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
bool Stack341<datatype>::Clear() {

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


/* Top()
 * Returns the top element of the stack */

template <class datatype>
datatype Stack341<datatype>::Top() {

    try {

        // Throws an exception if stack is empty
        if ( Empty() ) {
            throw Exceptions341("Stack is empty, cannot call Top()\n");
        }

        else {
            return m_tail->data;
        }

    }

    catch (Exceptions341 &E) { 
        cout << E.GetMessage();
    }

}


#endif