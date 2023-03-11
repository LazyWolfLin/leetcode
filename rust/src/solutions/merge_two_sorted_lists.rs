// LeetCode 21. Merge Two Sorted Lists

use super::Solution;
use crate::common::ListNode;

impl Solution {
    pub fn merge_two_lists(
        list1: Option<Box<ListNode>>,
        list2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let (mut list1, mut list2) = (list1.as_ref(), list2.as_ref());
        let mut head = Box::new(ListNode::new(0));
        let mut ptr = &mut head;
        while let (Some(l1), Some(l2)) = (list1, list2) {
            if l1.val < l2.val {
                ptr.next = list1.cloned();
                list1 = l1.next.as_ref().clone();
            } else {
                ptr.next = list2.cloned();
                list2 = l2.next.as_ref().clone();
            }
            ptr = ptr.next.as_mut().unwrap();
        }
        if list1.is_some() {
            ptr.next = list1.cloned();
        }
        if list2.is_some() {
            ptr.next = list2.cloned();
        }
        head.next
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use crate::common::{list_create, list_equal};

    #[test]
    fn example1() {
        let l1 = list_create(&[1, 2, 4]);
        let l2 = list_create(&[1, 3, 4]);
        let ans = list_create(&[1, 1, 2, 3, 4, 4]);
        assert!(list_equal(&Solution::merge_two_lists(l1, l2), &ans));
    }

    #[test]
    fn example2() {
        let l1 = list_create(&[]);
        let l2 = list_create(&[]);
        let ans = list_create(&[]);
        assert!(list_equal(&Solution::merge_two_lists(l1, l2), &ans));
    }

    #[test]
    fn example3() {
        let l1 = list_create(&[]);
        let l2 = list_create(&[0]);
        let ans = list_create(&[0]);
        assert!(list_equal(&Solution::merge_two_lists(l1, l2), &ans));
    }
}
