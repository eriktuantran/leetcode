#include "testsuite.hh"
#include "sliding-windows-data.hh"

TEST_F(TestSuite, maxProfit) {
    std::vector<int> data = { 7, 1, 5, 3, 6, 4 };
    EXPECT_EQ(5, s.maxProfit(data));
    data = { 7, 6, 4, 3, 1 };
    EXPECT_EQ(0, s.maxProfit(data));
    EXPECT_EQ(999, s.maxProfit(maxProfit_data));
}
