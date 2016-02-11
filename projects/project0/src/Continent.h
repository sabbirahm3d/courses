#ifndef CONTINENT_H
#define CONTINENT_H

#include "Country.h"

class Continent : public Country {

public:

	Continent();
	void AddCountry(Country);
	void Init() {

		GetHighestLitRate();
		GetHighestEduGDP();
		GetHighestPop();

	}
	long GetHighestPop();
	float GetHighestLitRate();
	float GetHighestEduGDP();

	friend ostream &operator << (ostream &os, const Continent &continentObj){

		os << " * Total population: " << continentObj.totalPopulation << endl;

		os << " * Country with highest literacy rate: " <<
		continentObj.highestLitRate.GetName() << " with a population of " <<
		continentObj.highestLitRate.GetPopulation() << " and a literacy rate of "
		<< continentObj.highestLitRate.GetLitRate() << "." << endl ;

		os << " * Country with highest GDP spent on education: " <<
		continentObj.highestGDPSpent.GetName() << " with a population of " <<
		continentObj.highestGDPSpent.GetPopulation() << " and a literacy rate of "
		<< continentObj.highestGDPSpent.GetLitRate() << "." << endl ;

		os << " * Country with highest population: " <<
		continentObj.highestPopulation.GetName() << " with a population of " <<
		continentObj.highestPopulation.GetPopulation() << " and a literacy rate of "
		<< continentObj.highestPopulation.GetLitRate() << "." << endl ;

		return os;

	}

private:

	long maxPopulation;
	long totalPopulation;
	float maxLitRate;
	float maxEduGDP;

	Country highestPopulation;
	Country highestGDPSpent;
	Country highestLitRate;
	vector<Country> countriesInContinent;

};

#endif