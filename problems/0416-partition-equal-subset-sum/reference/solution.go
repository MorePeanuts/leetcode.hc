package main

func canPartition(nums []int) bool {
	total := 0
	for _, value := range nums {
		total += value
	}
	if total%2 != 0 {
		return false
	}
	target := total / 2
	possible := make([]bool, target+1)
	possible[0] = true
	for _, value := range nums {
		for subtotal := target; subtotal >= value; subtotal-- {
			possible[subtotal] = possible[subtotal] || possible[subtotal-value]
		}
	}
	return possible[target]
}
