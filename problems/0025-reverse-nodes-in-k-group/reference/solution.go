package main

// Reverses each full group in place behind the tail of the group before it; a
// short last group is left as it is.
func reverseKGroup(head *ListNode, k int) *ListNode {
	dummy := &ListNode{Next: head}
	before := dummy
	for {
		end := before
		for i := 0; i < k; i++ {
			end = end.Next
			if end == nil {
				return dummy.Next
			}
		}
		after := end.Next
		prev, cur := after, before.Next
		for cur != after {
			cur.Next, prev, cur = prev, cur, cur.Next
		}
		first := before.Next
		before.Next = end
		before = first
	}
}
