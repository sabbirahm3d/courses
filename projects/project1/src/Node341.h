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


    datatype data; // stores data of the datatype specified by the template
    Node341 *next; // pointers to the next and previous data nodes
    Node341 *prev;
	// Node341() { next = prev = NULL; }

};


#include "Node341.cpp"
#endif