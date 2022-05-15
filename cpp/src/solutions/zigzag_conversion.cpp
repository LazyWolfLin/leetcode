// LeetCode 6. ZigZag Conversion in C++

#include "cpp/src/common/common.h"

class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1 || numRows > s.size()) return s;
    string ans;
    ans.reserve(s.size());
    for (auto i = 0; i < numRows; i++) {
      auto key = (numRows - i - 1) * 2;
      auto j = i;
      while (j < s.size()) {
        ans += s[j];
        if (i != 0 && key != 0 && j + key < s.size()) {
          ans += s[j + key];
        }
        j += key + 2 * i;
      }
    }
    return ans;
  }
};

TEST(convert, example1) {
  string s = "PAYPALISHIRING", ans = "PAHNAPLSIIGYIR";
  int numRows = 3;
  EXPECT_EQ(Solution().convert(s, numRows), ans);
}

TEST(convert, example2) {
  string s = "PAYPALISHIRING", ans = "PINALSIGYAHRPI";
  int numRows = 4;
  EXPECT_EQ(Solution().convert(s, numRows), ans);
}

TEST(convert, example3) {
  string s = "A", ans = "A";
  int numRows = 1;
  EXPECT_EQ(Solution().convert(s, numRows), ans);
}
