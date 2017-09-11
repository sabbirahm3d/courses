/*
File: Vertex.h
Project: CMSC 202 Project 3, Spring 2015
Author: Sabbir Ahmed
Date: 03/09/15
Discussion section: 15
e-mail: sabbir1@umbc.edu

  This header file contains the declaration of the class Vertex of Project 3.
*/

#ifndef VERTEX_H
#define VERTEX_H

using namespace std;


class Vertex {

  public:
  
  /* Vertex() - default constructor
  Preconditions: none
  Postconditions: creates a Vertex object with
  unique integer ID. */

  Vertex();

  /* GetID() - returns the ID of the Vertex object.
  Preconditions: none
  Postconditions: returns the integer ID of the
  Vertex object. */

  int GetID() const;

  /* operator<< - overload output operator
  Preconditions: none
  Postconditions: Prints a Vertex as
        ID: v
  where v is the vertex. */

  friend ostream& operator<<(ostream &sout, const Vertex &e);

  private:

  int m_ID;

};

#endif
