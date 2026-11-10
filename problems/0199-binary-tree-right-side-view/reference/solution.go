package main

// Depth-first, right before left: the first node reached at each depth is
// the one seen from the right.
func rightSideView(root *TreeNode) []int {
	var view []int
	var walk func(*TreeNode, int)
	walk = func(n *TreeNode, d int) {
		if n == nil {
			return
		}
		if d == len(view) {
			view = append(view, n.Val)
		}
		walk(n.Right, d+1)
		walk(n.Left, d+1)
	}
	walk(root, 0)
	return view
}
