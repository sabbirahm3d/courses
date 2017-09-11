#ifndef RESIDENCE_H
#define RESIDENCE_H

#include <iostream>
using namespace std;

class Residence {

 public:

  Residence();
  Residence(int numRooms, int numWalls, bool hasWasher);

 protected:

  virtual double PropertyValue() const;
  virtual int NumWindows() const ;
  virtual bool HasWasher() const;

  int m_numWalls;
  int m_numRooms;
  bool m_hasWasher;

 private:

  friend ostream& operator<<(ostream& out, const Residence& residence);

};

#endif
