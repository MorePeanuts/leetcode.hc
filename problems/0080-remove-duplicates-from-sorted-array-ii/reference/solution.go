package main

func removeDuplicates(nums []int) int {
	k := 0
	for _, v := range nums {
		if k < 2 || v != nums[k-2] {
			nums[k] = v
			k++
		}
	}
	return k
}
