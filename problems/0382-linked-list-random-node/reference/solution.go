package main

import "math/rand"

type Solution struct{ head *ListNode }

func Constructor(head *ListNode) Solution { return Solution{head: head} }
func (s *Solution) GetRandom() int {
	result := s.head.Val
	count := 0
	for node := s.head; node != nil; node = node.Next {
		count++
		if rand.Intn(count) == 0 {
			result = node.Val
		}
	}
	return result
}
