#include <fstream>

#include "TicTacToe.h"

#include <iostream>
using namespace std;


TicTacToe::TicTacToe() { /* Empty constructor */ }


TicTacToe::TicTacToe(string fileName) {

    m_isOver = false;
    m_results = 0;
    ReadGame(fileName);

}


TicTacToe::~TicTacToe() { Clear(); }


void TicTacToe::ReadGame(string fileName) {

    cout << endl << "========================" << endl;
    cout << "Reading: " << fileName << endl;
    cout << "========================" << endl;

    ifstream gameFile(fileName.c_str());

    if ( gameFile.is_open() ) {

        string line, dummy;
        string state = "";

        // Read through the entire file
        while ( getline(gameFile, line) ) {

            if ( line.length() ) {

                state = "";

                while ( state.length() < 9 ) {
                    state += line;
                    getline(gameFile, line);
                }

                Push(state);

            }
        }

        EndGame(state);

    }

    else {
        cerr << "\'" << fileName << "\' does not exist." << endl;
    }


}


int TicTacToe::GetResults() {

    return m_results;

}


void TicTacToe::EndGame(string finalBoard) {

    for ( unsigned int i = 0; i < finalBoard.length(); i++ ) {

        if ( (finalBoard[i] == '-') && !GetIsOver() ) {
            m_results = 0;
            m_isOver = false;
        }

        else {
            m_isOver = true;
        }

    }

    if ( m_isOver ) {

        if ( GetWinner(finalBoard, 'X') ) {
            m_results = 1;
            cout << "Player X won!" << endl;
            cout << "Game board:" << endl;

            for ( unsigned int i = 1; i < finalBoard.size() + 1; i++ ) {

                cout << finalBoard[i-1];

                if ( !(i % 3) ) {
                    cout << endl;
                }

            }
        }

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


bool TicTacToe::GetIsOver() {

    return m_isOver;

}


bool TicTacToe::GetWinner(string state, char player){

    return (

    // Horizontal
    ((state[0] == player) && (state[1] == player) && (state[2] == player))
    || ((state[3] == player) && (state[4] == player) && (state[5] == player))
    || ((state[6] == player) && (state[7] == player) && (state[8] == player))

    // Vertical
    || ((state[0] == player) && (state[3] == player) && (state[6] == player))
    || ((state[1] == player) && (state[4] == player) && (state[7] == player))
    || ((state[2] == player) && (state[5] == player) && (state[8] == player))

    // Diagonal
    || ((state[0] == player) && (state[4] == player) && (state[8] == player))
    || ((state[2] == player) && (state[4] == player) && (state[6] == player))
    );

}


/* ******************** Helper linked list functions ******************** */


/* Size()
 * Returns the size of the list */

int TicTacToe::Size() const {

    unsigned int size = 0;

    for ( TicTacNode *current = m_head; current; current = current->next ) {
        size++;
    }

    return size++;

}


/* Empty()
 * Returns true if the list is empty, false otherwise */

bool TicTacToe::Empty() const { return (m_head == NULL && m_tail == NULL); }


/* Push()
 * Pushes data into the list, and returns true if success */

void TicTacToe::Push(string value) {

    // create a cursor pointer to move all the elements
    TicTacNode* cursor = new TicTacNode();

    cursor->SetData(value);
    // cursor->next = NULL;

    // If list is empty, value is the only element
    if ( Empty() ) {
        cursor->prev = NULL;
        m_head = cursor;
        m_tail = cursor;
        return;
    }

    // If list is not empty, all the elements get pushed
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

        // Temporary pointers to Node341 objects
        TicTacNode* temp;
        TicTacNode* cursor = m_head;

        // Traverse the list and delete the nodes one by one from the m_head
        while (cursor != NULL) {

            // iterate the cursor through
            temp = cursor;
            cursor = cursor -> next;

            // take out the pointer to the cursor 
            delete temp;
            temp = NULL;
        }

        /* Reset the m_head and m_tail node */
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