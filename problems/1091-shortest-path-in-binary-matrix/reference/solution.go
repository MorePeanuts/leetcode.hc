package main

func shortestPathBinaryMatrix(grid [][]int) int {
	n := len(grid)
	if grid[0][0] != 0 || grid[n-1][n-1] != 0 {
		return -1
	}
	seen := make([][]bool, n)
	for r := range seen {
		seen[r] = make([]bool, n)
	}
	seen[0][0] = true
	queue := [][3]int{{0, 0, 1}}
	for head := 0; head < len(queue); head++ {
		cur := queue[head]
		r, c, d := cur[0], cur[1], cur[2]
		if r == n-1 && c == n-1 {
			return d
		}
		for dr := -1; dr <= 1; dr++ {
			for dc := -1; dc <= 1; dc++ {
				if dr == 0 && dc == 0 {
					continue
				}
				nr, nc := r+dr, c+dc
				if nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0 && !seen[nr][nc] {
					seen[nr][nc] = true
					queue = append(queue, [3]int{nr, nc, d + 1})
				}
			}
		}
	}
	return -1
}
