/*                                                                         
File: WalkGraph.h
Project: CMSC 202 Project 4, Spring 2015                                   
Author: Sabbir Ahmed                                                       
Date: 05/04/15                                                             
Discussion section: 15                                                     
e-mail: sabbir1@umbc.edu                                                   

The header file for the WalkGraph class.                            */

#ifndef WALKGRAPH_H
#define WALKGRAPH_H

#include <vector>
#include "WalkVertex.h"
#include "WalkEdge.h"

using namespace std;

const int MAXDESCRIPTIONLEN = 80;

class WalkGraph {

 public:

  /* WalkGraph() - default constructor
     Preconditions: none
     Postconditions: creates WalkGraph object with empty vertex
     and edge vectors.                                             */

  WalkGraph();

  /* WalkGraph() - non-default constructor
     Preconditions: vertices are non-NULL; vertices in edges 
     are non-NULL.
     Postconitions: creates WalkGraph object with given vertices
     and edges; if there any NULL WalkVertex pointers in the
     vertices or edges, prints an error and exit.                  */

  WalkGraph(vector<WalkVertex*> vertices, vector<WalkEdge*> edges);

  /* LoadFromFile() - load graph data from a file
     Preconditions: fileName is the name of a file that 
     contains valid graph data.
     Postconditions: loads graph data into WalkGraph object and
     returns true; if any errors occur, returns false.            */

  bool LoadFromFile(string fileName);

  /* GetNumVertices() - get the number of vertices 
     Preconditions: none
     Postconditions: returns the number of vertices in the graph. */
  
  int GetNumVertices() const;

  /* GetNumEdges() - get the number of eges
     Preconditions: none
     Postconditions: returns the number of eges in the graph.     */

  int GetNumEdges() const;

  /* GetVertices() - get a vector of vertices
     Preconditions: none
     Postconditions: returns a vector of pointers to vertices.    */

  vector<WalkVertex *> GetVertices() const;

  /* GetEdges() - get a vector of edges
     Preconditions: none
     Postconditions: returns a vector of pointers to edges.       */

  vector<WalkEdge *> GetEdges() const;

  /* Walk() - simulate a random walk on the graph.
     Preconditions: 
     - start is a ptr to a valid WalkVertex on the graph
     - maxSteps is > 0
     - seed is an unsigned integer value
     Postconditions: 
     - returns a walk as a vector of pointers to WalkVertex objects
     - the objects are in walk-order in the vector, i.e. the walk 
       is walk[0] --> walk[1] --> walk[2], etc.
     - the last item in the vector will be a SafeHouse or 
       PoliceStation object, unless one has not been reached
       in maxSteps steps.  The walk will never be more than
       maxSteps+1 long (the start doesn't count as a step).
     - if maxSteps <= 0, an empty vector is returned
     - the seed value is used with srand() to initialize the 
       random number generator                                    */
     
  vector<WalkVertex*> Walk(WalkVertex *start, int maxSteps, unsigned int seed) const;

  /* Neighbors() - return a vector of "neighbors" of a given vertex 
     Preconditions:
     - v is a ptr to a valid WalkVertex on the graph
     Postconditions:
     - returns a vector of ptrs to WalkVertex objects, all of which
       are connectd to v by an edge.  v is not itself included in the
       vector (v is not it's own neighbor).                            */

  vector<WalkVertex*> Neighbors(WalkVertex* v) const;  

 private:

  /* Locate() - find a WalkVertex in a vector
     Preconditions: v is a ptr to a WalkVertex object and vertices
     is a vector of ptrs to WalkVertex objects.
     Postconditions: returns the index of v in vertices, or -1 if
     v is not found in the vector.                                    */

  static int Locate(vector<WalkVertex*> vertices, WalkVertex* v);

  /* Locate() - find a WalkVertex in a vector
     Preconditions: id is an integer and vertices is a vector of ptrs 
     to WalkVertex objects.
     Postconditions: returns the index of the vertex with given id in
     the vector, or -1 if no WalkVector with the given id is found.    */

  static int Locate(vector<WalkVertex*> vertices, int id);
  
  /* RandomInt() - generate a pseudo-random integer
     Preconditions: upper > 0 and upper <= a variable upper bound 
     MAXLIMIT.
     Postconditions: returns an integer in the range 0..(upper-1).
     If upper <= 0, returns zero; if upper > MAXLIMIT, returns
     an integer in the range 0..(MAXLIMIT-1).                         */
  
  static int RandomInt(int upper);

  /* Class variables */

  vector<WalkVertex *> m_vertices; // Vertices stored as vector of WalkVertex pointers
  vector<WalkEdge *> m_edges;      // Edges stored as vector of WalkEdge pointers
  

};

#endif
