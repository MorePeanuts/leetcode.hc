package main

func cloneGraph(node *Node) *Node {
	if node == nil {
		return nil
	}
	copies := map[*Node]*Node{node: {Val: node.Val}}
	queue := []*Node{node}
	for head := 0; head < len(queue); head++ {
		cur := queue[head]
		// Reverse adjacency order: a deep copy is independent of neighbor order.
		for i := len(cur.Neighbors) - 1; i >= 0; i-- {
			next := cur.Neighbors[i]
			if _, ok := copies[next]; !ok {
				copies[next] = &Node{Val: next.Val}
				queue = append(queue, next)
			}
			copies[cur].Neighbors = append(copies[cur].Neighbors, copies[next])
		}
	}
	return copies[node]
}
