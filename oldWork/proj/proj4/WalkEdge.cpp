/**************************************/
/* STUDENTS - DO NOT MODIFY THIS FILE */
/**************************************/

#include <iostream>
#include <cstdlib>
#include "WalkEdge.h"
#include "WalkVertex.h"

using namespace std;

WalkEdge::WalkEdge(WalkVertex *v1, WalkVertex *v2) : 
  m_v1(v1), m_v2(v2)
{ 
  if (v1 == NULL || v2 == NULL) {
    cerr << "Error: WalkEdge constructor expects non-null WalkVertex pointers." << endl;
    exit(1);
  }
}

WalkVertex* WalkEdge::GetV1() const {

  return m_v1;

}

WalkVertex* WalkEdge::GetV2() const {

  return m_v2;

}

void WalkEdge::SetV1(WalkVertex *v1) {

  if (v1 != NULL)
    m_v1 = v1;
  else
    cerr << "Warning: SetV1() expects non-null WalkVertex pointer." << endl;

}

void WalkEdge::SetV2(WalkVertex *v2) {

  if (v2 != NULL)
    m_v2 = v2;
  else
    cerr << "Warning: SetV2() expects non-null WalkVertex pointer." << endl;

}

ostream& operator<<(ostream &sout, const WalkEdge &e) {

  sout << e.m_v1->ToString() << "\n      <--> " << e.m_v2->ToString();
  
  return sout;

}
