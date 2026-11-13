package main

func sumNumbers(root *TreeNode) int {
	var visit func(*TreeNode, int) int
	visit = func(node *TreeNode, prefix int) int {
		if node == nil {
			return 0
		}
		number := prefix*10 + node.Val
		if node.Left == nil && node.Right == nil {
			return number
		}
		return visit(node.Left, number) + visit(node.Right, number)
	}
	return visit(root, 0)
}
