/* File:    YearCompare.cpp
 * Project: CMSC 341: Project 3, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    4/11/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu

 * functor to compare data so it is stored in sorted order. Calling
 * Compare()(a, b) returns true if a is less than b, and false otherwise.
 */

#include "YearCompare.h"

bool YearCompare::operator()(const Song *a, const Song *b) {
    return a->year < b->year;
}


bool YearCompare::operator()(const Song *song, const unsigned long year) {
    return song->year < year;
}


bool YearCompare::operator()(const unsigned long year, const Song *song) {
    return year < song->year;
}
