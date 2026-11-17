package main

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	parents := map[*TreeNode]*TreeNode{root: nil}
	stack := []*TreeNode{root}
	for {
		_, foundP := parents[p]
		_, foundQ := parents[q]
		if foundP && foundQ {
			break
		}
		node := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		if node.Left != nil {
			parents[node.Left] = node
			stack = append(stack, node.Left)
		}
		if node.Right != nil {
			parents[node.Right] = node
			stack = append(stack, node.Right)
		}
	}
	ancestors := make(map[*TreeNode]bool)
	for p != nil {
		ancestors[p] = true
		p = parents[p]
	}
	for !ancestors[q] {
		q = parents[q]
	}
	return q
}
