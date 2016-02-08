#ifndef CONTINENT_H
#define CONTINENT_H

#include "Country.h"

class Continent : public Country {

	public:

	Continent(Country country) {

		countriesInContinent.push_back(country);

	}

	private:

	Country highestPopulation;

	Country highestGDPSpent;

	Country highestLitRate;

	vector<Country> countriesInContinent;

};

#endif