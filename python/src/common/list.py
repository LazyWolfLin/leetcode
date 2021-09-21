from typing import List, Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def list_create(list: List) -> Optional[ListNode]:
    head = tail = ListNode()
    for val in list:
        tail = list_insert(tail, val)
    return head.next


def list_insert(node: Optional[ListNode], val) -> Optional[ListNode]:
    new_node = ListNode(val, node.next)
    node.next = new_node
    return new_node


def list_equal(lhs: Optional[ListNode], rhs: Optional[ListNode]) -> bool:
    while lhs and rhs and lhs.val == rhs.val:
        lhs = lhs.next
        rhs = rhs.next
    return lhs == rhs
