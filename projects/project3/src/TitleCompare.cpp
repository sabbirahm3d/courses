#include "TitleCompare.h"


bool TitleCompare::operator()(const Song *a, const Song *b) {


    if (std::string(a->title) < std::string(b->title)) { return true; }

    return false;

}


bool TitleCompare::operator()(const Song *song, const std::string &title) {

    if (std::string(song->title) < std::string(title)) { return true; }

    return false;
}


bool TitleCompare::operator()(const std::string &title, const Song *song) {

    if (std::string(title) < std::string(song->title)) { return true; }

    return false;
}