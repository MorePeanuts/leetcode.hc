package main

// Merges the lists pairwise, doubling the step, as in a bottom-up merge sort.
func mergeKLists(lists []*ListNode) *ListNode {
	if len(lists) == 0 {
		return nil
	}
	for step := 1; step < len(lists); step *= 2 {
		for i := 0; i+step < len(lists); i += 2 * step {
			lists[i] = mergeTwo(lists[i], lists[i+step])
		}
	}
	return lists[0]
}

func mergeTwo(a, b *ListNode) *ListNode {
	dummy := &ListNode{}
	tail := dummy
	for a != nil && b != nil {
		if a.Val <= b.Val {
			tail.Next, a = a, a.Next
		} else {
			tail.Next, b = b, b.Next
		}
		tail = tail.Next
	}
	if a != nil {
		tail.Next = a
	} else {
		tail.Next = b
	}
	return dummy.Next
}
