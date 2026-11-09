package main

// Recursive post-order: a subtree's height, or -1 once any node below is
// unbalanced, so each node is visited once.
func isBalanced(root *TreeNode) bool {
	var height func(*TreeNode) int
	height = func(n *TreeNode) int {
		if n == nil {
			return 0
		}
		l := height(n.Left)
		if l < 0 {
			return -1
		}
		r := height(n.Right)
		if r < 0 || l-r > 1 || r-l > 1 {
			return -1
		}
		if l > r {
			return l + 1
		}
		return r + 1
	}
	return height(root) >= 0
}
