#include <iostream>
using namespace std;

int main() {
  int x;

  x = - 3  + 4 * (5 - 6);
  cout << x << endl;

  x = (3 + 4) % 5 - 6;
  cout << x << endl;

  x = - 3 * (4 % - 6) / 5;
  cout << x << endl;

  x =  (7 + (6  % 5)) / 2;
  cout << x << endl;

  return 0;
}
