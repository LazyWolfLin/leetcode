# LeetCode 6. ZigZag Conversion in Python

import unittest


class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1 or numRows >= len(s):
            return s
        ans = str()
        for i in range(0, numRows):
            key = (numRows - i - 1) * 2
            j = i
            while j < len(s):
                ans += s[j]
                if i != 0 and key != 0 and j + key < len(s):
                    ans += s[j + key]
                j += key + 2 * i
        return ans


class TestConvert(unittest.TestCase):

    def testExample1(self):
        s = "PAYPALISHIRING"
        ans = "PAHNAPLSIIGYIR"
        numRows = 3
        self.assertEqual(Solution().convert(s, numRows), ans)

    def testExample2(self):
        s = "PAYPALISHIRING"
        ans = "PINALSIGYAHRPI"
        numRows = 4
        self.assertEqual(Solution().convert(s, numRows), ans)

    def testExample3(self):
        s = "A"
        ans = "A"
        numRows = 1
        self.assertEqual(Solution().convert(s, numRows), ans)
