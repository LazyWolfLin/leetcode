// LeetCode 2. Add Two Numbers

package solutions

import (
	"testing"
)

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var head ListNode
	tail := &head
	var val int
	for l1 != nil || l2 != nil || val > 0 {
		if l1 != nil {
			val += l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			val += l2.Val
			l2 = l2.Next
		}
		tail.Next = &ListNode{Val: val % 10}
		tail = tail.Next
		val /= 10
	}
	return head.Next
}

func TestAddTwoNumbers(t *testing.T) {
	var tests = []struct {
		l1  *ListNode
		l2  *ListNode
		ans *ListNode
	}{
		{
			listCreate([]int{2, 4, 3}),
			listCreate([]int{5, 6, 4}),
			listCreate([]int{7, 0, 8}),
		},
		{
			listCreate([]int{0}),
			listCreate([]int{0}),
			listCreate([]int{0}),
		},
		{
			listCreate([]int{9, 9, 9, 9, 9, 9, 9}),
			listCreate([]int{9, 9, 9, 9}),
			listCreate([]int{8, 9, 9, 9, 0, 0, 0, 1}),
		},
	}

	for _, test := range tests {
		if !listEqual(addTwoNumbers(test.l1, test.l2), test.ans) {
			t.Errorf("addTwoNumbers(%v, %v) != %v", test.l1, test.l2, test.ans)
		}
	}
}
