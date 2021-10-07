// LeetCode 15. 3Sum by C++

#include "common.h"

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (auto i = 0; i < nums.size(); i++) {
      if ((i > 0) && (nums[i] == nums[i - 1])) continue;
      for (int j = i + 1, k = nums.size() - 1; j < k;) {
        if (nums[i] + nums[j] + nums[k] == 0) {
          ans.push_back({nums[i], nums[j], nums[k]});
          j++;
          k--;
          while ((j < k) && (nums[j] == nums[j - 1])) {
            j++;
          }
          while ((j < k) && (nums[k] == nums[k + 1])) {
            k--;
          }
        } else if (nums[i] + nums[j] + nums[k] > 0) {
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