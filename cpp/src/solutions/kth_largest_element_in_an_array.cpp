// LeetCode 215. Kth Largest Element in an Array

#include "cpp/src/common/common.h"

class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    k = k - 1;
    int l = 0, r = nums.size();
    while (l + 1 < r) {
      auto i = l, j = r - 1, num = nums[(l + r) >> 1];
      while (i < j) {
        while (nums[i] > num) {
          i++;
        }
        while (nums[j] < num) {
          j--;
        }
        if (i < j) {
          swap(nums[i], nums[j]);
          i++;
        }
      }
      if (i <= k) {
        l = i;
      } else {
        r = i;
      }
    }
    return nums[k];
  }
};

TEST(findKthLargest, example1) {
  vector<int> nums = {3, 2, 1, 5, 6, 4};
  int k = 2, ans = 5;
  EXPECT_EQ(Solution().findKthLargest(nums, k), ans);
}

TEST(findKthLargest, example2) {
  vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
  int k = 4, ans = 4;
  EXPECT_EQ(Solution().findKthLargest(nums, k), ans);
}