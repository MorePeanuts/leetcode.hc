package main

func rotate(nums []int, k int) {
	reverse := func(left, right int) {
		for left < right {
			nums[left], nums[right] = nums[right], nums[left]
			left++
			right--
		}
	}
	k %= len(nums)
	reverse(0, len(nums)-1)
	reverse(0, k-1)
	reverse(k, len(nums)-1)
}
