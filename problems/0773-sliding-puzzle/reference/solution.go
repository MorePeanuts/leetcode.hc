package main

func slidingPuzzle(board [][]int) int {
	neighbors := [][]int{{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}}
	var state [6]int
	copy(state[:3], board[0])
	copy(state[3:], board[1])
	target := [6]int{1, 2, 3, 4, 5, 0}
	queue := [][6]int{state}
	seen := map[[6]int]bool{state: true}
	for moves := 0; len(queue) > 0; moves++ {
		nextLayer := [][6]int{}
		for _, current := range queue {
			if current == target {
				return moves
			}
			blank := 0
			for current[blank] != 0 {
				blank++
			}
			for _, to := range neighbors[blank] {
				next := current
				next[blank], next[to] = next[to], next[blank]
				if !seen[next] {
					seen[next] = true
					nextLayer = append(nextLayer, next)
				}
			}
		}
		queue = nextLayer
	}
	return -1
}
