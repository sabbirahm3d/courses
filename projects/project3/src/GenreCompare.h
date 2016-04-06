#ifndef GENRE_COMPARE_H
#define GENRE_COMPARE_H

/* Declaration of the comparison functor for use with the Title index */

#include <string>
#include "Song.h"

struct GenreCompare {
    /*
     * Return whether or not song a's title is
     * lexicographically less than song b's title
     */
    bool operator()(const Song *, const Song *);

    /*
     * Return whether or not the song's title is
     * lexicographically less than the given title
     */
    bool operator()(const Song *, const std::string &);

    /*
     * Return whether or not the given title is
     * lexicographically less than the song's title
     */
    bool operator()(const std::string &, const Song *);

};

#endif