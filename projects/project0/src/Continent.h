#ifndef CONTINENT_H
#define CONTINENT_H

#include "Country.h"

class Continent : public Country {

public:

  Continent();
  void Init();
  void AddCountry(Country);
  long GetHighestPop();
  float GetHighestLitRate();
  float GetHighestEduGDP();

  friend ostream &operator << (ostream &output, Continent &continentObj){

    continentObj.Init();

    output << " * Total population: " << continentObj.m_totalPopulation << endl;

    output << " * Country with highest literacy rate: " <<
    continentObj.highestLitRate.GetName() << " with a population of " <<
    continentObj.highestLitRate.GetPopulation() <<
    " and a literacy rate of " << continentObj.highestLitRate.GetLitRate()
    << "." << endl;

    output << " * Country with highest GDP spent on education: " <<
    continentObj.highestGDPSpent.GetName() << " with a population of " <<
    continentObj.highestGDPSpent.GetPopulation() <<
    " and a literacy rate of " << continentObj.highestGDPSpent.GetLitRate()
    << "." << endl;

    output << " * Country with highest population: " <<
    continentObj.highestPopulation.GetName() << " with a population of "
    << continentObj.highestPopulation.GetPopulation() <<
    " and a literacy rate of " <<
    continentObj.highestPopulation.GetLitRate() << "." << endl;

    return output;

  }

private:

  long m_highestPopulation;
  long m_totalPopulation;
  float m_highestLitRate;
  float m_highestEduGDP;

  Country highestPopulation;
  Country highestGDPSpent;
  Country highestLitRate;
  vector<Country> countriesInContinent;

};

#endif