package main

func levelOrder(root *Node) [][]int {
	result := [][]int{}
	if root == nil {
		return result
	}
	queue := []*Node{root}
	for head := 0; head < len(queue); {
		end := len(queue)
		level := make([]int, 0, end-head)
		for head < end {
			node := queue[head]
			head++
			level = append(level, node.Val)
			queue = append(queue, node.Children...)
		}
		result = append(result, level)
	}
	return result
}
