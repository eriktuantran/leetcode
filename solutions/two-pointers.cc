#include "solutions.hh"

#include <time.h>

#include <iostream>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std; // I dont like this, but it's a leetcode thing

// https://leetcode.com/problems/valid-palindrome/
// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplana c analpanama" is a palindrome.
bool Solution::isPalindrome(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        while (!isalnum(s[i]) && i < j) {
            i++;
        }
        while (!isalnum(s[j]) && j > i) {
            j--;
        }
        if (tolower(s[i]) != tolower(s[j])) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}