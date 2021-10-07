// LeetCode 5. Longest Palindromic Substring by C++
// Manacher Algorithms

#include "common.h"

class Solution {
 public:
  string longestPalindrome(string s) {
    string t = "$#" + string(s.size() * 2, '#');
    for (int i = 0; i < s.size(); i++) {
      t[i * 2 + 2] = s[i];
    }
    vector<int> f(t.size(), 1);
    int current_center = 0, current_right = 0, ans_len = 0, ans_center = 0;
    for (int i = 1; i < t.size(); i++) {
      if (current_right > i) {
        f[i] = min(f[2 * current_center - i], current_right - i);
      }
      while (t[i + f[i]] == t[i - f[i]]) {
        f[i]++;
      }
      if (i + f[i] > current_right) {
        current_right = i + f[i];
        current_center = i;
      }
      if (f[i] > ans_len) {
        ans_len = f[i];
        ans_center = i;
      }
    }
    return s.substr((ans_center - ans_len) / 2, ans_len - 1);
  }
};

TEST(longestPalindrome, example1) {
  string s = "babad", ans = "bab";
  EXPECT_EQ(Solution().longestPalindrome(s), ans);
}

TEST(longestPalindrome, example2) {
  string s = "cbbd", ans = "bb";
  EXPECT_EQ(Solution().longestPalindrome(s), ans);
}

TEST(longestPalindrome, example3) {
  string s = "a", ans = "a";
  EXPECT_EQ(Solution().longestPalindrome(s), ans);
}

TEST(longestPalindrome, example4) {
  string s = "ac", ans = "a";
  EXPECT_EQ(Solution().longestPalindrome(s), ans);
}