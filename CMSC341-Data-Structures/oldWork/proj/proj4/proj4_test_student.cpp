/*
File: proj4_test_student.cpp
Project: CMSC 202 Project 4, Spring 2015
Author: Sabbir Ahmed
Date: 05/04/15
Discussion section: 15
e-mail: sabbir1@umbc.edu

The advanced testing for proj4.cpp. This file checks if the same seed is entered for
the random walk implementation, the output is identical.              */

#include <iostream>
#include <vector>
#include "WalkGraph.h"
#include "WalkEdge.h"
#include "WalkVertex.h"
#include "Intersection.h"
#include "SafeHouse.h"
#include "PoliceStation.h"
#include "/afs/umbc.edu/users/c/m/cmarron/pub/gtest-1.7.0/include/gtest/gtest.h"
//#include "../gtest-1.7.0/include/gtest/gtest.h"

using namespace std;

TEST(Project4_STUDENT, WalkGraph_Walk) {

  WalkGraph graph_test;

  int start_test = 5;
  unsigned int maxSteps_test = 10;
  int seed_test = 69;

  /* Load into file */
  graph_test.LoadFromFile("data/hamilton_v20.dat");

  /* Creating two randWalks using the same seed */
  vector<WalkVertex*> vertices_test1 = graph_test.GetVertices();
  vector<WalkVertex*> randWalk_test1 = graph_test.Walk(vertices_test1[start_test], maxSteps_test, seed_test);

  graph_test.LoadFromFile("data/hamilton_v20.dat");
  vector<WalkVertex*> vertices_test2 = graph_test.GetVertices();
  vector<WalkVertex*> randWalk_test2 = graph_test.Walk(vertices_test2[start_test], maxSteps_test, seed_test);
 
  /* Set bool to true */
  bool compareWalks = true;

  /* Comparing each ID value */
  for (int i = 0; i < randWalk_test1.size(); i++) {
    
    /* Set compareWalks to false if the ID's do not match */
    if ((randWalk_test1[i]->GetID()) != 
	((randWalk_test2[i]->GetID() - vertices_test1.size())))
      compareWalks = false;

  } 

  EXPECT_EQ(true, compareWalks);
  
}

int main(int argc, char **argv) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();

}
