/* File:    TicTacNode.cpp
 * Project: CMSC 341: Project 2, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    3/14/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * The implementation file for the TicTacNode class. The file consists of the
 * constructors, destructors, getters and setters as well as helper functions
 * of the class to hold and copy information about the game boards. 
 */


#include "TicTacNode.h"


/* ******************** Constructors ******************** */


/* TicTacNode() - Default constructor
 * Creates a TicTacNode object and initializes its member
   attributes */

TicTacNode::TicTacNode() {

    m_data = " ";
    m_child = ' ';
    next = prev = NULL;

}


/* ******************** Destructors ******************** */


/* ~TicTacNode() - Default destructor
 * Empties the node of its data and destroys its 
   children */

TicTacNode::~TicTacNode() {

    m_data = " ";
    m_child = ' ';
    next = prev = NULL;

    // Clear the member containers

    for ( unsigned int i = 0; i < m_children.size(); i++ ) {

        // reassign all the elements to one index
        m_children[0] = m_children[i];

    }

    // shrink the vector back to 0
    m_children.resize(0);

    for ( unsigned int i = 0; i < m_board.size(); i++ ) {

        // reassign all the values to one index
        m_board[0] = m_board[i];

        // free their memory
        m_board.erase(i);
    }

}


/* ******************** Accessors / getters ******************** */


/* GetData()
 * Returns the game board stored in the node */

string TicTacNode::GetData() { return m_data; }


/* GetChildContent()
 * Returns the child stored in the game board */

char TicTacNode::GetChildContent() { return m_child; }


/* ******************** Mutators / setters ******************** */


/* SetData()
 * Assigns m_data to the parameter */

void TicTacNode::SetData(string data) {

    m_data = data; 

    for ( unsigned int i = 0; i < data.length(); i++ ) {
        m_board.insert( pair<int, char> (i, data[i]) );
    }

}


/* SetChildContent()
 * Assigns m_child to the parameter */

void TicTacNode::SetChildContent(char dataChar) { m_child = dataChar; }


/* AddChild()
 * Adds a child of the node */

void TicTacNode::AddChild(TicTacNode* child) { m_children.push_back(child); }


/* ******************** Extra functions ******************** */


/* FindChild()
 * Returns the child node if found */

TicTacNode* TicTacNode::FindChild(char dataChar) {

    for ( unsigned int i = 0; i < m_children.size(); i++ ) {
        TicTacNode* tmp = m_children.at(i);
        if ( tmp->GetChildContent() == dataChar ) {
            return tmp;
        }
    }

    return NULL;
}


/* ******************** Operator overloaders ******************** */


/* operator<< - Overloaded output operator
 * Prints out the data in the TicTacNode object */

ostream& operator<<(ostream& out, TicTacNode& node){

    map<int, char>::iterator it;

    for ( it = node.m_board.begin(); it != node.m_board.end(); ++it ) {
        out << it->second << endl;
    }

    return out;

}


/* operator== - Overloaded comparison operator
 * Compares the contents of TicTacNode objects */

bool TicTacNode::operator==(const TicTacNode& rhs) const {

    if ( this->m_data == rhs.m_data ) {
        return true;
    }

    else {
        return false;
    }

}


/* operator= - Overloaded assignment operator
 * Maps the content of the node to m_board */

TicTacNode& TicTacNode::operator=(const TicTacNode& rhs) { 

    if (this == &rhs) {
        return *this;
    }

    this->m_board = rhs.m_board;
    return *this;

}