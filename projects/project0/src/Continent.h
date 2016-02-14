/* File:    Continent.h
 * Project: CMSC 341: Project 0, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    2/13/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu

 * This header file contains the declarations for the member variables and
 * methods for the Continent class used in the project. The class is considered
 * a subclass (child) of the Country class.
 */


#ifndef CONTINENT_H
#define CONTINENT_H

#include "Country.h"


class Continent : public Country {

public:

	// Constructor

	/* Continent() - Overloaded constructor
	 * Preconditions: None.
	 * Postconditions: Creates a Continent object and initializes the member
	   variables. */

	Continent();


	// Mutators/ setters

	/* SetHighestPop()
	 * Preconditions: None.
	 * Postconditions: Returns the Country object with the highest
	   population. */

	void SetHighestPop();


	/* SetHighestLitRate()
	 * Preconditions: None.
	 * Postconditions: Returns the Country object with the highest
	   literacy rate. */

	void SetHighestLitRate();


	/* SetHighestEduGDP()
	 * Preconditions: None.
	 * Postconditions: Returns the Country object with the highest
	   spending on education. */

	void SetHighestEduGDP();


	/* AddCountry()
	 * Preconditions: Requires a Country object.
	 * Postconditions: Appends to the vector of Country objects. */

	void AddCountry(Country);


	/* operator<< - Overloaded output operator.
	 * Preconditions: None.
	 * Postconditions: Returns the Country object with the highest
	   spending on education. */

	friend ostream& operator<<(ostream&, Continent&);


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