package main

func maxAreaOfIsland(grid [][]int) int {
	rows, cols := len(grid), len(grid[0])
	best := 0
	dirs := [][2]int{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}
	for r := 0; r < rows; r++ {
		for c := 0; c < cols; c++ {
			if grid[r][c] != 1 {
				continue
			}
			grid[r][c] = 0
			queue := [][2]int{{r, c}}
			for head := 0; head < len(queue); head++ {
				cell := queue[head]
				for _, d := range dirs {
					x, y := cell[0]+d[0], cell[1]+d[1]
					if x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 1 {
						grid[x][y] = 0
						queue = append(queue, [2]int{x, y})
					}
				}
			}
			if len(queue) > best {
				best = len(queue)
			}
		}
	}
	return best
}
