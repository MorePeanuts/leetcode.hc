package main

func rob(nums []int) int {
	twoBack, oneBack := 0, 0
	for _, money := range nums {
		twoBack, oneBack = oneBack, max(oneBack, twoBack+money)
	}
	return oneBack
}
