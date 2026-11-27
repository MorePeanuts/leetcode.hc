package main

func maximumDetonation(bombs [][]int) int {
	edges := make([][]int, len(bombs))
	for i, b := range bombs {
		radius := int64(b[2])
		for j, other := range bombs {
			dx, dy := int64(b[0]-other[0]), int64(b[1]-other[1])
			if i != j && dx*dx+dy*dy <= radius*radius {
				edges[i] = append(edges[i], j)
			}
		}
	}
	best := 0
	for start := range bombs {
		seen := make([]bool, len(bombs))
		seen[start] = true
		queue := []int{start}
		for head := 0; head < len(queue); head++ {
			for _, next := range edges[queue[head]] {
				if !seen[next] {
					seen[next] = true
					queue = append(queue, next)
				}
			}
		}
		best = max(best, len(queue))
		if best == len(bombs) {
			break
		}
	}
	return best
}
