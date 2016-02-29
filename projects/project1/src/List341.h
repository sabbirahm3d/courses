/* File:    List341.h
 * Project: CMSC 341: Project 1, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    2/27/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * The header file for the List341 class. This file declares an abstract
 * templated superclass for the 2 types of linked lists mentioned in the 
 * project description. It makes use of the templated Node341 class to store
 * the data and manage the linkages between them.
 */

#ifndef LIST341_H
#define LIST341_H

#include "Node341.h"


template <class datatype>
class List341 {

protected:

/* ******************** Constructors ******************** */


/* List341() - Default constructor
 * Preconditions: None
 * Postconditions: Creates a List341 object */

List341();



/* List341() - Default constructor
 * Preconditions: None
 * Postconditions: Creates a List341 object */

List341(Node341<datatype>*, Node341<datatype>*, int);


/* ******************** Destructors ******************** */

/* ~List341() - Empty constructor
 * Preconditions: None
 * Postconditions: Deletes the List341 object after instantiation */

virtual ~List341();


/* ******************** Virtual methods ******************** */
/* *** These methods are only implemented in its child classes *** */

/* Size()
 * Preconditions: None
 * Postconditions: Returns size of the list */

virtual int Size() const = 0;


/* Empty()
 * Preconditions: None
 * Postconditions: Checks if the list is empty */

virtual bool Empty() const = 0;


/* Push()
 * Preconditions: value must be a valid data type
 * Postconditions: Pushes data into the list, and returns confirmation of
   success or failure */

virtual bool Push(datatype value) = 0;


/* Pop()
 * Preconditions: None
 * Postconditions: Implements the pop_front feature of linked lists - returns 
   the first element of the list before removing it */

virtual bool Pop() = 0;


/* Clear()
 * Preconditions: None
 * Postconditions: Clears the list of elements and returns confirmation of
   success or failure */

virtual bool Clear() = 0;


/* ******************** Protected attributes ******************** */

// initializes head and tail pointers to Node341 objects
Node341<datatype>* m_head;
Node341<datatype>* m_tail;
int m_size; // stores the size of the list

};


#include "List341.cpp"
#endif