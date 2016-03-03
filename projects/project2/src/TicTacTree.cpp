#include <fstream>

#include "TicTacTree.h"


TicTacTree::TicTacTree(){}

TicTacTree::TicTacTree(string fileName) {

	ReadGame(fileName);

}

void TicTacTree::ReadGame(string fileName) {

    ifstream gameFile(fileName.c_str());

    if (gameFile.is_open()) {

    	cout << "========================" << endl;
    	cout << "Reading: " << fileName << endl;
    	cout << "========================" << endl;

        string line;

        // Read through the entire file
        while ( !gameFile.eof() ) {

            getline(gameFile, line);

	        if ( line.length() ) {

		        string state = "";

	            while (state.length() < 9) {
		            state += line;
		            // counter--;
		            cout << state << endl;
		        }
		       //      // cout << "---------line---------" << endl;
			}

        }


    }

    else {
        cerr << "Please make sure the file name is valid." << endl;
    }



}