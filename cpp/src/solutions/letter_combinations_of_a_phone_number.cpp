// LeetCode 17. Letter Combinations of a Phone Number in C++

#include "common.h"

class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    const string letters[10] = {"",    "",    "abc",  "def", "ghi",
                                "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    if (digits.size() == 0) {
      return ans;
    }
    ans = {""};
    for (auto digit : digits) {
      vector<string> tmp;
      auto& letter = letters[digit - '0'];
      for (auto& str : ans) {
        for (auto ch : letter) {
          tmp.push_back(str + ch);
        }
      }
      ans = tmp;
    }
    return ans;
  }
};

TEST(letterCombinations, example1) {
  string digits = "23";
  vector<string> ans = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
  EXPECT_EQ(Solution().letterCombinations(digits), ans);
}

TEST(letterCombinations, example2) {
  string digits = "";
  vector<string> ans;
  EXPECT_EQ(Solution().letterCombinations(digits), ans);
}

TEST(letterCombinations, example3) {
  string digits = "2";
  vector<string> ans = {"a", "b", "c"};
  EXPECT_EQ(Solution().letterCombinations(digits), ans);
}