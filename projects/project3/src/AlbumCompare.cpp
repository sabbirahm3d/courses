/* File:    AlbumCompare.cpp
 * Project: CMSC 341: Project 3, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    4/11/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu

 * functor to compare data so it is stored in sorted order. Calling
 * Compare()(a, b) returns true if a is less than b, and false otherwise.
 */

#include "AlbumCompare.h"

bool AlbumCompare::operator()(const Song *a, const Song *b) {
    return a->album < b->album;
}


bool AlbumCompare::operator()(const Song *song, const std::string &album) {
    return song->album < album;
}


bool AlbumCompare::operator()(const std::string &album, const Song *song) {
    return album < song->album;
}
