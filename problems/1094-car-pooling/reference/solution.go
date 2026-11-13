package main

func carPooling(trips [][]int, capacity int) bool {
	difference := make([]int, 1001)
	for _, t := range trips {
		difference[t[1]] += t[0]
		difference[t[2]] -= t[0]
	}
	onboard := 0
	for _, change := range difference {
		onboard += change
		if onboard > capacity {
			return false
		}
	}
	return true
}
