/* File:    TicTacNode.h
 * Project: CMSC 341: Project 2, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    1/3/37
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * Description:
 * Node class that will be used in TicTacToe & TicTacTrie.
 * This class holds information about the current state of the game board.
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
     * Postconditions: Creates a TicTacNode object and initializes its member
       attributes */

    TicTacNode();


    /* ******************** Destructors ******************** */

    /* ~TicTacNode() - Default destructor
     * Preconditions: None
     * Postconditions: Empties the node of its data and destroys its 
       children */

    ~TicTacNode();


    /* ******************** Accessors / getters ******************** */

    /* GetData()
     * Preconditions: None
     * Postconditions: Returns the game board stored in the node */

    string GetData();


    /* GetChildContent()
     * Preconditions: None
     * Postconditions: Returns the child stored in the game board */

    char GetChildContent();


    /* ******************** Mutators / setters ******************** */


    /* SetData()
     * Preconditions: Parameter is a string
     * Postconditions: Assigns m_data to the parameter */

    void SetData(string);


    /* SetChildContent()
     * Preconditions: Parameter is an index of string
     * Postconditions: Assigns m_child to the parameter */

    void SetChildContent(char);


    /* AddChild()
     * Preconditions: Parameter is a node determined to be a child node
     * Postconditions: Adds a child of the node */

    void AddChild(TicTacNode*);


    /* ******************** Extra functions ******************** */


    /* FindChild()
     * Preconditions: Parameter is an index of the string
     * Postconditions: Returns the child node if found */

    TicTacNode* FindChild(char);


    /* ******************** Operator overloaders ******************** */


    /* operator<< - Overloaded output operator
     * Preconditions: None
     * Postconditions: Prints out the data in the TicTacNode object */

    friend ostream &operator<<(ostream&, TicTacNode&);


    /* operator== - Overloaded comparison operator
     * Preconditions: None
     * Postconditions: Compares the contents of TicTacNode objects */

    bool operator==(const TicTacNode&) const;


    /* ******************** Public TicTacNode attributes ******************** */


    TicTacNode *next, *prev;

private:

    /* ******************** Operator overloaders ******************** */


    /* operator= - Overloaded assignment operator
     * Preconditions: None
     * Postconditions: Maps the content of the node to m_board */

    TicTacNode& operator=(const TicTacNode&);


    /* ******************** Private TicTacNode attributes ******************** */


    string m_data;
    char m_child;
    vector<TicTacNode*> m_children;
    map<int, char> m_board;

};


#endif