package main

func buildTree(inorder []int, postorder []int) *TreeNode {
	positions := make(map[int]int, len(inorder))
	for i, value := range inorder {
		positions[value] = i
	}
	index := len(postorder) - 1
	var build func(int, int) *TreeNode
	build = func(lo, hi int) *TreeNode {
		if lo >= hi {
			return nil
		}
		value := postorder[index]
		index--
		split := positions[value]
		node := &TreeNode{Val: value}
		node.Right = build(split+1, hi)
		node.Left = build(lo, split)
		return node
	}
	return build(0, len(inorder))
}
