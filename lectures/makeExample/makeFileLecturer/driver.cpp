#include <iostream>
#include <string>
using namespace std;

#include "Lecturer.h"


int main()
{
  Lecturer Park("John", "Park", 112, 3000);

  cout << Park.GetAge();

  return 0;
}