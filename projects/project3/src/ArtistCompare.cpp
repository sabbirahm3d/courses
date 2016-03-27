#include "ArtistCompare.h"


bool ArtistCompare::operator()(const Song* a, const Song* b) {

    if (a->artist < b->artist) { return true; }

    return false;

}


bool ArtistCompare::operator()(const Song* song, const std::string& artist) {

    if (song->artist < artist) { return true; }

    return false;

}


bool ArtistCompare::operator()(const std::string& artist, const Song* song) {

    if (artist < song->artist) { return true; }

    return false;

}
