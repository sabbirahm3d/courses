#include <iostream>
#include "IntArray.h"

using namespace std;

int main()
{
  // Create IntArray objects and call methods here...
  IntArray h(-3, 4);
  IntArray f(0, 0);
  IntArray j;
  IntArray a[0];
  cout << h << endl;
  cout << h.Get(-3) << endl;
  cout << f << endl;
  if(h == f)
    cout << "fdfsdf" << endl;
  if(f!=h)
    cout << "fdsnfkjsnd" << endl;
  cout << f[4];
  cout << h.Contains(1,-7) << endl;
  cout << h.Contains(-1, 7) << endl;
  cout << h.IndexOf(-6) << endl;
  // cout << a.AddToAll(0) << endl;
  cout << 
  // Print out the number of errors/edge cases found
  cout << endl << endl << IntArray::GetProgress() << endl;
    
  return 0;
}
