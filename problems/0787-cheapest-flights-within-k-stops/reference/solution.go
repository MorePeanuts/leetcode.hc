package main

func findCheapestPrice(n int, flights [][]int, src int, dst int, k int) int {
	const inf = 1000000000
	distance := make([]int, n)
	for i := range distance {
		distance[i] = inf
	}
	distance[src] = 0
	for round := 0; round <= k; round++ {
		following := append([]int{}, distance...)
		for _, e := range flights {
			following[e[1]] = min(following[e[1]], distance[e[0]]+e[2])
		}
		distance = following
	}
	if distance[dst] == inf {
		return -1
	}
	return distance[dst]
}
