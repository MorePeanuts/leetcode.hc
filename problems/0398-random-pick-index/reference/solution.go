package main

import "math/rand"

type Solution struct{ indices map[int][]int }

func Constructor(nums []int) Solution {
	indices := make(map[int][]int)
	for i, value := range nums {
		indices[value] = append(indices[value], i)
	}
	return Solution{indices: indices}
}
func (s *Solution) Pick(target int) int {
	positions := s.indices[target]
	return positions[rand.Intn(len(positions))]
}
