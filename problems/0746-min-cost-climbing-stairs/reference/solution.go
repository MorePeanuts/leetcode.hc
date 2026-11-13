package main

func minCostClimbingStairs(cost []int) int {
	twoBack, oneBack := 0, 0
	for step := 2; step <= len(cost); step++ {
		twoBack, oneBack = oneBack, min(oneBack+cost[step-1], twoBack+cost[step-2])
	}
	return oneBack
}
