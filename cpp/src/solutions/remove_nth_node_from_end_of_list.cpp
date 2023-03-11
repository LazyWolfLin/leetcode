// LeetCode 19. Remove Nth Node From End of List

#include "cpp/src/common/common.h"

/// Create two pointers.First pointer move n nodes and then two pointers move
/// together. When the first pointer arrive the end of list, the second pointer
/// arrive the nth node from the end of list.

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* ptr = new ListNode(0, head);
    ListNode* fast = ptr;
    ListNode* slow = ptr;
    while (n > 0 && fast != nullptr) {
      fast = fast->next;
      n--;
    }
    while (fast->next != nullptr) {
      fast = fast->next;
      slow = slow->next;
    }
    if (slow != nullptr) {
      ListNode* tmp = slow->next;
      slow->next = tmp->next;
      delete tmp;
    }
    return ptr->next;
  }
};

TEST(removeNthFromEnd, example1) {
  ListNode* head = list_create({1, 2, 3, 4, 5});
  int n = 2;
  ListNode* ans = list_create({1, 2, 3, 5});
  EXPECT_TRUE(list_equal(Solution().removeNthFromEnd(head, n), ans));
}

TEST(removeNthFromEnd, example2) {
  ListNode* head = list_create({1});
  int n = 1;
  ListNode* ans = list_create({});
  EXPECT_TRUE(list_equal(Solution().removeNthFromEnd(head, n), ans));
}

TEST(removeNthFromEnd, example3) {
  ListNode* head = list_create({1, 2});
  int n = 1;
  ListNode* ans = list_create({1});
  EXPECT_TRUE(list_equal(Solution().removeNthFromEnd(head, n), ans));
}