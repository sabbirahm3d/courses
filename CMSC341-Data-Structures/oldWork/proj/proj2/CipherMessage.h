/*
File: CipherMessage.h
Project: CMSC 202 Project 2, Spring 2015
Author: Sabbir Ahmed
Date: 03/30/15
Discussion section: 15
e-mail: sabbir1@umbc.edu

  This header file contains the declaration for the CipherMessage class of
Project 2.
*/

#ifndef CIPHERMESSAGE_H
#define CIPHERMESSAGE_H

#include <string>
#include "Date.h"

using namespace std;

/* Constants for alphabet and letter frequencies 
   ALPHABET - allowed cipher and plain characters
   ALPHALEN - number of characters in alphabet
   EN_FREQ - frequencies of letters in English.
             EN_FREQ[0] - frequency of 'A'
	     EN_FREQ[1] - frequency of 'B'
	     etc.                                    */

const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int ALPHALEN = 26;
const double EN_FREQ[ALPHALEN] = {0.08167, 0.01492, 0.02782, 0.04253, 0.12702,
				  0.02228, 0.02015, 0.06094, 0.06966, 0.00153,
				  0.00772, 0.04025, 0.02406, 0.06749, 0.07507,
				  0.01929, 0.00095, 0.05987, 0.06327, 0.09056,
				  0.02758, 0.00978, 0.02361, 0.00150, 0.01974,
				  0.00074};

/* Constants for cipher and keys
   MAX_KEYLEN - maximum length of Vigenere key
   MAX_CIPHERLEN - maximum length of cipher message  */

const int MAX_KEYLEN = 6;
const int MAX_CIPHERLEN = 1000;

class CipherMessage {

 public:

  /* CipherMessage() - default constructor
     Preconditions - None
     Postconditions - new CipherMessage object with m_to, m_from, m_text
       set to "" and m_sentDate set to 1/1/1970                          */
 
  CipherMessage();

  /* CipherMessage() - non-default constructor
     Preconditions - None
     Postconditions - new CipherMessage object with m_to, m_from, set to 
       user supplied strings, m_sentDate set to user supplied date.
       m_text set to uppercase letters from text (all other characters
       deleted).                                                         */

  CipherMessage(string from, string to, Date sentDate, string text);

  /* LoadFromFile() - load object data from a file
     Preconditions - specified data file contains four lines
       line 1 - FROM information, no whitespace
       line 2 - TO information, no whitespace
       line 3 - SENTDATE information, mm dd yyyy (3 integers separated
         by spaces)
       line 4 - CIPHER data
     Postconditions - m_from, m_to, m_sentDate set to values in file.
       Only uppercase letters from cipher data are copied to m_text.
       If there is an error reading the file or if the date info
       is invalid, the class variables are unchanged.                    */

  bool LoadFromFile(string fileName);

  /* Decipher() - decipher the message 
     Preconditions - valid cipher in m_text
     Postconditions - best attempt at decryption OR failure message
       returned.                                                         */

  string Decipher();

  /* Decipher() - decipher the message with the given key
     Preconditions - valid cipher in m_text and correct key passed.
     Postconditions - decryption of m_text with key is returned.         */

  string Decipher(string key);

  /* GetText(), GetFrom(), GetTo(), GetSentDate() - standard accessors 
     Precondtions - none
     Postconditinos - returns value of class variable                    */

  string GetText() const;
  string GetFrom() const;
  string GetTo() const;
  Date GetSentDate() const;

  /* SetText() - standard mutator
     Preconditions - valid cipher passed as argument
     Postcondition - uppercase letters of text are copied to m_text    */

  void SetText(string text);

  /* SetFrom(), SetTo(), SetSentDate() - standard mutators
     Preconditions - valid data passed as argument
     Postconditions - class variable set to argument value              */

  void SetFrom(string from);
  void SetTo(string to);
  void SetSentDate(const Date& sentDate);

 private:
  string m_text;      // Contains cipher text
  string m_from;      // Contains sender info
  string m_to;        // Contains recipient info
  Date m_sentDate;    // Contains message sent date

};

#endif
