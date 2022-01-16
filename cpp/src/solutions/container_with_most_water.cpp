// LeetCode 11. Container With Most Water in C++

#include "cpp/src/common/common.h"

class Solution {
 public:
  int maxArea(vector<int>& height) {
    int l = 0, r = height.size() - 1, ans = 0;
    while (l < r) {
      auto low = min(height[l], height[r]);
      ans = max(ans, (r - l) * low);
      while (l < r && height[l] <= low) {
        l++;
      }
      while (l < r && height[r] <= low) {
        r--;
      }
    }
    return ans;
  }
};

TEST(maxArea, example1) {
  vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  int ans = 49;
  EXPECT_EQ(Solution().maxArea(height), ans);
}

TEST(maxArea, example2) {
  vector<int> height = {1, 1};
  int ans = 1;
  EXPECT_EQ(Solution().maxArea(height), ans);
}

TEST(maxArea, example3) {
  vector<int> height = {4, 3, 2, 1, 4};
  int ans = 16;
  EXPECT_EQ(Solution().maxArea(height), ans);
}

TEST(maxArea, example4) {
  vector<int> height = {1, 2, 1};
  int ans = 2;
  EXPECT_EQ(Solution().maxArea(height), ans);
}