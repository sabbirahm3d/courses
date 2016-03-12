/* File:    TicTacNode.cpp
 * Project: CMSC 341: Project 2, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    2/
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * The implementation file for the TicTacTicTacNode class. The file simply consists
 */


#include "TicTacNode.h"

/* ******************** Constructors ******************** */

 void TicTacNode::findChild(char c) {


    // cout << "before loop " << c << endl;

    for ( unsigned int i = 0; i < m_children.size(); i++ ) {

        // TicTacNode* tmp = m_children.at(i);
        // string hey = tmp->content();
        for (unsigned int j = 0; j < (m_children[i])->content().length(); j++){
            cout << "ehhh " << m_children[i]->content()[j] << endl;
            if ( m_children[i]->content()[j] == c) {
                cout << c << endl;
            }
        }        // for ( unsigned int j = 0; j < hey.length(); j++ ) {
        //     if ( tmp->content() == c ) {
        //         return tmp;
        //     }
        }
    // }

    // return NULL;

    }


    void TicTacNode::operator= (const TicTacNode& D) { 

    // // map<int, char> newBoard;

    // for (unsigned int i = 0; i < m_data.length(); i++) {

    //     m_board.insert(pair<int, char>(i + 1, m_data[i] ));

    // }

        m_board = D.m_board;

    }


    ostream& operator<< (ostream& out, TicTacNode& node){

        map<int, char>::iterator it = node.m_board.begin();

        for (it = node.m_board.begin(); it != node.m_board.end(); ++it) {
            out << it->first << " => " << it->second << endl;
        }

    // for (unsigned int i = 0; i < m_data.length(); i++) {

    //     node.m_board.insert(pair<int, char>(i + 1, m_data[i] ));

    // }    

    // out << node.m_board;

        return out;

    }
