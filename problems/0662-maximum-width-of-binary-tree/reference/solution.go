package main

func widthOfBinaryTree(root *TreeNode) int {
	type item struct {
		node  *TreeNode
		index uint64
	}
	level := []item{{root, 0}}
	widest := uint64(0)
	for len(level) > 0 {
		width := level[len(level)-1].index - level[0].index + 1
		if width > widest {
			widest = width
		}
		base := level[0].index
		next := []item{}
		for _, entry := range level {
			index := entry.index - base
			if entry.node.Left != nil {
				next = append(next, item{entry.node.Left, 2 * index})
			}
			if entry.node.Right != nil {
				next = append(next, item{entry.node.Right, 2*index + 1})
			}
		}
		level = next
	}
	return int(widest)
}
