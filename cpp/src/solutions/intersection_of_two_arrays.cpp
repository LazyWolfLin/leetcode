// LeetCode 349. Intersection of Two Arrays

#include "cpp/src/common/common.h"

class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    unordered_set<int> flag;
    for (auto num : nums1) {
      flag.insert(num);
    }
    for (auto num : nums2) {
      if (flag.find(num) != flag.end()) {
        ans.push_back(num);
        flag.erase(num);
      }
    }
    return ans;
  }
};

TEST(intersection, example1) {
  vector<int> nums1 = {1, 2, 2, 1};
  vector<int> nums2 = {2, 2};
  vector<int> ans = {2};
  auto nums = Solution().intersection(nums1, nums2);
  std::sort(nums.begin(), nums.end());
  EXPECT_EQ(nums, ans);
}

TEST(intersection, example2) {
  vector<int> nums1 = {4, 9, 5};
  vector<int> nums2 = {9, 4, 9, 8, 4};
  vector<int> ans = {4, 9};
  auto nums = Solution().intersection(nums1, nums2);
  std::sort(nums.begin(), nums.end());
  EXPECT_EQ(nums, ans);
}
