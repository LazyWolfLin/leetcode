// LeetCode 203. Remove Linked List Elements in Rust

use super::Solution;
use crate::common::ListNode;

// impl Solution {
//     pub fn remove_elements(head: Option<Box<ListNode>>, val: i32) -> Option<Box<ListNode>> {
//         let mut dummy = Box::new(ListNode::new(0));
//         dummy.next = head;
//         let mut ptr = &mut dummy;
//         while ptr.next.is_some() {
//             if ptr.next.as_ref().unwrap().val == val{
//                 ptr.next = ptr.next.as_mut().unwrap().next.take();
//             } else {
//                 ptr = ptr.next.as_mut().unwrap();
//             }
//         }
//         dummy.next
//     }
// }

impl Solution {
    pub fn remove_elements(head: Option<Box<ListNode>>, val: i32) -> Option<Box<ListNode>> {
        let mut head = head;
        let mut ans = None;
        let mut tail = &mut ans;
        while let Some(mut node) = head.take() {
            head = node.next.take();
            if node.val != val {
                tail = &mut tail.insert(node).next;
            }
        }
        ans
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use crate::common::{list_create, list_equal};

    #[test]
    fn example1() {
        let head = list_create(&[1, 2, 6, 3, 4, 5, 6]);
        let val = 6;
        let ans = list_create(&[1, 2, 3, 4, 5]);
        assert!(list_equal(&Solution::remove_elements(head, val), &ans));
    }
    #[test]
    fn example2() {
        let head = list_create(&[]);
        let val = 1;
        let ans = list_create(&[]);
        assert!(list_equal(&Solution::remove_elements(head, val), &ans));
    }
    #[test]
    fn example3() {
        let head = list_create(&[7, 7, 7, 7]);
        let val = 7;
        let ans = list_create(&[]);
        assert!(list_equal(&Solution::remove_elements(head, val), &ans));
    }
}
