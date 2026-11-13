package main

func mergeTriplets(triplets [][]int, target []int) bool {
	best := [3]int{}
	for _, triplet := range triplets {
		if triplet[0] > target[0] || triplet[1] > target[1] || triplet[2] > target[2] {
			continue
		}
		for i := 0; i < 3; i++ {
			best[i] = max(best[i], triplet[i])
		}
	}
	return best[0] == target[0] && best[1] == target[1] && best[2] == target[2]
}
