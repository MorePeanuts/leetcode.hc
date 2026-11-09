package main

import "container/heap"

// farthest is a max-heap of points by squared distance to the origin.
type farthest [][]int

func dist(p []int) int { return p[0]*p[0] + p[1]*p[1] }

func (h farthest) Len() int           { return len(h) }
func (h farthest) Less(i, j int) bool { return dist(h[i]) > dist(h[j]) }
func (h farthest) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *farthest) Push(x any)        { *h = append(*h, x.([]int)) }
func (h *farthest) Pop() any {
	old := *h
	x := old[len(old)-1]
	*h = old[:len(old)-1]
	return x
}

// Keep the k closest points seen so far in a max-heap, and return them in
// the heap's order (farthest first), not sorted.
func kClosest(points [][]int, k int) [][]int {
	h := make(farthest, 0, k)
	for _, p := range points {
		if h.Len() < k {
			heap.Push(&h, p)
		} else if dist(p) < dist(h[0]) {
			h[0] = p
			heap.Fix(&h, 0)
		}
	}
	return h
}
