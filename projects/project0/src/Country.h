/* File:    Country.h
 * Project: CMSC 341: Project 0, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    2/13/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu

 * This header file contains the declarations for the member variables and
 * methods for the Country class used in the project. The class is considered
 * a superclass (parent) of the Continent class, so all the libraries imported
 * here will be inherited to the other files in the project.
 */


#ifndef COUNTRY_H
#define COUNTRY_H

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Country {

public:

/* ******************** Constructors ******************** */


/* Country() - Empty constructor
 * Preconditions: None.
 * Postconditions: None. */

Country();


/* Country() - Overloaded constructor
 * Preconditions: The parameters must be of the data type specified.
 * Postconditions: Creates a Country object with the parameters as its
   attibutes. */

Country(string, long, float, float, float, float, float, float, float);


/* ******************** Mutators/ setters ******************** */

/* SetName()
 * Preconditions: The parameter must be a string.
 * Postconditions: Sets the parameter to m_name */

void const SetName(string);


/* SetPopulation()
 * Preconditions: The parameter must be a long.
 * Postconditions: Sets the parameter to m_population */

void const SetPopulation(long);


/* SetLitRate()
 * Preconditions: The parameter must be a float.
 * Postconditions: Sets the parameter to m_litRate */

void const SetLitRate(float);


/* SetPriCompFem()
 * Preconditions: The parameter must be a float.
 * Postconditions: Sets the parameter to m_priCompFem */

void const SetPriCompFem(float);


/* SetPriCompMale()
 * Preconditions: The parameter must be a float.
 * Postconditions: Sets the parameter to m_priCompMale */

void const SetPriCompMale(float);


/* SetPriCompTot()
 * Preconditions: The parameter must be a float.
 * Postconditions: Sets the parameter to m_priCompTot */

void const SetPriCompTot(float);


/* SetEduGDP()
 * Preconditions: The parameter must be a float.
 * Postconditions: Sets the parameter to m_eduGDP */

void const SetEduGDP(float);


/* SetYouthLitFem()
 * Preconditions: The parameter must be a float.
 * Postconditions: Sets the parameter to m_youthLitFem */

void const SetYouthLitFem(float);


/* SetYouthLitMale()
 * Preconditions: The parameter must be a float.
 * Postconditions: Sets the parameter to m_youthLitMale */

void const SetYouthLitMale(float);


/* ******************** Accessors/ getters ******************** */


/* GetName()
 * Preconditions: None.
 * Postconditions: Returns m_name */

string GetName() const;


/* GetPopulation()
 * Preconditions: None.
 * Postconditions: Returns m_population */

long GetPopulation() const;


/* GetLitRate()
 * Preconditions: None.
 * Postconditions: Returns m_litRate */

float GetLitRate() const;

/* GetPriCompFem()
 * Preconditions: None.
 * Postconditions: Returns m_priCompFem */

float GetPriCompFem() const;


/* GetPriCompMale()
 * Preconditions: None.
 * Postconditions: Returns m_priCompMale */

float GetPriCompMale() const;


/* GetPriCompTot()
 * Preconditions: None.
 * Postconditions: Returns m_priCompTot */

float GetPriCompTot() const;


/* GetEduGDP()
 * Preconditions: None.
 * Postconditions: Returns m_eduGDP */

float GetEduGDP() const;


/* GetYouthLitFem()
 * Preconditions: None.
 * Postconditions: Returns m_youthLitFem */

float GetYouthLitFem() const;


/* GetYouthLitMale()
 * Preconditions: None.
 * Postconditions: Returns m_youthLitMale */

float GetYouthLitMale() const;


private:


/* ******************** Class attributes ******************** */

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