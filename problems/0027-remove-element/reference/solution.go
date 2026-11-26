package main

func removeElement(nums []int, val int) int {
	end := len(nums)
	for i := 0; i < end; {
		if nums[i] == val {
			end--
			nums[i] = nums[end]
		} else {
			i++
		}
	}
	return end
}
