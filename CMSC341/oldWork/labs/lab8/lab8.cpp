#include <iostream>
#include "Complex.h"

using namespace std;

int main()
{
  double real;
  double imaginary;

  cout << "Enter the first complex number : " << endl;
  cout << "Real Part : ";
  cin >> real;
  cout << "Imaginary Part : ";
  cin >> imaginary;

  Complex number1(real, imaginary);

  cout << endl;
  cout << "Enter the second complex number : " << endl;
  cout << "Real Part : ";
  cin >> real;
  cout << "Imaginary Part : ";
  cin >> imaginary;

  Complex number2(real, imaginary);
  
  cout << endl;
  cout << "The Complex numbers you entered are : " << endl;
  cout << "First number : " << number1 << endl;
  cout << "Second number : " << number2 << endl;
  cout << endl;
  cout << "The negation of first number is : " << -number1 << endl;
  cout  << "The negation of second number is : " << -number2 << endl;
  cout << "The sum of the two numbers is : " << number1 + number2 << endl;

  return 0;
}
