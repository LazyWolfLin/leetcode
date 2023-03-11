// LeetCode 27. Remove Element

#include "cpp/src/common/common.h"

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    for (auto iter = nums.rbegin(); iter != nums.rend(); iter++) {
      if (*iter == val) {
        std::swap(*iter, *nums.rbegin());
        nums.pop_back();
      }
    }
    return nums.size();
  }
};

TEST(removeElement, example1) {
  vector<int> nums = {3, 2, 2, 3};
  int val = 3;
  int ans = 2;
  EXPECT_EQ(Solution().removeElement(nums, val), ans);
  std::sort(nums.begin(), nums.end());
  EXPECT_EQ(nums, vector<int>({2, 2}));
}

TEST(removeElement, example2) {
  vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
  int val = 2;
  int ans = 5;
  EXPECT_EQ(Solution().removeElement(nums, val), ans);
  std::sort(nums.begin(), nums.end());
  EXPECT_EQ(nums, vector<int>({0, 0, 1, 3, 4}));
}
