package main

func findMinHeightTrees(n int, edges [][]int) []int {
	if n == 1 {
		return []int{0}
	}
	if n == 2 {
		return []int{1, 0}
	}
	graph := make([][]int, n)
	degree := make([]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		graph[a] = append(graph[a], b)
		graph[b] = append(graph[b], a)
		degree[a]++
		degree[b]++
	}
	leaves := []int{}
	for v := range graph {
		if degree[v] == 1 {
			leaves = append(leaves, v)
		}
	}
	remaining := n
	for remaining > 2 {
		remaining -= len(leaves)
		next := []int{}
		for _, leaf := range leaves {
			for _, v := range graph[leaf] {
				degree[v]--
				if degree[v] == 1 {
					next = append(next, v)
				}
			}
		}
		leaves = next
	}
	if len(leaves) == 2 && leaves[0] < leaves[1] {
		leaves[0], leaves[1] = leaves[1], leaves[0]
	}
	return leaves
}
