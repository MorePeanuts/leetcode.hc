package main

import "container/heap"

type cell struct{ time, row, col int }
type priorityQueue []cell

func (q priorityQueue) Len() int           { return len(q) }
func (q priorityQueue) Less(i, j int) bool { return q[i].time < q[j].time }
func (q priorityQueue) Swap(i, j int)      { q[i], q[j] = q[j], q[i] }
func (q *priorityQueue) Push(x any)        { *q = append(*q, x.(cell)) }
func (q *priorityQueue) Pop() any {
	entries := *q
	last := entries[len(entries)-1]
	*q = entries[:len(entries)-1]
	return last
}
func swimInWater(grid [][]int) int {
	n := len(grid)
	best := make([][]int, n)
	for r := range best {
		best[r] = make([]int, n)
		for c := range best[r] {
			best[r][c] = n * n
		}
	}
	best[0][0] = grid[0][0]
	queue := &priorityQueue{{grid[0][0], 0, 0}}
	heap.Init(queue)
	directions := [][2]int{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}
	for queue.Len() > 0 {
		cur := heap.Pop(queue).(cell)
		if cur.time != best[cur.row][cur.col] {
			continue
		}
		if cur.row == n-1 && cur.col == n-1 {
			return cur.time
		}
		for _, d := range directions {
			r, c := cur.row+d[0], cur.col+d[1]
			if r >= 0 && r < n && c >= 0 && c < n {
				candidate := max(cur.time, grid[r][c])
				if candidate < best[r][c] {
					best[r][c] = candidate
					heap.Push(queue, cell{candidate, r, c})
				}
			}
		}
	}
	return -1
}
