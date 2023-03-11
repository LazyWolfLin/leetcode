# LeetCode 4. Median of Two Sorted Arrays

import unittest
from typing import List


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        m = len(nums1)
        n = len(nums2)
        l = 0
        r = m + 1
        half = (m + n + 1) // 2
        i = j = 0
        while l <= r:
            i = (l+r)//2
            j = half - i
            if i > 0 and nums1[i - 1] > nums2[j]:
                r = i
            elif i < m and nums1[i] < nums2[j - 1]:
                l = i
            else:
                break
        ans = 0.0
        if i == 0:
            ans = nums2[j - 1]
        elif j == 0:
            ans = nums1[i - 1]
        else:
            ans = max(nums1[i - 1], nums2[j - 1])
        if (m + n) % 2 == 0:
            if i == m:
                ans += nums2[j]
            elif j == n:
                ans += nums1[i]
            else:
                ans += min(nums1[i], nums2[j])
            ans /= 2
        return ans


class TestFindMedianSortedArrays(unittest.TestCase):
    def testxample1(self):
        nums1 = [1, 3]
        nums2 = [2]
        ans = 2.0
        self.assertEqual(Solution().findMedianSortedArrays(nums1, nums2), ans)

    def testxample2(self):
        nums1 = [1, 2]
        nums2 = [3, 4]
        ans = 2.5
        self.assertEqual(Solution().findMedianSortedArrays(nums1, nums2), ans)

    def testxample3(self):
        nums1 = [0, 0]
        nums2 = [0, 0]
        ans = 0.0
        self.assertEqual(Solution().findMedianSortedArrays(nums1, nums2), ans)

    def testxample4(self):
        nums1 = []
        nums2 = [1]
        ans = 1.0
        self.assertEqual(Solution().findMedianSortedArrays(nums1, nums2), ans)

    def testxample5(self):
        nums1 = [2]
        nums2 = []
        ans = 2.0
        self.assertEqual(Solution().findMedianSortedArrays(nums1, nums2), ans)
