package main

func allPathsSourceTarget(graph [][]int) [][]int {
	result := [][]int{}
	path := []int{0}
	var visit func(int)
	visit = func(node int) {
		if node == len(graph)-1 {
			result = append(result, append([]int(nil), path...))
			return
		}
		// Reverse neighbor order to exercise the unordered outer comparison.
		for i := len(graph[node]) - 1; i >= 0; i-- {
			path = append(path, graph[node][i])
			visit(graph[node][i])
			path = path[:len(path)-1]
		}
	}
	visit(0)
	return result
}
