package main

// Recursive in-order traversal, counting down k and stopping once it
// reaches the k-th node.
func kthSmallest(root *TreeNode, k int) int {
	ans := 0
	var walk func(*TreeNode)
	walk = func(n *TreeNode) {
		if n == nil || k == 0 {
			return
		}
		walk(n.Left)
		if k == 0 {
			return
		}
		k--
		if k == 0 {
			ans = n.Val
			return
		}
		walk(n.Right)
	}
	walk(root)
	return ans
}
