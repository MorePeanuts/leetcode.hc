package main

import "container/heap"

type entry struct{ cost, node int }
type priorityQueue []entry

func (q priorityQueue) Len() int           { return len(q) }
func (q priorityQueue) Less(i, j int) bool { return q[i].cost < q[j].cost }
func (q priorityQueue) Swap(i, j int)      { q[i], q[j] = q[j], q[i] }
func (q *priorityQueue) Push(x any)        { *q = append(*q, x.(entry)) }
func (q *priorityQueue) Pop() any          { a := *q; x := a[len(a)-1]; *q = a[:len(a)-1]; return x }
func networkDelayTime(times [][]int, n int, k int) int {
	edges := make([][]entry, n+1)
	for _, e := range times {
		edges[e[0]] = append(edges[e[0]], entry{e[2], e[1]})
	}
	const inf = 1000000000
	distance := make([]int, n+1)
	for i := range distance {
		distance[i] = inf
	}
	distance[k] = 0
	queue := &priorityQueue{{0, k}}
	heap.Init(queue)
	for queue.Len() > 0 {
		cur := heap.Pop(queue).(entry)
		if cur.cost != distance[cur.node] {
			continue
		}
		for _, e := range edges[cur.node] {
			candidate := cur.cost + e.cost
			if candidate < distance[e.node] {
				distance[e.node] = candidate
				heap.Push(queue, entry{candidate, e.node})
			}
		}
	}
	answer := 0
	for i := 1; i <= n; i++ {
		if distance[i] == inf {
			return -1
		}
		answer = max(answer, distance[i])
	}
	return answer
}
