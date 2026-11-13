package main

func solve(board [][]byte) {
	rows, cols := len(board), len(board[0])
	queue := [][2]int{}
	mark := func(r, c int) {
		if board[r][c] == 'O' {
			board[r][c] = '#'
			queue = append(queue, [2]int{r, c})
		}
	}
	for r := 0; r < rows; r++ {
		mark(r, 0)
		mark(r, cols-1)
	}
	for c := 0; c < cols; c++ {
		mark(0, c)
		mark(rows-1, c)
	}
	dirs := [][2]int{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}
	for h := 0; h < len(queue); h++ {
		v := queue[h]
		for _, d := range dirs {
			r, c := v[0]+d[0], v[1]+d[1]
			if r >= 0 && r < rows && c >= 0 && c < cols {
				mark(r, c)
			}
		}
	}
	for r := 0; r < rows; r++ {
		for c := 0; c < cols; c++ {
			if board[r][c] == '#' {
				board[r][c] = 'O'
			} else {
				board[r][c] = 'X'
			}
		}
	}
}
