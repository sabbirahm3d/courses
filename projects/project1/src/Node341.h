#ifndef NODE341_H
#define NODE341_H

#include <iostream>

using namespace std;

template <class datatype>
class node {


	datatype data;
	struct node *next;
	struct node *prev;

};

#include "Node341.cpp"
#endif