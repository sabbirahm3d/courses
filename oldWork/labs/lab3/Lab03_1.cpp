#include <iostream>
using namespace std;

int main() {
  int i1;
  char s1[80], s2[80];
  char dummy[80];

  cin >> i1;
  cin.getline(dummy, sizeof(dummy));   // reads the newline
  cin.getline(s1, sizeof(s1));
  cin.getline(s2, sizeof(s2));
  cout << i1 << s1 << s2;

  return 0;
}
