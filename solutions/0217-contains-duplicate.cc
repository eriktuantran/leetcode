#include "0217-contains-duplicate.hh"

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

void independentMethod(int &i) { i = 0; }

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

bool Solution::containsNearbyDuplicate(std::vector<int> &nums, int k) {
  std::unordered_map<int, int> s;
  for (unsigned i = 0; i < nums.size(); i++) {
    if (s.find(nums[i]) != s.end()) {
      if (i - s[nums[i]] <= k) {
        return true;
      }
    }
    s[nums[i]] = i;
  }
  return false;
}
