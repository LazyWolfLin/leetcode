// LeetCode 13. Roman to Integer

#include "cpp/src/common/common.h"

class Solution {
 public:
  int romanToInt(string s) {
    map<char, int> value_map = {
        {'I', 1},   {'V', 5},   {'X', 10},   {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000},
    };

    int ans = 0, last = 0;
    for (auto iter = s.rbegin(); iter != s.rend(); ++iter) {
      auto curr = value_map[*iter];
      if (curr < last) {
        ans -= curr;
      } else {
        ans += curr;
      }
      last = curr;
    }
    return ans;
  }
};

TEST(romanToInt, example1) {
  string s = "III";
  int ans = 3;
  EXPECT_EQ(Solution().romanToInt(s), ans);
}

TEST(romanToInt, example2) {
  string s = "IV";
  int ans = 4;
  EXPECT_EQ(Solution().romanToInt(s), ans);
}

TEST(romanToInt, example3) {
  string s = "IX";
  int ans = 9;
  EXPECT_EQ(Solution().romanToInt(s), ans);
}

TEST(romanToInt, example4) {
  string s = "LVIII";
  int ans = 58;
  EXPECT_EQ(Solution().romanToInt(s), ans);
}

TEST(romanToInt, example5) {
  string s = "MCMXCIV";
  int ans = 1994;
  EXPECT_EQ(Solution().romanToInt(s), ans);
}