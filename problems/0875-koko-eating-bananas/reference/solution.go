package main

import "sort"

// Searches with sort.Search between ceil(sum / h), below which no speed can
// finish, and the largest pile, instead of the Python reference's [1, max].
func minEatingSpeed(piles []int, h int) int {
	sum, most := 0, 0
	for _, p := range piles {
		sum += p
		if p > most {
			most = p
		}
	}
	lo := (sum + h - 1) / h
	return lo + sort.Search(most-lo+1, func(i int) bool {
		k := lo + i
		hours := 0
		for _, p := range piles {
			hours += (p + k - 1) / k
		}
		return hours <= h
	})
}
