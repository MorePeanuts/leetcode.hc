package main

func isPalindrome(head *ListNode) bool {
	slow, fast := head, head
	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
	}
	var previous *ListNode
	for slow != nil {
		following := slow.Next
		slow.Next = previous
		previous = slow
		slow = following
	}
	for left, right := head, previous; right != nil; left, right = left.Next, right.Next {
		if left.Val != right.Val {
			return false
		}
	}
	return true
}
