package main

// A hash map from keys to the nodes of a doubly linked list, most recently
// used first, between two sentinels.
type lruNode struct {
	key, value int
	prev, next *lruNode
}

type LRUCache struct {
	capacity   int
	nodes      map[int]*lruNode
	head, tail *lruNode
}

func Constructor(capacity int) LRUCache {
	head, tail := &lruNode{}, &lruNode{}
	head.next, tail.prev = tail, head
	return LRUCache{capacity: capacity, nodes: make(map[int]*lruNode), head: head, tail: tail}
}

func (c *LRUCache) unlink(n *lruNode) {
	n.prev.next, n.next.prev = n.next, n.prev
}

func (c *LRUCache) pushFront(n *lruNode) {
	n.prev, n.next = c.head, c.head.next
	c.head.next.prev = n
	c.head.next = n
}

func (c *LRUCache) Get(key int) int {
	n, ok := c.nodes[key]
	if !ok {
		return -1
	}
	c.unlink(n)
	c.pushFront(n)
	return n.value
}

func (c *LRUCache) Put(key int, value int) {
	if n, ok := c.nodes[key]; ok {
		n.value = value
		c.unlink(n)
		c.pushFront(n)
		return
	}
	n := &lruNode{key: key, value: value}
	c.nodes[key] = n
	c.pushFront(n)
	if len(c.nodes) > c.capacity {
		last := c.tail.prev
		c.unlink(last)
		delete(c.nodes, last.key)
	}
}
