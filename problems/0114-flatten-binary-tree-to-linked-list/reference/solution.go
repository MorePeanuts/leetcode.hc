package main

func flatten(root *TreeNode) {
	for root != nil {
		if root.Left != nil {
			predecessor := root.Left
			for predecessor.Right != nil {
				predecessor = predecessor.Right
			}
			predecessor.Right = root.Right
			root.Right = root.Left
			root.Left = nil
		}
		root = root.Right
	}
}
