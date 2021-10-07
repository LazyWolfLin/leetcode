// LeetCode 2. Add Two Numbers in C++

#include "common.h"

class Solution {
 public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode head, *tail = &head;
    int val = 0;
    while (l1 != nullptr || l2 != nullptr || val > 0) {
      if (l1 != nullptr) {
        val += l1->val;
        l1 = l1->next;
      }
      if (l2 != nullptr) {
        val += l2->val;
        l2 = l2->next;
      }
      tail->next = new ListNode(val % 10);
      tail = tail->next;
      val /= 10;
    }
    return head.next;
  }
};

TEST(addTwoNumbers, example1) {
  auto l1 = list_create({2, 4, 3});
  auto l2 = list_create({5, 6, 4});
  auto ans = list_create({7, 0, 8});
  EXPECT_TRUE(list_equal(Solution().addTwoNumbers(l1, l2), ans));
}

TEST(addTwoNumbers, example2) {
  auto l1 = list_create({0});
  auto l2 = list_create({0});
  auto ans = list_create({0});
  EXPECT_TRUE(list_equal(Solution().addTwoNumbers(l1, l2), ans));
}

TEST(addTwoNumbers, example3) {
  auto l1 = list_create({9, 9, 9, 9, 9, 9, 9});
  auto l2 = list_create({9, 9, 9, 9});
  auto ans = list_create({8, 9, 9, 9, 0, 0, 0, 1});
  EXPECT_TRUE(list_equal(Solution().addTwoNumbers(l1, l2), ans));
}