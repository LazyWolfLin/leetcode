// LeetCode 206. Reverse Linked List

#include "cpp/src/common/common.h"

class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode dummy(0);
    while (head != nullptr) {
      auto ptr = head;
      head = head->next;
      ptr->next = dummy.next;
      dummy.next = ptr;
    }
    return dummy.next;
  }
};

TEST(reverseList, example1) {
  ListNode* head = list_create({1, 2, 3, 4, 5});
  ListNode* ans = list_create({5, 4, 3, 2, 1});
  EXPECT_TRUE(list_equal(Solution().reverseList(head), ans));
}

TEST(reverseList, example2) {
  ListNode* head = list_create({1, 2});
  ListNode* ans = list_create({2, 1});
  EXPECT_TRUE(list_equal(Solution().reverseList(head), ans));
}

TEST(reverseList, example3) {
  ListNode* head = list_create({});
  ListNode* ans = list_create({});
  EXPECT_TRUE(list_equal(Solution().reverseList(head), ans));
}
