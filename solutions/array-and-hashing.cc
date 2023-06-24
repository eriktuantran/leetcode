#include "array-and-hashing.hh"

#include <time.h>

#include <iostream>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std; // I dont like this, but it's a leetcode thing
void independentMethod(int &i) {
    i = 0;
}

// https://leetcode.com/problems/contains-duplicate/
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

// https://leetcode.com/problems/contains-duplicate-ii/
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

#define containsNearbyAlmostDuplicate_OPTIMAL
// https://leetcode.com/problems/contains-duplicate-iii/
bool Solution::containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff, int valueDiff) {
#ifndef containsNearbyAlmostDuplicate_OPTIMAL
    for (unsigned i = 0; i < nums.size(); i++) {
        for (unsigned j = i + 1; j < nums.size(); j++) {
            if (j - i <= indexDiff && abs(nums[i] - nums[j]) <= valueDiff) {
                return true;
            }
        }
    }
    return false;
#else
    int n = nums.size();
    if (n == 0 || indexDiff < 0 || valueDiff < 0)
        return false;

    unordered_map<int, int> buckets;

    for (int i = 0; i < n; ++i) {
        int bucket = nums[i] / ((long)valueDiff + 1);

        // For negative numbers, we need to decrement bucket by 1
        // to ensure floor division.
        // For example, -1/2 = 0 but -1 should be put in Bucket[-1].
        // Therefore, decrement by 1.
        if (nums[i] < 0)
            --bucket;

        if (buckets.find(bucket) != buckets.end())
            return true;
        else {
            buckets[bucket] = nums[i];
            if (buckets.find(bucket - 1) != buckets.end() &&
                (long)nums[i] - buckets[bucket - 1] <= valueDiff)
                return true;
            if (buckets.find(bucket + 1) != buckets.end() &&
                (long)buckets[bucket + 1] - nums[i] <= valueDiff)
                return true;

            if (buckets.size() > indexDiff) {
                int key_to_remove = nums[i - indexDiff] / ((long)valueDiff + 1);

                if (nums[i - indexDiff] < 0)
                    --key_to_remove;

                buckets.erase(key_to_remove);
            }
        }
    }

    return false;

#endif
}

//  https://leetcode.com/problems/valid-anagram
//  Input: s = "anagram", t = "nagaram"
//  Output: true
// #define my_isAnagram
bool Solution::isAnagram(string s, string t) {
#ifdef my_isAnagram
    if (s.size() != t.size())
        return false;
    std::unordered_multiset<char> s_set(s.begin(), s.end());

    for (auto &c : t) {
        auto it = s_set.find(c);
        if (it == s_set.end())
            return false;
        s_set.erase(it);
    }
    return true;

#else

    if (s.size() != t.size())
        return false;

    unordered_map<char, int> smap;
    unordered_map<char, int> tmap;

    for (int i = 0; i < s.size(); i++) {
        smap[s[i]]++;
        tmap[t[i]]++;
    }
    for (auto &iter : smap) {
        if (smap[iter.first] != tmap[iter.first]) {
            return false;
        }
    }
    return true;
#endif
}

// https://leetcode.com/problems/two-sum/description/
vector<int> Solution::twoSum(vector<int> &nums, int target) {
    std::unordered_map<int, int> s;
    for (int i = 0; i < nums.size(); i++) {
        std::vector<int> result = { i };
        int finding = target - nums[i];
        if (s.find(finding) != s.end()) {
            result.push_back(s[finding]);
            return result;
        }
        s[nums[i]] = i;
    }
    return {};
}
