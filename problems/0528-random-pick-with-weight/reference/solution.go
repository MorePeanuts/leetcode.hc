package main

import (
	"math/rand"
	"sort"
)

type Solution struct{ prefix []int }

func Constructor(w []int) Solution {
	prefix := make([]int, len(w))
	sum := 0
	for i, weight := range w {
		sum += weight
		prefix[i] = sum
	}
	return Solution{prefix: prefix}
}

func (s *Solution) PickIndex() int {
	draw := rand.Intn(s.prefix[len(s.prefix)-1]) + 1
	return sort.SearchInts(s.prefix, draw)
}
