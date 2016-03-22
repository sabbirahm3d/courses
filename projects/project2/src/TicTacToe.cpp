/* File:    TicTacToe.cpp
 * Project: CMSC 341: Project 2, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    3/15/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * This class holds single tic tac toe game in linked list format
 * This class will essentially be a linked list of TicTacNode objects
 * containing the information about a game that was read in
 */


#include "TicTacToe.h"


/* ******************** Constructors ******************** */

/* TicTacNode()
 * Default constructor - does nothing */

TicTacToe::TicTacToe() { /* Empty constructor */ }


/* TicTacNode()
 * Overloaded constructor - Initializes its member variables, and reads through
   the game file */

TicTacToe::TicTacToe(string fileName) {

    m_isOver = false;
    m_results = 0;
    m_head = m_tail = NULL;
    ReadGame(fileName);

}


/* ******************** Destructors ******************** */

/* TicTacNode()
 * Default destructor - clears the list */

TicTacToe::~TicTacToe() { Clear(); }


/* ******************** Helper functions ******************** */


/* ReadGame()
 * Reads through the game, and assigns the data into 
   TicTacNode objects which is then pushed into the list. Also calls
   other functions to determine the winner */

void TicTacToe::ReadGame(string fileName) {

    cout << endl << "========================" << endl;
    cout << "Reading: " << fileName << endl;
    cout << "========================" << endl;

    ifstream gameFile(fileName.c_str());

    if ( gameFile.is_open() ) {

        string line, dummy;
        string board = "";

        // Read through the entire file
        while ( getline(gameFile, line) ) {

            // ignore empty lines
            if ( line.length() ) {

                board = "";

                // a game board is represented with its whitespace stripped
                while ( board.length() < 9 ) {
                    board += line;
                    getline(gameFile, line);
                }

                // the board is then converted into a TicTacNode and pushed
                // into the TicTacToe list
                Push(board);

            }
        }

        // call the other functions when the program is done reading the games
        EndGame(board);

    }

    else {
        cerr << "\'" << fileName << "\' does not exist." << endl;
    }


}


/* EndGame()
 * Displays if the game is over and who the winner is */

void TicTacToe::EndGame(string finalBoard) {

    for ( unsigned int i = 0; i < finalBoard.length(); i++ ) {

        if ( (finalBoard[i] == '-') && !GetIsOver() ) {
            m_results = 0;
            m_isOver = false;
        }

        else {
            m_isOver = true; // if game is over
        }

    }

    // once game is over, determine the winner
    if ( m_isOver ) {

        // if X wins
        if ( GetWinner(finalBoard, 'X') ) {
            m_results = 1;
            cout << "Player X won!" << endl;
            cout << "Game board:" << endl;

            // print out the final board of the game
            for ( unsigned int i = 1; i < finalBoard.size() + 1; i++ ) {

                cout << finalBoard[i-1];

                // insert a newline after every rows
                if ( !(i % 3) ) {
                    cout << endl;
                }

            }
        }

        // if O wins
        else if ( GetWinner(finalBoard, 'O') ) {
            m_results = 2;
            cout << "Player O won!" << endl;
            cout << "Game board:" << endl;

            for ( unsigned int i = 1; i < finalBoard.size() + 1; i++ ) {

                cout << finalBoard[i-1];

                if ( !(i % 3) ) {
                    cout << endl;
                }

            }
        }

        // if draw
        else {
            m_results = 3;
            cout << "The game was a draw!" << endl;
            cout << "Game board:" << endl;

            for ( unsigned int i = 1; i < finalBoard.size() + 1; i++ ) {

                cout << finalBoard[i-1];

                if ( !(i % 3) ) {
                    cout << endl;
                }

            }

        }
    }

}

/* ******************** Accessors/ getters ******************** */


/* GetResults()
 * Returns the final result of the game */

int TicTacToe::GetResults() { return m_results; }


/* GetIsOver()
 * Returns true if the game is over */

bool TicTacToe::GetIsOver() { return m_isOver; }


/* GetWinner()
 * Determines the winner of the game */

bool TicTacToe::GetWinner(string board, char player){

    return (

    // Horizontal match
    ((board[0] == player) && (board[1] == player) && (board[2] == player))
    || ((board[3] == player) && (board[4] == player) && (board[5] == player))
    || ((board[6] == player) && (board[7] == player) && (board[8] == player))

    // Vertical match
    || ((board[0] == player) && (board[3] == player) && (board[6] == player))
    || ((board[1] == player) && (board[4] == player) && (board[7] == player))
    || ((board[2] == player) && (board[5] == player) && (board[8] == player))

    // Diagonal match
    || ((board[0] == player) && (board[4] == player) && (board[8] == player))
    || ((board[2] == player) && (board[4] == player) && (board[6] == player))

    );

}


/* ******************** Helper linked list functions ******************** */


/* Size()
 * Returns the size of the list */

int TicTacToe::Size() const {

    unsigned int size = 0;

    // traverse through the entire list while incrementing the counter
    for ( TicTacNode *current = m_head; current; current = current->next ) {
        ++size;
    }

    return size;

}


/* Empty()
 * Returns true if the list is empty, false otherwise */

bool TicTacToe::Empty() const { return (m_head == NULL && m_tail == NULL); }


/* Push()
 * Pushes data into the list */

void TicTacToe::Push(string value) {

    // create a cursor pointer to move all the elements
    TicTacNode* cursor = new TicTacNode();

    cursor->SetData(value);

    // if list is empty, value is the only element
    if ( Empty() ) {
        cursor->prev = NULL;
        m_head = cursor;
        m_tail = cursor;
        return;
    }

    // if list is not empty, all the elements get pushed
    else if ( !Empty() ) {
        m_tail->next = cursor;
        m_tail = cursor;
        cursor->next = NULL;
        return;
    }

    delete cursor;
    cursor = NULL;

}


/* Clear()
 * Clears the TicTacToe object */

bool TicTacToe::Clear() {

    if ( Empty() ) {
        return false;
    }

    else {

        // temporary pointers to Node341 objects
        TicTacNode* temp;
        TicTacNode* cursor = m_head;

        // traverse the list and delete the nodes one by one from the m_head
        while (cursor != NULL) {

            // iterate the cursor through
            temp = cursor;
            cursor = cursor -> next;

            // delete the pointer to the cursor 
            delete temp;
            temp = NULL;
        }

        /* reset the m_head and m_tail node */
        delete cursor;
        m_head = m_tail = NULL;
        cursor = NULL;

        return true;
    }

}

/* Pop()
 * Pops the first element of the list to implement a pop_front method */

TicTacNode* TicTacToe::Pop() {

    TicTacNode* cursor = m_head;
    m_head = m_head->next;
    return cursor;

}