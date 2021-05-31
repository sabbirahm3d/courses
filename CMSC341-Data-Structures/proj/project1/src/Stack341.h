/* File:    Stack341.h
 * Project: CMSC 341: Project 1, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    2/27/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * The header file for the Stack341 class. This file declares the inherited
 * methods and attributes of List341 to simulate a stack linked list.
 */

#ifndef STACK341_H
#define STACK341_H


#include "List341.cpp"

template <class datatype>
class Stack341 : public List341<datatype> {

public:


/* ******************** Constructors ******************** */


/* Stack341() - Default constructor
 * Preconditions: None
 * Postconditions: Creates a Stack341 object and initializes its attributes */

Stack341();


/* ******************** Destructors ******************** */


/* ~Stack341() - Default destructor
 * Preconditions: None
 * Postconditions: Clears the list */

~Stack341();


/* ******************** Stack341 methods ******************** */

/* Size()
 * Preconditions: None
 * Postconditions: Returns size of the list */

virtual int Size() const;


/* Empty()
 * Preconditions: None
 * Postconditions: Checks if the list is empty */

virtual bool Empty() const;


/* Push()
 * Preconditions: value must be a valid data type
 * Postconditions: Pushes data into the list, and returns confirmation of
   success or failure */

virtual bool Push(datatype value);


/* Pop()
 * Preconditions: None
 * Postconditions: Implements the pop_front feature of linked lists - returns 
   the first element of the list before removing it */

virtual bool Pop();


/* Clear()
 * Preconditions: None
 * Postconditions: Clears the list of elements and returns confirmation of
   success or failure */

virtual bool Clear();


/* Top()
 * Preconditions: None
 * Postconditions: Returns the top of the stack, or throws an exception if the
   list is empty */

datatype Top();


/* ******************** Private attributes ******************** */

private:

Node341<datatype>* m_head;
Node341<datatype>* m_tail;
datatype *m_top;
int m_size;

};


#include "Stack341.cpp"
#endif