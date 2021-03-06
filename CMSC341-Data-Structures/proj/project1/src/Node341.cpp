/* File:    Node341.cpp
 * Project: CMSC 341: Project 1, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    2/27/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * The implementation file for the Node341 class. The file simply consists
 * of the default constructor that initializes the member variables for the
 * linked lists.
 */

#ifndef NODE341_CPP
#define NODE341_CPP


#include <iostream>
#include "Node341.h"

using namespace std;


/* ******************** Constructors ******************** */

/* Node341()
 * Default constructor; creates a Node341 object and initializes its member
   attributes */

template<class datatype>
Node341<datatype>::Node341() {

	next = prev = NULL;
	this->data = data;

}


#endif