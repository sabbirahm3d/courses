/* File:    Node341.h
 * Project: CMSC 341: Project 1, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    2/27/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * The header file for the Node341 class, this file simulates nodes of data
 * for the List341 class which simulates a linked list structure.
 */


#ifndef NODE341_H
#define NODE341_H


template <class datatype>
class Node341 {

public:

/* ******************** Constructors ******************** */


/* Node341() - Default constructor
 * Preconditions: None
 * Postconditions: Creates a Node341 object and initializes its member 
   variables */

Node341();


/* ******************** Member variables ******************** */

datatype data;

// links pointers to the data
Node341 *next;
Node341 *prev;

};


#include "Node341.cpp"
#endif