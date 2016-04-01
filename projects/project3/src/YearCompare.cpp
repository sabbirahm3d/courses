#include "YearCompare.h"

bool YearCompare::operator()(const Song *a, const Song *b) {
	return a -> year < b -> year;
}


bool YearCompare::operator()(const Song *song, const unsigned long year) {
	return song -> year < year;
}


bool YearCompare::operator()(const unsigned long year, const Song *song) {
	return year < song -> year;
}
