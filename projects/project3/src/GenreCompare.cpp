#include "GenreCompare.h"


bool GenreCompare::operator()(const Song* a, const Song* b) {

    if (a->genre < b->genre) { return true; }

    return false;

}


bool GenreCompare::operator()(const Song* song, const std::string& genre) {

    if (song->genre < genre) { return true; }

    return false;

}


bool GenreCompare::operator()(const std::string& genre, const Song* song) {

    if (genre < song->genre) { return true; }

    return false;

}
