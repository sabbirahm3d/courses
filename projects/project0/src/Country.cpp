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

string Country::GetName() { return m_name; }

long Country::GetPopulation() { return m_population; }

float Country::GetLitRate() { return m_litRate; }

float Country::GetPriCompFem() { return m_priCompFem; }

float Country::GetPriCompMale() { return m_priCompMale; }

float Country::GetPriCompTot() { return m_priCompTot; }

float Country::GetEduGDP() { return m_eduGDP; }

float Country::GetYouthLitFem() { return m_youthLitRateFem; }

float Country::GetYouthLitMale() { return m_youthLitRateMale; }