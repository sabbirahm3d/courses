/* File:    TicTacToe.h
 * Project: CMSC 341: Project 2, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    1/3/37
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * Description:
 * The header file for the TicTacToe class
 */


#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "TicTacNode.h"


class TicTacToe {

public:

    /* ******************** Constructors ******************** */

    /* TicTacNode() - Default constructor
     * Preconditions: None
     * Postconditions: None */

    TicTacToe();


    /* TicTacNode() - Overloaded constructor
     * Preconditions: The parameter is a path to a tic tac toe game
     * Postconditions: Initializes its member variables, and reads through
       the game file */

    TicTacToe(string);


    /* ******************** Destructors ******************** */

    /* TicTacNode() - Default destructor
     * Preconditions: None
     * Postconditions: Clears the list */

    ~TicTacToe();



    /* ******************** Accessors/ getters ******************** */

    /* GetWinner()
     * Preconditions: The parameters are extracted from the game
     * Postconditions: Returns true if the player is a winner */

    bool GetWinner(string, char);


    /* GetIsOver()
     * Preconditions: None
     * Postconditions: Returns true if the game is over */

    bool GetIsOver();


    /* GetResults()
     * Preconditions: None
     * Postconditions: Returns the final result of the game, where:
       0 - Game has not ended
       1 - Player X won
       2 - Player O won
       3 - Game was a draw */
 
    int GetResults();


    /* ******************** Helper functions ******************** */


    /* ReadGame()
     * Preconditions: The parameter is the path to a tic tac toe game
     * Postconditions: Reads through the game, and assigns the data into 
       TicTacNode objects which is then pushed into the list. Also calls
       other functions to determine the winner */

    void ReadGame(string);


    /* EndGame()
     * Preconditions: The parameter is the final board of the game
     * Postconditions: Verifies if the game is over and who the winner is */

    void EndGame(string);


    /* ******************* Helper linked list functions ******************* */



    /* Empty()
     * Preconditions: None
     * Postconditions: Returns true if the list is empty, false otherwise */

    bool Empty() const;


    /* Push()
     * Preconditions: None
     * Postconditions: Pushes data into the list */

    void Push(string value);


    /* Clear()
     * Preconditions: None
     * Postconditions: Clears the TicTacToe object */

    bool Clear();


    /* Size()
     * Preconditions: None
     * Postconditions: Returns the size of the list */

    int Size() const;


    /* Pop()
     * Preconditions: None
     * Postconditions: Pops the first element of the list to implement a
       pop_front method */

    TicTacNode* Pop();


private:

    /* ******************* Private class attributes ******************* */

    TicTacNode *m_head, *m_tail;
    bool m_isOver;
    int m_results;

};


#endif