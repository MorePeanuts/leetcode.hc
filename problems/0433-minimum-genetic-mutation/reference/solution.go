package main

func minMutation(startGene string, endGene string, bank []string) int {
	queue := []string{startGene}
	seen := map[string]bool{startGene: true}
	for steps := 0; len(queue) > 0; steps++ {
		nextLayer := []string{}
		for _, current := range queue {
			if current == endGene {
				return steps
			}
			for _, next := range bank {
				if seen[next] {
					continue
				}
				differences := 0
				for i := range current {
					if current[i] != next[i] {
						differences++
					}
				}
				if differences == 1 {
					seen[next] = true
					nextLayer = append(nextLayer, next)
				}
			}
		}
		queue = nextLayer
	}
	return -1
}
