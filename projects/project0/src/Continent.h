#ifndef CONTINENT_H
#define CONTINENT_H

#include "Country.h"

class Continent : public Country {

	public:

	Continent(){ /* empty */ }

	void AddCountry(Country country) {

		countriesInContinent.push_back(country);
		// SetHighestPop();

	}


	// void SetHighestPop() {

	// 	for (vector<Country>::iterator it = countriesInContinent.begin(); it != countriesInContinent.end(); ++it){
	// 		if ( (*it).GetPopulation() >= maxPopulation ) {
	// 			maxPopulation = (*it).GetPopulation();
	// 		}
	// 	}

	// 	// if ( maxPopulation < population ) {
	// 	// 	maxPopulation = population;
	// 	// }

	// }


	long GetHighestPop(){

		// for (vector<Country>::iterator it = countriesInContinent.begin(); it != countriesInContinent.end(); ++it){
		// 	cout << (*it).GetName() << endl;
		// } // for testing

		for (vector<Country>::iterator it = countriesInContinent.begin(); it != countriesInContinent.end(); ++it){
			if ( (*it).GetPopulation() >= maxPopulation ) {
				maxPopulation = (*it).GetPopulation();
				totalPopulation += (*it).GetPopulation();
				highestPopulation = (*it).GetName();
			}
		}

		return maxPopulation;

	}

	friend ostream &operator << (ostream &os, const Continent &x){

		os << "<------------->" << endl;
		os << "Highest population: " << x.totalPopulation << " " << x.maxPopulation << endl;

		return os;

	}



	private:

	static long maxPopulation;
	static long totalPopulation;
	// Country highestPopulation;
	string highestPopulation;
	Country highestGDPSpent;
	Country highestLitRate;
	vector<Country> countriesInContinent;

};

#endif