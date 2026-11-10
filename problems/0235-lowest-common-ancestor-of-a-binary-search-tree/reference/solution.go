package main

// Walk down from the root while p and q are both on one side of the node;
// the first node that separates them, or is one of them, is the answer.
func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	node := root
	for {
		switch {
		case p.Val < node.Val && q.Val < node.Val:
			node = node.Left
		case p.Val > node.Val && q.Val > node.Val:
			node = node.Right
		default:
			return node
		}
	}
}
