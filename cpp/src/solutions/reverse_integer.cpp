// LeetCode 7. Reverse Integer

#include "cpp/src/common/common.h"

class Solution {
 public:
  int reverse(int x) {
    int ans = 0;
    while (x != 0) {
      if (ans > numeric_limits<int>::max() / 10 ||
          ans < numeric_limits<int>::min() / 10)
        return 0;
      ans *= 10;
      ans += x % 10;
      x /= 10;
    }
    return ans;
  }
};

TEST(reverse, example1) {
  int x = 123, ans = 321;
  EXPECT_EQ(Solution().reverse(x), ans);
}

TEST(reverse, example2) {
  int x = -123, ans = -321;
  EXPECT_EQ(Solution().reverse(x), ans);
}

TEST(reverse, example3) {
  int x = 120, ans = 21;
  EXPECT_EQ(Solution().reverse(x), ans);
}

TEST(reverse, example4) {
  int x = 0, ans = 0;
  EXPECT_EQ(Solution().reverse(x), ans);
}