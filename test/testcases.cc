#include <iostream>

#include "array-and-hashing.hh"
#include "gtest/gtest.h"
#include "test-data.hh"

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
class TestSuite : public ::testing::Test
{
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
    EXPECT_EQ(false, s.containsDuplicate(containsDuplicate_data));
    containsDuplicate_data.push_back(containsDuplicate_data[0]);
    EXPECT_EQ(true, s.containsDuplicate(containsDuplicate_data));
}

TEST_F(TestSuite, containsNearbyDuplicate) {
    EXPECT_EQ(false,
              s.containsNearbyDuplicate(containsNearbyDuplicate_data.first,
                                        containsNearbyDuplicate_data.second));
    int offset = 200;

    unsigned vector_size = containsNearbyDuplicate_data.first.size();
    unsigned k = containsNearbyDuplicate_data.second;
    int random = rand() % 500;
    containsNearbyDuplicate_data.first[vector_size - random - 1] =
        containsNearbyDuplicate_data.first[vector_size - random - k];
    EXPECT_EQ(true, s.containsNearbyDuplicate(containsNearbyDuplicate_data.first, k));
}

TEST_F(TestSuite, containsNearbyAlmostDuplicate) {
    std::tuple<std::vector<int>, int, int> data = { { 1, 2, 3, 1 }, 3, 0 };
    EXPECT_EQ(
        true,
        s.containsNearbyAlmostDuplicate(std::get<0>(data), std::get<1>(data), std::get<2>(data)));

    data = { { 1, 5, 9, 1, 5, 9 }, 2, 3 };
    EXPECT_EQ(
        false,
        s.containsNearbyAlmostDuplicate(std::get<0>(data), std::get<1>(data), std::get<2>(data)));

    auto data_alias = &containsNearbyAlmostDuplicate_data;
    EXPECT_EQ(false,
              s.containsNearbyAlmostDuplicate(
                  std::get<0>(*data_alias), std::get<1>(*data_alias), std::get<2>(*data_alias)));
}

TEST_F(TestSuite, isAnagram) {
    EXPECT_EQ(true, s.isAnagram("anagram", "nagaram"));
    EXPECT_EQ(false, s.isAnagram("rat", "car"));
    EXPECT_EQ(true, s.isAnagram(isAnagram_data.first, isAnagram_data.second));
}

TEST_F(TestSuite, twoSum) {
    std::tuple<std::vector<int>, int> data = { { 2, 7, 11, 15 }, 9 };
    std::vector<int> expect = { 0, 1 };
    auto actual = s.twoSum(std::get<0>(data), std::get<1>(data));
    std::sort(expect.begin(), expect.end());
    std::sort(actual.begin(), actual.end());
    EXPECT_EQ(expect, actual);

    data = { { 3, 2, 4 }, 6 };
    expect = { 1, 2 };
    actual = s.twoSum(std::get<0>(data), std::get<1>(data));
    std::sort(expect.begin(), expect.end());
    std::sort(actual.begin(), actual.end());
    EXPECT_EQ(expect, actual);

    data = { { 3, 2, 4 }, 6 };
    expect = { 1, 2 };
    actual = s.twoSum(std::get<0>(data), std::get<1>(data));
    std::sort(expect.begin(), expect.end());
    std::sort(actual.begin(), actual.end());
    EXPECT_EQ(expect, actual);

    expect = { 9998, 9999 };
    actual = s.twoSum(std::get<0>(twoSum_data), std::get<1>(twoSum_data));
    std::sort(expect.begin(), expect.end());
    std::sort(actual.begin(), actual.end());
    EXPECT_EQ(expect, actual);
}

// }  // namespace - could surround Project1Test in a namespace