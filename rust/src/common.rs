use std::borrow::Borrow;

#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

#[allow(dead_code)]
pub fn list_create(list: &[i32]) -> Option<Box<ListNode>> {
    let mut head = Box::new(ListNode::new(0));
    let mut tail = head.as_mut();
    for val in list {
        list_insert(tail, val);
        tail = tail.next.as_mut().unwrap();
    }
    head.next
}

#[allow(dead_code)]
pub fn list_insert(node: &mut ListNode, val: &i32) {
    node.next = Some(Box::new(ListNode::new(*val)));
}

#[allow(dead_code)]
pub fn list_equal(lhs: &Option<Box<ListNode>>, rhs: &Option<Box<ListNode>>) -> bool {
    let (mut lhs, mut rhs) = (lhs, rhs);
    while lhs.is_some() && rhs.is_some() && lhs.as_ref().unwrap().val == rhs.as_ref().unwrap().val {
        lhs = lhs.as_ref().unwrap().next.borrow();
        rhs = rhs.as_ref().unwrap().next.borrow();
    }
    lhs == rhs
}
