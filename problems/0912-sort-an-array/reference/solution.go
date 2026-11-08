package main

func sortArray(nums []int) []int {
	siftDown := func(root, end int) {
		value := nums[root]
		child := 2*root + 1
		for child < end {
			if child+1 < end && nums[child] < nums[child+1] {
				child++
			}
			if nums[child] <= value {
				break
			}
			nums[root] = nums[child]
			root = child
			child = 2*root + 1
		}
		nums[root] = value
	}
	n := len(nums)
	for root := n/2 - 1; root >= 0; root-- {
		siftDown(root, n)
	}
	for end := n - 1; end > 0; end-- {
		nums[0], nums[end] = nums[end], nums[0]
		siftDown(0, end)
	}
	return nums
}
