// LeetCode 21. Merge Two Sorted Lists by C++

#include "common.h"

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode head, *p = &head;
    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val < l2->val) {
        p->next = l1;
        l1 = l1->next;
      } else {
        p->next = l2;
        l2 = l2->next;
      }
      p = p->next;
    }
    if (l1 != nullptr) {
      p->next = l1;
    }
    if (l2 != nullptr) {
      p->next = l2;
    }
    return head.next;
  }
};

TEST(mergeTwoLists, example1) {
  auto l1 = list_create({1, 2, 4});
  auto l2 = list_create({1, 3, 4});
  auto ans = list_create({1, 1, 2, 3, 4, 4});
  EXPECT_TRUE(list_equal(Solution().mergeTwoLists(l1, l2), ans));
}

TEST(mergeTwoLists, example2) {
  auto l1 = list_create({});
  auto l2 = list_create({});
  auto ans = list_create({});
  EXPECT_TRUE(list_equal(Solution().mergeTwoLists(l1, l2), ans));
}

TEST(mergeTwoLists, example3) {
  auto l1 = list_create({});
  auto l2 = list_create({0});
  auto ans = list_create({0});
  EXPECT_TRUE(list_equal(Solution().mergeTwoLists(l1, l2), ans));
}