package main

// Returns the pair with the larger index first, the reverse of the Python
// reference, to prove that the judge ignores the order.
func twoSum(nums []int, target int) []int {
	seen := make(map[int]int, len(nums))
	for i, x := range nums {
		if j, ok := seen[target-x]; ok {
			return []int{i, j}
		}
		seen[x] = i
	}
	return nil
}
