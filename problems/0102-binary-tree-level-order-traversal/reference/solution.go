package main

// Depth-first, left before right: each node's value is appended to the list
// of its depth, which keeps every level in left-to-right order.
func levelOrder(root *TreeNode) [][]int {
	var levels [][]int
	var walk func(*TreeNode, int)
	walk = func(n *TreeNode, d int) {
		if n == nil {
			return
		}
		if d == len(levels) {
			levels = append(levels, nil)
		}
		levels[d] = append(levels[d], n.Val)
		walk(n.Left, d+1)
		walk(n.Right, d+1)
	}
	walk(root, 0)
	return levels
}
