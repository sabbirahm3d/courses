/* File:    TicTacTrie.h
 * Project: CMSC 341: Project 2, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    3/14/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * Description:
 * The header file for the TicTacTrie class
 */

#ifndef TICTACTRIE_H
#define TICTACTRIE_H

#include "TicTacNode.h"
#include "TicTacToe.h"


class TicTacTrie {

public:


    /* ******************** Constructors ******************** */


    /* TicTacTrie() - Default constructor
     * Preconditions: None
     * Postconditions: Initializes its member variables and root */

    TicTacTrie();


    /* ******************** Destructors ******************** */


    /* ~TicTacTrie() - Default destructor
     * Preconditions: None
     * Postconditions: Deletes the node */

    ~TicTacTrie();


    /* ******************** Accessors/ getters ******************** */


    int GetXWins() const;

    int GetOWins() const;

    int GetDraws() const;

    int Size() const;


    /* ******************* Helper functions ******************* */


    void AddGame(TicTacToe&);


    /* ******************* Helper tree functions ******************* */


    void AddTicTacNode(string);


private:

    TicTacNode* root;

    vector<TicTacNode*> m_leaves;

    int m_xWins; // The number of games Player X has won

    int m_oWins; // The number of games Player O has won

    int m_draws; // The number of games resulting in a draw

    int m_size;  // The current number of nodes in the tree

};

#endif