package main

import "math/rand"

type RandomizedSet struct {
	values    []int
	positions map[int]int
}

func Constructor() RandomizedSet {
	return RandomizedSet{positions: make(map[int]int)}
}

func (s *RandomizedSet) Insert(val int) bool {
	if _, ok := s.positions[val]; ok {
		return false
	}
	s.positions[val] = len(s.values)
	s.values = append(s.values, val)
	return true
}

func (s *RandomizedSet) Remove(val int) bool {
	i, ok := s.positions[val]
	if !ok {
		return false
	}
	last := s.values[len(s.values)-1]
	s.values[i] = last
	s.positions[last] = i
	s.values = s.values[:len(s.values)-1]
	delete(s.positions, val)
	return true
}

func (s *RandomizedSet) GetRandom() int {
	// Sampling the reversed index is also uniform.
	return s.values[len(s.values)-1-rand.Intn(len(s.values))]
}
