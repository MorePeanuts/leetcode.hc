package main

// Splits the list at its middle, reverses the second half, then weaves the
// two halves together.
func reorderList(head *ListNode) {
	slow, fast := head, head
	for fast.Next != nil && fast.Next.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
	}
	second := slow.Next
	slow.Next = nil
	var prev *ListNode
	for second != nil {
		second.Next, prev, second = prev, second, second.Next
	}
	first, second := head, prev
	for second != nil {
		firstNext, secondNext := first.Next, second.Next
		first.Next = second
		second.Next = firstNext
		first, second = firstNext, secondNext
	}
}
