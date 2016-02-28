/* File:    List341.cpp
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

#ifndef LIST341_CPP
#define LIST341_CPP

#include "Exceptions341.h"
#include "List341.h"


template <class datatype>
List341<datatype>::List341() {
    
    m_head = m_tail = NULL;
    m_size = 0;

}


template <class datatype>
List341<datatype>::~List341() {

    Node341<datatype>* cursor = m_head;

    while (cursor != NULL) {
        Node341<datatype>* next = cursor->next;
        delete cursor;
        cursor = next;
    }

    m_head = m_tail = NULL;

}

#endif