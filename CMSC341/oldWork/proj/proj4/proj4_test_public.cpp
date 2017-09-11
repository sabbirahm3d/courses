#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include "WalkGraph.h"
#include "WalkEdge.h"
#include "WalkVertex.h"
#include "Intersection.h"
#include "SafeHouse.h"
#include "PoliceStation.h"
//#include "../gtest-1.7.0/include/gtest/gtest.h"
#include "/afs/umbc.edu/users/c/m/cmarron/pub//gtest-1.7.0/include/gtest/gtest.h"

using namespace std;

bool IsEdge(WalkVertex* v1, WalkVertex* v2, vector<WalkEdge*> edges);

TEST(Project4_BASIC, Intersection_DefaultConstructor_Accessor) {
  const int num_vert = 20;

  vector<WalkVertex*> v;

  // Create a vector of Intersection objects

  for (int i = 0; i < num_vert; i++) 
    v.push_back( new Intersection );

  // Check that all entries are non-NULL

  for (int i = 0; i < num_vert; i++)
    ASSERT_NE((WalkVertex *) NULL, v[i]);

  // Check that IDs are unique

  for (int i = 1; i < num_vert; i++)
    for (int j = 0; j < i; j++)
      EXPECT_NE(v[i]->GetID(), v[j]->GetID());

  for (int i = 0; i < num_vert; i++)
    EXPECT_EQ(CONTINUE, v[i]->Status());

}

TEST(Project4_BASIC, Intersection_NonDefaultConstructor_Accessor) {
  const int num_vert = 20;

  vector<WalkVertex*> v;

  // Create a vector of Intersection objects

  for (int i = 0; i < num_vert; i++) {
    stringstream ss;
    ss << "Intersection " << i;
    v.push_back( new Intersection(ss.str()) );
  }

  // Check that all entries are non-NULL

  for (int i = 0; i < num_vert; i++)
    ASSERT_NE((WalkVertex *) NULL, v[i]);

  // Check that description includes the correct string

  for (int i = 0; i < num_vert; i++) {
    stringstream ss;
    ss << "Intersection " << i;
    EXPECT_NE(string::npos, v[i]->ToString().find(ss.str()));
  }
  
  // Check that IDs are unique

  for (int i = 1; i < num_vert; i++)
    for (int j = 0; j < i; j++)
      EXPECT_NE(v[i]->GetID(), v[j]->GetID());

  // Check that Status() return continue
  for (int i = 0; i < num_vert; i++)
    EXPECT_EQ(CONTINUE, v[i]->Status());

}

TEST(Project4_BASIC, SafeHouse_DefaultConstructor_Accessor) {
  const int num_vert = 20;

  vector<WalkVertex*> v;

  // Create a vector of SafeHouse objects

  for (int i = 0; i < num_vert; i++) 
    v.push_back( new SafeHouse );

  // Check that all entries are non-NULL

  for (int i = 0; i < num_vert; i++)
    ASSERT_NE((WalkVertex *) NULL, v[i]);

  // Check that IDs are unique

  for (int i = 1; i < num_vert; i++)
    for (int j = 0; j < i; j++)
      EXPECT_NE(v[i]->GetID(), v[j]->GetID());

  // Check that Status() returns SUCCESS
  
  for (int i = 0; i < num_vert; i++)
    EXPECT_EQ(SUCCESS, v[i]->Status());

}

TEST(Project4_BASIC, SafeHouse_NonDefaultConstructor_Accessor) {
  const int num_vert = 20;

  vector<WalkVertex*> v;

  // Create a vector of SafeHouse objects

  for (int i = 0; i < num_vert; i++) {
    stringstream ss;
    ss << "SafeHouse " << i;
    v.push_back( new SafeHouse(ss.str()) );
  }

  // Check that all entries are non-NULL

  for (int i = 0; i < num_vert; i++)
    ASSERT_NE((WalkVertex *) NULL, v[i]);

  // Check that description includes the correct string

  for (int i = 0; i < num_vert; i++) {
    stringstream ss;
    ss << "SafeHouse " << i;
    EXPECT_NE(string::npos, v[i]->ToString().find(ss.str()));
  }
  
  // Check that IDs are unique

  for (int i = 1; i < num_vert; i++)
    for (int j = 0; j < i; j++)
      EXPECT_NE(v[i]->GetID(), v[j]->GetID());

  // Check that Status() returns SUCCESS

  for (int i = 0; i < num_vert; i++)
    EXPECT_EQ(SUCCESS, v[i]->Status());

}

TEST(Project4_BASIC, PoliceStation_DefaultConstructor_Accessor) {
  const int num_vert = 20;

  vector<WalkVertex*> v;

  // Create a vector of PoliceStation objects

  for (int i = 0; i < num_vert; i++) 
    v.push_back( new PoliceStation );

  // Check that all entries are non-NULL

  for (int i = 0; i < num_vert; i++)
    ASSERT_NE((WalkVertex *) NULL, v[i]);

  // Check that IDs are unique

  for (int i = 1; i < num_vert; i++)
    for (int j = 0; j < i; j++)
      EXPECT_NE(v[i]->GetID(), v[j]->GetID());

  for (int i = 0; i < num_vert; i++)
    EXPECT_EQ(FAILURE, v[i]->Status());

}

