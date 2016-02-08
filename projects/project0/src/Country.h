#ifndef COUNTRY_H
#define COUNTRY_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm> // for copy
#include <iterator> // for ostream_iterator


using namespace std;


class Country {

	public:

	// Constructor

	Country() { cerr << "Default constructor used." << endl; }

	Country(string name, long population, float litRate,
			 float eduGDP, float priCompTot,
			 float priCompMale, float priCompFem, 
			 float youthLitRateFem, float youthLitRateMale) {

		SetName(name);
		SetPopulation(population);
		SetLitRate(litRate);
		SetPriCompFem(priCompFem);
		SetPriCompMale(priCompMale);
		SetPriCompTot(priCompTot);
		SetEduGDP(eduGDP);
		SetYouthLitFem(youthLitRateFem);
		SetYouthLitMale(youthLitRateMale);

	}


	// Accessors

	string GetName() { return m_name; }

	long GetPopulation() { return m_population; }

	float GetLitRate() { return m_litRate; }

	float GetPriCompFem() { return m_priCompFem; }

	float GetPriCompMale() { return m_priCompMale; }

	float GetPriCompTot() { return m_priCompTot; }

	float GetEduGDP() { return m_eduGDP; }

	float GetYouthLitFem() { return m_youthLitRateFem; }

	float GetYouthLitMale() { return m_youthLitRateMale; }


	// Mutators

	void SetName(string arg) { m_name = arg; }

	void SetPopulation(long arg) { m_population = arg; }

	void SetLitRate(float arg) { m_litRate = arg; }

	void SetPriCompFem(float arg) { m_priCompFem = arg; }

	void SetPriCompMale(float arg) { m_priCompMale = arg; }

	void SetPriCompTot(float arg) { m_priCompTot = arg; }

	void SetEduGDP(float arg) { m_eduGDP = arg; }

	void SetYouthLitFem(float arg) { m_youthLitRateFem = arg; }

	void SetYouthLitMale(float arg) { m_youthLitRateMale = arg; }

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