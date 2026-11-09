package main

// One post-order pass: each call returns its subtree's height in nodes, and
// the longest path turning at a node is the sum of its subtrees' heights.
func diameterOfBinaryTree(root *TreeNode) int {
	best := 0
	var height func(*TreeNode) int
	height = func(n *TreeNode) int {
		if n == nil {
			return 0
		}
		l, r := height(n.Left), height(n.Right)
		if l+r > best {
			best = l + r
		}
		if l > r {
			return l + 1
		}
		return r + 1
	}
	height(root)
	return best
}
