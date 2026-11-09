package main

// A sliding window: each right end shrinks the window from the left while
// its sum still reaches target.
func minSubArrayLen(target int, nums []int) int {
	n := len(nums)
	best, total, left := n+1, 0, 0
	for right, x := range nums {
		total += x
		for total >= target {
			if right-left+1 < best {
				best = right - left + 1
			}
			total -= nums[left]
			left++
		}
	}
	if best > n {
		return 0
	}
	return best
}
