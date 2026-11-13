package main

func orangesRotting(grid [][]int) int {
	rows, cols := len(grid), len(grid[0])
	fresh := 0
	queue := [][2]int{}
	for r := 0; r < rows; r++ {
		for c := 0; c < cols; c++ {
			if grid[r][c] == 2 {
				queue = append(queue, [2]int{r, c})
			} else if grid[r][c] == 1 {
				fresh++
			}
		}
	}
	dirs := [][2]int{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}
	minutes := 0
	head := 0
	for head < len(queue) && fresh > 0 {
		end := len(queue)
		for head < end {
			v := queue[head]
			head++
			for _, d := range dirs {
				r, c := v[0]+d[0], v[1]+d[1]
				if r >= 0 && r < rows && c >= 0 && c < cols && grid[r][c] == 1 {
					grid[r][c] = 2
					fresh--
					queue = append(queue, [2]int{r, c})
				}
			}
		}
		minutes++
	}
	if fresh > 0 {
		return -1
	}
	return minutes
}
