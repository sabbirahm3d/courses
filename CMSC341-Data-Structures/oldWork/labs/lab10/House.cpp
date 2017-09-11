#include "House.h"

using namespace std;

House::House() : Residence(4, 4, true)
{
  /* nothing */
}

House::House(int numRoom, int numWalls, bool hasWasher) 
  : Residence(numRoom,numWalls,hasWasher) {
  /* nothing */
}
