/* File:    Country.cpp
 * Project: CMSC 341: Project 0, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    2/13/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu

 * This file implements all the methods and variables of the Country class. The
 * class reads in the data extracted by the driver program from the input files
 * provided by the project description, and uses setters to assign them as
 * attributes.
 */


#include "Country.h"

// Constructor

Country::Country() { /* Empty constructor */ }

Country::Country(string name, long population, float litRate, float eduGDP,
	float priCompTot, float priCompMale, float priCompFem, 
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


// Mutators

void const Country::SetName(string arg) { m_name = arg; }

void const Country::SetPopulation(long arg) { m_population = arg; }

void const Country::SetLitRate(float arg) { m_litRate = arg; }

void const Country::SetPriCompFem(float arg) { m_priCompFem = arg; }

void const Country::SetPriCompMale(float arg) { m_priCompMale = arg; }

void const Country::SetPriCompTot(float arg) { m_priCompTot = arg; }

void const Country::SetEduGDP(float arg) { m_eduGDP = arg; }

void const Country::SetYouthLitFem(float arg) { m_youthLitRateFem = arg; }

void const Country::SetYouthLitMale(float arg) { m_youthLitRateMale = arg; }


// Accessors

string Country::GetName() const { return m_name; }

long Country::GetPopulation() const { return m_population; }

float Country::GetLitRate() const { return m_litRate; }

float Country::GetPriCompFem() const { return m_priCompFem; }

float Country::GetPriCompMale() const { return m_priCompMale; }

float Country::GetPriCompTot() const { return m_priCompTot; }

float Country::GetEduGDP() const { return m_eduGDP; }

float Country::GetYouthLitFem() const { return m_youthLitRateFem; }

float Country::GetYouthLitMale() const { return m_youthLitRateMale; }