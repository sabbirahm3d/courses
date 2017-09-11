/*
File: Graph.h
Project: CMSC 202 Project 3, Spring 2015
Author: Sabbir Ahmed
Date: 03/09/15
Discussion section: 15
e-mail: sabbir1@umbc.edu

  This header file contains the declaration of the Graph class of Project 3.
*/

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "Vertex.h"
#include "Edge.h"
#include "Matrix.h"

using namespace std;

class Graph {

 public:

  /* Graph() - default constructor
     Preconditions: none
     Postconditions: creates Graph object with empty vertex
     and edge vectors.                                             */

  Graph();

  /* Graph() - non-default constructor
     Preconditions: vertices are non-NULL; vertices in edges 
     are non-NULL.
     Postconitions: creates Graph object with given vertices
     and edges; if there any NULL Vertex pointers in the
     vertices or edges, prints an error and exit.                  */

  Graph(vector<Vertex*> vertices, vector<Edge*> edges);

  /* LoadFromFile() - load graph data from a file
     Preconditions: fileName is the name of a file that 
     contains valid graph data.
     Postconditions: loads graph data into Graph object and
     returns true; if any errors occur, returns false.            */

  bool LoadFromFile(string fileName);

  /* GetNumVertices() - get the number of vertices 
     Preconditions: none
     Postconditions: returns the number of vertices in the graph. */

  int GetNumVertices() const;

  /* GetNumEges() - get the number of eges
     Preconditions: none
     Postconditions: returns the number of eges in the graph.     */

  int GetNumEdges() const;

  /* GetVertices() - get a vector of vertices
     Preconditions: none
     Postconditions: returns a vector of pointers to vertices.    */

  vector<Vertex *> GetVertices() const;

  /* GetEdges() - get a vector of edges
     Preconditions: none
     Postconditions: returns a vector of pointers to edges.       */

  vector<Edge *> GetEdges() const;

  /* GetAdjacencyMatrix() - build the adjacency matrix 
     Preconditions: none
     Postconditions: returns an adjacency matrix for the graph.   */

  Matrix GetAdjacencyMatrix() const;

  /* GetConnectedComponent() - returns a vector of pointers to
     vertices that are connected to a given vertex.
     Preconditions: v is non-NULL.
     Postconditions: returns a vector of pointers to vertices that
     are in the connected component of v; if v is NULL, prints a
     warning message and returns an empty vector.                 */

  vector<Vertex *> GetConnectedComponent(Vertex *v) const;
  
 private:
  vector<Vertex *> m_vertices;   // Vertices stored as vector of Vertex pointers
  vector<Edge *> m_edges;        // Edges stored as vector of Edge pointers

};

#endif
