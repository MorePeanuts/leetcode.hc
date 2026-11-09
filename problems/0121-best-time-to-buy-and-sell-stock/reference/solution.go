package main

// One pass: the best sale on each day is at the lowest price before it.
func maxProfit(prices []int) int {
	lowest, best := prices[0], 0
	for _, p := range prices {
		if p < lowest {
			lowest = p
		} else if p-lowest > best {
			best = p - lowest
		}
	}
	return best
}
