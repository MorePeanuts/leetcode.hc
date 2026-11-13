package main

import "strings"

func solveNQueens(n int) [][]string {
	answer := [][]string{}
	columns := make([]bool, n)
	descending := make([]bool, 2*n-1)
	ascending := make([]bool, 2*n-1)
	placement := make([]int, n)
	var search func(int)
	search = func(row int) {
		if row == n {
			board := make([]string, n)
			for r, c := range placement {
				board[r] = strings.Repeat(".", c) + "Q" + strings.Repeat(".", n-c-1)
			}
			answer = append(answer, board)
			return
		}
		for col := n - 1; col >= 0; col-- {
			d, a := row-col+n-1, row+col
			if columns[col] || descending[d] || ascending[a] {
				continue
			}
			columns[col], descending[d], ascending[a] = true, true, true
			placement[row] = col
			search(row + 1)
			columns[col], descending[d], ascending[a] = false, false, false
		}
	}
	search(0)
	return answer
}
