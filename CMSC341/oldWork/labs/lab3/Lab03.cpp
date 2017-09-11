#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int MAX_STR = 100;

int main(){
  // double vowelFreq;
  char buffer[MAX_STR];
  //int totalChars;
  int x;

  cout << "Enter your sentence\n";
  cin.getline(buffer, sizeof(buffer));
  cout << buffer;
  cin.getline(x,sizeof(buffer));
  //totalChars= strlen(buffer);

  int vowelCount = 0;
  switch (x) 
    {
  case '.': case ',': case ';':
  case ':': case '!': case '?':
    cout << "The character is punctuation." << endl;
    break;
  case 'a': case 'A': case 'e': case 'E':
  case 'i': case 'I': case 'o': case 'O':
  case 'u': case 'U':
    cout << "The character is a vowel." << endl;
    vowelCount++;
    break;
  default:
    cout << "The character is not a vowel or punctuation." << endl;
  }
  cout << vowelCount << endl;
}
