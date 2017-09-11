#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

using namespace std;

class Complex
{
 public:
  // Constructor with default arguments
  Complex(double real = 1.0, double imaginary = 1.0);
      
  // Accessor method which return the real part 
  double GetReal() const;
      
  // Accessor method which return the imaginary part
  double GetImaginary() const;
      
  // Overloaded + operator as member function
  const Complex operator+ (const Complex& rhs) const;

  // Overloaded unary minus operator as member function 
  const Complex operator-() const;
    
 private:
  double m_real;
  double m_imaginary;
};


// Overloaded << operator as non-member function 
ostream & operator << (ostream& out, const Complex& number);

#endif
