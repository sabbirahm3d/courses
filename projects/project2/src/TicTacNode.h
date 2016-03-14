/* File:    TicTacNode.h
 * Project: CMSC 341: Project 2, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    1/3/37
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * Description:
 * - Node class that will be used in TicTacToe & TicTacTrie
 * - This class holds information about the current state of the game board.
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

	TicTacNode() {
		m_data = ' ';
		m_cursor = false;
		next = prev = NULL;
	}

	// TicTacNode(string node) { setContent(node); setWordMarker(); }
	~TicTacNode() { }

	string content() {
		return m_data;
	}

	bool wordMarker() { return m_cursor; }

	vector< TicTacNode * > children() { return m_children; }

	void setContent(string c) {

		for (unsigned int i = 0; i < c . length(); i++) {

			m_board . insert(pair< int, char >(i + 1, c[i]));

		}

		m_data = c;
	}

	void setWordMarker() { m_cursor = true; }

	void findChild(char c);

	void appendChild(TicTacNode *child) { m_children . push_back(child); }

	/* ******************** Operator overloaders ******************** */


	/* operator<< - Overloaded output operator.
	 * Preconditions: None.
	 * Postconditions: Returns the Country object with the highest
		 spending on education. */

	// !! Required Function !!
	// A friend class in C++ can access the "private" and "protected"
	// members of the class in which it is declared as a friend.
	friend ostream &operator<<(ostream &, TicTacNode &);



	string m_data;
	TicTacNode *next, *prev;

	// !! Required Variable !!
	// Must be a vector containing pointers to all of the chilren of this node
	vector< TicTacNode * > m_children;



	private:

	void operator=(const TicTacNode &);

	// !! Required Variable !!
	// A map containing the game board
	map< int, char > m_board;

	bool m_cursor;

};


#endif