#include "Continent.h"


Continent::Continent() { 

  m_totalPopulation = 0;
  m_highestPopulation = 0;
  m_highestEduGDP = 0;
  m_highestLitRate = 0;

}

void Continent::Init() {

  GetHighestLitRate();
  GetHighestEduGDP();
  GetHighestPop();

}


void Continent::AddCountry(Country country) {

  countriesInContinent.push_back(country);

}


long Continent::GetHighestPop() {

  vector<Country>::iterator it;

  for (it = countriesInContinent.begin(); 
    it != countriesInContinent.end(); ++it) {

      m_totalPopulation += (*it).GetPopulation();

      if ( (*it).GetPopulation() >= m_highestPopulation ) {
        m_highestPopulation = (*it).GetPopulation();
        highestPopulation = *it;
      }

  }

  return m_highestPopulation;

}


float Continent::GetHighestLitRate() {

  vector<Country>::iterator it;

  for (it = countriesInContinent.begin(); 
    it != countriesInContinent.end(); ++it){
    
    if ( (*it).GetLitRate() >= m_highestLitRate ) {
      m_highestLitRate = (*it).GetLitRate();
      highestLitRate = *it;
    }

  }

  return m_highestLitRate;

}


float Continent::GetHighestEduGDP() {

  vector<Country>::iterator it;

  for (it = countriesInContinent.begin(); 
    it != countriesInContinent.end(); ++it){
    
    if ( (*it).GetEduGDP() >= m_highestEduGDP ) {
      m_highestEduGDP = (*it).GetEduGDP();
      highestGDPSpent = *it;
    }

  }

  return m_highestEduGDP;

}