/* File:    Driver.cpp
 * Project: CMSC 341: Project 0, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    2/13/16
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
#include <iostream>
#include <string>
#include <fstream>
#include <vector>


#include "TicTacTree.h"

using namespace std;

/* ******************** Declaration of functions ******************** */




/* ******************** Implementation of functions ******************** */


/* main()
 * Driver function. Calls ReadFromFiles() after passing in the paths to the
   input files. */

int main (int argc, char* fileName[] ) {

    cout << fileName[1] << endl;

    ifstream listOfGames(fileName[1], ios_base::in);

    if (listOfGames.is_open()) {

        string dirLine;
        // vector<ifstream*>* files = new vector<ifstream*>;

        // Read through the entire file
        while ( !listOfGames.eof() ) {

            getline(listOfGames, dirLine);
            TicTacTree* yee = new TicTacTree(dirLine);
            // yee->addWord(dirLine);
            // cout << yee->searchWord(dirLine) << endl;
            // files->push_back(&games);
            // cout << files->size() << endl;
            delete yee;
            yee = NULL;

        }


    }

    else {
        cerr << "Please make sure the file name is valid." << endl;
    }

    return 0;

}