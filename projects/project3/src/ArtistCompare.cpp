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
