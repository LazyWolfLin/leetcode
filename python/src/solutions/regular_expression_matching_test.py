# LeetCode 10. Regular Expression Matching in Python

import unittest


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        dp = [[False] * (len(p) + 1) for i in range(len(s) + 1)]
        dp[len(s)][len(p)] = True
        for i in range(len(s), -1, -1):
            for j in range(len(p) - 1, -1, -1):
                dp[i][j] = i < len(s) and p[j] in {s[i], '.'}
                if j + 1 < len(p) and p[j + 1] == '*':
                    dp[i][j] = dp[i][j + 2] or (dp[i][j] and dp[i + 1][j])
                else:
                    dp[i][j] = dp[i][j] and dp[i + 1][j + 1]
        return dp[0][0]


class TestIsMatch(unittest.TestCase):

    def testExample1(self):
        s = "aa"
        p = "a"
        ans = False
        self.assertEqual(Solution().isMatch(s, p), ans)

    def testExample2(self):
        s = "aa"
        p = "a*"
        ans = True
        self.assertEqual(Solution().isMatch(s, p), ans)

    def testExample3(self):
        s = "ab"
        p = ".*"
        ans = True
        self.assertEqual(Solution().isMatch(s, p), ans)

    def testExample4(self):
        s = "aab"
        p = "c*a*b"
        ans = True
        self.assertEqual(Solution().isMatch(s, p), ans)

    def testExample5(self):
        s = "mississippi"
        p = "mis*is*p*."
        ans = False
        self.assertEqual(Solution().isMatch(s, p), ans)
