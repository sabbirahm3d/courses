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


/* ******************** Constructors ******************** */

/* Country()
 * Empty constructor */

Country::Country() { /* Empty constructor */ }


/* Country()
 * Overloaded constructor; creates a Country object and uses mutators
 * to assign attributes to it. */

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


/* ******************** Mutators/ setters ******************** */


/* SetName()
 * Assigns m_name */

void const Country::SetName(string arg) { m_name = arg; }


/* SetPopulation()
 * Assigns m_population */

void const Country::SetPopulation(long arg) { m_population = arg; }


/* SetLitRate()
 * Assigns m_litRate */

void const Country::SetLitRate(float arg) { m_litRate = arg; }


/* SetPriCompFem()
 * Assigns m_priCompFem */

void const Country::SetPriCompFem(float arg) { m_priCompFem = arg; }


/* SetPriCompMale()
 * Assigns m_priCompMale */

void const Country::SetPriCompMale(float arg) { m_priCompMale = arg; }


/* SetPriCompTot()
 * Assigns m_priCompTot */

void const Country::SetPriCompTot(float arg) { m_priCompTot = arg; }


/* SetEduGDP()
 * Assigns m_eduGDP */

void const Country::SetEduGDP(float arg) { m_eduGDP = arg; }


/* SetYouthLitFem()
 * Assigns m_youthLitRateFem */

void const Country::SetYouthLitFem(float arg) { m_youthLitRateFem = arg; }


/* SetYouthLitMale()
 * Assigns m_youthLitRateMale */

void const Country::SetYouthLitMale(float arg) { m_youthLitRateMale = arg; }


/* ******************** Accessors/ getters ******************** */


/* GetName()
 * Returns m_name */

string Country::GetName() const { return m_name; }


/* GetPopulation()
 * Returns m_population */

long Country::GetPopulation() const { return m_population; }


/* GetLitRate()
 * Returns m_litRate */

float Country::GetLitRate() const { return m_litRate; }


/* GetPriCompFem()
 * Returns m_priCompFem */

float Country::GetPriCompFem() const { return m_priCompFem; }


/* GetPriCompMale()
 * Returns m_priCompMale */

float Country::GetPriCompMale() const { return m_priCompMale; }


/* GetPriCompTot()
 * Returns m_priCompTot */

float Country::GetPriCompTot() const { return m_priCompTot; }


/* GetEduGDP()
 * Returns m_eduGDP */

float Country::GetEduGDP() const { return m_eduGDP; }


/* GetYouthLitFem()
 * Returns m_youthLitRateFem */

float Country::GetYouthLitFem() const { return m_youthLitRateFem; }


/* GetYouthLitMale()
 * Returns m_youthLitRateMale */

float Country::GetYouthLitMale() const { return m_youthLitRateMale; }