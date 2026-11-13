package main

type RecentCounter struct {
	times []int
	head  int
}

func Constructor() RecentCounter { return RecentCounter{} }
func (s *RecentCounter) Ping(t int) int {
	s.times = append(s.times, t)
	for s.times[s.head] < t-3000 {
		s.head++
	}
	return len(s.times) - s.head
}
