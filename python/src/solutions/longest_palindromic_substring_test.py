# LeetCode 5. Longest Palindromic Substring
# Manacher Algorithms


import unittest


class Solution:
    def longestPalindrome(self, s: str) -> str:
        t = "$#"
        for i in range(0, len(s)):
            t += s[i]
            t += '#'
        t += '!'
        f = [1] * (len(t) - 1)
        current_center = current_right = ans_len = ans_center = 0
        for i in range(1, len(t) - 1):
            if current_right > 1:
                f[i] = min(f[2 * current_center - i], current_right - i)
            while t[i + f[i]] == t[i - f[i]]:
                f[i] += 1
            if i + f[i] > current_right:
                current_right = i + f[i]
                current_center = i
            if f[i] > ans_len:
                ans_len = f[i]
                ans_center = i
        return s[(ans_center - ans_len) // 2: (ans_center + ans_len) // 2 - 1]


class TestLongestPalindrome(unittest.TestCase):

    def testExample1(self):
        s = "babad"
        ans = "bab"
        self.assertEqual(Solution().longestPalindrome(s), ans)

    def testExample2(self):
        s = "cbbd"
        ans = "bb"
        self.assertEqual(Solution().longestPalindrome(s), ans)

    def testExample3(self):
        s = "a"
        ans = "a"
        self.assertEqual(Solution().longestPalindrome(s), ans)

    def testExample4(self):
        s = "ac"
        ans = "a"
        self.assertEqual(Solution().longestPalindrome(s), ans)
