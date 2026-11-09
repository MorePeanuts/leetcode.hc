package main

import "sort"

// Binary searches the last row whose first value is at most target, then
// that row: two searches, O(log m + log n), instead of the Python
// reference's one search over the flattened matrix.
func searchMatrix(matrix [][]int, target int) bool {
	r := sort.Search(len(matrix), func(i int) bool { return matrix[i][0] > target }) - 1
	if r < 0 {
		return false
	}
	row := matrix[r]
	j := sort.SearchInts(row, target)
	return j < len(row) && row[j] == target
}
