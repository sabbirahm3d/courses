#ifndef LAB6_H
#define LAB6_H
#include <string>

using namespace std;

class Fraction {

 public:

  Fraction();
  Fraction(int numerator, int denominator);
  Fraction Reciprocal();
  void Output();

 private:

  int m_numerator, m_denominator;

};

#endif
