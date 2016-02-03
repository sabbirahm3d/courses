/*                                                                         
File: SafeHouse.cpp                                                            
Project: CMSC 202 Project 4, Spring 2015                                   
Author: Sabbir Ahmed                                                       
Date: 05/04/15                                                             
Discussion section: 15                                                     
e-mail: sabbir1@umbc.edu                                                   

Contains implementation of the SafeHouse class, a derived class of WalkVertex. */

#include <iostream> 
#include <sstream>   // Needed for stringstream class
#include "SafeHouse.h"

using namespace std;

SafeHouse::SafeHouse()
  : WalkVertex()
{/* Empty constructor body */}

SafeHouse::SafeHouse(string description) 
  : WalkVertex(description)
{/* Empty constructor body */}

string SafeHouse::ToString() const {

  // Use the stringstream class to create the string representation.
  stringstream ss;

  ss << "ID " << GetID() <<": SafeHouse (" << m_description << ")";

  return ss.str();

}

walk_status_t SafeHouse::Status() const {

  // Always return SUCCESS for an SafeHouse object.
  return SUCCESS;

}
