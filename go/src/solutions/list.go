package solutions

type ListNode struct {
	Val  int
	Next *ListNode
}

func listCreate(list []int) *ListNode {
	var head ListNode
	tail := &head
	for _, val := range list {
		tail = listInsert(tail, val)
	}
	return head.Next
}

func listInsert(node *ListNode, val int) *ListNode {
	newNode := &ListNode{Val: val, Next: node.Next}
	node.Next = newNode
	return newNode
}

func listEqual(lhs, rhs *ListNode) bool {
	for lhs != nil && rhs != nil && lhs.Val == rhs.Val {
		lhs = lhs.Next
		rhs = rhs.Next
	}
	return lhs == rhs
}
