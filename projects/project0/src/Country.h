#ifndef COUNTRY_H
#define COUNTRY_H

#include <string>

using namespace std;


class Country {

private:

string m_name;
long m_population;
float m_literacyRate;
float m_primaryCompletionFemale;
float m_primaryCompletionMale;
float m_primaryCompletionTotal;
float m_educationGDPSpent;
float m_youthLitRateFem;
float m_youthLitRateMale;


public:

// Constructor

Country(string name, long population, float literacyRate, \
	float primaryCompletionFemale, float primaryCompletionMale, \
	float primaryCompletionTotal, float educationGDPSpent, \
	float youthLitRateFem, float youthLitRateMale){

	SetName(name);
	SetPopulation(population);
	SetPrimaryCompFem(primaryCompletionFemale);
	SetPrimaryCompMale(primaryCompletionMale);
	SetPrimaryCompTotal(primaryCompletionTotal);
	SetEduGDP(educationGDPSpent);
	SetYouthLitFem(youthLitRateFem);
	SetYouthLitMale(youthLitRateMale);

}


// Accessors

string GetName(){ return m_name; }

long GetPopulation(){ return m_population; }

float GetLiteracyRate(){ return m_literacyRate; }

float GetPrimaryCompFem(){ return m_primaryCompletionFemale; }

float GetPrimaryCompMale(){ return m_primaryCompletionMale; }

float GetPrimaryCompTotal(){ return m_primaryCompletionTotal; }

float GetEduGDP(){ return m_educationGDPSpent; }
	
float GetYouthLitFem(){ return m_youthLitRateFem; }

float GetYouthLitMale(){ return m_youthLitRateMale; }


// Mutators

void SetName(string arg){ m_name = arg; }

void SetPopulation(long arg){ m_population = arg; }

void SetLiteracyRate(float arg){ m_literacyRate = arg; }

void SetPrimaryCompFem(float arg){ m_primaryCompletionFemale = arg; }

void SetPrimaryCompMale(float arg){ m_primaryCompletionMale = arg; }

void SetPrimaryCompTotal(float arg){ m_primaryCompletionTotal = arg; }

void SetEduGDP(float arg){ m_educationGDPSpent = arg; }

void SetYouthLitFem(float arg){ m_youthLitRateFem = arg; }

void SetYouthLitMale(float arg){ m_youthLitRateMale = arg; }

};

#endif