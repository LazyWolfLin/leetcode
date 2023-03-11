// LeetCode 16. 3Sum Closest

#include "cpp/src/common/common.h"

class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int ans = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1, k = nums.size() - 1; j < k;) {
        int tmp = nums[i] + nums[j] + nums[k];
        if (tmp == target) {
          return target;
        }
        if (abs(ans - target) > abs(tmp - target)) {
          ans = tmp;
        }
        if (tmp > target) {
          k--;
        } else {
          j++;
        }
      }
    }
    return ans;
  }
};

TEST(threeSumClosest, example1) {
  vector<int> nums = {-1, 2, 1, -4};
  int target = 1, ans = 2;
  EXPECT_EQ(Solution().threeSumClosest(nums, target), ans);
}

TEST(threeSumClosest, example2) {
  vector<int> nums = {0, 0, 0};
  int target = 1, ans = 0;
  EXPECT_EQ(Solution().threeSumClosest(nums, target), ans);
}