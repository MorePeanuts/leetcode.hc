package main

import "container/heap"

// minHeap is a min-heap of integers.
type minHeap []int

func (h minHeap) Len() int           { return len(h) }
func (h minHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h minHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *minHeap) Push(x any)        { *h = append(*h, x.(int)) }
func (h *minHeap) Pop() any {
	old := *h
	x := old[len(old)-1]
	*h = old[:len(old)-1]
	return x
}

// A min-heap of the k largest values seen: its top is the k-th largest.
func findKthLargest(nums []int, k int) int {
	h := minHeap(append([]int{}, nums[:k]...))
	heap.Init(&h)
	for _, x := range nums[k:] {
		if x > h[0] {
			h[0] = x
			heap.Fix(&h, 0)
		}
	}
	return h[0]
}
