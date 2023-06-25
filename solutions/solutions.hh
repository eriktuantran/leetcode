#pragma once
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std; // I dont like this, but it's a leetcode thing
class Solution
{
  public:
    // Array and Hashing
    bool containsDuplicate(std::vector<int> &nums);
    bool containsNearbyDuplicate(std::vector<int> &nums, int k);
    bool containsNearbyAlmostDuplicate(std::vector<int> &nums, int indexDiff, int valueDiff);
    bool isAnagram(string s, string t);
    vector<int> twoSum(vector<int> &nums, int target);

    // Two Pointers
    bool isPalindrome(string s);

    // Sliding Window
    int maxProfit(vector<int> &prices);
};

void independentMethod(int &i);