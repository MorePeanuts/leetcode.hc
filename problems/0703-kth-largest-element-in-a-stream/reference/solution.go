package main

// A min-heap of the k largest values so far: its top is the k-th largest.
type KthLargest struct {
	k    int
	heap []int
}

func Constructor(k int, nums []int) KthLargest {
	h := KthLargest{k: k, heap: make([]int, 0, k)}
	for _, x := range nums {
		h.Add(x)
	}
	return h
}

func (h *KthLargest) Add(val int) int {
	if len(h.heap) < h.k {
		h.heap = append(h.heap, val)
		h.up(len(h.heap) - 1)
	} else if val > h.heap[0] {
		h.heap[0] = val
		h.down(0)
	}
	return h.heap[0]
}

func (h *KthLargest) up(i int) {
	for i > 0 {
		p := (i - 1) / 2
		if h.heap[p] <= h.heap[i] {
			break
		}
		h.heap[p], h.heap[i] = h.heap[i], h.heap[p]
		i = p
	}
}

func (h *KthLargest) down(i int) {
	n := len(h.heap)
	for {
		l := 2*i + 1
		if l >= n {
			return
		}
		if r := l + 1; r < n && h.heap[r] < h.heap[l] {
			l = r
		}
		if h.heap[i] <= h.heap[l] {
			return
		}
		h.heap[i], h.heap[l] = h.heap[l], h.heap[i]
		i = l
	}
}
