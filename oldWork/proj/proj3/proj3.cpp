/*
File: proj3.cpp
Project: CMSC 202 Project 3, Spring 2015
Author: Sabbir Ahmed
Date: 03/09/15
Discussion section: 15
e-mail: sabbir1@umbc.edu

  This file contains the main driver program for Project 3. The program handles
input from the user to load a data file, use the file to create a graph object,
display its edges and vertices, and the connected component of the graph by 
implementing the 4 classes in the project.
*/

#include <iostream>
#include <string>
#include "Matrix.h"
#include "Graph.h"
#include "Edge.h"
#include "Vertex.h"

using namespace std;

/* Prototypes for the extra functions. */

/*
PrintMenu()
Contains the menu to display to the user
Pre-conditions: none
Post-conditions: outputs the lines of the menu
*/
void PrintMenu();

/*
HandleInput()
Handles input by user and calls corresponding functions.
Pre-condtions: input is a valid char of length 1
Post-conditions: calls functions based on inputs by user
*/
void HandleInput(char userInput);

/*
main()
Calls PrintMenu() and HandleInput() to begin the program with the first input
Pre-conditions: none
Post-conditions: rest of the program is called
*/
int main() {

  char userInput;

  PrintMenu();
  cin >> userInput;
  HandleInput(userInput);

}

void HandleInput(char userInput) {

  /* menuFlag acts as the flag to keep the while loop running when necessary;
  fileLoaded determines if a file is loaded. */
  bool menuFlag = true, fileLoaded = false;
  Graph graph;
  string fileName;

  while (menuFlag == true) {
    /* Uses switch case to handle the user prompts */
    switch (userInput) {

    /* Loads data file into program */
    case 'l': {

      cout << "Enter the file name: ";
      cin >> fileName;
      graph.LoadFromFile(fileName);

      if (graph.LoadFromFile(fileName) == true) {
	cout << "The data file " << fileName << " is currently loaded."
	     << endl;
        PrintMenu();
        cin >> userInput;
	fileLoaded = true;
      }

      else {
	cout << "Error loading data file (" << fileName << ")" << endl;
	PrintMenu();
        cin >> userInput;
      }

      break;
    }

    /* Displays the vertices of the graph */
    case 'v': {

      if (fileLoaded == true) {

	/* Prints the vertices of the graph that were saved as pointers */
	for (int i = 0; i < graph.GetNumVertices(); i++)
	  cout << *graph.GetVertices()[i] << endl;

	cout << "The data file " << fileName << " is currently loaded."
	      << endl;
         PrintMenu();
         cin >> userInput;
      }

      else {
        cout << "There is no data file loaded." << endl;
        PrintMenu();
        cin >> userInput;
      }

      break;
    }

    /* Displays the edges of the graph */
    case 'e': {

      if (fileLoaded == true) {

	/* Prints out the edges of the graph saved as pointers */
	for (int i =0; i < graph.GetNumEdges(); i++)
	  cout << *graph.GetEdges()[i] << endl;

        cout << "The data file " << fileName << " is currently loaded."
             << endl;
        PrintMenu();
        cin >> userInput;
      }

      else {
        cout << "There is no data file loaded." << endl;
        PrintMenu();
        cin >> userInput;
      }

      break;
    }

    case 'c': {
      if (fileLoaded == true) {
        cout << "The data file " << fileName << " is currently loaded."
             << endl;
        PrintMenu();
        cin >> userInput;
      }
      else {
        cout << "There is no data file loaded." << endl;
        PrintMenu();
        cin >> userInput;
      }

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
      PrintMenu();
      cin >> userInput;
    }

    }
  }

}

void PrintMenu() {

  cout << "Choose an action from the following menu:\n" << endl;
  cout << "l - load a graph data file" << endl;
  cout << "v - list the vertices of the loaded graph" << endl;
  cout << "e - list the edges of the loaded graph" << endl;
  cout << "c - list the connected component of a specific vertex" << endl;
  cout << "q - quit" << endl;
  cout << "\nSelection: ";

}
