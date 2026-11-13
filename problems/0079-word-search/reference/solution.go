package main

func exist(board [][]byte, word string) bool {
	rows, cols := len(board), len(board[0])
	var search func(int, int, int) bool
	search = func(row, col, pos int) bool {
		if row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] != word[pos] {
			return false
		}
		if pos == len(word)-1 {
			return true
		}
		saved := board[row][col]
		board[row][col] = '#'
		found := search(row+1, col, pos+1) || search(row-1, col, pos+1) || search(row, col+1, pos+1) || search(row, col-1, pos+1)
		board[row][col] = saved
		return found
	}
	for row := 0; row < rows; row++ {
		for col := 0; col < cols; col++ {
			if search(row, col, 0) {
				return true
			}
		}
	}
	return false
}
