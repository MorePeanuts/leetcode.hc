package main

import "strconv"

func openLock(deadends []string, target string) int {
	var seen [10000]bool
	for _, dead := range deadends {
		state, _ := strconv.Atoi(dead)
		seen[state] = true
	}
	if seen[0] {
		return -1
	}
	goal, _ := strconv.Atoi(target)
	queue := []int{0}
	seen[0] = true
	head := 0
	for turns := 0; head < len(queue); turns++ {
		end := len(queue)
		for head < end {
			state := queue[head]
			head++
			if state == goal {
				return turns
			}
			for place := 1; place <= 1000; place *= 10 {
				digit := state / place % 10
				up, down := state+place, state-place
				if digit == 9 {
					up = state - 9*place
				}
				if digit == 0 {
					down = state + 9*place
				}
				for _, next := range [2]int{up, down} {
					if !seen[next] {
						seen[next] = true
						queue = append(queue, next)
					}
				}
			}
		}
	}
	return -1
}
