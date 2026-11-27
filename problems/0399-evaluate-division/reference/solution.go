package main

type edge struct {
	to    string
	ratio float64
}

func calcEquation(equations [][]string, values []float64, queries [][]string) []float64 {
	graph := make(map[string][]edge)
	for i, eq := range equations {
		a, b := eq[0], eq[1]
		graph[a] = append(graph[a], edge{b, values[i]})
		graph[b] = append(graph[b], edge{a, 1 / values[i]})
	}
	quotient := func(start, target string) float64 {
		if graph[start] == nil || graph[target] == nil {
			return -1
		}
		seen := map[string]bool{start: true}
		queue := []edge{{start, 1}}
		for i := 0; i < len(queue); i++ {
			current := queue[i]
			if current.to == target {
				return current.ratio
			}
			for _, next := range graph[current.to] {
				if !seen[next.to] {
					seen[next.to] = true
					queue = append(queue, edge{next.to, current.ratio * next.ratio})
				}
			}
		}
		return -1
	}
	result := make([]float64, len(queries))
	for i, q := range queries {
		result[i] = quotient(q[0], q[1])
	}
	return result
}
