/* File:    TicTacNode.cpp
 * Project: CMSC 341: Project 2, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    2/
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * The implementation file for the TicTacNode class. The file simply consists
 */

#include "TicTacNode.h"

/* ******************** Constructors ******************** */

/* Node341()
 * Default constructor; creates a Node341 object and initializes its member
   attributes */

TicTacNode::TicTacNode() {

	next = prev = NULL;
	this->data = data;

}


ostream& operator<< (ostream& out, TicTacNode& continentObj){


    // out << " * Total population: " << continentObj.m_totalPopulation << endl;

    // out << " * Country with highest literacy rate: " <<
    // continentObj.highestLitRate.GetName() << " with a population of " <<
    // continentObj.highestLitRate.GetPopulation() <<
    // " and a literacy rate of " << continentObj.highestLitRate.GetLitRate()
    // << "." << endl;

    // out << " * Country with highest GDP spent on education: " <<
    // continentObj.highestGDPSpent.GetName() << " with a population of " <<
    // continentObj.highestGDPSpent.GetPopulation() <<
    // " and a literacy rate of " << continentObj.highestGDPSpent.GetLitRate()
    // << "." << endl;

    // out << " * Country with highest population: " <<
    // continentObj.highestPopulation.GetName() << " with a population of "
    // << continentObj.highestPopulation.GetPopulation() <<
    // " and a literacy rate of " <<
    // continentObj.highestPopulation.GetLitRate() << "." << endl;

    return out;

}

#endif