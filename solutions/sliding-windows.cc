#include "solutions.hh"

#include <time.h>

#include <iostream>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you
// sell.
int Solution::maxProfit(vector<int> &prices) {
    int max_profit = 0;
    int min_price = std::numeric_limits<int>::max();
    for (auto price : prices) {
        if (price < min_price) {
            min_price = price;
        }
        if (price - min_price > max_profit) {
            max_profit = price - min_price;
        }
    }
    return max_profit;
}