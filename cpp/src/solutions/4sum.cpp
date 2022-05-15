// LeetCode 18. 4Sum in C++

#include "cpp/src/common/common.h"

class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (auto i = 0; i < nums.size(); i++) {
      if ((i > 0) && (nums[i] == nums[i - 1])) {
        continue;
      }
      for (auto j = i + 1; j < nums.size(); j++) {
        if ((j > i + 1) && (nums[j] == nums[j - 1])) {
          continue;
        }
        for (int k = j + 1, l = nums.size() - 1; k < l;) {
          if (nums[i] + nums[j] + nums[k] + nums[l] == target) {
            ans.push_back({nums[i], nums[j], nums[k], nums[l]});
            k++;
            l--;
            while ((k < l) && (nums[k] == nums[k - 1])) {
              k++;
            }
            while ((k < l) && (nums[l] == nums[l + 1])) {
              l--;
            }
          } else if (nums[i] + nums[j] + nums[k] + nums[l] > target) {
            l--;
          } else {
            k++;
          }
        }
      }
    }
    return ans;
  }
};

TEST(fourSum, example1) {
  vector<int> nums = {1, 0, -1, 0, -2, 2};
  int target = 0;
  vector<vector<int>> ans = {{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}};
  EXPECT_EQ(Solution().fourSum(nums, target), ans);
}

TEST(fourSum, example2) {
  vector<int> nums = {2,2,2,2};
  int target = 8;
  vector<vector<int>> ans = {{2,2,2,2}};
  EXPECT_EQ(Solution().fourSum(nums, target), ans);
}