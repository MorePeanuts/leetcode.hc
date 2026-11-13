package main

import "sort"

func isNStraightHand(hand []int, groupSize int) bool {
	if len(hand)%groupSize != 0 {
		return false
	}
	counts := map[int]int{}
	for _, value := range hand {
		counts[value]++
	}
	sort.Ints(hand)
	for _, first := range hand {
		amount := counts[first]
		if amount == 0 {
			continue
		}
		for value := first; value < first+groupSize; value++ {
			if counts[value] < amount {
				return false
			}
			counts[value] -= amount
		}
	}
	return true
}
