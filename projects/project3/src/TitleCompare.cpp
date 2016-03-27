#include "TitleCompare.h"


bool TitleCompare::operator()(const Song* a, const Song* b) {

    if (a->title < b->title) { return true; }

    return false;

}


bool TitleCompare::operator()(const Song* song, const std::string& title) {

    if (song->title < title) { return true; }

    return false;

}


bool TitleCompare::operator()(const std::string& title, const Song* song) {

    if (title < song->title) { return true; }

    return false;

}
