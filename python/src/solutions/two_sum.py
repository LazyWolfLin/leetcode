# LeetCode 1. Two Sum in Python

import unittest
from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        indices = dict()
        for i in range(0, len(nums)):
            if (target - nums[i]) in indices:
                return [indices[target - nums[i]], i]
            else:
                indices[nums[i]] = i
        return []


class TestTwoSum(unittest.TestCase):

    def testExample1(self):
        nums = [2, 7, 11, 15]
        target = 9
        ans = [0, 1]
        self.assertEqual(ans, Solution().twoSum(nums, target))

    def testExample2(self):
        nums = [3, 2, 4]
        target = 6
        ans = [1, 2]
        self.assertEqual(ans, Solution().twoSum(nums, target))

    def testExample3(self):
        nums = [3, 3]
        target = 6
        ans = [0, 1]
        self.assertEqual(ans, Solution().twoSum(nums, target))
