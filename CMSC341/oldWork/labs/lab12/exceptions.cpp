#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

class InvalidSize {

public:

  InvalidSize() : m_message("LEARN TO COUNT"){}

  const string& GetMessage() const {return m_message;}

private:
  const string m_message;
};

class StackFull {

public:

  StackFull() : m_message("STACK IS FULL YO"){}

  const string& GetMessage() const {return m_message;}

private:
  const string m_message;
};

class StackEmpty{

public:

  StackEmpty():m_message("Stack izzzzzzzzzzz empty"){}
  const string& GetMessage(){return m_message;}

private:
  const string m_message;
};

class IntStack {

public:
  // MaxSize should be an unsigned int, but for the sake of example...
  IntStack(int MaxSize)
  {
    if(MaxSize < 0)
      {
	throw InvalidSize();
	/*	cerr << "Cannot create a negative size stack" << endl;
	exit(1);*/
      }
    
    data.resize(MaxSize);
    cur_index = 0;
  }

  void push(int new_data)
  {
    if(cur_index == data.size())
      {
	throw StackFull();
	/*	cerr << "Push to full stack" << endl;
		exit(1);*/
      }
    else
      {
	data.at(cur_index) = new_data;
	cur_index++;
      }
  }

  int pop()
  {
    if(cur_index == 0)
      {
	throw StackEmpty();
	/*	cerr << "Pop from empty stack" << endl;
	exit(1);*/
      }
    else
      {
	// pop off the int and return it
	cur_index--;
	return data.at(cur_index);
      }
  }

private:
  vector<int> data;
  unsigned int cur_index;
};

int main()
{
  // Testing Constructor
  try {
  IntStack c_test(-10);

  c_test.push(3);
  c_test.push(4);
  c_test.pop();
  c_test.pop();
  }

  catch (InvalidSize& ex) {
    cerr << "Calling exception handler so you can" << ex.GetMessage() << endl;}
  
  
  // Testing push
  try {
  IntStack push_test(5);
  
  for(unsigned int i = 0; i < 7; i++) {
    push_test.push(i);
  }
  }
  catch (StackFull& ex) {
    cerr << "fjdshfbdsjhbdsf" << ex.GetMessage() << endl;
}
  
  // Testing pop
  try {
  IntStack pop_test(2);
  
  pop_test.push(1);
  pop_test.push(2);
  pop_test.pop();
  pop_test.pop();
  pop_test.pop();
  }

  catch (StackEmpty& ex) {
    cerr << "Calling exception at" << ex.GetMessage() << endl;
}
  cout << "Completed!" << endl;
}
