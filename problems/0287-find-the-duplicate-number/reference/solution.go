package main

// Floyd's cycle detection on i -> nums[i]: index 0 is never a target, so the
// walk from it enters a cycle, whose entrance is the duplicate.
func findDuplicate(nums []int) int {
	slow, fast := 0, 0
	for {
		slow = nums[slow]
		fast = nums[nums[fast]]
		if slow == fast {
			break
		}
	}
	slow = 0
	for slow != fast {
		slow = nums[slow]
		fast = nums[fast]
	}
	return slow
}
