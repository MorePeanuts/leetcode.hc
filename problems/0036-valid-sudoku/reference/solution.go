package main

func isValidSudoku(board [][]byte) bool {
	var rows, cols, boxes [9]uint16
	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {
			c := board[i][j]
			if c == '.' {
				continue
			}
			bit := uint16(1) << (c - '1')
			b := i/3*3 + j/3
			if rows[i]&bit != 0 || cols[j]&bit != 0 || boxes[b]&bit != 0 {
				return false
			}
			rows[i] |= bit
			cols[j] |= bit
			boxes[b] |= bit
		}
	}
	return true
}
