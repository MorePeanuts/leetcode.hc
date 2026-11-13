package main

import "container/heap"

type pairEntry struct{ sum, i, j int }
type pairHeap []pairEntry

func (h pairHeap) Len() int { return len(h) }
func (h pairHeap) Less(i, j int) bool {
	if h[i].sum != h[j].sum {
		return h[i].sum < h[j].sum
	}
	// Choose the opposite tie order from Python to exercise the checker.
	if h[i].i != h[j].i {
		return h[i].i > h[j].i
	}
	return h[i].j > h[j].j
}
func (h pairHeap) Swap(i, j int) { h[i], h[j] = h[j], h[i] }
func (h *pairHeap) Push(x any)   { *h = append(*h, x.(pairEntry)) }
func (h *pairHeap) Pop() any {
	old := *h
	x := old[len(old)-1]
	*h = old[:len(old)-1]
	return x
}

func kSmallestPairs(nums1 []int, nums2 []int, k int) [][]int {
	h := pairHeap{}
	for i := 0; i < len(nums1) && i < k; i++ {
		h = append(h, pairEntry{nums1[i] + nums2[0], i, 0})
	}
	heap.Init(&h)
	result := make([][]int, 0, k)
	for len(result) < k {
		p := heap.Pop(&h).(pairEntry)
		result = append(result, []int{nums1[p.i], nums2[p.j]})
		if p.j+1 < len(nums2) {
			heap.Push(&h, pairEntry{nums1[p.i] + nums2[p.j+1], p.i, p.j + 1})
		}
	}
	// Output order is not part of the requested selection of pairs.
	for i, j := 0, len(result)-1; i < j; i, j = i+1, j-1 {
		result[i], result[j] = result[j], result[i]
	}
	return result
}
