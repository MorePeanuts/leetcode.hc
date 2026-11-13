package main

func deleteDuplicates(head *ListNode) *ListNode {
	dummy := &ListNode{Next: head}
	previous, current := dummy, head
	for current != nil {
		if current.Next != nil && current.Val == current.Next.Val {
			value := current.Val
			for current != nil && current.Val == value {
				current = current.Next
			}
			previous.Next = current
		} else {
			previous = current
			current = current.Next
		}
	}
	return dummy.Next
}
