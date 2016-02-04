#ifndef CONTINENT_H
#define CONTINENT_H

#include <string>
#include <vector>

#include "Country.h"

using namespace std;

class Continent : public Country{

public:

Continent();

vector<Country *> CountriesInContinent();

Country HighestPopulation();

Country HighestGDPSpent();

Country HighestLitRate();


};


#endif