package main

func nextPermutation(nums []int) {
	pivot := len(nums) - 2
	for pivot >= 0 && nums[pivot] >= nums[pivot+1] {
		pivot--
	}
	if pivot >= 0 {
		successor := len(nums) - 1
		for nums[successor] <= nums[pivot] {
			successor--
		}
		nums[pivot], nums[successor] = nums[successor], nums[pivot]
	}
	for left, right := pivot+1, len(nums)-1; left < right; left, right = left+1, right-1 {
		nums[left], nums[right] = nums[right], nums[left]
	}
}
