/* File:    Driver.cpp
 * Project: CMSC 341: Project 4, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * Implementation of a custom exception class
 */

#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <string>

class MyException {

public:

    /* ******************** Constructors ******************** */

    /* MyException()
     * Preconditions: The error message passed in must be valid string
     * Postconditions: Creates an instance with the error message */

    MyException(std::string message) : m_message(message) { }


    /* ******************** Public methods ******************** */

    /* getMessage()
     * Preconditions: None
     * Postconditions: Returns the error message */

    const std::string getMessage() { return m_message; }

private:

    /* ******************** Private attributes ******************** */

    std::string m_message; // error message

};


#endif