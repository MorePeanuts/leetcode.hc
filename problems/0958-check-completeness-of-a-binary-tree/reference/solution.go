package main

func isCompleteTree(root *TreeNode) bool {
	queue := []*TreeNode{root}
	gap := false
	for i := 0; i < len(queue); i++ {
		node := queue[i]
		if node == nil {
			gap = true
		} else {
			if gap {
				return false
			}
			queue = append(queue, node.Left, node.Right)
		}
	}
	return true
}
