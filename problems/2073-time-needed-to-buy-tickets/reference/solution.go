package main

func timeRequiredToBuy(tickets []int, k int) int {
	target, total := tickets[k], 0
	for i, count := range tickets {
		limit := target
		if i > k {
			limit--
		}
		if count > limit {
			count = limit
		}
		total += count
	}
	return total
}
