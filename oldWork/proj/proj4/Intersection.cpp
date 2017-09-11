/*
File: Intersection.cpp
Project: CMSC 202 Project 4, Spring 2015
Author: Sabbir Ahmed
Date: 05/04/15
Discussion section: 15
e-mail: sabbir1@umbc.edu

The implementation file for the Intersection class, a derived class of 
WalkVertex.                                        */

#include <iostream> 
#include <sstream>   // Needed for stringstream class
#include "Intersection.h"

using namespace std;

Intersection::Intersection() 
  : WalkVertex()
{ /* empty constructor body */ }

Intersection::Intersection(string description) 
  : WalkVertex(description)
{ /* empty constructor body */ }

string Intersection::ToString() const {

  // Use the stringstream class to create the string representation.
  stringstream ss;

  ss << "ID " << GetID() <<": Intersection (" << m_description << ")";

  return ss.str();

}

walk_status_t Intersection::Status() const {

  // Always return CONTINUE for an Intersection object.
  return CONTINUE;

}
