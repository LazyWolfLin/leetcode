// LeetCode 9. Palindrome Number in C++

#include "cpp/src/common/common.h"

class Solution {
 public:
  bool isPalindrome(int x) {
    long long y = 0;
    int tmp = x;
    while (tmp > 0) {
      y *= 10;
      y += tmp % 10;
      tmp /= 10;
    }
    return x == y;
  }
};

TEST(isPalindrome, example1) {
  int x = 121;
  bool ans = true;
  EXPECT_EQ(Solution().isPalindrome(x), ans);
}

TEST(isPalindrome, example2) {
  int x = 1121;
  bool ans = false;
  EXPECT_EQ(Solution().isPalindrome(x), ans);
}

TEST(isPalindrome, example3) {
  int x = 10;
  bool ans = false;
  EXPECT_EQ(Solution().isPalindrome(x), ans);
}

TEST(isPalindrome, example4) {
  int x = -101;
  bool ans = false;
  EXPECT_EQ(Solution().isPalindrome(x), ans);
}