#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  bool containsDuplicate(std::vector<int> &nums);
  bool containsNearbyDuplicate(std::vector<int> &nums, int k);
};

void independentMethod(int &i);