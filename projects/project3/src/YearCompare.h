/* File:    YearCompare.h
 * Project: CMSC 341: Project 3, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    4/11/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu

 * Class declaration for functor
 */

#ifndef YEAR_COMPARE_H
#define YEAR_COMPARE_H

/* Declaration of the comparison functor for use with the Title index */

#include "Song.h"

struct YearCompare {

    /* 
     * Return whether or not song a's title is 
     * lexicographically less than song b's title
     */
    bool operator()(const Song *, const Song *);

    /*
     * Return whether or not the song's title is
     * lexicographically less than the given title
     */
    bool operator()(const Song *, const unsigned long);

    /*
     * Return whether or not the given title is
     * lexicographically less than the song's title
     */
    bool operator()(const unsigned long, const Song *);

};


#endif