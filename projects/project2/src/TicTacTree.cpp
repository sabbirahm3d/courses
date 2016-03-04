#include <fstream>

#include "TicTacTree.h"


TicTacTree::TicTacTree(){}

TicTacTree::TicTacTree(string fileName) {

    ReadGame(fileName);

}

TicTacTree::~TicTacTree() {

}


void TicTacTree::ReadGame(string fileName) {

    ifstream gameFile(fileName.c_str());

    if (gameFile.is_open()) {

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
            TicTacNode yo(state);
            cout << yo << endl;
            state = "";

        }

    }

    else {
        cerr << "Please make sure the file name is valid." << endl;
    }


}