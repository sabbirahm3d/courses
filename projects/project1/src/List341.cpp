/* File:    List341.cpp
 * Project: CMSC 341: Project 1, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    2/27/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * The implementation file for the List341 class. This file implements the 
 * abstract templated superclass for the 2 types of linked lists mentioned in
 * the project description. It makes use of the templated Node341 class to 
 * store the data and manage the linkages between them.
 */

#ifndef LIST341_CPP
#define LIST341_CPP


#include "Exceptions341.h"
#include "List341.h"


/* ******************** Constructors ******************** */

/* List341()
 * Default constructor; creates a List341 object and initializes its
   attributes to NULL and 0 */

template <class datatype>
List341<datatype>::List341() { 

    m_head = m_tail = NULL;
    m_size = 0;

}


/* ******************** Destructors ******************** */

/* ~List341()
 * Default destructor; deletes the List341 object by iterating through
   and deleting each Node341 objects */

template <class datatype>
List341<datatype>::~List341() {

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

}


#endif