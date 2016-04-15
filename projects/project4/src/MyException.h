/* File:    Driver.cpp
 * Project: CMSC 341: Project 4, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * Implementation of custom exception class
 */

#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <string>

class MyException {

public:

/**********************************************************************
 * Exceptions341 (Constructor)
 * PreCondition: String containing error description.
 *
 * PostCondition:  Error object
 *********************************************************************/

    MyException(std::string message) : m_message(message) { }

/**********************************************************************
 * Name: GetMessage
 * PreCondition: None.
 *
 * PostCondition:  Returns error message.
 *********************************************************************/

    const std::string GetMessage() { return m_message; }

private:

    std::string m_message; //Error message

};


#endif