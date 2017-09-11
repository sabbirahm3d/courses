/*
File: PoliceStation.cpp
Project: CMSC 202 Project 4, Spring 2015
Author: Sabbir Ahmed
Date: 05/04/15
Discussion section: 15
e-mail: sabbir1@umbc.edu

The implementation file for the PoliceStation class, a derived class of 
WalkVertex.                                       */

#include <iostream>
#include <sstream>   // Needed for stringstream class
#include <stdlib.h>
#include "PoliceStation.h"

using namespace std;

PoliceStation::PoliceStation()
  : WalkVertex(), m_probCaught(1.0)
{/* Empty constructor body */}

PoliceStation::PoliceStation(double probCaught, string description)
  : WalkVertex(description), m_probCaught(probCaught)
{/* Empty constructor body */}

string PoliceStation::ToString() const {

  /* Use the stringstream class to create the string representation. */
  stringstream ss;

  ss << "ID " << GetID() << ": Police Station (" << m_description << ")";
  return ss.str();

}

walk_status_t PoliceStation::Status() const {

  double probSum = (RAND_MAX - rand()) / static_cast<double>(RAND_MAX);

  if (probSum < m_probCaught)
    return FAILURE; // caught by the police

  else
    return CONTINUE; // got away


}
