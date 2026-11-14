package main

func postorderTraversal(root *TreeNode) []int {
	result := []int{}
	var visit func(*TreeNode)
	visit = func(node *TreeNode) {
		if node == nil {
			return
		}
		visit(node.Left)
		visit(node.Right)
		result = append(result, node.Val)
	}
	visit(root)
	return result
}
