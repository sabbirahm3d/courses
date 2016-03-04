/* File:    TicTacNode.cpp
 * Project: CMSC 341: Project 2, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    2/
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * The implementation file for the TicTacTicTacNode class. The file simply consists
 */


/* ******************** Constructors ******************** */

// /* TicTacNode341()
//  * Default constructor; creates a TicTacNode341 object and initializes its member
//    attributes */

// TicTacTicTacNode::TicTacTicTacNode() {

// 	next = prev = NULL;
// 	this->data = data;

// }


#include "TicTacNode.h"


TicTacNode* TicTacNode::findChild(string c) {

    for ( unsigned int i = 0; i < m_children.size(); i++ ) {

        TicTacNode* tmp = m_children.at(i);

        if ( tmp->content() == c ) {
            return tmp;
        }

    }

    return NULL;

}


ostream& operator<< (ostream& out, TicTacNode& node){

    out << node.m_data;

    return out;

}
