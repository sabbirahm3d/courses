/* File:    TicTacToe.h
 * Project: CMSC 341: Project 2, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    1/3/37
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * Description:
 * - This class holds single tic tac toe game in linked list format
 * - This class will essentially be a linked list of TicTacNode objects
 *   containing the information about a game that was read in
 */

#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <string>
#include "TicTacNode.h"

class TicTacToe {

	public:

	TicTacToe();

	TicTacToe(string);

	~TicTacToe();

	void ReadGame(string);

	bool GetWinner(string, char);

	bool GetIsOver();

	int GetResults();

	bool Empty() const;

	bool Push(string value);

	bool Clear();

	int Size() const;

	void EndGame(string);

	TicTacNode* Pop();


	private:

	TicTacNode *m_head, *m_tail;

	// !! REQUIRED VARIABLES !!

	bool m_isOver; // defines whether or not hte game in the file reached an end


	// Defines the outcome of a game
	// 0 - Game has not ended
	// 1 - Player X won
	// 2 - Player O won
	// 3 - Game was a draw
	int m_results;

	// !! END REQUIRED VARIABLES !!

};

#endif