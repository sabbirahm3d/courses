#include "YearCompare.h"


bool YearCompare::operator()(const Song* a, const Song* b) {

    if (a->year < b->year) { return true; }

    return false;

}


bool YearCompare::operator()(const Song* song, const unsigned long year) {

    if (song->year < year) { return true; }

    return false;

}


bool YearCompare::operator()(const unsigned long year, const Song* song) {

    if (year < song->year) { return true; }

    return false;

}
