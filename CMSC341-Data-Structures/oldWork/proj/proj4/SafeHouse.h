/*                                                                         
File: SafeHouse.h                                                            
Project: CMSC 202 Project 4, Spring 2015                                   
Author: Sabbir Ahmed                                                       
Date: 05/04/15                                                             
Discussion section: 15                                                     
e-mail: sabbir1@umbc.edu                                                   

The header file for the SafeHouse class.                        */

#ifndef SAFEHOUSE_H
#define SAFEHOUSE_H

#include "WalkVertex.h"

using namespace std;

class SafeHouse : public WalkVertex {

 public:

  /* SafeHouse() - default constructor
     Preconditions: none
     Postconditions: creates SafeHouse object with unique ID and
     description "(none)".                                           */

  SafeHouse();

  /* SafeHouse() - non-default constructor
     Preconditions: none
     Postconditions: creates SafeHouse object with unique ID and
     description specified in the argument.                          */

  SafeHouse(string description);
  
  /* ToString() - string representation of a SafeHouse object
     Preconditions: none
     Postconditions: returns a string representation of the object.  */

  virtual string ToString() const;

  /* Status() - walk status
     Preconditions: none
     Postconditions: returns status SUCCESS.                        */

  virtual walk_status_t Status() const;

};

#endif
