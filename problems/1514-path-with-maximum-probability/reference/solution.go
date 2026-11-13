package main

import "container/heap"

type probabilityEdge struct {
	to          int
	probability float64
}
type probabilityEntry struct {
	probability float64
	node        int
}
type probabilityHeap []probabilityEntry

func (h probabilityHeap) Len() int           { return len(h) }
func (h probabilityHeap) Less(i, j int) bool { return h[i].probability > h[j].probability }
func (h probabilityHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *probabilityHeap) Push(x any)        { *h = append(*h, x.(probabilityEntry)) }
func (h *probabilityHeap) Pop() any          { old := *h; x := old[len(old)-1]; *h = old[:len(old)-1]; return x }
func maxProbability(n int, edges [][]int, succProb []float64, start_node int, end_node int) float64 {
	graph := make([][]probabilityEdge, n)
	for i, e := range edges {
		a, b := e[0], e[1]
		graph[a] = append(graph[a], probabilityEdge{b, succProb[i]})
		graph[b] = append(graph[b], probabilityEdge{a, succProb[i]})
	}
	best := make([]float64, n)
	best[start_node] = 1
	h := &probabilityHeap{{1, start_node}}
	for h.Len() > 0 {
		cur := heap.Pop(h).(probabilityEntry)
		if cur.probability < best[cur.node] {
			continue
		}
		if cur.node == end_node {
			return cur.probability
		}
		for _, e := range graph[cur.node] {
			candidate := cur.probability * e.probability
			if candidate > best[e.to] {
				best[e.to] = candidate
				heap.Push(h, probabilityEntry{candidate, e.to})
			}
		}
	}
	return 0
}
