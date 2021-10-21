# LeetCode 3. Longest Substring Without Repeating Characters in Python

import unittest


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        letter = [0] * 128
        ans = 0
        l = 0
        for r, ch in enumerate(s):
            l = max(l, letter[ord(ch)])
            ans = max(ans, r - l + 1)
            letter[ord(ch)] = r + 1
        return ans


class TestLengthOfLongestSubstring(unittest.TestCase):
    def testExample1(self):
        s = "abcabcbb"
        ans = 3
        self.assertEqual(Solution().lengthOfLongestSubstring(s), ans)

    def testExample2(self):
        s = "bbbbb"
        ans = 1
        self.assertEqual(Solution().lengthOfLongestSubstring(s), ans)

    def testExample3(self):
        s = "pwwkew"
        ans = 3
        self.assertEqual(Solution().lengthOfLongestSubstring(s), ans)

    def testExample4(self):
        s = ""
        ans = 0
        self.assertEqual(Solution().lengthOfLongestSubstring(s), ans)
