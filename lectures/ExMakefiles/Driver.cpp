#include <cstdlib> // or sometimes <stdlib>

#include <string>
#include <iostream>

using namespace std;

int main ( int argc, char *argv[] ){

  string hello = "Hello";

  if ( argc != 2 )
    cout << "usage: "<< argv[0] << "COUNT" << endl;
  else
  {

  	cout << "You asked to loop the string " << argv[1] << " times." << endl;

  	for (int i; i <= atoi( argv[1] ); i++){
		cout << hello << endl;
	}

  }

};