package main

func findTargetSumWays(nums []int, target int) int {
	total := 0
	for _, value := range nums {
		total += value
	}
	if target > total || target < -total || (total+target)%2 != 0 {
		return 0
	}
	goal := (total + target) / 2
	ways := make([]int, goal+1)
	ways[0] = 1
	for _, value := range nums {
		for subtotal := goal; subtotal >= value; subtotal-- {
			ways[subtotal] += ways[subtotal-value]
		}
	}
	return ways[goal]
}
