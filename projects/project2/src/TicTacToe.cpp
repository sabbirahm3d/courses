#include <fstream>

#include "TicTacToe.h"


TicTacToe::TicTacToe(){}

TicTacToe::TicTacToe(string fileName) {

    ReadGame(fileName);

}

TicTacToe::~TicTacToe() {

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


            while ( state.length() < 9 ) {
                state += line;
                state += "\n";
                getline(gameFile, line);
            }

            cout << state << endl;
            cout << Push(state) << endl;
            // TicTacNode yo(state);
            // cout << yo << endl;
            state = "";

        }

    }

    else {
        cerr << "Please make sure the file name is valid." << endl;
    }


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
        return true;
    }

    // If list is not empty, all the elements get pushed
    else if ( !Empty() ) {
        m_tail->next = cursor;
        m_tail = cursor;
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

        return true;
    }

}