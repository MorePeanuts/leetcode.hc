package main

import "container/heap"

// counts is a max-heap of the copies left of each task.
type counts []int

func (h counts) Len() int           { return len(h) }
func (h counts) Less(i, j int) bool { return h[i] > h[j] }
func (h counts) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *counts) Push(x any)        { *h = append(*h, x.(int)) }
func (h *counts) Pop() any {
	old := *h
	x := old[len(old)-1]
	*h = old[:len(old)-1]
	return x
}

// A task that ran, with the copies it has left and the last interval it
// must stay idle.
type cooling struct{ left, until int }

// Simulate: at each interval run the task with the most copies left among
// those not cooling down; a task that ran waits in a queue until its gap of
// n intervals is over. When every task left is cooling down, skip the idle
// intervals at once.
func leastInterval(tasks []byte, n int) int {
	var freq [26]int
	for _, t := range tasks {
		freq[t-'A']++
	}
	h := counts{}
	for _, c := range freq {
		if c > 0 {
			h = append(h, c)
		}
	}
	heap.Init(&h)
	var queue []cooling
	time := 0
	for h.Len() > 0 || len(queue) > 0 {
		time++
		if h.Len() > 0 {
			if left := heap.Pop(&h).(int) - 1; left > 0 {
				queue = append(queue, cooling{left, time + n})
			}
		} else {
			time = queue[0].until
		}
		if len(queue) > 0 && queue[0].until == time {
			heap.Push(&h, queue[0].left)
			queue = queue[1:]
		}
	}
	return time
}
