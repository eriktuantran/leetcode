#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;  // I dont like this, but it's a leetcode thing
class Solution {
 public:
  bool containsDuplicate(std::vector<int> &nums);
  bool containsNearbyDuplicate(std::vector<int> &nums, int k);
  bool containsNearbyAlmostDuplicate(std::vector<int> &nums, int indexDiff, int valueDiff);
};

void independentMethod(int &i);