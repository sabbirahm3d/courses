#include <iostream>
#include "lab4.h"

using namespace std;

int main() {

  int i = 5;
  Factorial(i);

  for (int i = 5; i <= 10; ++i)
    cout << "Factorial(" << i << ") = " << Factorial(i) << endl;

  ChooseTwo(i);

  for (int i = 5; i <= 10; ++i)
    cout << "ChooseTwo(" << i << ") = " << ChooseTwo(i) << endl;
}

int ChooseTwo(int n) {
  if (n < 2)
    return -1;
  else
    return (n*(n-1))/2;
}

int Factorial(int n){
  if (n < 0)
    return -1;
  else if (n == 0)
    return 1;
  else
    n = (n * Factorial(n-1));
    return n;
}
