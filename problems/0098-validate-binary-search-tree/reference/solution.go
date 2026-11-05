package main

import "math"

// Recursion with the open interval each node's value must lie in; the bounds
// are one wider than int32 so that the extreme values need no special case.
func isValidBST(root *TreeNode) bool {
	return valid(root, math.MinInt32-1, math.MaxInt32+1)
}

func valid(n *TreeNode, lo, hi int) bool {
	if n == nil {
		return true
	}
	if n.Val <= lo || n.Val >= hi {
		return false
	}
	return valid(n.Left, lo, n.Val) && valid(n.Right, n.Val, hi)
}
