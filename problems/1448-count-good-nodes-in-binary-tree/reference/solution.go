package main

// Recursive depth-first, carrying the largest value on the path above each
// node: a node is good when it is at least that large.
func goodNodes(root *TreeNode) int {
	var walk func(*TreeNode, int) int
	walk = func(n *TreeNode, high int) int {
		if n == nil {
			return 0
		}
		good := 0
		if n.Val >= high {
			good = 1
			high = n.Val
		}
		return good + walk(n.Left, high) + walk(n.Right, high)
	}
	return walk(root, root.Val)
}
