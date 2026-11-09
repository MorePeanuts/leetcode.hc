package main

// Weaves each copy in right after its original, sets the copies' random
// pointers from the originals', then unweaves the two lists.
func copyRandomList(head *Node) *Node {
	for node := head; node != nil; node = node.Next.Next {
		node.Next = &Node{Val: node.Val, Next: node.Next}
	}
	for node := head; node != nil; node = node.Next.Next {
		if node.Random != nil {
			node.Next.Random = node.Random.Next
		}
	}
	dummy := &Node{}
	tail := dummy
	for node := head; node != nil; node = node.Next {
		tail.Next = node.Next
		tail = tail.Next
		node.Next = tail.Next
	}
	return dummy.Next
}
