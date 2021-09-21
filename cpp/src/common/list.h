#pragma once

#include <initializer_list>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *list_create(std::initializer_list<int> list);

ListNode *list_insert(ListNode *node, int val);

bool list_equal(const ListNode *lhs, const ListNode *rhs);