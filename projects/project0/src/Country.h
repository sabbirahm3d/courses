#ifndef COUNTRY_H
#define COUNTRY_H

#include <string>
#include <iostream>
using namespace std;


class Country {

private:

string name;
long population;
float literacyRate;
float primaryCompletionFemale;
float primaryCompletionMale;
float primaryCompletionTotal;
float educationGDPSpent;
float youthLitRateFem;
float youthLitRateMale;


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

string GetName(){ return name; }

long GetPopulation(){ return population; }

float GetLiteracyRate(){ return literacyRate; }

float GetPrimaryCompFem(){ return primaryCompletionFemale; }

float GetPrimaryCompMale(){ return primaryCompletionMale; }

float GetPrimaryCompTotal(){ return primaryCompletionTotal; }

float GetEduGDP(){ return educationGDPSpent; }
	
float GetYouthLitFem(){ return youthLitRateFem; }

float GetYouthLitMale(){ return youthLitRateMale; }


// Mutators

void SetName(string arg){ name = arg; }

void SetPopulation(long arg){ population = arg; }

void SetLiteracyRate(float arg){ literacyRate = arg; }

void SetPrimaryCompFem(float arg){ primaryCompletionFemale = arg; }

void SetPrimaryCompMale(float arg){ primaryCompletionMale = arg; }

void SetPrimaryCompTotal(float arg){ primaryCompletionTotal = arg; }

void SetEduGDP(float arg){ educationGDPSpent = arg; }

void SetYouthLitFem(float arg){ youthLitRateFem = arg; }

void SetYouthLitMale(float arg){ youthLitRateMale = arg; }

};

#endif