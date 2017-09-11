/*
File: proj2.cpp
Project: CMSC 202 Project 2, Spring 2015
Author: Sabbir Ahmed
Date: 03/30/15
Discussion section: 15
e-mail: sabbir1@umbc.edu

  This file contains the main driver program for Project 2. The program
handles input from the user to implement the 2 classes used for deciphering 
Caeser and Vignere ciphers.
*/

#include <iostream>
#include <string>
#include "CipherMessage.h"

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
Calls PrintMenu() and HandleInput() to begin the program with the first 
input
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

  /* 2 bool variables: 
  menuFlag acts as the flag to keep the while loop running when necessary;
  fileLoaded determines if a message is loaded to be deciphered, read the
  text, etc. */
  bool menuFlag = true, fileLoaded = false;
  CipherMessage message;
  Date sentDate;
  string fileName, key;

  while (menuFlag == true) {
    switch (userInput) {

    case 'l': {
      cout << "Enter the file name: ";
      cin >> fileName;
      message.LoadFromFile(fileName);
      if (message.LoadFromFile(fileName) == true) {
	cout << "The cipher file " << fileName << " is currently loaded."
	     << endl;
        PrintMenu();
        cin >> userInput;
	fileLoaded = true;
      }
      else {
	cout << "Error loading cipher file (" << fileName << ")" << endl;
	PrintMenu();
        cin >> userInput;
      }
      break;
    }

    case 'h': {
      if (fileLoaded== true) {
        cout << "From: "  << message.GetFrom() << endl;
        cout << "To: "  << message.GetTo() << endl;
	sentDate = message.GetSentDate();
	cout <<	"Date: ";
        sentDate.PrintDate();
        cout <<"\nThe cipher file " << fileName << " is currently loaded."
             << endl;
        PrintMenu();
        cin >> userInput;
      }
      else {
	cout << "There is no cipher file loaded." << endl;
	PrintMenu();
	cin >> userInput;
      }
      break;
    }

    case 't': {
      if (fileLoaded == true) {
         cout << message.GetText() << endl;
	 cout <<"The cipher file " << fileName << " is currently loaded."
	      << endl;
         PrintMenu();
         cin >> userInput;
      }
      else {
        cout << "There is no cipher file loaded." << endl;
        PrintMenu();
        cin >> userInput;
      }
      break;
    }

    case 'd': {
      if (fileLoaded == true) {
        cout << "Enter the key: ";
        cin >> key;
        cout << message.Decipher(key) << endl;
        cout <<"The cipher file " << fileName << " is currently loaded."
             << endl;
        PrintMenu();
        cin >> userInput;
      }
      else {
        cout << "There is no cipher file loaded." << endl;
        PrintMenu();
        cin >> userInput;
      }
      break;
    }
    
    case 'u': {
      if (fileLoaded == true) {
        cout << message.Decipher() << endl;
        cout <<"The cipher file " << fileName << " is currently loaded."
             << endl;
        PrintMenu();
        cin >> userInput;
      }
      else {
        cout << "There is no cipher file loaded." << endl;
        PrintMenu();
        cin >> userInput;
      }
      break;
    }

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

  cout << "\nChoose an action from the following menu:\n" << endl;
  cout << "l - load a cipher file" << endl;
  cout << "h - display cipher file header" << endl;
  cout << "t - display cipher file text" << endl;
  cout << "d - decipher file with known key" << endl;
  cout << "u - decipher file (key unknown)" << endl;
  cout << "q - quit" << endl;
  cout << "\nSelection: ";

}
