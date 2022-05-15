# LeetCode 2. Add Two Numbers in Python

import unittest
from typing import Optional

from common.list import *


class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        head = tail = ListNode()
        val = 0
        while l1 or l2 or val > 0:
            if l1:
                val += l1.val
                l1 = l1.next
            if l2:
                val += l2.val
                l2 = l2.next
            tail.next = ListNode(val % 10)
            tail = tail.next
            val //= 10
        return head.next


class TestAddTwoNumbers(unittest.TestCase):

    def testExample1(self):
        l1 = list_create([2, 4, 3])
        l2 = list_create([5, 6, 4])
        ans = list_create([7, 0, 8])
        self.assertTrue(list_equal(Solution().addTwoNumbers(l1, l2), ans))

    def testExample2(self):
        l1 = list_create([0])
        l2 = list_create([0])
        ans = list_create([0])
        self.assertTrue(list_equal(Solution().addTwoNumbers(l1, l2), ans))

    def testExample3(self):
        l1 = list_create([9, 9, 9, 9, 9, 9, 9])
        l2 = list_create([9, 9, 9, 9])
        ans = list_create([8, 9, 9, 9, 0, 0, 0, 1])
        self.assertTrue(list_equal(Solution().addTwoNumbers(l1, l2), ans))
