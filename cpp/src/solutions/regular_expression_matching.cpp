// LeetCode 10. Regular Expression Matching in C++

#include "common.h"

class Solution {
 public:
  bool isMatch(string s, string p) {
    bool** dp = new bool*[s.size() + 1];
    for (auto i = 0; i <= s.size(); i++) {
      dp[i] = new bool[p.size() + 1];
      memset(dp[i], false, (p.size() + 1) * sizeof(bool));
    }
    dp[s.size()][p.size()] = true;
    for (int i = s.size(); i >= 0; i--)
      for (int j = p.size() - 1; j >= 0; j--) {
        auto matched = i < s.size() && (p[j] == s[i] || p[j] == '.');
        if (j + 1 < p.size() && p[j + 1] == '*') {
          dp[i][j] = dp[i][j + 2] || (matched && dp[i + 1][j]);
        } else {
          dp[i][j] = matched && dp[i + 1][j + 1];
        }
      }
    return dp[0][0];
  }
};

TEST(isMatch, example1) {
  string s = "aa", p = "a";
  bool ans = false;
  EXPECT_EQ(Solution().isMatch(s, p), ans);
}

TEST(isMatch, example2) {
  string s = "aa", p = "a*";
  bool ans = true;
  EXPECT_EQ(Solution().isMatch(s, p), ans);
}

TEST(isMatch, example3) {
  string s = "ab", p = ".*";
  bool ans = true;
  EXPECT_EQ(Solution().isMatch(s, p), ans);
}

TEST(isMatch, example4) {
  string s = "aab", p = "c*a*b";
  bool ans = true;
  EXPECT_EQ(Solution().isMatch(s, p), ans);
}

TEST(isMatch, example5) {
  string s = "mississippi", p = "mis*is*p*.";
  bool ans = false;
  EXPECT_EQ(Solution().isMatch(s, p), ans);
}