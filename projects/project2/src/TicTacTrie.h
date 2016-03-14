/* File:    TicTacTrie.h
 * Project: CMSC 341: Project 2, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    1/3/37
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

	void AddGame(TicTacToe &game);

	void addWord(TicTacNode &s);

	// bool searchWord(string s);
	// void deleteWord(string s);
	bool searchWord(TicTacNode *, const char *);


	// !! REQUIRED FUNCTIONS !!

	/* MOST IMPORTANT & REQUIRED FUNCTION OF TicTacTrie class
	 * - Iterates through the TicTacToe game that is passed into it
	 *
	 * TODO: If it finds a node that isn't in the trie,
	 * TODO: -> then it will add it to the appropriate spot
	 *
	 * TODO: If it finds moves that are already in the trie
	 * TODO: -> it will follow through and add any new moves
	 */

	void addGame(TicTacToe game);

	int getPlayerXWins() const;
	int getPlayerOWins() const;
	int getNumberOfDraws() const;
	int getNumberOfNodesInTree() const;

	void setPlayerXWins(int wins);
	void setPlayerOWins(int wins);
	void setNumberOfDraws(int draws);
	void setNumberOfNodesInTree(int sizeOfTree);


	// !! END REQUIRED FUNCTIONS !!

	private:

	TicTacNode *root;
	vector< TicTacNode > *m_childrens;
	vector< int > occurrences;

	// !! REQUIRED VARIABLES !!

	int m_xWins; // The number of games Player X has won

	int m_oWins; // The number of games Player O has won

	int m_draws; // The number of games resulting in a draw

	int m_size;  // The current number of nodes in the tree

	// !! END REQUIRED VARIABLES !!
};

#endif