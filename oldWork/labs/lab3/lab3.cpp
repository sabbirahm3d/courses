#include <iostream>
#include <cstring>
using namespace std;

const int MAX_STR = 100;

double ComputerVowelFrequency(char* buffer, double totalChars);

int main(){
  
  char buffer[MAX_STR];
  double vowelFreq, totalChars;
  
  cout << "Please enter a string:" << endl;
  cin.getline(buffer, sizeof(buffer));
  totalChars = strlen(buffer);
  vowelFreq = ComputerVowelFrequency(buffer, totalChars);
  
  cout << "The relative frequency of vowels in your string is " 
           << vowelFreq << endl;
}

double ComputerVowelFrequency(char* buffer, double totalChars){

  int index = 0;
  double vowelCount = 0;

  while (buffer[index] != '\0') {
    switch (buffer[index]) {
        case 'a': case 'e': case 'i': case 'o': case 'u':
        case 'A': case 'E': case 'I': case 'O': case 'U':
            vowelCount++;
            break;
        case '!': case '?': case ',': case '.': 
        case ';': case ':': case ' ':
	    totalChars--;
            break;
}
    index++;
}
  cout << "Number of vowels was " << vowelCount << "\n";
  return (vowelCount/totalChars);
}
