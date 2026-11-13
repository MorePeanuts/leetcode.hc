package main

func pathSum(root *TreeNode, targetSum int) int {
	prefix := map[int64]int{0: 1}
	target := int64(targetSum)
	var visit func(*TreeNode, int64) int
	visit = func(node *TreeNode, sum int64) int {
		if node == nil {
			return 0
		}
		sum += int64(node.Val)
		count := prefix[sum-target]
		prefix[sum]++
		count += visit(node.Left, sum) + visit(node.Right, sum)
		prefix[sum]--
		return count
	}
	return visit(root, 0)
}
