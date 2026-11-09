package main

// Recursive: one more than the deeper subtree.
func maxDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	l, r := maxDepth(root.Left), maxDepth(root.Right)
	if l > r {
		return l + 1
	}
	return r + 1
}
