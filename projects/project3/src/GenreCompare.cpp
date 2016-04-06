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
