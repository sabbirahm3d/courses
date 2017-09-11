#include <iostream>
#include "Fraction.h"

//Constructors:

Fraction::Fraction(){

    m_numerator = 1;
   m_denominator = 1;  

}

Fraction::Fraction(int numerator, int denominator){

  if (denominator == 0)
    cout << "you can't divide by zero.";

  else{
    m_numerator = numerator;
    m_denominator = denominator;
    cout << m_numerator << "/"  << m_denominator << "\n";
  }

}

void Fraction::Output(){

    cout << m_numerator << "/" << m_denominator;

}

Fraction Fraction::Reciprocal(){

  Fraction newFrac(m_denominator, m_numerator);
  return newFrac;

}
