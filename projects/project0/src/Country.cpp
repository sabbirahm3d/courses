#include "Country.h"


Country::Country(string name, long population, float litRate, float eduGDP,
  float priCompTot, float priCompMale, float priCompFem, 
  float youthLitRateFem, float youthLitRateMale) {

  this -> m_name = name;
  this -> m_population = population;
  this -> m_litRate = litRate;
  this -> m_eduGDP = eduGDP;
  this -> m_priCompTot = priCompTot;
  this -> m_priCompMale = priCompMale;
  this -> m_priCompFem = priCompFem;
  this -> m_youthLitRateFem = youthLitRateFem;
  this -> m_youthLitRateMale = youthLitRateMale;

}


string Country::GetName() const { return m_name; }

long Country::GetPopulation() const { return m_population; }

float Country::GetLitRate() const { return m_litRate; }

float Country::GetPriCompFem() const { return m_priCompFem; }

float Country::GetPriCompMale() const { return m_priCompMale; }

float Country::GetPriCompTot() const { return m_priCompTot; }

float Country::GetEduGDP() const { return m_eduGDP; }

float Country::GetYouthLitFem() const { return m_youthLitRateFem; }

float Country::GetYouthLitMale() const { return m_youthLitRateMale; }