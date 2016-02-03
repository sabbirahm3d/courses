#include <iostream>
#include "List.h"

using namespace std;

int main() {

   int i;
   List queue1;
   List queue2;



   cout << "Testing Adding to queue1..." << endl;
   for(i = -5; i < 10; i+=2) {
      queue1.AddToEnd(i);
   }

   cout << "Testing Adding to queue2..." << endl;
   for(i = -5; i < 10; i+=3) {
      queue2.AddToEnd(i);
   }

   cout << "Should Print: -5 -3 -1 1 3 5 7 9 (Note: should NOT print 0!)\n";
   cout << "Actual Print: ";
   queue1.Print();
   cout << endl << endl;
   cout << "Should Print: -5 -2 1 4 7 (Again, should NOT print 0!)\n";
   cout << "Actual Print: ";
   queue2.Print();
   cout << endl << endl;


   cout << "Testing queue1.Size..." << endl;
   cout << "Expecting: 8; got: " << queue1.Size() << endl << endl;
   cout << "Testing queue2.Size..." << endl;
   cout << "Expecting: 5; got: " << queue2.Size() << endl << endl;


   cout << "Testing Removing from queue1..." << endl;
   for(i = -5; i < 10; i+=2) {
      int val = queue1.RemoveFromStart();
      cout << "Expecting: " << i << "; got: " << val << endl;
   }


   return 0;

}
