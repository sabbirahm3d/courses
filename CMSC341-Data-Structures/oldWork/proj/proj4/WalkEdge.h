/**************************************/
/* STUDENTS - DO NOT MODIFY THIS FILE */
/**************************************/

#ifndef WALKEDGE_H
#define WALKEDGE_H

#include <iostream>
#include "WalkVertex.h"

using namespace std;

class WalkEdge {

 public:

  /* WalkEdge() - constructor
     Preconditions: v1 and v2 are non-NULL.
     Postconditions: creates an WalkEdge object with vertices v1 and v2;
     if either v1 or v2 is NULL, prints an error message and exits.   */

  WalkEdge(WalkVertex *v1, WalkVertex *v2);

  /* GetV1() - returns a pointer to the first WalkVertex in the WalkEdge
     Preconditions: none
     Postconditions: returns pointer to the first WalkVertex.             */

  WalkVertex* GetV1() const;

  /* GetV2() - returns a pointer to the second WalkVertex in the WalkEdge
     Preconditions: none
     Postconditions: returns pointer to the second WalkVertex.            */

  WalkVertex* GetV2() const;
  
  /* SetV1() - sets the first WalkVertex (m_v1) in the WalkEdge
     Preconditions: v is non-NULL
     Postconditions: sets m_v1 to v; if v is  NULL, prints a warning 
     message and does NOT change m_v1.                                */

  void SetV1(WalkVertex *v);

  /* SetV2() - sets the second WalkVertex (m_v2) in the WalkEdge
     Preconditions: v is non-NULL
     Postconditions: sets m_v2 to v; if v is  NULL, prints a warning 
     message and does NOT change m_v2.                                */

  void SetV2(WalkVertex *v);

  /* operator<< - overload output operator
     Preconditions: none
     Postconditions: Uses ToString() to print a WalkEdge as
          string representation of m_v1
   	       <--> string representation of m_v2                    */
     

  friend ostream& operator<<(ostream &sout, const WalkEdge &e);
  
 private:
  WalkVertex* m_v1;
  WalkVertex* m_v2;

};

#endif
