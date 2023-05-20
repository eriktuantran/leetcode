#include <iostream>

#include "gtest/gtest.h"
#include "0217-contains-duplicate.hh"

// IndependentMethod is a test case - here, we have 2 tests for this 1 test case
TEST(IndependentMethod, ResetsToZero) {
  int i = 3;
  independentMethod(i);
  EXPECT_EQ(0, i);

  i = 12;
  independentMethod(i);
  EXPECT_EQ(0, i);
}

TEST(IndependentMethod, ResetsToZero2) {
  int i = 0;
  independentMethod(i);
  EXPECT_EQ(0, i);
}

// The fixture for testing class Project1. From google test primer.
class TestSuite : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  TestSuite() {
    // You can do set-up work for each test here.
  }

  virtual ~TestSuite() {
    // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:
  virtual void SetUp() {
    // Code here will be called immediately after the constructor (right
    // before each test).
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test (right
    // before the destructor).
  }

  // Objects declared here can be used by all tests in the test case for Project1.
  Solution s;
};

// Test case must be called the class above
// Also note: use TEST_F instead of TEST to access the test fixture (from google test primer)

TEST_F(TestSuite, containsDuplicate) {
  std::vector<int> v = {1, 2, 3, 4, 1};
  EXPECT_EQ(true, s.containsDuplicate(v));
}

// }  // namespace - could surround Project1Test in a namespace