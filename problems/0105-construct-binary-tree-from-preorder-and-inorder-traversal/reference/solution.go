package main

// Recursive divide and conquer: the next preorder value is the root of the
// current inorder range, found through a map from value to inorder index;
// the values before it in the range form the left subtree, those after it
// the right one. O(n).
func buildTree(preorder []int, inorder []int) *TreeNode {
	index := make(map[int]int, len(inorder))
	for i, v := range inorder {
		index[v] = i
	}
	next := 0
	var build func(lo, hi int) *TreeNode
	build = func(lo, hi int) *TreeNode {
		if lo > hi {
			return nil
		}
		v := preorder[next]
		next++
		mid := index[v]
		node := &TreeNode{Val: v}
		node.Left = build(lo, mid-1)
		node.Right = build(mid+1, hi)
		return node
	}
	return build(0, len(inorder)-1)
}
