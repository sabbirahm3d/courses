#ifndef CONTINENT_H
#define CONTINENT_H

#include "Country.h"

class Continent : public Country {

public:

	Continent();
	void AddCountry(Country);
	long GetHighestPop();
	float GetHighestLitRate();
	float GetHighestEduGDP();

	friend ostream &operator << (ostream &os, const Continent &x){

		os << " Population: " << x.totalPopulation << endl;

		os << " Country with highest literacy rate: " << 
		x.highestLitRate.GetName() << " with a population of " <<
		x.highestLitRate.GetPopulation() << " and a literacy rate of "
		<< x.highestLitRate.GetLitRate() << endl ;

		os << " Country with highest GDP spent on education: " << 
		x.highestGDPSpent.GetName() << " with a population of " <<
		x.highestGDPSpent.GetPopulation() << " and a literacy rate of "
		<< x.highestGDPSpent.GetLitRate() << endl ;

		os << " Country with highest population: " << 
		x.highestPopulation.GetName() << " with a population of " <<
		x.highestPopulation.GetPopulation() << " and a literacy rate of "
		<< x.highestPopulation.GetLitRate() << endl ;

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