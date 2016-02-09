#ifndef CONTINENT_H
#define CONTINENT_H

#include "Country.h"

class Continent : public Country {

	public:

	Continent(Country country) {

		countriesInContinent.push_back(country);
		SetHighestPop(country.GetPopulation());

	}


	void SetHighestPop(long population){

		if ( maxPopulation < population){
			maxPopulation = population;
		}

	}


	long GetHighestPop(){

		return maxPopulation;

	}

	friend ostream &operator << (ostream &os, const Continent &x){

		os << "Highest population: " << x.maxPopulation << endl;

		return os;

	}



	private:

	static long maxPopulation;
	Country highestPopulation;
	Country highestGDPSpent;
	Country highestLitRate;
	vector<Country> countriesInContinent;

};

#endif