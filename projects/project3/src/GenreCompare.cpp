/* File:    GenreCompare.cpp
 * Project: CMSC 341: Project 3, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    4/11/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu

 * functor to compare data so it is stored in sorted order. Calling
 * Compare()(a, b) returns true if a is less than b, and false otherwise.
 */

#include "GenreCompare.h"

bool GenreCompare::operator()(const Song *a, const Song *b) {
    return a->genre < b->genre;
}


bool GenreCompare::operator()(const Song *song, const std::string &genre) {
    return song->genre < genre;
}


bool GenreCompare::operator()(const std::string &genre, const Song *song) {
    return genre < song->genre;
}
