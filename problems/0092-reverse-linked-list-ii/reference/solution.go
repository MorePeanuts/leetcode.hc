package main

// One pass: walks to the node before position left, then moves each following
// node of the stretch to its front.
func reverseBetween(head *ListNode, left int, right int) *ListNode {
	dummy := &ListNode{Next: head}
	before := dummy
	for i := 1; i < left; i++ {
		before = before.Next
	}
	first := before.Next
	for i := left; i < right; i++ {
		moved := first.Next
		first.Next = moved.Next
		moved.Next = before.Next
		before.Next = moved
	}
	return dummy.Next
}
