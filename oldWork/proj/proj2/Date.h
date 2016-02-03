/*
File: Date.h
Project: CMSC 202 Project 2, Spring 2015
Author: Sabbir Ahmed
Date: 03/30/15
Discussion section: 15
e-mail: sabbir1@umbc.edu

  This header file contains the declaration of the Date class of Project 2.
*/

#ifndef DATE_H
#define DATE_H

const int MAX_YEAR = 2115;
const int MIN_YEAR = 1970;

class Date {

 public:

  /* Date() - default constructor
     Preconditions - none
     Postconditions - date set to 1/1/MIN_YEAR */

  Date();
  
  /* Date() - non-default constructor
     Preconditions - none
     Postconditions - date set to user-supplied values, 
       if they are valid; if invalid, set to default
       values and print error (see standard mutators).
       Attempts to set month first, then year, then day. */

  Date(int month, int day, int year);

  /* GetMonth(), GetDay(), GetYear() - standard accessors
     Preconditons - none
     Postconditions - returns requested class variable   */

  int GetMonth() const;
  int GetDay() const;
  int GetYear() const;

  /* SetMonth(), SetDay(), SetYear() - standard mutators 
     Preconditions - valid data in argument
     Postconditions - class variable set to user-supplied
       value if data is valid; if invalid, set to 
       default value and print error                   
     Data Validity
       year  - MIN_YEAR to MAX_YEAR  (default: MIN_YEAR)
       month - 1 to 12  (default: 1)
       day   - 1 to 31, depending on month and leap years 
                 (default: 1)                            */

  void SetMonth(int month);
  void SetDay(int day);
  void SetYear(int year);

  /* PrintDate() - print the date in mm/dd/yyyy format
     Preconditions - none
     Postconditions - date is printed to stdout         */

  void PrintDate() const;
  
 private:
  int m_month;   // month
  int m_day;     // day
  int m_year;    // year
};

#endif
