// LeetCode 3. Longest Substring Without Repeating Characters

#include "cpp/src/common/common.h"

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    vector<int> letter(128, 0);
    int ans = 0;
    for (int l = 0, r = 0; r < s.size(); r++) {
      l = max(l, letter[s[r]]);
      ans = max(ans, r - l + 1);
      letter[s[r]] = r + 1;
    }
    return ans;
  }
};

TEST(lengthOfLongestSubstring, example1) {
  string s = "abcabcbb";
  int ans = 3;
  EXPECT_EQ(Solution().lengthOfLongestSubstring(s), ans);
}

TEST(lengthOfLongestSubstring, example2) {
  string s = "bbbbb";
  int ans = 1;
  EXPECT_EQ(Solution().lengthOfLongestSubstring(s), ans);
}

TEST(lengthOfLongestSubstring, example3) {
  string s = "pwwkew";
  int ans = 3;
  EXPECT_EQ(Solution().lengthOfLongestSubstring(s), ans);
}

TEST(lengthOfLongestSubstring, example4) {
  string s = "";
  int ans = 0;
  EXPECT_EQ(Solution().lengthOfLongestSubstring(s), ans);
}
