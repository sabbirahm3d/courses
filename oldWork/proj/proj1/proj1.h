/*
File: proj1.h (redo)
Project: CMSC 202 Project 1, Spring 2015
Author: Sabbir Ahmed
Date: 05/15/15
Discussion section: 15
e-mail: sabbir1@umbc.edu

  The header file for Project 1, this file contains all the function prototypes
and constant variables required for the implementation file.             */

#ifndef PROJ1_H
#define PROJ1_H

const int MAX_VERTICES = 20; // maximum number of vertices in the graph

/* CheckInput()
An overloaded function to verify the size of the vertices inputted by user.
PreConditions: 'size' inputted is an integer.
PostConditions: Verifies the size inputted.                              */
bool CheckInput(int size);

/* CheckInput()
An overloaded function to verify the vertices inputted by the user.
Preconditions: Inputs size, u, and v are all integers.
PostConditions: 'u' and 'v' are valid vertices within the range of its size
declared.                                                                */
bool CheckInput(int u, int v, int size);

/* InitializeGraph()
Used to initialize graph[][] to with the size from the user.
PreConditions: graph[][] is the MAX_VERTICES by MAX_VERTICES array used to
store the graph. 'size' is the valid size inputted by the user.
PostConditions: graph[][] is created with the dimensions provided from 'size'
and each element are only comprised as zeros.                            */
void InitializeGraph(int graph[][MAX_VERTICES], int size);

/* VerticeInput()
Takes in user input of the vertices and sets them in the graph as 1.
PreConditions: graph[][] is the MAX_VERTICES by MAX_VERTICES array used to
store the graph initialized by InitializeGraph()
PostConditions: The vertices and edges are set on graph[][].             */
void VertexInput(int graph[][MAX_VERTICES], int size);

/* RemoveEdge()
Removes the edges from the graph created and returns if possible or not.
PreConditions: graph[][] has valid dimensions, and the vertices u and v are
valid inputs.
PostConditions: Returns true if edge was able to be removed to signify
existence of one to start with.                                          */
bool RemoveEdge(int graph[][MAX_VERTICES], int size, int u, int v);

/* CreateEdge()
Creates the edges from the graph after being removes and returns if possible
or not.
PreConditions: graph[][] has valid dimensions, and the vertices u and v are
valid inputs.
PostConditions: Returns true if edge was able to be recreateded to signify
existence of one to start with.                                           */
bool CreateEdge(int graph[][MAX_VERTICES], int size, int u, int v);

/* IsEdge()
Checks if the space between vertices is connected by an edge.
PreConditions:
graph[][] has valid dimensions, and the vertices u and v are valid inputs.
PostConditions: Returns true if an edge was able to be removed and recreated
to verify the edge.                                                      */
bool IsEdge(int graph[][MAX_VERTICES], int size, int u, int v);

/* IsConnected()
Checks if the graph is connected.
PreConditions: graph[][] has valid dimensions, and the vertices u and v are
valid inputs.
PostConditions: Returns true if graph is connected.                      */
bool IsConnected(int graph[][MAX_VERTICES], int size);

/* MatVec()
Uses recursion to multiply the graph matrix to determine connectedness.
Pre-Conditions: graph[][] has valid dimensions, and size is a valid integer.
PostConditions: returns the result of the matrix multiplication.         */
void MatVec(int graph[][MAX_VERTICES], int initVert[], int resultVert[], int size, int vertices);

#endif
