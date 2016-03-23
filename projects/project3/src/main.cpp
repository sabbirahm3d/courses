/*
 * Basic driver to get you started
 */

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include "Library.h"
#include "Song.h"
#include "Tree.h"
#include "TitleCompare.h"

#define EXPECTED_ARGC 2

/* Print the given song to stdout */
void printSong(Song *song)
{
    std::cout << song << '\n';
}

int main(int argc, char **argv)
{
    if (argc != EXPECTED_ARGC)
    {
        std::cerr << "Usage: " << argv[0] << " <library-path>" << std::endl;
        return 1;
    }

    /* Read in the library */
    Library library(argv[1]);
    Tree<Song *, TitleCompare> titleIndex;

    /* Populate the indexes */
    for (Library::const_iterator iter = library.begin(); 
         iter != library.end(); 
         iter++)
    {
        titleIndex.insert(*iter);
    }

#ifdef DEBUG
    /* Level order printing */
    std::cout << titleIndex << '\n' << std::endl;
#endif

    /* In order printing */
    std::for_each(titleIndex.begin(), titleIndex.end(), printSong);
    std::cout << std::endl;

    return 0;
}
