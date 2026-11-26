package main

func removeDuplicates(nums []int) int {
	k := 0
	for _, value := range nums {
		if k == 0 || nums[k-1] != value {
			nums[k] = value
			k++
		}
	}
	return k
}
