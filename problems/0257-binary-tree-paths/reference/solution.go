package main

import "strconv"

func binaryTreePaths(root *TreeNode) []string {
	answer := []string{}
	if root == nil {
		return answer
	}
	type frame struct {
		node *TreeNode
		path string
	}
	stack := []frame{{root, strconv.Itoa(root.Val)}}
	for len(stack) > 0 {
		f := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		n := f.node
		if n.Left == nil && n.Right == nil {
			answer = append(answer, f.path)
		}
		// Left first on the stack makes right paths appear first in output.
		if n.Left != nil {
			stack = append(stack, frame{n.Left, f.path + "->" + strconv.Itoa(n.Left.Val)})
		}
		if n.Right != nil {
			stack = append(stack, frame{n.Right, f.path + "->" + strconv.Itoa(n.Right.Val)})
		}
	}
	return answer
}
