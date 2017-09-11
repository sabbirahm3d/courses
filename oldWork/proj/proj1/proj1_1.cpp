/*
File: proj1.cpp
Project: CMSC 202 Project 1, Spring 2015
Author: Sabbir Ahmed
Date: 02/25/15
Discussion section: 15
e-mail: sabbir1@umbc.edu

  This file contains the main driver program for Project 1. The program takes
in the size and vertices inputted by the user, verifies if they are possible
and creates a two-dimensional array using 0 as empty spaces and 1 as vertices
and edges.                                            */

#include <iostream>
//#include "proj1.h"

using namespace std;

/*
main()
Takes in the size of the graph inputted by the user and calls the functions
to initialize it, to put the vertice inputs in, and also to check if the
graph is connected or not.                            */

int main() {

  int size; 
  //  int u = 1;
  // int v = 1; // u and v are initialized at 1 to keep the while loop true
  int graph[MAX_VERTICES][MAX_VERTICES]; //the dimensions of the array are
                                         //restricted by MAX_VERTICES

  cout << "How many vertices?" << endl;
  cin >> size;

  // If the user inputs an invalid size, prompt them again
  while (CheckInput(size) != true) {
    cout << "Please enter a number under 20." << endl;
    cin >> size;
  }

  // If the user inputs a valid size, call the rest of the program.
  if (CheckInput(size) == true) {
    InitializeGraph(graph, size);
    VertexInput(graph, size);
    IsConnected(graph, size);
  }

}

/* VertexInput()
Takes in the user inputs of the vertices and assigns them to the graph, and
also determines if the graph is connected.          */

void VertexInput(int graph[][MAX_VERTICES], int size) {

  int u, v;
  do {
  cout << "Enter a vertex pair (0 0 to end): ";
  cin >> u >> v;

  if (CheckInput(u, v, size) == true)
  }  // Assign 1 to all the vertices and edges inputted by user
  while (CheckInput(u, v, size) == true) {
    cout << "Enter a vertex pair (0 0 to end): ";
    cin >> u >> v;
    graph[u-1][v-1] = 1; // assigns 1 to edge between u to v
    graph[v-1][u-1] = 1; // assigns 1 to edge between v to u
    graph[u-1][u-1] = 1; // assigns 1 to vertex u
    graph[v-1][v-1] = 1; // assigns 1 to vertez v
  }

  // Assign 0 to graph when an invalid integer is inputted to undo the
  // assignment at first
  if (CheckInput(u, v, size) != true) {
    graph[u-1][v-1] = 0;
    graph[v-1][u-1] = 0;
    graph[u-1][u-1] = 0;
    graph[v-1][v-1] = 0;
  }

  // Calls the functions to determine if the graph is connected
  if ((IsConnected(graph, size) == true)) {

    //      && (IsEdge(graph, u, v, size) == false))
    cout << "Graph is connected." << endl;
  }
  else {
    cout << "Graph is not connected." << endl;
  }

}

/*
CheckInput()
Verifies the size the user inputs is under the constant value.
*/
bool CheckInput(int size) {
  
  if ((size <= MAX_VERTICES) && (size > 0))
    return true;
  else
    return false;

}

/*
CheckInput()
Verifies the vertice inputs are within the range of the size the user inputs.
*/
bool CheckInput(int u, int v, int size) {

  if ((u <= size) && (v <= size) && (u > 0) && (v > 0))
    return true;
  else if ((u == 0) && (v == 0))
    return false;
  //  else
  // cout << "Please enter correct vertices." << endl;

}

/*
InitializeGraph()
Creates a two dimensional array using the dimensions of the size inputted
and initializes it with 0 as values.     */
void InitializeGraph(int graph[][MAX_VERTICES], int size) {

for(int i = 0; i < size; i++)
  for(int j = 0; j < size; j++)
    graph[i][j] = 0;

}

/*
RemoveEdge()
Checks if an edge exists between 2 vertices and removes it. If it was not
possible, then the edge never existed and therefore false.
*/
bool RemoveEdge(int graph[][MAX_VERTICES], int size, int u, int v){

  if ((graph[u-1][v-1] == 1) || (graph[v-1][u-1] == 1)) {
    graph[u-1][v-1] = 0;
    graph[v-1][u-1] = 0;
    return true;
  }
  else
    return false;

}

/*
CreateEdge()
Checks if an edge can be created between 2 vertices and creates it. If it was
not possible, then the edge could not be removed and it would return false.
*/
bool CreateEdge(int graph[][MAX_VERTICES], int size, int u, int v){

  if ((u > size) || (v > size))
    return false;
  else if ((graph[u-1][v-1] == 0) || (graph[v-1][u-1]) == 0) {
    graph[u-1][v-1] = 1;
    graph[v-1][u-1] = 1;
    return true;
  }
  else
    return false;

}

/*
IsEdge()
Takes in values of RemoveEdge() and CreateEdge() and if they are both true,
it returns true.
*/
bool IsEdge(int graph[][MAX_VERTICES], int size, int u, int v) {

  if ((RemoveEdge(graph, size, u, v) == true) 
      && (CreateEdge(graph, size, u, v) == true))
    return true;
  else
    return false; 

}

/* IsConnected()
Checks if the edges iniside the graph connect to make a connected graph.  */
bool IsConnected(int graph[][MAX_VERTICES], int size) {
  
  /*  // Loops through the graph and checks the edges if they form a patter
  for(int i = 0; i < size; i++)
    for(int j = 0; j < size; j++){
      if((graph[i][j] == graph[j][i]) &&
	 (graph[i][j] == graph[i][j - 1])) {
        return true;
      }

      else
	return false;
	}*/
  int y[MAX_VERTICES];
  int x[MAX_VERTICES];
  x[0] = 1;
  //  y[0] = 0;

  for (int i = 1; i < size; i++) {
    x[i] = 0;
    // y[i] = 0;
  }

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      y[i] += x[j]*graph[i][j];
    }
    cout << y[i] << endl;
  }


  return true;

    // Loop over columns in matrix
    /*    for (int j = 0; j < size; ++j) {
      y[i] += graph[i][j]*x[j];
    }
  }
  
  for (int i = 0; i < size; i++) {
    if (y[i] == 0) {
      return false;
    }
    for (int i = 0; i < size; i++)
      cout << y[i] << endl;
  }
  return true;

    */
}
