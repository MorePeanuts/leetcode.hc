package main

func minCostConnectPoints(points [][]int) int {
	n := len(points)
	best := make([]int, n)
	used := make([]bool, n)
	for i := range best {
		best[i] = 1000000000
	}
	best[0] = 0
	total := 0
	abs := func(v int) int {
		if v < 0 {
			return -v
		}
		return v
	}
	for step := 0; step < n; step++ {
		vertex := -1
		for i := 0; i < n; i++ {
			if !used[i] && (vertex < 0 || best[i] < best[vertex]) {
				vertex = i
			}
		}
		used[vertex] = true
		total += best[vertex]
		for i, p := range points {
			if !used[i] {
				distance := abs(points[vertex][0]-p[0]) + abs(points[vertex][1]-p[1])
				best[i] = min(best[i], distance)
			}
		}
	}
	return total
}
