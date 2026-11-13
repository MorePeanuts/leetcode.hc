package main

func isBipartite(graph [][]int) bool {
	colors := make([]int, len(graph))
	for start := range graph {
		if colors[start] != 0 {
			continue
		}
		colors[start] = 1
		queue := []int{start}
		for head := 0; head < len(queue); head++ {
			node := queue[head]
			for _, v := range graph[node] {
				if colors[v] == colors[node] {
					return false
				}
				if colors[v] == 0 {
					colors[v] = -colors[node]
					queue = append(queue, v)
				}
			}
		}
	}
	return true
}
