/*
File: Vertex.cpp
Project: CMSC 202 Project 3, Spring 2015
Author: Sabbir Ahmed
Date: 03/09/15
Discussion section: 15
e-mail: sabbir1@umbc.edu

  This file contains the implementation of the Vertex class.
*/

#include <iostream>
#include "Vertex.h"
#include "Edge.h"

using namespace std;

Vertex::Vertex() {

  /* Uses a static variable to keep track of the vertex IDs */
  static int vertexCount = 0;

  m_ID = vertexCount;
  vertexCount++;

}

/* Standard accessor: returns the ID of the vertex */
int Vertex::GetID() const {

  return m_ID;

}

/* << operator overloader */
ostream& operator<<(ostream &vout, const Vertex &v) {

  vout << "ID: " << v.GetID();
  return vout;

}

