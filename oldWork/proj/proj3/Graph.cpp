/*
File: Graph.cpp
Project: CMSC 202 Project 3, Spring 2015
Author: Sabbir Ahmed
Date: 03/09/15 
Discussion section: 15
 e-mail: sabbir1@umbc.edu

  This file contains the implementation of the Graph class of Project 3. It
constructs a graph from the data file inputted by the user's prompt and assigns
its vertices, edges, and adjacency matrices.
*/

#include <cstdlib>
#include <vector>
#include <fstream>
#include <iostream>
#include "Graph.h"
#include "Vertex.h"
#include "Edge.h"

using namespace std;

Graph::Graph()
{ /* nothing to do */ }

Graph::Graph(vector<Vertex *> vertices, vector<Edge *> edges) :
  m_vertices(vertices), m_edges(edges)
{
  for (int i = 0; i < vertices.size(); i++)
    if (vertices[i] == NULL) {
      cerr << "Error: Graph constructor expects non-null vertices." << endl;
      exit(1);
    }
  
  for (int i = 0; i < edges.size(); i++)
    if (edges[i]->GetV1() == NULL || edges[i]->GetV2() == NULL) {
      cerr << "Error: Graph constructor expects edges with non-null vertices." << endl;
      exit(1);
    }
}      

bool Graph::LoadFromFile(string fileName) {
  int numVertices;
  int v1, v2;
  vector<Vertex*> vertices;
  vector<Edge*> edges;
  ifstream dataFile;
      
  /* Set exception flags for file input stream */ 

  dataFile.exceptions(ios::failbit | ios::badbit);

  try {

    /* Assigns lines from the data file to variables */
    dataFile.open(fileName.c_str());
    dataFile >> numVertices;

    for ( int i = 0; i < numVertices; i++ )
      vertices.push_back( new Vertex() );

    dataFile >> v1 >> v2;
  
    while ( v1 > 0 && v2 > 0 ) {
      if (v1 <= numVertices && v2 <= numVertices )
	edges.push_back( new Edge(vertices[v1-1], vertices[v2-1]) );
      dataFile >> v1 >> v2;
    }

    dataFile.close();
  }
  catch (exception e) {
    return false;
  }

  /* If the data file is valid */
  m_vertices = vertices;
  m_edges = edges;

  return true;
}

/* Standard accessors: returns the vertices and edges of the graph and the
number of them as well */
int Graph::GetNumVertices() const {

  return m_vertices.size();

}  

int Graph::GetNumEdges() const {

  return m_edges.size();

}

vector<Vertex *> Graph::GetVertices() const {

  return m_vertices;

}

vector<Edge *> Graph::GetEdges() const {

  return m_edges;

}

Matrix Graph::GetAdjacencyMatrix() const {

  Matrix matrix(GetNumVertices(),GetNumVertices());

  /* Fills the matrix with 1 diagonally */
  for (int i = 0; i < GetNumVertices(); i++)
    matrix.Set(i,i,1.0);

  /* Stores the pointer to the first vertex */
  Vertex initializeStore = *m_vertices[0];

  /* Store the ID of the first vertex */
  int initializeID = initializeStore.GetID();

  /* Pointers to the rest of the vertices */
  Vertex *v1, *v2;

  /* Stores the ID of the rest of the vertices */
  int numV1, numV2;

  for (int i = 0; i < GetNumEdges(); i++) {
    /* Uses the pointers to get to the actual values of the vertices */
    v1 = m_edges[i]->GetV1();
    v2 = m_edges[i]->GetV2();

    /* Stores the ID of the vertices */
    numV1 = v1->GetID();
    numV2 = v2->GetID();

    /* Subtracts from the initial value to check the vertices are in bounds */
    numV1 -= initializeID;
    numV2 -= initializeID;

    /* Sets the matrix to 1 at those vertices */
    matrix.Set(numV1, numV2, 1.0);
    matrix.Set(numV2, numV1, 1.0);
  }

  return matrix;

}
