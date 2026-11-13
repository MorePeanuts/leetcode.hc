package main

func sortColors(nums []int) {
	low, scan, high := 0, 0, len(nums)-1
	for scan <= high {
		if nums[scan] == 0 {
			nums[low], nums[scan] = nums[scan], nums[low]
			low++
			scan++
		} else if nums[scan] == 2 {
			nums[high], nums[scan] = nums[scan], nums[high]
			high--
		} else {
			scan++
		}
	}
}
