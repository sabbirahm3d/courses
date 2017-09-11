/* File:    main.cpp
 * Project: CMSC 341: Project 3, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    4/11/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu

 * The driver program for Project 3, this file reads through the file passed
 * in as a command line argument containing the path to the file containing
 * the library of songs
 */


#include <algorithm>
#include <iostream>
#include "Library.h"
#include "Tree.h"
#include "TitleCompare.h"
#include "YearCompare.h"
#include "ArtistCompare.h"
#include "AlbumCompare.h"
#include "GenreCompare.h"

#define EXPECTED_ARGC 2

/* Print the given song to stdout */
void printSong(Song *song) {
    std::cout << song << '\n';
}


int main(int argc, char **argv) {

    if (argc != EXPECTED_ARGC) {
        std::cerr << "Usage: " << argv[0] << " <library-path>" << std::endl;
        return 1;
    }

    int choice, print;
    bool flag = true;
    Library library(argv[1]);

    Tree<Song *, TitleCompare> *titleTree = new Tree<Song *, TitleCompare>;
    Tree<Song *, ArtistCompare> *artistTree = new Tree<Song *, ArtistCompare>;
    Tree<Song *, AlbumCompare> *albumTree = new Tree<Song *, AlbumCompare>;
    Tree<Song *, GenreCompare> *genreTree = new Tree<Song *, GenreCompare>;
    Tree<Song *, YearCompare> *yearTree = new Tree<Song *, YearCompare>;

    // Populate the indexes
    for (Library::const_iterator iter = library.begin();
         iter != library.end(); iter++) {

        titleTree->insert(*iter);
        artistTree->insert(*iter);
        albumTree->insert(*iter);
        genreTree->insert(*iter);
        yearTree->insert(*iter);

    }

    // Menu to test level order and in-order printing
    while (flag) {

        std::cout << std::endl << "----------------------------" << std::endl;
        std::cout << "1. Use TitleCompare" << std::endl;
        std::cout << "2. Use ArtistCompare" << std::endl;
        std::cout << "3. Use AlbumCompare" << std::endl;
        std::cout << "4. Use GenreCompare" << std::endl;
        std::cout << "5. Use YearCompare" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice : ";
        std::cin >> choice;

        // User inputs their options
        switch (choice) {

            case 1: {

                std::cout << "1. Level order print" << std::endl;
                std::cout << "2. In-order print" << std::endl;
                std::cout << "Enter your choice : ";
                std::cin >> print;

                if (print == 1) {

                    std::cout << *titleTree << std::endl;

                } else if (print == 2) {

                    std::for_each(titleTree->begin(), titleTree->end(),
                                  printSong);

                } else {

                    std::cout << "Wrong choice" << std::endl;

                }

                break;

            }

            case 2: {

                std::cout << "1. Level order print" << std::endl;
                std::cout << "2. In-order print" << std::endl;
                std::cout << "Enter your choice : ";
                std::cin >> print;

                if (print == 1) {

                    std::cout << *artistTree << std::endl;

                } else if (print == 2) {

                    std::for_each(artistTree->begin(), artistTree->end(),
                                  printSong);

                } else {

                    std::cout << "Wrong choice" << std::endl;

                }

                break;

            }

            case 3: {

                std::cout << "1. Level order print" << std::endl;
                std::cout << "2. In-order print" << std::endl;
                std::cout << "Enter your choice : ";
                std::cin >> print;

                if (print == 1) {

                    std::cout << *albumTree << std::endl;

                } else if (print == 2) {

                    std::for_each(albumTree->begin(), albumTree->end(),
                                  printSong);

                } else {

                    std::cout << "Wrong choice" << std::endl;

                }

                break;
            }

            case 4: {

                std::cout << "1. Level order print" << std::endl;
                std::cout << "2. In-order print" << std::endl;
                std::cout << "Enter your choice : ";
                std::cin >> print;

                if (print == 1) {

                    std::cout << *genreTree << std::endl;

                } else if (print == 2) {

                    std::for_each(genreTree->begin(), genreTree->end(),
                                  printSong);

                } else {

                    std::cout << "Wrong choice" << std::endl;

                }

                break;

            }

            case 5: {

                std::cout << "1. Level order print" << std::endl;
                std::cout << "2. In-order print" << std::endl;
                std::cout << "Enter your choice : ";
                std::cin >> print;

                if (print == 1) {

                    std::cout << *yearTree << std::endl;

                } else if (print == 2) {

                    std::for_each(yearTree->begin(), yearTree->end(),
                                  printSong);

                } else {

                    std::cout << "Wrong choice" << std::endl;

                }

                break;
            }

            case 6: {
                std::cout << "Program terminated." << std::endl;
                flag = false;
                break;
            }

            default:
                std::cout << "Wrong choice" << std::endl;

        }

    }

    delete titleTree;
    delete artistTree;
    delete albumTree;
    delete genreTree;
    delete yearTree;

    return 0;

}
