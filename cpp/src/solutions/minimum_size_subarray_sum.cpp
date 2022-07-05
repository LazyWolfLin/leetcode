// LeetCode 209. Minimum Size Subarray Sum in C++

#include "cpp/src/common/common.h"

class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int ans = nums.size() + 1, sum = 0;
    for (auto l = 0, r = 0; r < nums.size(); r++) {
      sum += nums[r];
      while (sum >= target) {
        ans = std::min(r - l + 1, ans);
        sum -= nums[l];
        l++;
      }
    }
    if (ans > nums.size()) {
      ans = 0;
    }
    return ans;
  }
};

TEST(minSubArrayLen, example1) {
  vector<int> nums = {2, 3, 1, 2, 4, 3};
  int target = 7;
  int ans = 2;
  EXPECT_EQ(Solution().minSubArrayLen(target, nums), ans);
}

TEST(minSubArrayLen, example2) {
  vector<int> nums = {1, 4, 4};
  int target = 4;
  int ans = 1;
  EXPECT_EQ(Solution().minSubArrayLen(target, nums), ans);
}

TEST(minSubArrayLen, example3) {
  vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1};
  int target = 11;
  int ans = 0;
  EXPECT_EQ(Solution().minSubArrayLen(target, nums), ans);
}