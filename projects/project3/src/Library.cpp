/* File:    Library.cpp
 * Project: CMSC 341: Project 3, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    4/11/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu

 * Song library class implementation. Readable collection of Songs constructed
 * from a file with a list of song metadata.
 */

#include "Library.h"
#include <stdexcept>
#include <fstream>


Library::Library(const std::string &libraryPath) {

    Song *song = NULL;
    std::ifstream libraryFile(libraryPath.c_str());

    if (!libraryFile) {
        throw std::invalid_argument("Bad library path");
    }


    while (libraryFile.good()) {

        song = new Song();

        libraryFile >> *song;
        _library.push_back(song);

        /*
         * _library vector takes ownership of the pointer -
         * we don't want to mess with it any further
         */
        song = NULL;

        /* Eat whitespace */
        while (libraryFile.good() &&
               (libraryFile.peek() == '\n' || libraryFile.peek() == ' ')) {
            libraryFile.get();
        }

    }

}


Library::~Library() {

    for (iterator iter = _library.begin(); iter != _library.end(); iter++) {

        if (*iter != NULL) {
            delete *iter;
            *iter = NULL;
        }

    }

}


Library::const_iterator Library::begin() const { return _library.begin(); }


Library::const_iterator Library::end() const { return _library.end(); }