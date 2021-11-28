// LeetCode 15. 3Sum in C++

#include "common.h"

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (auto i = 0; i < nums.size(); i++) {
      auto x = nums[i];
      if ((i > 0) && (x == nums[i - 1])) continue;
      for (int j = i + 1, k = nums.size() - 1; j < k;) {
        auto y = nums[j], z = nums[k];
        if (-x == y + z) {
          ans.push_back({x, y, z});
          while ((j < k) && (y == nums[j])) {
            j++;
          }
          while ((j < k) && (z == nums[k])) {
            k--;
          }
        } else if (-x < y + z) {
          k--;
        } else {
          j++;
        }
      }
    }
    return ans;
  }
};

TEST(threeSum, example1) {
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> ans = {{-1, -1, 2}, {-1, 0, 1}};
  EXPECT_EQ(Solution().threeSum(nums), ans);
}

TEST(threeSum, example2) {
  vector<int> nums;
  vector<vector<int>> ans;
  EXPECT_EQ(Solution().threeSum(nums), ans);
}

TEST(threeSum, example3) {
  vector<int> nums = {0};
  vector<vector<int>> ans;
  EXPECT_EQ(Solution().threeSum(nums), ans);
}