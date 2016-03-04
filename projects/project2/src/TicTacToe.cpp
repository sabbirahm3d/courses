#include <fstream>

#include "TicTacToe.h"


TicTacToe::TicTacToe() { /* Empty constructor */ }


TicTacToe::TicTacToe(string fileName) {

    ReadGame(fileName);
    m_isOver = false;
    m_results = 0;
    // m_size = 0;

}


TicTacToe::~TicTacToe() {

    Clear();

}


void TicTacToe::ReadGame(string fileName) {

    ifstream gameFile(fileName.c_str());

    if ( gameFile.is_open() ) {

        cout << "========================" << endl;
        cout << "Reading: " << fileName << endl;
        cout << "========================" << endl << endl;

        string line, dummy;
        string state = "";

        // Read through the entire file
        while ( getline(gameFile, line) ) {

            if ( line.length() ) {
                state = "";

                while ( state.length() < 9 ) {
                    state += line;
                    // state += "\n";
                    getline(gameFile, line);
                }

                // cout << state << endl;
                this->Push(state);
                // cout << Size() << endl;
            }
        }

        m_isOver = true;

        if ( GetResults(state, 'X') ) {
            m_results = 1;
            cout << "X won" << endl;
            cout << state << endl;
        }

        else if ( GetResults(state, 'O') ) {
            m_results = 2;
            cout << "O won" << endl;
            cout << state << endl;
        }

        else {
            m_results = 3;
            cout << "It's a draw" << endl;
        }

    }

    else {
        cerr << "Please make sure the file name is valid." << endl;
    }


}


bool TicTacToe::GetIsOver() {

    return m_isOver;

}


// int TicTacToe::Size() const {

//     return m_size;

// }


bool TicTacToe::GetResults(string state, char player){

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


bool TicTacToe::Empty() const {

    return (m_head == NULL && m_tail == NULL); 

}


bool TicTacToe::Push(string value) {

    // create a cursor pointer to move all the elements
    TicTacNode* cursor = new TicTacNode();

    cursor->m_data = value;
    cursor->next = NULL;

    // If list is empty, value is the only element
    if ( Empty() ) {
        cursor->prev = NULL;
        m_head = cursor;
        m_tail = cursor;
        // m_size++;
        return true;
    }

    // If list is not empty, all the elements get pushed
    else if ( !Empty() ) {
        m_tail->next = cursor;
        m_tail = cursor;
        // m_size++;
        return true;
    }

    else {
        return false;
    }

    delete cursor;
    cursor = NULL;

}


bool TicTacToe::Clear() {

    if ( Empty() ) {
        return false;
    }

    else {

        // Temporary pointers to Node341 objects
        TicTacNode *temp;
        TicTacNode *cursor = m_head;

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
        // m_size = 0;

        return true;
    }

}

void TicTacToe::Print() {

    if (m_head == NULL) {
        cout << "Game empty."<<endl;
        return;
    }

    TicTacNode* q = m_head;
    cout << "The game is:" << endl;

    while (q != NULL) {
        cout << *q << " <-> ";
        q = q->next;
    }

    cout << "NULL" << endl;

}