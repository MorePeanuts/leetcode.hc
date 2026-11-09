package main

// One pass: the lead pointer runs n nodes ahead, so when it reaches the tail
// the other one is just before the node to remove.
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	dummy := &ListNode{Next: head}
	lead, trail := dummy, dummy
	for i := 0; i < n; i++ {
		lead = lead.Next
	}
	for lead.Next != nil {
		lead = lead.Next
		trail = trail.Next
	}
	trail.Next = trail.Next.Next
	return dummy.Next
}
