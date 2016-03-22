/* File:    Driver.cpp
 * Project: CMSC 341: Project 2, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    3/14/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu

 * The driver program for Project 2, this file reads through the file passed
 * in as a command line argument containing the paths to the files containing
 * the tic tac toe game boards, converts them into linked list objects to be
 * later merged into a trie tree containing all the moves in the games
 */


#include "TicTacToe.h"
#include "TicTacTrie.h"


/* Driver function
 * Reads in the command line arguments, and constructs TicTacToe linked list
   objects and TicTacTrie trie tree objects */

 int main (int argc, char* fileName[] ) {

    // number of command line arguments must be exactly 2:
    // 0th default argument is the executible file, 1st is the input file name
    if ( argc == 2 ) {

        ifstream listOfGames(fileName[1], ios_base::in);

        if ( listOfGames.is_open() ) {

            string dirLine;
            TicTacTrie* trie = new TicTacTrie();

            // Read through the entire file
            while ( !( listOfGames.eof() ) ) {

                getline(listOfGames, dirLine);

                // pass in paths of game files to create instances of TicTacToe
                // objects
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