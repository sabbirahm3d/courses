/* File:    Queue341.h
 * Project: CMSC 341: Project 1, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    2/27/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * The header file for the Queue341 class. This file declares the inherited
 * methods and attributes of List341 to simulate a queue linked list.
 */

#ifndef QUEUE341_H
#define QUEUE341_H


#include "List341.cpp"

template <class datatype>
class Queue341 : public List341<datatype> {

public:


/* ******************** Constructors ******************** */

/* Stack341() - Default constructor
 * Preconditions: None
 * Postconditions: Creates a Stack341 object and initializes its attributes */

Queue341();


/* ******************** Destructors ******************** */


/* ~Stack341() - Default destructor
 * Preconditions: None
 * Postconditions: Clears the list */

~Queue341();

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


/* Front()
 * Preconditions: None
 * Postconditions: Returns the front of the queue, or throws an exception if the
   list is empty */

datatype Front();


/* Back()
 * Preconditions: None
 * Postconditions: Returns the back of the queue, or throws an exception if the
   list is empty */

datatype Back();


/* ******************** Private attributes ******************** */

private:

Node341< datatype > *m_head;
Node341< datatype > *m_tail;
datatype *m_front;
datatype *m_back;
int m_size;

};


#include "Queue341.cpp"
#endif