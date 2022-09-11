// LeetCode 383. Ransom Note in C++

#include "cpp/src/common/common.h"

class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    vector<int> flag(26, 0);
    for_each(ransomNote.begin(), ransomNote.end(),
             [&](char &ch) { flag[ch - 'a'] += 1; });
    for_each(magazine.begin(), magazine.end(),
             [&](char &ch) { flag[ch - 'a'] -= 1; });
    auto valid = count_if(flag.begin(), flag.end(),
                          [](int &value) { return value > 0; });
    return valid == 0;
  }
};

TEST(canConstruct, example1) {
  string ransomNote = "a", magazine = "b";
  bool ans = false;
  EXPECT_EQ(Solution().canConstruct(ransomNote, magazine), ans);
}

TEST(canConstruct, example2) {
  string ransomNote = "aa", magazine = "ab";
  bool ans = false;
  EXPECT_EQ(Solution().canConstruct(ransomNote, magazine), ans);
}

TEST(canConstruct, example3) {
  string ransomNote = "aa", magazine = "aab";
  bool ans = true;
  EXPECT_EQ(Solution().canConstruct(ransomNote, magazine), ans);
}