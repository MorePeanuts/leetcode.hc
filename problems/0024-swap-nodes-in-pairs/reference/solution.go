package main

func swapPairs(head *ListNode) *ListNode {
	dummy := &ListNode{Next: head}
	previous := dummy
	for previous.Next != nil && previous.Next.Next != nil {
		first := previous.Next
		second := first.Next
		first.Next = second.Next
		second.Next = first
		previous.Next = second
		previous = first
	}
	return dummy.Next
}
