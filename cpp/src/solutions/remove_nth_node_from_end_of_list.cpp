// LeetCode 19. Remove Nth Node From End of List in C++

#include "common.h"

/// Create two pointers.First pointer move n nodes and then two pointers move
/// together. When the first pointer arrive the end of list, the second pointer
/// arrive the nth node from the end of list.

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *quick = head, *slow = head;
    while (n > 0 && quick != nullptr) {
      quick = quick->next;
      n--;
    }
    ListNode *tmp = head;
    if (quick == nullptr) {
      head = head->next;
    } else {
      while (quick->next != nullptr) {
        quick = quick->next;
        slow = slow->next;
      }
      tmp = slow->next;
      slow->next = slow->next->next;
    }
    delete tmp;
    return head;
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