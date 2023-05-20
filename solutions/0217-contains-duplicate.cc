#include "0217-contains-duplicate.hh"

#include <iostream>
#include <unordered_set>
#include <vector>

bool Solution::containsDuplicate(std::vector<int> &nums) {
  std::unordered_set<int> s;
  for (unsigned i = 0; i < nums.size(); i++) {
    if (s.find(nums[i]) != s.end()) {
      return true;
    }
    s.insert(nums[i]);
  }
  return false;
}

void independentMethod(int &i) {
	i = 0;
}
