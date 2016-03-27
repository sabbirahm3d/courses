#ifndef HOUSE_H
#define HOUSE_H

#include "Residence.h"

using namespace std;

class House : public Residence {

 public:

  House();
  House(int numRoom, int numWalls, bool hasWasher);

};

#endif
