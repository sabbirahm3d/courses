/*
File: proj4.cpp
Project: CMSC 202 Project 4, Spring 2015
Author: Sabbir Ahmed
Date: 05/04/15
Discussion section: 15
e-mail: sabbir1@umbc.edu

This file contains the main driver program for Project 4. It loads data files 
containing maps of intersections, safehouses, and police stations 
represented by the edges and vertices of combinatorial graphs, and simulates 
a random walk of a robber's escape from inputs by the user to decide the 
probability of success for the robber's escape. It implements the WalkGraph 
class and links to it components, the WalkVertex and WalkEdge classes, and the 
derived classes, Intersection, SafeHouse, and PoliceStation.          */

#include <iostream>
#include <string>

#include "WalkGraph.h"

using namespace std;

/* PrintMenu()
   Contains the menu to display to the user
   Pre-conditions: none
   Post-conditions: outputs the lines of the menu           */

void PrintMenu();

int main() {

  bool menuFlag = true; // flag to keep the while loop running when necessary
  bool fileLoaded = false; //determines if a file is loaded
  char userInput;
  string fileName;
  WalkGraph graph;

  while (menuFlag == true) {

    if (fileLoaded == true)
      cout << "The data file (" << fileName << ") is currectly loaded." 
	   << endl;
    else
      cout << "There is no file loaded." << endl;

    PrintMenu();
    cin >> userInput;

    /* Uses switch case to handle the user prompts */
    switch (userInput) {

    /* Loads data file into program */
    case 'l':

      cout << "Enter the file name: ";
      cin >> fileName;

      if (graph.LoadFromFile(fileName) == true) {
	cout << "The data file " << fileName << " is currently loaded."
	     << endl;
	fileLoaded = true;
      }

      else
	cout << "Error loading data file (" << fileName << ")" << endl;

      break;

    /* Displays the vertices of the graph */
    case 'v': {

      if (fileLoaded == true) {

	/* Prints the vertices of the graph that were saved as pointers */      
	cout << "Vertices:" << endl;
	for (int i = 0; i < graph.GetNumVertices(); i++)

	  /* virtual function ToString() had to be used since WalkVertex cannot
	     have a distinct operator<< overloader */
	  cout << graph.GetVertices()[i]->ToString() << endl;
      }

      else
	cout << "There is no data file loaded." << endl;

      break;
    }

    /* Displays the edges of the graph */
    case 'e': {

      if (fileLoaded == true) {

	/* Prints out the edges of the graph saved as pointers */
	cout << "\nEdges:" << endl;
	for (int i = 0; i < graph.GetNumEdges(); i++)

	  /* Uses the operator<< overloader function here */
	  cout << *graph.GetEdges()[i] << endl;
      }

      else
        cout << "There is no data file loaded." << endl;

      break;
    }

    /* Generates a random walk through the graph */
    case 'w': {

      unsigned int seed;
      int maxSteps;
      int start;

      if (fileLoaded == true) {

	/* Prompts the user for the arguments required for the random walk */
	cout << "Simulate a random walk from a given vertex." << endl
	     << "Enter vertex ID: ";
	cin >> start;

	cout << "Enter the maximum number of steps in the simulation: ";
	cin >> maxSteps;

	cout << "Enter an integer seed for the random number generator: ";
	cin >> seed;

	/* First parameter of WalkGraph::Walk() requires a WalkVertex* */
	vector<WalkVertex*> randWalk 
	  = graph.Walk(graph.GetVertices()[start], maxSteps, seed);

	cout << "\nRandom walk:" << endl;
	for (int i = 0; i < randWalk.size(); i++)
	    cout << randWalk[i]->ToString() << endl;

	/* Prints messages if the robber escapes or gets caught */
	if (randWalk.back()->Status() == SUCCESS) //.back() is the last element
	  cout << "YOU ESCAPED THE LAW!" << endl << endl;

	else if (randWalk.back()->Status() == FAILURE)
	  cout << "BUSTED! Why'd you walk into a police station anyways?"
	       << endl << endl;
      }

      else
        cout << "There is no data file loaded." << endl;

      break;
    }

    /* Quits the program */
    case 'q': {

      cout << "Goodbye!" << endl;
      menuFlag = false;
      break;
    }

    default: {
      cout << "Please enter an option from the menu." << endl;;
    }

    }
  }

}

void PrintMenu() {

  cout << endl << "****************************************************" << endl
       << "Choose an action from the following menu:\n" << endl
       << "l - load a graph data file" << endl
       << "v - list the vertices of the loaded graph" << endl
       << "e - list the edges of the loaded graph" << endl
       << "w - simulate a random walk from a given vertex" << endl
       << "q - quit" << endl
       << "\nSelection: ";

}
