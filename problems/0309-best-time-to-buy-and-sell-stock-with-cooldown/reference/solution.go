package main

func maxProfit(prices []int) int {
	hold, sold, rest := -prices[0], 0, 0
	for _, price := range prices[1:] {
		hold, sold, rest = max(hold, rest-price), hold+price, max(rest, sold)
	}
	return max(sold, rest)
}
