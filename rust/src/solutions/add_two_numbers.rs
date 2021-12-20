// LeetCode 2. Add Two Numbers in Rust

use super::Solution;
use crate::common::ListNode;

impl Solution {
    pub fn add_two_numbers(
        l1: Option<Box<ListNode>>,
        l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let mut head = Box::new(ListNode::new(0));
        let mut tail = &mut head;
        let (mut l1, mut l2) = (l1, l2);
        let mut val: i32 = 0;
        while l1.is_some() || l2.is_some() || val > 0 {
            if let Some(node) = l1 {
                val += node.val;
                l1 = node.next;
            }
            if let Some(node) = l2 {
                val += node.val;
                l2 = node.next;
            }
            tail.next = Some(Box::new(ListNode::new(val % 10)));
            tail = tail.next.as_mut().unwrap();
            val /= 10;
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
        let l1 = list_create(&[2, 4, 3]);
        let l2 = list_create(&[5, 6, 4]);
        let ans = list_create(&[7, 0, 8]);
        assert!(list_equal(&Solution::add_two_numbers(l1, l2), &ans));
    }

    #[test]
    fn example2() {
        let l1 = list_create(&[0]);
        let l2 = list_create(&[0]);
        let ans = list_create(&[0]);
        assert!(list_equal(&Solution::add_two_numbers(l1, l2), &ans));
    }

    #[test]
    fn example3() {
        let l1 = list_create(&[9, 9, 9, 9, 9, 9, 9]);
        let l2 = list_create(&[9, 9, 9, 9]);
        let ans = list_create(&[8, 9, 9, 9, 0, 0, 0, 1]);
        assert!(list_equal(&Solution::add_two_numbers(l1, l2), &ans));
    }
}
