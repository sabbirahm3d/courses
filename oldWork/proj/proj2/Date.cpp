/*
File: Date.cpp
Project: CMSC 202 Project 2, Spring 2015
Author: Sabbir Ahmed
Date: 03/30/15
Discussion section: 15
e-mail: sabbir1@umbc.edu

  This file contains the the implementation file for the Date Class in
Project 2. The program checks the input date from the file read by 
CipherMessage.cpp and verifies its validity in terms of the number of days
in a certain month and leap years.
*/

#include <iostream>
#include "Date.h"

using namespace std;

Date::Date() {

  m_month = 1;
  m_day = 1;
  m_year = 1970;

}

Date::Date(int month, int day, int year) {

  SetMonth(month);
  SetDay(day);
  SetYear(year);

}

/* Standard accessors: returns month, day and year respectively */
int Date::GetMonth() const {

  return m_month;

}

int Date::GetDay() const {

  return m_day;

}

int Date::GetYear() const {

  return m_year;

}

/* Standard mutators: sets input variables to member variables */
void Date::SetMonth(int month) {

  /* Assign input month to m_month only if it's valid */
  if ((month >= 1) && (12 >= month))
    m_month = month;
  else
    m_month = 1;

}

void Date::SetDay(int day) {

  /* Checks if the year inputted is a leap year.
  For a year to be a leap year, it must be evenly divisible by 4 and 400. 
  However, 2100 is the only year within the range of this project to fall
  under that special circumstance. */
  if ((m_year % 4 == 0) && (m_year != 2100) 
     && (m_month == 2) && (day <= 29))
      m_day = day;
  else {
    switch (m_month) {

    /* Checks if days in January, March, May, July, August, October and 
    December are <= 31 */
    case 1: case 3: case 5: case 7: case 8: case 10: case 12: {
      if (day <= 31)
        m_day = day;
      else
        m_day = 1;
      break;
    }

    /* Checks if days in April, June, September and November are <= 30 */
    case 4: case 6: case 9: case 11: {
      if (day <= 30)
        m_day = day;
      else
        m_day = 1;
     break;
    }

    /* Checks if days in February on a non-leap year are <= 28 */
    case 2: {
      if (day <= 28)
        m_day = day;
      else
        m_day = 1;
      break;
    }

    default:
      m_day = 1;
    }
  }

}

void Date::SetYear(int year) {

  /* Assigns input year to m_year only if it's within the range of the
  project */
  if ((year >= MIN_YEAR) && (MAX_YEAR >= year))
    m_year = year;
  else {
    m_year = MIN_YEAR;
  }

}

/* Prints out the date after being verified and assigned */
void Date::PrintDate() const {

  cout << m_month << "/" << m_day << "/" 
       << m_year;

}
