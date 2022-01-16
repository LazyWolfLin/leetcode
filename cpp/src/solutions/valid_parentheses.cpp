// LeetCode 20. Valid Parentheses in C++

#include "cpp/src/common/common.h"

class Solution {
 public:
  bool isValid(string s) {
    stack<char> stack;
    for (auto ch : s) {
      if (ch == '(' || ch == '{' || ch == '[') {
        stack.push(ch);
      } else if (!stack.empty() && ((ch == ')' && stack.top() == '(') ||
                                    (ch == '}' && stack.top() == '{') ||
                                    (ch == ']' && stack.top() == '['))) {
        stack.pop();
      } else {
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