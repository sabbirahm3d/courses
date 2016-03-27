/*
File: Intersection.h
Project: CMSC 202 Project 4, Spring 2015
Author: Sabbir Ahmed
Date: 05/04/15
Discussion section: 15
e-mail: sabbir1@umbc.edu

Header file for the Intersection class.             */

#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "WalkVertex.h"

using namespace std;

class Intersection : public WalkVertex {

 public:

  /* Intersection() - default constructor
     Preconditions: none
     Postconditions: creates Intersection object with unique ID and
     description "(none)".                                           */

  Intersection();

  /* Intersection() - non-default constructor
     Preconditions: none
     Postconditions: creates Intersection object with unique ID and
     description specified in the argument.                          */

  Intersection(string description);
  
  /* ToString() - string representation of a Intersection object
     Preconditions: none
     Postconditions: returns a string representation of the object.  */

  virtual string ToString() const;

  /* Status() - walk status
     Preconditions: none
     Postconditions: returns status CONTINUE.                        */

  virtual walk_status_t Status() const;

};

#endif
