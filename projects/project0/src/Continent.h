#ifndef CONTINENT_H
#define CONTINENT_H

#include "Country.h"

class Continent : public Country {

	public:

	Continent();

	vector< Country * > CountriesInContinent();

	Country HighestPopulation();

	Country HighestGDPSpent();

	Country HighestLitRate();

	private:

	vector< Country > countriesInContinent;


};

#endif