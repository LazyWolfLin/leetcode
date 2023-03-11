// LeetCode 203. Remove Linked List Elements

#include "cpp/src/common/common.h"

class Solution {
 public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode dummy(0, head);
    ListNode* ptr = &dummy;
    while (ptr->next != nullptr) {
      if (ptr->next->val == val) {
        auto tmp = ptr->next;
        ptr->next = tmp->next;
        delete tmp;
      } else {
        ptr = ptr->next;
      }
    }
    return dummy.next;
  }
};

TEST(removeElements, example1) {
  ListNode* head = list_create({1, 2, 6, 3, 4, 5, 6});
  int val = 6;
  ListNode* ans = list_create({1, 2, 3, 4, 5});
  EXPECT_TRUE(list_equal(Solution().removeElements(head, val), ans));
}

TEST(removeElements, example2) {
  ListNode* head = list_create({});
  int val = 1;
  ListNode* ans = list_create({});
  EXPECT_TRUE(list_equal(Solution().removeElements(head, val), ans));
}

TEST(removeElements, example3) {
  ListNode* head = list_create({7, 7, 7, 7});
  int val = 7;
  ListNode* ans = list_create({});
  EXPECT_TRUE(list_equal(Solution().removeElements(head, val), ans));
}
