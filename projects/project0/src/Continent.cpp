/* File:    Continent.cpp
 * Project: CMSC 341: Project 0, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    2/13/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu

 * This file implements all the methods and variables of the Continent class.
 * The class appends Country objects to its respective Continent vector and
 * searches for the Country object with the highest population, expendature
 * on education, literacy rate and total continent population and overloads
 * the output operator to display all the results.
 */


#include "Continent.h"


/* ******************** Constructors ******************** */

/* Continent()
 * Default constructor; creates a Continent object and uses mutators
   to initialize its attributes. */

Continent::Continent() { 

    SetTotalPop(0);
    SetHighestPop(0);
    SetHighestEduGDP(0);
    SetHighestLitRate(0);

}


/* ******************** Mutators/ setters ******************** */


/* SetHighestPop()
 * Assigns m_totalPopulation */

void Continent::SetTotalPop(int population) {

    m_totalPopulation = population;

}


/* SetHighestPop()
 * Assigns m_highestPopulation */

void Continent::SetHighestPop(int maxPopulation) {

    m_highestPopulation = maxPopulation;

}


/* SetHighestLitRate()
 * Assigns m_highestLitRate */

void Continent::SetHighestLitRate(int litRate) {

    m_highestLitRate = litRate;

}


/* SetHighestEduGDP()
 * Assigns m_highestEduGDP */

void Continent::SetHighestEduGDP(int eduGDP) {

    m_highestEduGDP = eduGDP;

}


/* ******************** Helper methods ******************** */


/* AddCountry()
 * Appends to countriesInContinent */

void Continent::AddCountry(Country country) {

    countriesInContinent.push_back(country);

}


/* ******************** Accessors/ getters ******************** */


/* GetHighestPop()
 * Loops through countriesInContinent for each of the 6 instances to find the
   total population of the continent and the Country object with the highest
   population. */

void Continent::GetHighestPop() {

    // Temporary iterator to iterate through countriesInContinent
    vector<Country>::iterator it;

    for (it = countriesInContinent.begin(); 
        it != countriesInContinent.end(); ++it) {

            m_totalPopulation += (*it).GetPopulation();

            if ( (*it).GetPopulation() >= m_highestPopulation ) {
                m_highestPopulation = (*it).GetPopulation();
                highestPopulation = *it;
            }

    }

}


/* GetHighestLitRate()
 * Loops through countriesInContinent for each of the 6 instances to find the
   Country object with the highest literacy rate. */

void Continent::GetHighestLitRate() {

    // Temporary iterator to iterate through countriesInContinent
    vector<Country>::iterator it;

    for (it = countriesInContinent.begin(); 
        it != countriesInContinent.end(); ++it){
        
        if ( (*it).GetLitRate() >= m_highestLitRate ) {
            m_highestLitRate = (*it).GetLitRate();
            highestLitRate = *it;
        }

    }

}


/* GetHighestEduGDP()
 * Loops through countriesInContinent for each of the 6 instances to find the
   Country object with the highest expendature on education. */

void Continent::GetHighestEduGDP() {

    // Temporary iterator to iterate through countriesInContinent
    vector<Country>::iterator it;

    for (it = countriesInContinent.begin(); 
        it != countriesInContinent.end(); ++it){
        
        if ( (*it).GetEduGDP() >= m_highestEduGDP ) {
            m_highestEduGDP = (*it).GetEduGDP();
            highestGDPSpent = *it;
        }

    }

}


/* ******************** Operator overloaders ******************** */


/* operator<<()
 * Overloaded output operator to display the countries with the highest
   statistics in the format specified in the Project 0 description. */

ostream& operator<< (ostream &out, Continent &continentObj){

    // Searches for the Country objects with the highest statistics only after
    // the Continent objects have all the Country objects as needed
    continentObj.GetHighestLitRate();
    continentObj.GetHighestEduGDP();
    continentObj.GetHighestPop();

    out << " * Total population: " << continentObj.m_totalPopulation << endl;

    out << " * Country with highest literacy rate: " <<
    continentObj.highestLitRate.GetName() << " with a population of " <<
    continentObj.highestLitRate.GetPopulation() <<
    " and a literacy rate of " << continentObj.highestLitRate.GetLitRate()
    << "." << endl;

    out << " * Country with highest GDP spent on education: " <<
    continentObj.highestGDPSpent.GetName() << " with a population of " <<
    continentObj.highestGDPSpent.GetPopulation() <<
    " and a literacy rate of " << continentObj.highestGDPSpent.GetLitRate()
    << "." << endl;

    out << " * Country with highest population: " <<
    continentObj.highestPopulation.GetName() << " with a population of "
    << continentObj.highestPopulation.GetPopulation() <<
    " and a literacy rate of " <<
    continentObj.highestPopulation.GetLitRate() << "." << endl;

    return out;

}