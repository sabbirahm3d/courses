#ifndef LIST_H
#define LIST_H

using namespace std;

// The node used in List
class Node
{
  public:
   Node(int data);

   int m_data;
   Node *m_next;
};


// List is a linked list of ints
class List
{
  public:
   // Creates a default empty list
   List();
   
   // Simple destructor
   ~List();
   
   // Insert "data" at the very end of the list
   void AddToEnd(int data);
   
   // Remove and return the first data item from the list.
   int RemoveFromStart();

	// Prints the list
   void Print() const;

   // Returns the size of the list
   unsigned int Size() const;

  private:

   Node *m_head;

};



#endif
