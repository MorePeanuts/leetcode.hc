package main

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	first, second := []int{}, []int{}
	for node := l1; node != nil; node = node.Next {
		first = append(first, node.Val)
	}
	for node := l2; node != nil; node = node.Next {
		second = append(second, node.Val)
	}
	carry := 0
	var head *ListNode
	for len(first) > 0 || len(second) > 0 || carry != 0 {
		total := carry
		if len(first) > 0 {
			total += first[len(first)-1]
			first = first[:len(first)-1]
		}
		if len(second) > 0 {
			total += second[len(second)-1]
			second = second[:len(second)-1]
		}
		carry = total / 10
		head = &ListNode{Val: total % 10, Next: head}
	}
	return head
}
