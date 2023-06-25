#include "testsuite.hh"
#include "two-pointers-data.hh"

TEST_F(TestSuite, isPalindrome) {
    EXPECT_EQ(true, s.isPalindrome("A man, a plan, a canal: Panama"));
    EXPECT_EQ(false, s.isPalindrome("race a car"));
    EXPECT_EQ(true, s.isPalindrome(" "));
    EXPECT_EQ(true, s.isPalindrome(isPalindrome_data));
}
