#ifndef COUNTRY_H
#define COUNTRY_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;


class Country {

	public:

	// Constructors

	Country() { /* Empty constructor */ }
	Country(string, long, float, float, float, float, float, float, float);


	// Accessors

	string GetName() const;
	long GetPopulation() const;
	float GetLitRate() const;
	float GetPriCompFem() const;
	float GetPriCompMale() const;
	float GetPriCompTot() const;
	float GetEduGDP() const;
	float GetYouthLitFem() const;
	float GetYouthLitMale() const;


	// // Mutators

	// void SetName(string arg) { m_name = arg; }

	// void SetPopulation(long arg) { m_population = arg; }

	// void SetLitRate(float arg) { m_litRate = arg; }

	// void SetPriCompFem(float arg) { m_priCompFem = arg; }

	// void SetPriCompMale(float arg) { m_priCompMale = arg; }

	// void SetPriCompTot(float arg) { m_priCompTot = arg; }

	// void SetEduGDP(float arg) { m_eduGDP = arg; }

	// void SetYouthLitFem(float arg) { m_youthLitRateFem = arg; }

	// void SetYouthLitMale(float arg) { m_youthLitRateMale = arg; }

	private:

	string m_name;
	long m_population;
	float m_litRate;
	float m_eduGDP;
	float m_priCompFem;
	float m_priCompMale;
	float m_priCompTot;
	float m_youthLitRateFem;
	float m_youthLitRateMale;


};

#endif