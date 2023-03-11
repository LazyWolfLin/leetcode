// LeetCode 704. Binary Search

#include "cpp/src/common/common.h"

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int ans = -1;
    int l = 0, r = nums.size();
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] == target) {
        ans = mid;
        break;
      } else if (nums[mid] < target) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    return ans;
  }
};

TEST(search, example1) {
  vector<int> nums = {-1, 0, 3, 5, 9, 12};
  int target = 9;
  int ans = 4;
  EXPECT_EQ(Solution().search(nums, target), ans);
}

TEST(search, example2) {
  vector<int> nums = {-1, 0, 3, 5, 9, 12};
  int target = 2;
  int ans = -1;
  EXPECT_EQ(Solution().search(nums, target), ans);
}