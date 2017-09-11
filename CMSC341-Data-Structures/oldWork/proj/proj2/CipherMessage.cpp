/*
 * Template CipherMessage.cpp
 *
 * Students may NOT modify the provided constructors or LoadFromFile()
 * function.  Functions may be added AFTER LoadFromFile().
 */

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cmath>
#include "CipherMessage.h"
#include "Date.h"

using namespace std;

CipherMessage::CipherMessage() 
  : m_text(""), m_from(""), m_to(""), m_sentDate(Date(1,1,1970))
{ /* Empty function body */ }

CipherMessage::CipherMessage(string from, string to, Date sentDate, string text) 
  : m_from(from), m_to(to), m_sentDate(sentDate)
{ 
  m_text = "";

  /* Only copy uppercase letters to m_text */

  for (int i = 0; i < text.length(); i++)
    if (text[i] >= 'A' && text[i] <= 'Z')
      m_text += text[i];
}

bool CipherMessage::LoadFromFile(string fileName) {
  ifstream dataFile;
  string from;
  string to;
  int month, day, year;
  char text_cstr[MAX_CIPHERLEN];
  string text;

  /* Set exception flags for file input stream */ 

  dataFile.exceptions(ios::failbit | ios::badbit);

  try {

    dataFile.open(fileName.c_str());

    /* Read from, to, month, day, year */

    dataFile >> from;
    dataFile >> to;
    dataFile >> month >> day >> year;

    /* Read text.  First getline() clears previous newline */

    dataFile.getline(text_cstr, MAX_CIPHERLEN);
    dataFile.getline(text_cstr, MAX_CIPHERLEN);

    /* Only copy uppercase letters to string */
    
    for (int i = 0; i < strlen(text_cstr); i++)
      if (text_cstr[i] >= 'A' && text_cstr[i] <= 'Z')
	text += text_cstr[i];

    dataFile.close();
  } 
  catch (exception e) {
    return false;
  }

  /* Made it through file read; assign to class variables. */

  m_from = from;
  m_to = to;
  m_sentDate = Date(month, day, year);
  m_text = text;

  return true;
}

