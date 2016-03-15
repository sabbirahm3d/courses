/* File:    TicTacTrie.h
 * Project: CMSC 341: Project 2, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    3/14/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * Description:
 * - This class holds the trie data structure using TicTacNode objects
 * - This class contains the trie data structure, which will hold all paths for
 *   the TicTacToe games
 * - Project Requirement: Each member variable must have a getter
 */

#ifndef TICTACTRIE_H
#define TICTACTRIE_H

#include "TicTacNode.h"
#include "TicTacToe.h"


class TicTacTrie {

public:

    TicTacTrie();

    ~TicTacTrie();

    void AddGame(TicTacToe&);

    void AddTicTacNode(string);

    int GetXWins() const;

    int GetOWins() const;

    int GetDraws() const;

    int Size() const;


private:

    TicTacNode *root;

    int m_xWins; // The number of games Player X has won

    int m_oWins; // The number of games Player O has won

    int m_draws; // The number of games resulting in a draw

    int m_size;  // The current number of nodes in the tree

};

#endif