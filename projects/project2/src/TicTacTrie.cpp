/* File:    TicTacTrie.cpp
 * Project: CMSC 341: Project 2, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    3/14/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * This class holds the trie data structure using TicTacNode objects
 * This class contains the trie data structure, which will hold all paths for
 * the TicTacToe games
 */

#include "TicTacTrie.h"


/* ******************** Constructors ******************** */


/* TicTacTrie() - Default constructor
 * Initializes its member attributes and root */

TicTacTrie::TicTacTrie() {

    root = new TicTacNode();

    m_xWins = 0;
    m_oWins = 0;
    m_draws = 0;
    m_size = 0;

}


/* ******************** Destructors ******************** */


/* ~TicTacTrie() - Default destructor
 * Resets its member attributes and frees the leaf pointers */

TicTacTrie::~TicTacTrie() {

    delete root;
    root = NULL;

    // destroy the leaves
    for ( unsigned int i = 0; i < leaves.size(); i++ ) {
        delete leaves[i];
        leaves[i] = NULL;
    }

    leaves.resize(0);

}


/* ******************** Accessors/ getters ******************** */


/* GetXWins()
 * Returns the number of times player X wins */

int TicTacTrie::GetXWins() const { return m_xWins; }


/* GetOWins()
 * Returns the number of times player O wins */

int TicTacTrie::GetOWins() const { return m_oWins; }


/* GetDraws()
 * Returns the number of draws */

int TicTacTrie::GetDraws() const { return m_draws; }


/* Size()
 * Returns the number of leaves in the tree */

int TicTacTrie::Size() const { return m_size; }


/* ******************* Helper functions ******************* */


/* AddGame()
 * Pops nodes off the list to convert into leaves for the tree */

void TicTacTrie::AddGame(TicTacToe& game) {

    // while the TicTacToe object contains TicTacNodes
    while ( game.Size() ) {

        // pop_front nodes off the list to be added as a leaf
        TicTacNode *cursor = game.Pop();
        AddLeaf(cursor->GetData());

        // delete pointer
        delete cursor;
        cursor = NULL;
    }

    // switch statement to keep track of the scoreboard
    switch ( game.GetResults() ) {

        case 1:
            m_xWins++;
            break;

        case 2:
            m_oWins++;
            break;

        case 3:
            m_draws++;
            break;

        default:
            break;

    }

}


/* ******************* Helper tree functions ******************* */


/* AddLeaf()
 * Adds the nodes as leaves to the tree */

void TicTacTrie::AddLeaf(string board) {


    TicTacNode* current = root;
    bool newChild = false;

    // if the node is empty, break out of function
    if ( !( board.length() ) ) {
        return;
    }

    for ( unsigned int i = 0; i < board.length(); i++ ) {   

        TicTacNode* child = current->FindChild(board[i]);

        // if the board has a child
        if ( child != NULL ) {
            current = child;
        }

        else {

            TicTacNode* tmp = new TicTacNode();
            tmp->SetChildContent(board[i]);

            // add new child
            current->AddChild(tmp);
            current = tmp;
            leaves.push_back(current);
            newChild = true;

        }

    }

    // increment the size of the tree if a new child is added
    if ( newChild ) {
        m_size++;
    }

}