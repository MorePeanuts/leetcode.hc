package main

import "container/heap"

type effortCell struct{ effort, row, col int }
type effortHeap []effortCell

func (h effortHeap) Len() int           { return len(h) }
func (h effortHeap) Less(i, j int) bool { return h[i].effort < h[j].effort }
func (h effortHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *effortHeap) Push(x any)        { *h = append(*h, x.(effortCell)) }
func (h *effortHeap) Pop() any          { old := *h; x := old[len(old)-1]; *h = old[:len(old)-1]; return x }
func minimumEffortPath(heights [][]int) int {
	rows, cols := len(heights), len(heights[0])
	best := make([][]int, rows)
	for r := range best {
		best[r] = make([]int, cols)
		for c := range best[r] {
			best[r][c] = 1000000
		}
	}
	best[0][0] = 0
	h := &effortHeap{{0, 0, 0}}
	dirs := [][2]int{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}
	for h.Len() > 0 {
		cur := heap.Pop(h).(effortCell)
		if cur.effort != best[cur.row][cur.col] {
			continue
		}
		if cur.row == rows-1 && cur.col == cols-1 {
			return cur.effort
		}
		for _, d := range dirs {
			r, c := cur.row+d[0], cur.col+d[1]
			if r < 0 || r >= rows || c < 0 || c >= cols {
				continue
			}
			diff := heights[r][c] - heights[cur.row][cur.col]
			if diff < 0 {
				diff = -diff
			}
			candidate := max(cur.effort, diff)
			if candidate < best[r][c] {
				best[r][c] = candidate
				heap.Push(h, effortCell{candidate, r, c})
			}
		}
	}
	return 0
}
