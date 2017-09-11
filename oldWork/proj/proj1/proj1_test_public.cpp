#include <fstream>
#include "proj1.h"
#include "/afs/umbc.edu/users/c/m/cmarron/pub/gtest-1.7.0/include/gtest/gtest.h"

using namespace std;

int load(int m[][MAX_VERTICES], string fileName);

namespace {

  class Project1Tests : public ::testing::Test {

  protected:

    virtual void SetUp() {
      v5_size   = load(  v5, "data/v5_c_h.dat");
      v5b_size  = load( v5b, "data/v5_nc_h.dat");
    }

    int load(int m[][MAX_VERTICES], string fileName) {
      int numVertices;
      int v1, v2;
      ifstream dataFile;
  
      for (int i=0; i<MAX_VERTICES; i++)
	for (int j=0; j<MAX_VERTICES; j++)
	  m[i][j] = 0;
      
      dataFile.open(fileName.c_str());
      dataFile >> numVertices;
      dataFile >> v1 >> v2;

      while ( v1 > 0 && v2 > 0 ) {
	if (v1 <= MAX_VERTICES && v2 <= MAX_VERTICES ) {
	  m[v1-1][v2-1] = m[v2-1][v1-1] = 1;
	}
	dataFile >> v1 >> v2;
      }

      return numVertices;
    }
    	
    int v5[MAX_VERTICES][MAX_VERTICES];
    int v5_size;

    int v5b[MAX_VERTICES][MAX_VERTICES];
    int v5b_size;

    int v6[MAX_VERTICES][MAX_VERTICES];
    int v6_size;

    int v6b[MAX_VERTICES][MAX_VERTICES];
    int v6b_size;

    int v7[MAX_VERTICES][MAX_VERTICES];
    int v7_size;

    int v7b[MAX_VERTICES][MAX_VERTICES];
    int v7b_size;

    int v10[MAX_VERTICES][MAX_VERTICES];
    int v10_size;

    int v10b[MAX_VERTICES][MAX_VERTICES];
    int v10b_size;

    int v20[MAX_VERTICES][MAX_VERTICES];
    int v20_size;

    int v20b[MAX_VERTICES][MAX_VERTICES];
    int v20b_size;
    
  };
}

/*
 * Test of InitializeGraph()
 *   
 * For graph sizes (number of vertices) from 1 to 20,
 * initialize matrix to all 1s, call InitializeGraph(),
 * and test that initialized portion of the matrix is
 * set to all zeros.
 */

TEST_F(Project1Tests, BASIC_InitializeGraph) {
  int graph[MAX_VERTICES][MAX_VERTICES];
  int numVertices = 7;

  // Graphs of size 1 to 20
  
  for (numVertices = 1; numVertices < 20; ++numVertices) {

    // Set entire matrix to 1s

    for (int i = 0; i < MAX_VERTICES; ++i)
      for (int j = 0; j < MAX_VERTICES; ++j)
	graph[i][j] = graph[j][i] = 1;

    InitializeGraph(graph, numVertices);

    // Check that initialized portion of matrix is all 0s

    for (int i = 0; i < numVertices; ++i)
      for (int j = 0; j < numVertices; ++j)
	ASSERT_EQ(0, graph[i][j]);
  }
}  

/*
 * Test of IsEdge()
 *
 * Test every edge of the five-vertex cyclic graph 
 * (v5_c_h.dat). Test non-edge and vertex out-of-range.
 */

TEST_F(Project1Tests, BASIC_IsEdge_V5_C) {

  // Check edge (i, i+1) for i in 1 to 4
  // Check edge (5, 1) separately
  for (int i = 1; i < 5; ++i)
    EXPECT_TRUE( IsEdge(v5, v5_size, i, i + 1) );
  EXPECT_TRUE( IsEdge(v5, v5_size, 5, 1) );
	
  // Check non-edge (1,3) and vertex out of range (5, 6)
  EXPECT_FALSE( IsEdge(v5, v5_size, 1, 3) );
  EXPECT_FALSE( IsEdge(v5, v5_size, 5, 6) );
}

TEST_F(Project1Tests, BASIC_RemoveEdge_V5_C) {
  EXPECT_TRUE(  RemoveEdge(v5, v5_size, 1, 2) );
  EXPECT_FALSE( IsEdge(v5, v5_size, 1, 2)     );
  EXPECT_FALSE( RemoveEdge(v5, v5_size, 0, 1) );
}

TEST_F(Project1Tests, BASIC_CreateEdge_V5_C) {
  EXPECT_TRUE(  CreateEdge(v5, v5_size, 1, 3) );
  EXPECT_TRUE(  IsEdge(v5, v5_size, 1, 3)     );
  EXPECT_FALSE( CreateEdge(v5, v5_size, 5, 6) );
}


TEST_F(Project1Tests, INTERMEDIATE_IsConnected_V5) {
  EXPECT_TRUE(  IsConnected(v5, v5_size)   );
  EXPECT_FALSE( IsConnected(v5b, v5b_size) );
}

      
#define main test_main
#include "proj1.cpp"
#undef main

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
