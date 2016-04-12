/* File:    ArtistCompare.cpp
 * Project: CMSC 341: Project 3, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    4/11/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu

 * functor to compare data so it is stored in sorted order. Calling
 * Compare()(a, b) returns true if a is less than b, and false otherwise.
 */

#include "ArtistCompare.h"

bool ArtistCompare::operator()(const Song *a, const Song *b) {
    return a->artist < b->artist;
}


bool ArtistCompare::operator()(const Song *song, const std::string &artist) {
    return song->artist < artist;
}


bool ArtistCompare::operator()(const std::string &artist, const Song *song) {
    return artist < song->artist;
}
