package main

func splitRun(node *ListNode, size int) *ListNode {
	if node == nil {
		return nil
	}
	for i := 1; i < size && node.Next != nil; i++ {
		node = node.Next
	}
	rest := node.Next
	node.Next = nil
	return rest
}

func sortList(head *ListNode) *ListNode {
	length := 0
	for node := head; node != nil; node = node.Next {
		length++
	}
	dummy := &ListNode{Next: head}
	for size := 1; size < length; size *= 2 {
		tail, current := dummy, dummy.Next
		for current != nil {
			left := current
			right := splitRun(left, size)
			current = splitRun(right, size)
			for left != nil && right != nil {
				if left.Val <= right.Val {
					tail.Next, left = left, left.Next
				} else {
					tail.Next, right = right, right.Next
				}
				tail = tail.Next
			}
			if left != nil {
				tail.Next = left
			} else {
				tail.Next = right
			}
			for tail.Next != nil {
				tail = tail.Next
			}
		}
	}
	return dummy.Next
}