TEST(Project4_BASIC, PoliceStation_NonDefaultConstructor_Accessor1) {
  const int num_vert = 20;

  vector<WalkVertex*> v;

  // Create a vector of PoliceStation objects

  for (int i = 0; i < num_vert; i++) {
    stringstream ss;
    ss << "PoliceStation " << i;
    v.push_back( new PoliceStation(1.0, ss.str()) );
  }

  // Check that all entries are non-NULL

  for (int i = 0; i < num_vert; i++)
    ASSERT_NE((WalkVertex *) NULL, v[i]);

  // Check that description includes the correct string

  for (int i = 0; i < num_vert; i++) {
    stringstream ss;
    ss << "PoliceStation " << i;
    EXPECT_NE(string::npos, v[i]->ToString().find(ss.str()));
  }
  
  // Check that IDs are unique

  for (int i = 1; i < num_vert; i++)
    for (int j = 0; j < i; j++)
      EXPECT_NE(v[i]->GetID(), v[j]->GetID());

  // Check that Status() returns FAILURE

  for (int i = 0; i < num_vert; i++)
    EXPECT_EQ(FAILURE, v[i]->Status());

}

TEST(Project4_BASIC, PoliceStation_NonDefaultConstructor_Accessor2) {
  const int num_vert = 30;
  const double prob_caught = 0.5;

  vector<WalkVertex*> v;

  // Create a vector of PoliceStation objects

  for (int i = 0; i < num_vert; i++) {
    stringstream ss;
    ss << "PoliceStation " << i;
    v.push_back( new PoliceStation(prob_caught, ss.str()) );
  }

  // Check that all entries are non-NULL

  for (int i = 0; i < num_vert; i++)
    ASSERT_NE((WalkVertex *) NULL, v[i]);

  // Check that description includes the correct string

  for (int i = 0; i < num_vert; i++) {
    stringstream ss;
    ss << "PoliceStation " << i;
    EXPECT_NE(string::npos, v[i]->ToString().find(ss.str()));
  }
  
  // Check that IDs are unique

  for (int i = 1; i < num_vert; i++)
    for (int j = 0; j < i; j++)
      EXPECT_NE(v[i]->GetID(), v[j]->GetID());

  // Check that Status() returns a mixture of CONTINUE and FAILURE

  int respondFailure = 0;
  int respondContinue = 0;
  int respondOther = 0;

  for (int i = 0; i < num_vert; i++) {
    int status = v[i]->Status();
    if (status == FAILURE)
      respondFailure++;
    else if (status == CONTINUE) 
      respondContinue++;
    else {
      respondOther++;
      cout << status << endl;
    }
  }

  // Should only receive FAILURE or CONTINUE, no "other"

  EXPECT_EQ(0, respondOther);

  // Expect number of FAILUREs to be mean +/- 5 standard deviations

  double sd = sqrt( num_vert * prob_caught*(1 - prob_caught) );
  double mu = num_vert * prob_caught;
  int lower = floor( mu - 5*sd );
  int upper = ceil( mu + 5*sd );

  EXPECT_LE(lower, respondFailure);
  EXPECT_GE(upper, respondFailure);

  // Expect number of CONTINUEs to be mean +/- 5 standard deviations

  mu = num_vert * (1 - prob_caught);
  lower = floor( mu - 5*sd );
  upper = ceil( mu + 5*sd );

  EXPECT_LE(lower, respondContinue);
  EXPECT_GE(upper, respondContinue);
}

TEST(Project4_INTERMEDIATE, Walk1) {
  const unsigned int max_steps = 20;
  unsigned int seed = 1234;

  WalkGraph G;
  G.LoadFromFile("data/campus_v5.dat");

  vector<WalkVertex*> vertices;
  vector<WalkVertex*> walk;
  vector<WalkEdge*> edges;

  vertices = G.GetVertices();
  edges = G.GetEdges();

  walk = G.Walk(vertices[0], max_steps, seed);

  // Walk length must be <= max_steps

  EXPECT_GE(max_steps, walk.size());

  // If walk ends in less than max_steps, last vertx must not 
  // me an Intersection (must have ended with SUCCESS or FAILURE)

  if (walk.size() < max_steps)
    EXPECT_NE( CONTINUE, walk[walk.size() - 1]->Status() );

  // Check that the walk is actually a walk, i.e. that the sequence
  // of vertices are all connected by edges.

  for (unsigned long i = 0; i < walk.size() - 1; i++) {
    WalkVertex* v1 = walk[i];
    WalkVertex* v2 = walk[i+1];
    EXPECT_EQ( true, IsEdge(v1, v2, edges) );
  }
}


/* 
 * Test that re-seeding is working with Walk()
 *
 * Generate multiple walks and check that their lengths are not
 * all identical.  Not a perfect test, but unlikely to fail.
 *
 */
  

TEST(Project4_INTERMEDIATE, Walk2) {
  const unsigned int max_steps = 50;
  const int max_tries = 20;

  unsigned int seed = 1234;

  WalkGraph G;

  G.LoadFromFile("data/hamilton_v20.dat");

  vector<WalkVertex*> vertices = G.GetVertices();
  vector<WalkVertex*> walk = G.Walk(vertices[4], max_steps, seed);
  unsigned long walkLen = walk.size();
  bool identicalWalks = true;

  for ( int i = 0; i < max_tries && identicalWalks; i++) {
    walk = G.Walk(vertices[4], max_steps, ++seed);
    if ( walk.size() != walkLen )
      identicalWalks = false;
  }

  EXPECT_EQ(false, identicalWalks);
      
}

    
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

bool IsEdge(WalkVertex* v1, WalkVertex* v2, vector<WalkEdge*> edges) {
  for (unsigned long i = 0; i < edges.size(); i++) {
    if ( ( v1 == edges[i]->GetV1() && v2 == edges[i]->GetV2() ) ||
	 ( v1 == edges[i]->GetV2() && v2 == edges[i]->GetV1() ) )
      return true;
  }
  
  return false;
}
