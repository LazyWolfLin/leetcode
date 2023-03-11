// LeetCode 454. 4Sum II

#include "cpp/src/common/common.h"

class Solution {
 public:
  int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                   vector<int>& nums4) {
    int ans = 0;
    unordered_map<int, int> sum;
    for (auto num1 : nums1) {
      for (auto num2 : nums2) {
        sum[num1 + num2] += 1;
      }
    }
    for (auto&& num3 : nums3) {
      for (auto&& num4 : nums4) {
        ans += sum[-(num3 + num4)];
      }
    }
    return ans;
  }
};

TEST(fourSumCount, example1) {
  vector<int> nums1 = {1, 2}, nums2 = {-2, -1}, nums3 = {-1, 2}, nums4 = {0, 2};
  int ans = 2;
  EXPECT_EQ(Solution().fourSumCount(nums1, nums2, nums3, nums4), ans);
}

TEST(fourSumCount, example2) {
  vector<int> nums1 = {0}, nums2 = {0}, nums3 = {0}, nums4 = {0};
  int ans = 1;
  EXPECT_EQ(Solution().fourSumCount(nums1, nums2, nums3, nums4), ans);
}