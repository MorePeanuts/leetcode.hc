package main

func zigzagLevelOrder(root *TreeNode) [][]int {
	result := [][]int{}
	if root == nil {
		return result
	}
	level := []*TreeNode{root}
	for len(level) > 0 {
		row := make([]int, len(level))
		next := []*TreeNode{}
		for i, node := range level {
			pos := i
			if len(result)%2 == 1 {
				pos = len(level) - 1 - i
			}
			row[pos] = node.Val
			if node.Left != nil {
				next = append(next, node.Left)
			}
			if node.Right != nil {
				next = append(next, node.Right)
			}
		}
		result = append(result, row)
		level = next
	}
	return result
}
