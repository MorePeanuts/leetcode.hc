package main

import (
	"container/heap"
	"sort"
)

type intervalCandidate struct{ size, right int }
type intervalHeap []intervalCandidate

func (h intervalHeap) Len() int           { return len(h) }
func (h intervalHeap) Less(i, j int) bool { return h[i].size < h[j].size }
func (h intervalHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *intervalHeap) Push(x any)        { *h = append(*h, x.(intervalCandidate)) }
func (h *intervalHeap) Pop() any {
	old := *h
	x := old[len(old)-1]
	*h = old[:len(old)-1]
	return x
}
func minInterval(intervals [][]int, queries []int) []int {
	sort.Slice(intervals, func(i, j int) bool { return intervals[i][0] < intervals[j][0] })
	order := make([]int, len(queries))
	for i := range order {
		order[i] = i
	}
	sort.Slice(order, func(i, j int) bool { return queries[order[i]] < queries[order[j]] })
	answer := make([]int, len(queries))
	candidates := &intervalHeap{}
	i := 0
	for _, index := range order {
		query := queries[index]
		for i < len(intervals) && intervals[i][0] <= query {
			left, right := intervals[i][0], intervals[i][1]
			heap.Push(candidates, intervalCandidate{right - left + 1, right})
			i++
		}
		for candidates.Len() > 0 && (*candidates)[0].right < query {
			heap.Pop(candidates)
		}
		answer[index] = -1
		if candidates.Len() > 0 {
			answer[index] = (*candidates)[0].size
		}
	}
	return answer
}
