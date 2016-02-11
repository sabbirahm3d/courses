#include "Continent.h"


Continent::Continent() { 

  totalPopulation = 0;
  maxPopulation = 0;
  maxEduGDP = 0;
  maxLitRate = 0;

}


void Continent::AddCountry(Country country) {

  countriesInContinent.push_back(country);

}


long Continent::GetHighestPop() {

  vector<Country>::iterator it;

  for (it = countriesInContinent.begin(); 
    it != countriesInContinent.end(); ++it) {

      totalPopulation += (*it).GetPopulation();

      if ( (*it).GetPopulation() >= maxPopulation ) {
        maxPopulation = (*it).GetPopulation();
        highestPopulation = *it;
      }

  }

  return maxPopulation;

}


float Continent::GetHighestLitRate() {

  vector<Country>::iterator it;

  for (it = countriesInContinent.begin(); 
    it != countriesInContinent.end(); ++it){
    
    if ( (*it).GetLitRate() >= maxLitRate ) {
      maxLitRate = (*it).GetLitRate();
      highestLitRate = *it;
    }

  }

  return maxLitRate;

}


float Continent::GetHighestEduGDP() {

  vector<Country>::iterator it;

  for (it = countriesInContinent.begin(); 
    it != countriesInContinent.end(); ++it){
    
    if ( (*it).GetEduGDP() >= maxEduGDP ) {
      maxEduGDP = (*it).GetEduGDP();
      highestGDPSpent = *it;
    }

  }

  return maxEduGDP;

}