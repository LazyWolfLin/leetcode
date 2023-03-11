# LeetCode 9. Palindrome Number

import unittest


class Solution:
    def isPalindrome(self, x: int) -> bool:
        x = str(x)
        return x == x[::-1]


class TestIsPalindrome(unittest.TestCase):

    def testExample1(self):
        x = 121
        ans = True
        self.assertEqual(Solution().isPalindrome(x), ans)

    def testExample2(self):
        x = 1121
        ans = False
        self.assertEqual(Solution().isPalindrome(x), ans)

    def testExample3(self):
        x = 10
        ans = False
        self.assertEqual(Solution().isPalindrome(x), ans)

    def testExample4(self):
        x = -101
        ans = False
        self.assertEqual(Solution().isPalindrome(x), ans)
