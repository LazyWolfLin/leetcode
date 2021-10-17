// LeetCode 17. Letter Combinations of a Phone Number in C++

#include "common.h"

class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    static string letter[10] = {"",    "",    "abc",  "def", "ghi",
                                "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    if (digits.length() > 0) {
      vector<string> tmp = letterCombinations(digits.substr(1));
      if (tmp.size() == 0) {
        tmp = {""};
      }
      auto& letters = letter[digits[0] - '0'];
      for (auto i = 0; i < letters.size(); i++) {
        for (auto j = 0; j < tmp.size(); j++) {
          ans.push_back(letters[i] + tmp[j]);
        }
      }
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