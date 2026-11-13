package main

func sortedArrayToBST(nums []int) *TreeNode {
	var build func(int, int) *TreeNode
	build = func(lo, hi int) *TreeNode {
		if lo == hi {
			return nil
		}
		// Choose the left middle on even lengths; Python chooses the right.
		mid := (lo + hi - 1) / 2
		return &TreeNode{Val: nums[mid], Left: build(lo, mid), Right: build(mid+1, hi)}
	}
	return build(0, len(nums))
}
