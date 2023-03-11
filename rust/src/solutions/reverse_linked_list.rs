// LeetCode 206. Reverse Linked List

use super::Solution;
use crate::common::ListNode;

impl Solution {
    pub fn reverse_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut head = head;
        let mut dummy = ListNode::new(0);
        while let Some(mut node) = head {
            head = node.next;
            node.next = dummy.next;
            dummy.next = Some(node);
        }
        dummy.next
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use crate::common::{list_create, list_equal};

    #[test]
    fn example1() {
        let head = list_create(&[1, 2, 3, 4, 5]);
        let ans = list_create(&[5, 4, 3, 2, 1]);
        assert!(list_equal(&Solution::reverse_list(head), &ans));
    }
    #[test]
    fn example2() {
        let head = list_create(&[1, 2]);
        let ans = list_create(&[2, 1]);
        assert!(list_equal(&Solution::reverse_list(head), &ans));
    }
    #[test]
    fn example3() {
        let head = list_create(&[]);
        let ans = list_create(&[]);
        assert!(list_equal(&Solution::reverse_list(head), &ans));
    }
}
