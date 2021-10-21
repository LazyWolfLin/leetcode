# LeetCode 8. String to Integer (atoi) in Python

import unittest


class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.lstrip()
        positive = True
        if len(s) > 0 and (s[0] == '+' or s[0] == '-'):
            positive = (s[0] == '+')
            s = s[1:]
        i = 0
        while i < len(s):
            if str.isdigit(s[i]):
                i += 1
            else:
                break
        s = s[:i]
        if len(s) == 0:
            return 0
        ans = int(s)
        if ans >= 2**31:
            ans = 2**31 if not positive else 2**31-1
        return ans if positive else -ans


class TestMyAtoi(unittest.TestCase):

    def testExample1(self):
        str = "42"
        ans = 42
        self.assertEqual(Solution().myAtoi(str), ans)

    def testExample2(self):
        str = "-42"
        ans = -42
        self.assertEqual(Solution().myAtoi(str), ans)

    def testExample3(self):
        str = "4193 with words"
        ans = 4193
        self.assertEqual(Solution().myAtoi(str), ans)

    def testExample4(self):
        str = "words and 987"
        ans = 0
        self.assertEqual(Solution().myAtoi(str), ans)

    def testExample5(self):
        str = "-91283472332"
        ans = -2147483648
        self.assertEqual(Solution().myAtoi(str), ans)
