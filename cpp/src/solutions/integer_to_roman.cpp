// LeetCode 12. Integer to Roman by C++

#include "common.h"

class Solution {
 public:
  string intToRoman(int num) {
    string table[4][10] = {
        {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
        {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
        {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
        {"", "M", "MM", "MMM", "", "", "", "", "", ""}};
    string ans;
    int i = 0;
    while (num) {
      ans = table[i++][num % 10] + ans;
      num = num / 10;
    }
    return ans;
  }
};

TEST(intToRoman, example1) {
  int nums = 3;
  string ans = "III";
  EXPECT_EQ(Solution().intToRoman(nums), ans);
}

TEST(intToRoman, example2) {
  int nums = 4;
  string ans = "IV";
  EXPECT_EQ(Solution().intToRoman(nums), ans);
}

TEST(intToRoman, example3) {
  int nums = 9;
  string ans = "IX";
  EXPECT_EQ(Solution().intToRoman(nums), ans);
}

TEST(intToRoman, example4) {
  int nums = 58;
  string ans = "LVIII";
  EXPECT_EQ(Solution().intToRoman(nums), ans);
}

TEST(intToRoman, example5) {
  int nums = 1994;
  string ans = "MCMXCIV";
  EXPECT_EQ(Solution().intToRoman(nums), ans);
}