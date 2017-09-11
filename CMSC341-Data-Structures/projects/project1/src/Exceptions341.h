/**************************************************************
 * File:    MyExceptions.h
 * Project: CMSC 341 - Project 1
 * Author : Frank Zastawnik
 * Date   : 12-February-2016
 * Section: 
 * E-mail:  frankz2@umbc.edu
 *
 * MyExceptions Class definition.
 *
 *************************************************************/

#ifndef EXCEPTIONS341_H
#define EXCEPTIONS341_H

#include <string>

using namespace std;

class Exceptions341 {

public:

/**********************************************************************
 * Exceptions341 (Constructor)
 * PreCondition: String containing error description.  
 * 
 * PostCondition:  Error object
 *********************************************************************/

Exceptions341(string message): m_message(message) {}

/**********************************************************************
 * Name: GetMessage
 * PreCondition: None.  
 * 
 * PostCondition:  Returns error message.
 *********************************************************************/

const string GetMessage() { return m_message; }

private:

string m_message; //Error message

};


#endif