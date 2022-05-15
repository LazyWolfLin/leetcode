// LeetCode 14. Longest Common Prefix in C++

#include "cpp/src/common/common.h"

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0) return "";
    string ans;
    for (auto ch : strs[0]) {
      for (auto& str : strs) {
        if (ans.size() >= str.size() || ch != str[ans.size()]) {
          return ans;
        }
      }
      ans += ch;
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