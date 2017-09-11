/* File:    TitleCompare.cpp
 * Project: CMSC 341: Project 3, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    4/11/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu

 * functor to compare data so it is stored in sorted order. Calling
 * Compare()(a, b) returns true if a is less than b, and false otherwise.
 */

#include "TitleCompare.h"

bool TitleCompare::operator()(const Song *a, const Song *b) {
    return a->title < b->title;
}


bool TitleCompare::operator()(const Song *song, const std::string &title) {
    return song->title < title;
}

bool TitleCompare::operator()(const std::string &title, const Song *song) {
    return title < song->title;
}