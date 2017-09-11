/*
File: proj1.cpp (redo)
Project: CMSC 202 Project 1, Spring 2015
Author: Sabbir Ahmed
Date: 05/15/15
Discussion section: 15
e-mail: sabbir1@umbc.edu

This file contains the main driver program for Project 1. The program takes in 
the size and vertices inputted by the user, verifies if they are possible and 
creates a two-dimensional array using 0 as empty spaces and 1 as vertices and 
edges.                                                               */

#include <iostream>
#include "proj1.h"

using namespace std;

int main() {

  int size;
  int graph[MAX_VERTICES][MAX_VERTICES];

  cout << "Enter the number of vertices: ";
  cin >> size;

  while (CheckInput(size) != true) {
    cout << "Please enter a valid number of vertices." << endl;
    cout << "Enter the number of vertices: ";
    cin >> size;
  }

  /* Fills in graph[][] with 0 */
  InitializeGraph(graph, size);

  int u, v;

  do {

    cout << "Enter a vertex pair (0 0 to end): ";
    cin >> u >> v;

    /* Assigns 1 to the vertices and the edges between them */
    if (CheckInput(u, v, size) == true) {
      graph[u-1][v-1] = 1; // edge between u to v
      graph[v-1][u-1] = 1; // edge between v to u
      graph[u-1][u-1] = 1; // vertex u
      graph[v-1][v-1] = 1; // vertex v
    }

    else if ((u == 0) && (v==0));

    else
      cerr << "Please enter valid vertex inputs." << endl;

  } while ((u != 0) || (v != 0));

  if (IsConnected(graph, size) == true)
    cout << "Graph is connected." << endl;
  
  else
    cout << "Graph is not connected." << endl;

}

bool CheckInput(int size) {

  /* Size is at least 3 vertices to be valid */
  if ((size <= MAX_VERTICES) && (3 <= size))
    return true;

  else
    return false;

}

bool CheckInput(int u, int v, int size) {

  /* Vertices have to be positive and less than size */
  if ((u <= size) && (v <= size) && (u > 0) && (v > 0))
    return true;

  else
    return false;

}

void InitializeGraph(int graph[][MAX_VERTICES], int size) {

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      graph[i][j] = 0;

}

bool IsEdge(int graph[][MAX_VERTICES], int size, int u, int v) {

  /* If edges contain 1, they exist after being initialized by user */
  if ((graph[u-1][v-1] == 1) && (graph[v-1][u-1] == 1)) 
    return true;

  else
    return false;

}

bool CreateEdge(int graph[][MAX_VERTICES], int size, int u, int v) {

  if ((u > size) || (v > size))
    return false;

  /* If edges do not exist, create them */
  else if ((graph[u-1][v-1] == 0) || (graph[v-1][u-1]) == 0) {
    graph[u-1][v-1] = 1;
    graph[v-1][u-1] = 1;
    return true;
  }

  else
    return false;

}

bool RemoveEdge(int graph[][MAX_VERTICES], int size, int u, int v) {

  /* If edges exist, remove them */
  if (IsEdge(graph, size, u, v) == true) {
    graph[u-1][v-1] = 0;
    graph[v-1][u-1] = 0;
    return true;
  }

  return false;
}

bool IsConnected(int graph[][MAX_VERTICES], int size) {

  int initVert[size]; // initialized to [1,0,0,...0]
  int resultVert[size]; // initialized empty as [0,0,0,...0]

  for (int i = 0; i < size; i++) {
    initVert[i] = 0;
    resultVert[i] = 0;
  }

  initVert[0] = 1;

  /* Pass in all arrays for matrix multiplication */
  MatVec(graph, resultVert, initVert, size, size);

  /* The resultant matrix does not include any 0 if the graph is connected. 
  Iterating until the number of vertices, multiplying matrices will result in
  all of the vertices overlapping each other. If a 0 exists, that vertex was
  never connected to anything else.                        */
  for(int i = 0; i < size; i++)
    if (resultVert[i] == 0)
      return false;

  return true;

}

void MatVec(int graph[][MAX_VERTICES], int resultVert[], int initVert[], int size, int vertices) {

  if (vertices == 0);
  /* Do nothing */

  else {

    /* Matrix multiplication */
    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++)
	resultVert[i] = resultVert[i] + (initVert[j]*graph[i][j]);

    /* Keep swapping arrays to multiply with matrix */
    MatVec(graph, initVert, resultVert, size, vertices - 1);
  }

}
