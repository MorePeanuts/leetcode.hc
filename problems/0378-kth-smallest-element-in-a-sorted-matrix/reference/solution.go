package main

import "container/heap"

type matrixEntry struct{ value, row, col int }
type matrixHeap []matrixEntry

func (h matrixHeap) Len() int           { return len(h) }
func (h matrixHeap) Less(i, j int) bool { return h[i].value < h[j].value }
func (h matrixHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *matrixHeap) Push(x any)        { *h = append(*h, x.(matrixEntry)) }
func (h *matrixHeap) Pop() any {
	old := *h
	x := old[len(old)-1]
	*h = old[:len(old)-1]
	return x
}

func kthSmallest(matrix [][]int, k int) int {
	n := len(matrix)
	h := matrixHeap{}
	for row := 0; row < n && row < k; row++ {
		h = append(h, matrixEntry{matrix[row][0], row, 0})
	}
	heap.Init(&h)
	value := 0
	for count := 0; count < k; count++ {
		p := heap.Pop(&h).(matrixEntry)
		value = p.value
		if p.col+1 < n {
			heap.Push(&h, matrixEntry{matrix[p.row][p.col+1], p.row, p.col + 1})
		}
	}
	return value
}
