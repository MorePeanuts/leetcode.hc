package main

// Two pointers from both ends: the sum is too small, so the left one moves
// right, or too large, so the right one moves left.
func twoSum(numbers []int, target int) []int {
	lo, hi := 0, len(numbers)-1
	for lo < hi {
		s := numbers[lo] + numbers[hi]
		if s == target {
			return []int{lo + 1, hi + 1}
		}
		if s < target {
			lo++
		} else {
			hi--
		}
	}
	return nil
}
