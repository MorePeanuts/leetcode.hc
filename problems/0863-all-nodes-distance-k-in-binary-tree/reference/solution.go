package main

func distanceK(root *TreeNode, target *TreeNode, k int) []int {
	parents := map[*TreeNode]*TreeNode{root: nil}
	nodes := []*TreeNode{root}
	for i := 0; i < len(nodes); i++ {
		node := nodes[i]
		for _, child := range []*TreeNode{node.Left, node.Right} {
			if child != nil {
				parents[child] = node
				nodes = append(nodes, child)
			}
		}
	}
	frontier := []*TreeNode{target}
	seen := map[*TreeNode]bool{target: true}
	for step := 0; step < k && len(frontier) > 0; step++ {
		next := []*TreeNode{}
		for _, node := range frontier {
			for _, other := range []*TreeNode{node.Left, node.Right, parents[node]} {
				if other != nil && !seen[other] {
					seen[other] = true
					next = append(next, other)
				}
			}
		}
		frontier = next
	}
	result := make([]int, len(frontier))
	for i, node := range frontier {
		result[len(frontier)-1-i] = node.Val
	}
	return result
}
