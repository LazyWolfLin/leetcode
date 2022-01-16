// LeetCode 19. Remove Nth Node From End of List in Rust

use super::Solution;
use crate::common::ListNode;

/// Create two pointers.First pointer move n nodes and then two pointers move
/// together. When the first pointer arrive the end of list, the second pointer
/// arrive the nth node from the end of list.

impl Solution {
    pub fn remove_nth_from_end(head: Option<Box<ListNode>>, n: i32) -> Option<Box<ListNode>> {
        let mut ptr = Box::new(ListNode::new(0));
        ptr.next = head;
        let (mut fast, mut slow) = (ptr.clone(), ptr.as_mut());
        for _ in 0..n {
            if fast.next.is_some() {
                fast = fast.next.unwrap();
            }
        }
        while fast.next.is_some() {
            fast = fast.next.unwrap();
            slow = slow.next.as_mut().unwrap();
        }
        if slow.next.is_some() {
            let tmp = slow.next.clone().unwrap();
            slow.next = tmp.next.clone();
        }
        ptr.next
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use crate::common::{list_create, list_equal};

    #[test]
    fn example1() {
        let head = list_create(&[1, 2, 3, 4, 5]);
        let n = 2;
        let ans = list_create(&[1, 2, 3, 5]);
        assert!(list_equal(&Solution::remove_nth_from_end(head, n), &ans));
    }
    #[test]
    fn example2() {
        let head = list_create(&[1]);
        let n = 1;
        let ans = list_create(&[]);
        assert!(list_equal(&Solution::remove_nth_from_end(head, n), &ans));
    }
    #[test]
    fn example3() {
        let head = list_create(&[1, 2]);
        let n = 1;
        let ans = list_create(&[1]);
        assert!(list_equal(&Solution::remove_nth_from_end(head, n), &ans));
    }
}