# LeetCode 7. Reverse Integer in Python

import unittest


class Solution:
    def reverse(self, x: int) -> int:
        ans = 0
        if x > 0:
            ans = int(str(x)[::-1])
        if x < 0:
            ans = int("-" + str(-x)[::-1])
        return ans if ans >= -2**31 and ans <= 2**31-1 else 0

class TestReverse(unittest.TestCase):

    def testExample1(self):
        x = 123
        ans = 321
        self.assertEqual(Solution().reverse(x), ans)

    def testExample2(self):
        x = -123
        ans = -321
        self.assertEqual(Solution().reverse(x), ans)

    def testExample3(self):
        x = 120
        ans = 21
        self.assertEqual(Solution().reverse(x), ans)

    def testExample4(self):
        x = 0
        ans = 0
        self.assertEqual(Solution().reverse(x), ans)
