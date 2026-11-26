package main

func partition(head *ListNode, x int) *ListNode {
	var small, large ListNode
	smallTail, largeTail := &small, &large
	for head != nil {
		if head.Val < x {
			smallTail.Next = head
			smallTail = head
		} else {
			largeTail.Next = head
			largeTail = head
		}
		head = head.Next
	}
	largeTail.Next = nil
	smallTail.Next = large.Next
	return small.Next
}
