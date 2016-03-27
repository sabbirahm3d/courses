/* File:    TicTacTrie.h
 * Project: CMSC 341: Project 2, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    3/14/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
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
     * Postconditions: Initializes its member attributes and root */

    TicTacTrie();


    /* ******************** Destructors ******************** */


    /* ~TicTacTrie() - Default destructor
     * Preconditions: None
     * Postconditions: Deletes the tree and all its member attributes */

    ~TicTacTrie();


    /* ******************** Accessors/ getters ******************** */


    /* GetXWins()
     * Preconditions: None
     * Postconditions: Returns the number of times player X won */

    int GetXWins() const;


    /* GetOWins()
     * Preconditions: None
     * Postconditions: Returns the number of times player O won */

    int GetOWins() const;


    /* GetDraws()
     * Preconditions: None
     * Postconditions: Returns the number of times game ended in a draw */

    int GetDraws() const;


    /* Size()
     * Preconditions: None
     * Postconditions: Returns the number of leaves in the tree */

    int Size() const;


    /* ******************* Helper functions ******************* */


    /* AddGame()
     * Preconditions: Parameter must be a valid TicTacToe object
     * Postconditions: Traverses through a game to convert the nodes into
       leaves of the tree */

    void AddGame(TicTacToe&);


    /* ******************* Helper tree functions ******************* */


    /* AddLeaf()
     * Preconditions: Parameter is the data of TicTacNodes
     * Postconditions: Adds the leaves into the the tree */

    void AddLeaf(string);


private:

    /* ******************* Private tree attributes ******************* */

    TicTacNode* root;
    vector<TicTacNode*> leaves;

    /* ******************* Private TicTacTrie attributes ******************* */

    int m_xWins; // The number of games Player X has won
    int m_oWins; // The number of games Player O has won
    int m_draws; // The number of games resulting in a draw
    int m_size;  // The current number of nodes in the tree

};

#endif