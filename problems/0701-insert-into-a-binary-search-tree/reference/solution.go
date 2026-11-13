package main

// Root insertion by splitting the search path yields a different valid shape.
func insertIntoBST(root *TreeNode, val int) *TreeNode {
	var split func(*TreeNode) (*TreeNode, *TreeNode)
	split = func(node *TreeNode) (*TreeNode, *TreeNode) {
		if node == nil {
			return nil, nil
		}
		if node.Val < val {
			a, b := split(node.Right)
			node.Right = a
			return node, b
		}
		a, b := split(node.Left)
		node.Left = b
		return a, node
	}
	left, right := split(root)
	return &TreeNode{Val: val, Left: left, Right: right}
}
