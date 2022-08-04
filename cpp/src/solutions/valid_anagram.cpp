// LeetCode 242. Valid Anagram in C++

#include "cpp/src/common/common.h"

class Solution {
 public:
  bool isAnagram(string s, string t) {
    vector<int> flag(26, 0);
    for_each(s.begin(), s.end(), [&](char &ch) { flag[ch - 'a'] += 1; });
    for_each(t.begin(), t.end(), [&](char &ch) { flag[ch - 'a'] -= 1; });
    auto valid = count_if(flag.begin(), flag.end(),
                          [](int &value) { return value != 0; });
    return valid == 0;
  }
};

TEST(isAnagram, example1) {
  string s = "anagram", t = "nagaram";
  bool ans = true;
  EXPECT_EQ(Solution().isAnagram(s, t), ans);
}

TEST(isAnagram, example2) {
  string s = "rat", t = "car";
  bool ans = false;
  EXPECT_EQ(Solution().isAnagram(s, t), ans);
}
