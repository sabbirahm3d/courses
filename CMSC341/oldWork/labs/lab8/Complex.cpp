#include "Complex.h"

// Complex class constructor
Complex::Complex(double real, double imaginary) : 
  m_real(real), m_imaginary(imaginary)
{
  
}

// Accessor that returns real part of complex number
double Complex::GetReal() const
{
  return m_real;
}

// Accessor that returns imaginary part of complex number
double Complex::GetImaginary() const
{
  return m_imaginary;
}

const Complex Complex::operator+ (const Complex& rhs) const {

  double newReal = m_real + rhs.GetReal();
  double newImaginary = m_imaginary + rhs.GetImaginary();
  return Complex(newReal, newImaginary);

}

const Complex Complex::operator- () const {

  double newReal = m_real * (-1);
  double newImaginary = m_imaginary * (-1);
  return Complex(newReal, newImaginary);

}

ostream& operator<< (ostream& out, const Complex& number) {
  
  out << number.GetReal() << number.GetImaginary();
  return out;

}
