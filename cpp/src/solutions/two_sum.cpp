// LeetCode 1. Two Sum in C++

#include "cpp/src/common/common.h"

class Solution {
 public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> indices;
    for (size_t i = 0; i < nums.size(); i++) {
      auto iter = indices.find(target - nums[i]);
      if (iter != indices.end()) return {iter->second, static_cast<int>(i)};
      indices[nums[i]] = i;
    }
    return {};
  }
};

TEST(twoSum, example1) {
  vector<int> nums = {2, 7, 11, 15}, ans = {0, 1};
  int target = 9;
  EXPECT_EQ(Solution().twoSum(nums, target), ans);
}

TEST(twoSum, example2) {
  vector<int> nums = {3, 2, 4}, ans = {1, 2};
  int target = 6;
  EXPECT_EQ(Solution().twoSum(nums, target), ans);
}

TEST(twoSum, example3) {
  vector<int> nums = {3, 3}, ans = {0, 1};
  int target = 6;
  EXPECT_EQ(Solution().twoSum(nums, target), ans);
}