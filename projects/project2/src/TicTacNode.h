/* File:    TicTacNode.h
 * Project: CMSC 341: Project 2, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    2/
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * The header file for the TicTacNode class, this file simulates nodes of data
 */


#ifndef TICTACNODE_H
#define TICTACNODE_H


#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;


class TicTacNode {

public:

/* ******************** Constructors ******************** */


/* TicTacNode() - Default constructor
 * Preconditions: None
 * Postconditions: Creates a Node341 object and initializes its member 
   variables */

TicTacNode();


/* ******************** Operator overloaders ******************** */


/* operator<< - Overloaded output operator.
 * Preconditions: None.
 * Postconditions: Returns the Country object with the highest
   spending on education. */

friend ostream& operator<<(ostream&, TicTacNode&);


/* ******************** Member variables ******************** */

string data;

// links pointers to the data
TicTacNode *next;
TicTacNode *prev;

private:

vector<string>* m_children;
map<char, string> m_board;


};


#endif