package main

func closedIsland(grid [][]int) int {
	rows, cols := len(grid), len(grid[0])
	answer := 0
	directions := [][2]int{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}
	for row := 0; row < rows; row++ {
		for col := 0; col < cols; col++ {
			if grid[row][col] != 0 {
				continue
			}
			stack := [][2]int{{row, col}}
			grid[row][col] = 1
			closed := true
			for len(stack) > 0 {
				cell := stack[len(stack)-1]
				stack = stack[:len(stack)-1]
				r, c := cell[0], cell[1]
				if r == 0 || c == 0 || r == rows-1 || c == cols-1 {
					closed = false
				}
				for _, delta := range directions {
					nr, nc := r+delta[0], c+delta[1]
					if nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 0 {
						grid[nr][nc] = 1
						stack = append(stack, [2]int{nr, nc})
					}
				}
			}
			if closed {
				answer++
			}
		}
	}
	return answer
}
