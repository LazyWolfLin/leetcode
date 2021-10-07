// LeetCode 20. Valid Parentheses by C++

#include "common.h"

class Solution {
 public:
  bool isValid(string s) {
    stack<char> stack;
    for (auto i = 0; i < s.size(); i++) {
      if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
        stack.push(s[i]);
      } else {
        if (stack.empty()) return false;
        if ((s[i] == ')' && stack.top() == '(') ||
            (s[i] == '}' && stack.top() == '{') ||
            (s[i] == ']' && stack.top() == '['))
          stack.pop();
        else
          return false;
      }
    }
    return stack.empty();
  }
};

TEST(isValid, example1) {
  string s = "()";
  bool ans = true;
  EXPECT_EQ(Solution().isValid(s), ans);
}

TEST(isValid, example2) {
  string s = "()[]{}";
  bool ans = true;
  EXPECT_EQ(Solution().isValid(s), ans);
}

TEST(isValid, example3) {
  string s = "(]";
  bool ans = false;
  EXPECT_EQ(Solution().isValid(s), ans);
}

TEST(isValid, example4) {
  string s = "([)]";
  bool ans = false;
  EXPECT_EQ(Solution().isValid(s), ans);
}

TEST(isValid, example5) {
  string s = "{[]}";
  bool ans = true;
  EXPECT_EQ(Solution().isValid(s), ans);
}