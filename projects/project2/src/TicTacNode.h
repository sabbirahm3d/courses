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

// using namespace std;


// class TicTacNode {

// public:

// /* ******************** Constructors ******************** */


// /* TicTacNode() - Default constructor
//  * Preconditions: None
//  * Postconditions: Creates a TicTacNode object and initializes its member 
//    variables */

// TicTacNode();




// /* ******************** Member variables ******************** */

// string data;

// // links pointers to the data
// TicTacNode *next;
// TicTacNode *prev;

// private:

// vector<string>* m_children;
// map<string, string> m_board;


// };

 using namespace std;

 class TicTacNode {

 public:

    TicTacNode() {
        m_data = ' ';
        m_cursor = false;
        next = prev = NULL;
    }

    // TicTacNode(string node) { setContent(node); setWordMarker(); }
    ~TicTacNode() {}

    string content() { 
        return m_data;
    }
    
    bool wordMarker() { return m_cursor; }
    vector<TicTacNode*> children() { return m_children; }

    void setContent(string c) {

        for (unsigned int i = 0; i < c.length(); i++) {

            m_board.insert(pair<int, char>(i + 1, c[i] ));

        }

       m_data = c;
    }

    void setWordMarker() { m_cursor = true; }

    // void findChild(string c);
    void appendChild(TicTacNode* child) { m_children.push_back(child); }

    /* ******************** Operator overloaders ******************** */


    /* operator<< - Overloaded output operator.
     * Preconditions: None.
     * Postconditions: Returns the Country object with the highest
       spending on education. */

     friend ostream& operator<<(ostream&, TicTacNode&);


     string m_data;
     TicTacNode *next, *prev;
     vector<TicTacNode*> m_children;

 private:

    void operator=(const TicTacNode&);
    map<int, char> m_board;
    bool m_cursor;

};


#endif