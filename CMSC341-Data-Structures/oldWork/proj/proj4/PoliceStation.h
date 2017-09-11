/*
File: PoliceStation.h
Project: CMSC 202 Project 4, Spring 2015
Author: Sabbir Ahmed
Date: 05/04/15
Discussion section: 15
e-mail: sabbir1@umbc.edu

The header file for the PoliceStation class. */

#ifndef POLICESTATION_H
#define POLICESTATION_H

#include "WalkVertex.h"

using namespace std;

class PoliceStation : public WalkVertex {

 public:

  /* PoliceStation() - default constructor
     Preconditions: none
     Postconditions: creates PoliceStation object with unique ID, sets the 
     probability of getting caught to 1.0, and description "(none)".      */

  PoliceStation();

  /* PoliceStation() - non-default constructor
     Preconditions: none
     Postconditions: creates PoliceStation object with unique ID, the probablity
     of the robber getting caught at the police station, and description specified
     in the argument. */

  PoliceStation(double probCaught, string description);

  /* ToString() - string representation of a PoliceStation object
     Preconditions: none
     Postconditions: returns a string representation of the object. */

  virtual string ToString() const;

  /* Status() - walk status
     Preconditions: none
     Postconditions: returns status either CONTINUE or FAILURE. */

  virtual walk_status_t Status() const;

 private:

  double m_probCaught;

};

#endif
