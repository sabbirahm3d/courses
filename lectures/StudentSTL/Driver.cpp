
#include "Player.cpp"

// #include <string>
// #include <iostream>
// #include <queue> // for priority queue
// #include <algorithm> // for sort

using namespace std;

int main()
{

	PLAYER* Sabbir = new PLAYER("Sabbir", "Ahmed", 50);
	PLAYER* Lupoli = new PLAYER("Mr.", "Lupoli", 100);
	PLAYER* Jack = new PLAYER("Jack", "McLaughlin", 25);

	priority_queue<PLAYER>* players = new priority_queue<PLAYER>;

	players->push(*Sabbir);
	players->push(*Lupoli);
	players->push(*Jack);
	cout << "The top player is " << players->top();

	return 0;
}
