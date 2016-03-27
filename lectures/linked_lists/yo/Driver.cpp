#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#include "LinkedList.h"

int main()
{
	Linked_List one;

	one.insert("Angela", 261);
	one.insert("Jack", 20);
	one.insert("Peter", 120);
	one.insert("Chris", 270);
	one.insert("Sabbir", 99);

	one.remove("Jack");

	one.insert("Lupoli", 9001);

	one.remove("Angela");
	one.remove("Chris");
	// one.print_list();

	one.insertAtFront("Eminem", 0);
	one.print_list();

	cout << "got here" << endl;

	return 0;
}
