#include "Continent.h"


Continent::Continent() { 

	m_totalPopulation = 0;
	m_highestPopulation = 0;
	m_highestEduGDP = 0;
	m_highestLitRate = 0;

}


void Continent::AddCountry(Country country) {

	countriesInContinent.push_back(country);

}


void Continent::SetHighestPop() {

	vector<Country>::iterator it;

	for (it = countriesInContinent.begin(); 
		it != countriesInContinent.end(); ++it) {

			m_totalPopulation += (*it).GetPopulation();

			if ( (*it).GetPopulation() >= m_highestPopulation ) {
				m_highestPopulation = (*it).GetPopulation();
				highestPopulation = *it;
			}

	}

}


void Continent::SetHighestLitRate() {

	vector<Country>::iterator it;

	for (it = countriesInContinent.begin(); 
		it != countriesInContinent.end(); ++it){
		
		if ( (*it).GetLitRate() >= m_highestLitRate ) {
			m_highestLitRate = (*it).GetLitRate();
			highestLitRate = *it;
		}

	}

}


void Continent::SetHighestEduGDP() {

	vector<Country>::iterator it;

	for (it = countriesInContinent.begin(); 
		it != countriesInContinent.end(); ++it){
		
		if ( (*it).GetEduGDP() >= m_highestEduGDP ) {
			m_highestEduGDP = (*it).GetEduGDP();
			highestGDPSpent = *it;
		}

	}

}


ostream &operator << (ostream &out, Continent &continentObj){

	continentObj.SetHighestLitRate();
	continentObj.SetHighestEduGDP();
	continentObj.SetHighestPop();

	out << " * Total population: " << continentObj.m_totalPopulation << endl;

	out << " * Country with highest literacy rate: " <<
	continentObj.highestLitRate.GetName() << " with a population of " <<
	continentObj.highestLitRate.GetPopulation() <<
	" and a literacy rate of " << continentObj.highestLitRate.GetLitRate()
	<< "." << endl;

	out << " * Country with highest GDP spent on education: " <<
	continentObj.highestGDPSpent.GetName() << " with a population of " <<
	continentObj.highestGDPSpent.GetPopulation() <<
	" and a literacy rate of " << continentObj.highestGDPSpent.GetLitRate()
	<< "." << endl;

	out << " * Country with highest population: " <<
	continentObj.highestPopulation.GetName() << " with a population of "
	<< continentObj.highestPopulation.GetPopulation() <<
	" and a literacy rate of " <<
	continentObj.highestPopulation.GetLitRate() << "." << endl;

	return out;

}
