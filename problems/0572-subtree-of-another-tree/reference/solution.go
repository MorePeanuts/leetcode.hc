package main

// Recursive: subRoot is the tree at root, or a subtree of one of root's
// subtrees. O(m * n) at worst.
func isSubtree(root *TreeNode, subRoot *TreeNode) bool {
	if root == nil {
		return false
	}
	return sameTree(root, subRoot) || isSubtree(root.Left, subRoot) || isSubtree(root.Right, subRoot)
}

func sameTree(a, b *TreeNode) bool {
	if a == nil || b == nil {
		return a == b
	}
	return a.Val == b.Val && sameTree(a.Left, b.Left) && sameTree(a.Right, b.Right)
}
