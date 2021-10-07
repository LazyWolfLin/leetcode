// LeetCode 8. String to Integer (atoi) by C++

#include "common.h"

class Solution {
 public:
  int myAtoi(string str) {
    int i = 0;
    while (i < str.size() && str[i] == ' ') {
      i++;
    }
    bool positive = true;
    if (i < str.size() && (str[i] == '+' || str[i] == '-')) {
      positive = str[i] == '+';
      i++;
    }
    long long ans = 0;
    while (i < str.size()) {
      if (isdigit(str[i])) {
        auto bit = str[i] - '0';
        if (!positive) bit = -bit;
        ans = ans * 10 + bit;
        if (ans > numeric_limits<int>::max()) {
          ans = numeric_limits<int>::max();
        }
        if (ans < numeric_limits<int>::min()) {
          ans = numeric_limits<int>::min();
        }
      } else {
        break;
      }
      i++;
    }
    return ans;
  }
};

TEST(myAtoi, example1) {
  string str = "42";
  int ans = 42;
  EXPECT_EQ(Solution().myAtoi(str), ans);
}

TEST(myAtoi, example2) {
  string str = "-42";
  int ans = -42;
  EXPECT_EQ(Solution().myAtoi(str), ans);
}

TEST(myAtoi, example3) {
  string str = "4193 with words";
  int ans = 4193;
  EXPECT_EQ(Solution().myAtoi(str), ans);
}

TEST(myAtoi, example4) {
  string str = "words and 987";
  int ans = 0;
  EXPECT_EQ(Solution().myAtoi(str), ans);
}

TEST(myAtoi, example5) {
  string str = "-91283472332";
  int ans = -2147483648;
  EXPECT_EQ(Solution().myAtoi(str), ans);
}