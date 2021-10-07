// LeetCode 14. Longest Common Prefix by C++

#include "common.h"

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    string ans = "";
    if (strs.size() == 0) return ans;
    for (int i = 0; i < strs[0].size(); i++) {
      for (int j = 1; j < strs.size(); j++) {
        if (strs[0][i] != strs[j][i]) {
          return ans;
        }
      }
      ans += strs[0][i];
    }
    return ans;
  }
};

TEST(longestCommonPrefix, example1) {
  vector<string> strs = {"flower", "flow", "flight"};
  string ans = "fl";
  EXPECT_EQ(Solution().longestCommonPrefix(strs), ans);
}

TEST(longestCommonPrefix, example2) {
  vector<string> strs = {"dog", "racecar", "car"};
  string ans = "";
  EXPECT_EQ(Solution().longestCommonPrefix(strs), ans);
}