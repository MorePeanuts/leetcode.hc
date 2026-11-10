package main

import (
	"strconv"
	"strings"
)

// Preorder, space-separated, "#" for a missing child: "1 2 # # 3 4 # # 5 # #",
// another format than the Python reference's level order.
type Codec struct{}

func Constructor() Codec {
	return Codec{}
}

// Serializes a tree to a single string.
func (this *Codec) serialize(root *TreeNode) string {
	var b strings.Builder
	var walk func(*TreeNode)
	walk = func(n *TreeNode) {
		if b.Len() > 0 {
			b.WriteByte(' ')
		}
		if n == nil {
			b.WriteByte('#')
			return
		}
		b.WriteString(strconv.Itoa(n.Val))
		walk(n.Left)
		walk(n.Right)
	}
	walk(root)
	return b.String()
}

// Deserializes your encoded data to tree.
func (this *Codec) deserialize(data string) *TreeNode {
	tokens := strings.Fields(data)
	next := 0
	var build func() *TreeNode
	build = func() *TreeNode {
		t := tokens[next]
		next++
		if t == "#" {
			return nil
		}
		v, _ := strconv.Atoi(t)
		n := &TreeNode{Val: v}
		n.Left = build()
		n.Right = build()
		return n
	}
	return build()
}
