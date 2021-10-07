// LeetCode 4. Median of Two Sorted Arrays by C++

#include "common.h"

class Solution {
 public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    if (nums1.size() > nums2.size()) {
      swap(nums1, nums2);
    }
    int m = nums1.size(), n = nums2.size();
    int l = 0, r = m + 1, half = (m + n + 1) / 2;
    int i, j;
    while (l <= r) {
      i = (l + r) / 2, j = half - i;
      if (i > 0 && nums1[i - 1] > nums2[j]) {
        r = i;
      } else if (i < m && nums1[i] < nums2[j - 1]) {
        l = i;
      } else
        break;
    }
    double ans = 0.0f;
    if (i == 0) {
      ans = nums2[j - 1];
    } else if (j == 0) {
      ans = nums1[i - 1];
    } else {
      ans = max(nums1[i - 1], nums2[j - 1]);
    }
    if ((m + n) % 2 == 0) {
      if (i == m) {
        ans += nums2[j];
      } else if (j == n) {
        ans += nums1[i];
      } else {
        ans += min(nums1[i], nums2[j]);
      }
      ans /= 2.0f;
    }
    return ans;
  }
};

TEST(findMedianSortedArrays, example1) {
  vector<int> nums1 = {1, 3}, nums2 = {2};
  double ans = 2.0f;
  EXPECT_EQ(Solution().findMedianSortedArrays(nums1, nums2), ans);
}

TEST(findMedianSortedArrays, example2) {
  vector<int> nums1 = {1, 2}, nums2 = {3, 4};
  double ans = 2.5f;
  EXPECT_EQ(Solution().findMedianSortedArrays(nums1, nums2), ans);
}

TEST(findMedianSortedArrays, example3) {
  vector<int> nums1 = {0, 0}, nums2 = {0, 0};
  double ans = 0.0f;
  EXPECT_EQ(Solution().findMedianSortedArrays(nums1, nums2), ans);
}

TEST(findMedianSortedArrays, example4) {
  vector<int> nums1, nums2 = {1};
  double ans = 1.0f;
  EXPECT_EQ(Solution().findMedianSortedArrays(nums1, nums2), ans);
}

TEST(findMedianSortedArrays, example5) {
  vector<int> nums1 = {2}, nums2;
  double ans = 2.0f;
  EXPECT_EQ(Solution().findMedianSortedArrays(nums1, nums2), ans);
}