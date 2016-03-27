#include "AlbumCompare.h"


bool AlbumCompare::operator()(const Song* a, const Song* b) {

    if (a->album < b->album) { return true; }

    return false;

}


bool AlbumCompare::operator()(const Song* song, const std::string& album) {

    if (song->album < album) { return true; }

    return false;

}


bool AlbumCompare::operator()(const std::string& album, const Song* song) {

    if (album < song->album) { return true; }

    return false;

}
