/* File:    Library.h
 * Project: CMSC 341: Project 3, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    4/11/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu

 * Song library class. Readable collection of Songs constructed from a file
 * with a list of song metadata.
 */

#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include "Song.h"

class Library {

private:

    /* Mutable iterator */
    typedef std::vector<Song *>::iterator iterator;

    /* Underlying song library */
    std::vector<Song *> _library;


public:

    /* Public read-only iterator */
    typedef std::vector<Song *>::const_iterator const_iterator;

    /* Construct the library and populate it with the songs in the given file */
    Library(const std::string &libraryPath);

    /* Destructor */
    ~Library();

    /* Return a const iterator to the beginning of the Song collection */
    const_iterator begin() const;

    /* Return a const iterator pointing past the end of the Song collection */
    const_iterator end() const;

};


#endif