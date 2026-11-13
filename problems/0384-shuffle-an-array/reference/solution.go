package main

import "math/rand"

type Solution struct{ original []int }

func Constructor(nums []int) Solution {
	return Solution{original: append([]int(nil), nums...)}
}
func (s *Solution) Reset() []int { return append([]int(nil), s.original...) }
func (s *Solution) Shuffle() []int {
	result := append([]int(nil), s.original...)
	for i := len(result) - 1; i > 0; i-- {
		j := rand.Intn(i + 1)
		result[i], result[j] = result[j], result[i]
	}
	return result
}
