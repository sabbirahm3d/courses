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
