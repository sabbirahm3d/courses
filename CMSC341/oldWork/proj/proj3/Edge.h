/*
File: Edge.h
Project: CMSC 202 Project 3, Spring 2015
Author: Sabbir Ahmed
Date: 03/09/15
Discussion section: 15
e-mail: sabbir1@umbc.edu

  This header file contains the declaration for the Edge class of Project 3.
*/

#ifndef EDGE_H
#define EDGE_H

#include <iostream>
#include "Vertex.h"

using namespace std;

class Edge {

 public:

  /* Edge() - constructor
     Preconditions: v1 and v2 are non-NULL.
     Postconditions: creates an Edge object with vertices v1 and v2;
     if either v1 or v2 is NULL, prints an error message and exits.   */

  Edge(Vertex *v1, Vertex *v2);

  /* GetV1() - returns a pointer to the first Vertex in the Edge
     Preconditions: none
     Postconditions: returns pointer to the first Vertex.             */

  Vertex* GetV1() const;

  /* GetV2() - returns a pointer to the second Vertex in the Edge
     Preconditions: none
     Postconditions: returns pointer to the second Vertex.            */

  Vertex* GetV2() const;
  
  /* SetV1() - sets the first Vertex (m_v1) in the Edge
     Preconditions: v is non-NULL
     Postconditions: sets m_v1 to v; if v is  NULL, prints a warning 
     message and does NOT change m_v1.                                */

  void SetV1(Vertex *v);

  /* SetV2() - sets the second Vertex (m_v2) in the Edge
     Preconditions: v is non-NULL
     Postconditions: sets m_v2 to v; if v is  NULL, prints a warning 
     message and does NOT change m_v2.                                */

  void SetV2(Vertex *v);

  /* operator<< - overload output operator
     Preconditions: none
     Postconditions: Prints an Edge as
          ID: m <--> ID: n
     where m and n are the IDs of the first and second Vertex.        */

  friend ostream& operator<<(ostream &sout, const Edge &e);

 private:

  Vertex* m_v1;
  Vertex* m_v2;

};

#endif
