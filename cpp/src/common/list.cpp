#include "list.h"

ListNode* list_create(std::initializer_list<int> list) {
  ListNode head;
  ListNode* tail = &head;
  for (auto val : list) {
    tail = list_insert(tail, val);
  }
  return head.next;
}

ListNode* list_insert(ListNode* node, int val) {
  ListNode* new_node = new ListNode(val, node->next);
  node->next = new_node;
  return new_node;
}

bool list_equal(const ListNode* lhs, const ListNode* rhs) {
  while (lhs != nullptr && rhs != nullptr && lhs->val == rhs->val) {
    lhs = lhs->next;
    rhs = rhs->next;
  }
  return lhs == rhs;
}