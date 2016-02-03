#include "Tent.h"
#include "Residence.h"

using namespace std;

Tent::Tent() : Residence(1, 2, false)
{
  /* nothing */
}

double Tent::PropertyValue() const {

  return 0;

}

int Tent::NumWindows() const {

  return 0;

}
