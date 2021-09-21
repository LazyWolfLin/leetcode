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
    let head = Box::new(ListNode::new(0));
    let mut tail = head.clone();
    for val in list {
        tail = list_insert(&mut tail, val);
    }
    head.next
}

#[allow(dead_code)]
pub fn list_insert(node: &mut Box<ListNode>, val: &i32) -> Box<ListNode> {
    let mut new_node = Box::new(ListNode::new(*val));
    new_node.next = node.next.clone();
    node.next = Some(new_node.clone());
    new_node
}

#[allow(dead_code)]
pub fn list_equal(mut lhs: Option<Box<ListNode>>, mut rhs: Option<Box<ListNode>>) -> bool {
    while lhs.is_some() && rhs.is_some() && lhs.as_ref().unwrap().val == rhs.as_ref().unwrap().val {
        lhs = lhs.unwrap().next;
        rhs = rhs.unwrap().next;
    }
    lhs == rhs
}
