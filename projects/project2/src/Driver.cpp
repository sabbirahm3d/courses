/* File:    Driver.cpp
 * Project: CMSC 341: Project 2, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    3/14/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu

 * The driver program for Project 0, this file reads through two input files to
 * map 6 dirLines to their corresponding countries, and adds statistics to
 * them to convert into Country objects. The Country objects are then appended
 * to their corresponding Continent object, and then used to find the total
 * population, the country with the highest population, literacy rate and
 * expendature on education for each dirLines.
 */

#include <cstdlib>
#include <fstream>


#include "TicTacToe.h"
#include "TicTacTrie.h"

 using namespace std;

/* Driver function. Calls ReadFromFiles() after passing in the paths to the
   input files. */

 int main (int argc, char* fileName[] ) {

    if ( argc == 2 ) {

        ifstream listOfGames(fileName[1], ios_base::in);

        if (listOfGames.is_open()) {

            string dirLine;
            TicTacTrie *trie = new TicTacTrie();

            // Read through the entire file
            while (!listOfGames.eof()) {

                getline(listOfGames, dirLine);
                TicTacToe* game = new TicTacToe(dirLine);
                trie -> AddGame(*game);
                delete game;
                game = NULL;

            }

            cout << endl << "Final TicTacTrie statistics:" << endl;
            cout << "============================" << endl;
            cout << "Player X wins: " << trie->GetXWins() << endl;
            cout << "Player O wins: " << trie->GetOWins() << endl;
            cout << "Draws: " << trie->GetDraws() << endl;
            cout << "Trie tree size: " << trie->Size() << endl;

            delete trie;
            trie = NULL;

        }

        else {
            cerr << "\'" << fileName[1] << "\' does not exist." << endl;
        }

    }

    else if (argc > 2) {
        cerr << 
        "Please include ONLY the input file path as the command line argument."
        << endl;
    }

    else {
        cerr <<
        "Please include the name of the file as the command line argument."
        << endl;
    }

    return 0;
}