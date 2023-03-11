// LeetCode 977. Squares of a Sorted Array

#include "cpp/src/common/common.h"

class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    for (auto& num : nums) {
      num *= num;
    }
    std::vector<int> ans;
    ans.reserve(nums.size());
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      if (nums[l] >= nums[r]) {
        ans.push_back(nums[l]);
        l++;
      } else {
        ans.push_back(nums[r]);
        r--;
      }
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
  }
};

TEST(sortedSquares, example1) {
  vector<int> nums = {-4, -1, 0, 3, 10};
  vector<int> ans = {0, 1, 9, 16, 100};
  EXPECT_EQ(Solution().sortedSquares(nums), ans);
}

TEST(sortedSquares, example2) {
  vector<int> nums = {-7, -3, 2, 3, 11};
  vector<int> ans = {4, 9, 9, 49, 121};
  EXPECT_EQ(Solution().sortedSquares(nums), ans);
}
