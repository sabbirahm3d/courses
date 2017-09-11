#include <iostream>
#include "lab4.h"
#include "/afs/umbc.edu/users/c/m/cmarron/pub//gtest-1.7.0/include/gtest/gtest.h"

using namespace std;

TEST(ChooseTwoTest, HandlesValidInput) {
  EXPECT_EQ(1, ChooseTwo(2));
  EXPECT_EQ(3, ChooseTwo(3));
  EXPECT_EQ(45, ChooseTwo(10));
  EXPECT_EQ(190, ChooseTwo(20));
}

TEST(ChooseTwoTest, HandlesInvalidInput) {
  EXPECT_EQ(-1, ChooseTwo(1));
  EXPECT_EQ(-1, ChooseTwo(0));
  EXPECT_EQ(-1, ChooseTwo(-1));
  EXPECT_EQ(-1, ChooseTwo(-100));
}

TEST(FactorialTest, HandlesValidInput) {
  EXPECT_EQ(1, Factorial(0));
  EXPECT_EQ(1, Factorial(1));
  EXPECT_EQ(2, Factorial(2));
  EXPECT_EQ(6, Factorial(3));
  EXPECT_EQ(3628800, Factorial(10));
}

TEST(FactorialTest, HandlesInvalidInput) {
  EXPECT_EQ(-1, Factorial(-1));
  EXPECT_EQ(-1, Factorial(-10));
  EXPECT_EQ(-1, Factorial(-2));
  EXPECT_EQ(-1, Factorial(-3));
  EXPECT_EQ(-1, Factorial(-695));
}


#define main test_main
#include "lab4.cpp"
#undef main

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
