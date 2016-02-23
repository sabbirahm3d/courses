// SOURCE
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "LinkedList.h"


Linked_List::Linked_List()
{
	FRONT_ptr = NULL;
	REAR_ptr = NULL;
	PREVIOUS_ptr = NULL;
}

Linked_List::~Linked_List()
{
  while(FRONT_ptr != NULL)
  {
      CURSOR = FRONT_ptr;
      FRONT_ptr = FRONT_ptr -> link; // moves FRONT_ptr up one node
	  delete CURSOR; // deletes and return NODE back to free memory!!!
  }
}

void Linked_List::insert(string n, int score)
{
	INSERT = new NODE;
	
	if(isEmpty()) // first item in List
	{
		// collect information into INSERT NODE
		INSERT-> name =  n; 
// must use strcpy to assign strings
		INSERT -> test_grade = score;
		INSERT -> link = NULL;
		FRONT_ptr = INSERT;
		REAR_ptr = INSERT;
	}
	else // else what?? When would this happen??
	{
		// collect information into INSERT NODE
		INSERT-> name = n; // must use strcpy to assign strings
		INSERT -> test_grade = score;
		REAR_ptr -> link = INSERT;
		INSERT -> link = NULL;
		REAR_ptr = INSERT;
	}
}

void Linked_List::print_list( )
{
  // good for only a few nodes in a list

	if(isEmpty() == 1)
	{
	cout << "No nodes to display" << endl;
	return;
	}

	for(CURSOR = FRONT_ptr; CURSOR; CURSOR = CURSOR-> link)
	{ cout << setw(8) << CURSOR->name; } cout << endl;
	for(CURSOR = FRONT_ptr; CURSOR; CURSOR = CURSOR-> link)
	{ cout << setw(8) << CURSOR->test_grade; } cout << endl;
}

void Linked_List::remove(string target)
{
	// 3 possible places that NODES can be removed from in the Linked List
	// FRONT
	// MIDDLE
	// REAR
	// all 3 condition need to be covered and coded

	// use Traversing to find TARGET

	PREVIOUS_ptr = NULL;

	for(CURSOR = FRONT_ptr; CURSOR; CURSOR = CURSOR-> link)
	{
		if(CURSOR->name == target) // match
		{ break; } // function will still continue, CURSOR will 
	// mark NODE to be removed
		else
		{ PREVIOUS_ptr = CURSOR; } // PREVIOUS marks what NODE CURSOR is marking 
	// JUST before CURSOR is about to move to the next NODE
	}

	if(CURSOR == NULL) { return; } // never found a match
	else
	{
		if((CURSOR == FRONT_ptr) && (CURSOR == REAR_ptr))
		{// TARGET node was the first and ONLY in the list
			FRONT_ptr = NULL; 
			REAR_ptr = NULL; 
		}
		else if (CURSOR == FRONT_ptr) // TARGET node was the first in the list
		{
			FRONT_ptr = FRONT_ptr -> link; // moves FRONT_ptr up one node
		}// why no need for PREVIOUS??
		else if (CURSOR == REAR_ptr) // TARGET node was the last in the list
		{ // will need PREVIOUS for this one
			PREVIOUS_ptr -> link = NULL; // since this node will become the last in the list
			REAR_ptr = PREVIOUS_ptr; // = REAR_ptr; // moves REAR_ptr into correct position in list
		}
		else // TARGET node was the middle of the list
		{ // will need PREVIOUS also for this one
			PREVIOUS_ptr -> link = CURSOR-> link; // moves PREV nodes' link to point where CURSOR nodes' points
		}
		delete CURSOR; // deletes and return NODE back to free memory!!!
		return;
	}
}

bool Linked_List::isEmpty()
{
	if ((FRONT_ptr == NULL) && (REAR_ptr == NULL))	{ return true; }
	else { return false;}
}


void Linked_List::insertAtFront(string n, int score){

	INSERT = new NODE;
	
		// collect information into INSERT NODE
		INSERT-> name =  n; 
// must use strcpy to assign strings
		INSERT -> test_grade = score;
		INSERT -> link = NULL;
		FRONT_ptr = INSERT;
		REAR_ptr = INSERT;

}