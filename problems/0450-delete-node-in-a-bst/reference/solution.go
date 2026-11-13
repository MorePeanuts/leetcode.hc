package main

func deleteNode(root *TreeNode, key int) *TreeNode {
	var parent *TreeNode
	node := root
	for node != nil && node.Val != key {
		parent = node
		if key < node.Val {
			node = node.Left
		} else {
			node = node.Right
		}
	}
	if node == nil {
		return root
	}
	// Use the predecessor, unlike the Python reference's successor.
	if node.Left != nil && node.Right != nil {
		previousParent, previous := node, node.Left
		for previous.Right != nil {
			previousParent, previous = previous, previous.Right
		}
		node.Val = previous.Val
		parent, node = previousParent, previous
	}
	child := node.Left
	if child == nil {
		child = node.Right
	}
	if parent == nil {
		return child
	}
	if parent.Left == node {
		parent.Left = child
	} else {
		parent.Right = child
	}
	return root
}
