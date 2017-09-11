/*
File: Edge.cpp
Project: CMSC 202 Project 3, Spring 2015
Author: Sabbir Ahmed
Date: 03/09/15
Discussion section: 15
e-mail: sabbir1@umbc.edu

  This file contains the implementation of the class Edge of Project 3.
*/

#include <iostream>
#include "Vertex.h"
#include "Edge.h"

using namespace std;

Edge::Edge(Vertex *v1, Vertex *v2) {

  if ((v1 == NULL) || (v2 == NULL))
    cerr << "Error. A null value was entered." << endl;

  else {
    m_v1 = v1;
    m_v2 = v2;
  }

}

Vertex* Edge::GetV1() const {

  return m_v1;

}

Vertex* Edge::GetV2() const {

  return m_v2;

}

void Edge::SetV1(Vertex *v) {

  if (v == NULL)
    cerr << "Error. A null value was entered." << endl;

  else
    m_v1 = v;

}

void Edge::SetV2(Vertex *v) {

  if (v == NULL)
    cerr << "Error. A null value was entered." << endl;

  else
    m_v2 = v;

}

ostream& operator<< (ostream &sout, const Edge &e) {

  sout << *e.GetV1() << " <--> " << *e.GetV2();
  return sout;

}
