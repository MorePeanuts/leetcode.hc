package main

// Recursive post-order: each call returns the best downward path from its
// node, and updates the best path that turns at it.
func maxPathSum(root *TreeNode) int {
	best := root.Val
	var gain func(*TreeNode) int
	gain = func(n *TreeNode) int {
		if n == nil {
			return 0
		}
		l := max0(gain(n.Left))
		r := max0(gain(n.Right))
		if s := n.Val + l + r; s > best {
			best = s
		}
		if l > r {
			return n.Val + l
		}
		return n.Val + r
	}
	gain(root)
	return best
}

func max0(x int) int {
	if x < 0 {
		return 0
	}
	return x
}
