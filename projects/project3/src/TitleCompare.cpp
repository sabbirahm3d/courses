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