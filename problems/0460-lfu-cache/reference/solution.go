package main

// Keys grouped by use counter, each group a doubly linked list in most
// recently used order, and the smallest counter in use: every call is O(1).

type lfuNode struct {
	key, value, count int
	prev, next        *lfuNode
}

// lfuList is a circular doubly linked list around a sentinel.
type lfuList struct {
	root lfuNode
	size int
}

func newLfuList() *lfuList {
	l := &lfuList{}
	l.root.prev = &l.root
	l.root.next = &l.root
	return l
}

func (l *lfuList) pushFront(n *lfuNode) {
	n.prev = &l.root
	n.next = l.root.next
	l.root.next.prev = n
	l.root.next = n
	l.size++
}

func (l *lfuList) remove(n *lfuNode) {
	n.prev.next = n.next
	n.next.prev = n.prev
	n.prev, n.next = nil, nil
	l.size--
}

type LFUCache struct {
	capacity int
	minCount int
	nodes    map[int]*lfuNode
	groups   map[int]*lfuList
}

func Constructor(capacity int) LFUCache {
	return LFUCache{
		capacity: capacity,
		nodes:    make(map[int]*lfuNode),
		groups:   make(map[int]*lfuList),
	}
}

func (this *LFUCache) group(count int) *lfuList {
	l := this.groups[count]
	if l == nil {
		l = newLfuList()
		this.groups[count] = l
	}
	return l
}

func (this *LFUCache) touch(n *lfuNode) {
	l := this.groups[n.count]
	l.remove(n)
	if l.size == 0 {
		delete(this.groups, n.count)
		if this.minCount == n.count {
			this.minCount++
		}
	}
	n.count++
	this.group(n.count).pushFront(n)
}

func (this *LFUCache) Get(key int) int {
	n := this.nodes[key]
	if n == nil {
		return -1
	}
	this.touch(n)
	return n.value
}

func (this *LFUCache) Put(key int, value int) {
	if n := this.nodes[key]; n != nil {
		n.value = value
		this.touch(n)
		return
	}
	if len(this.nodes) == this.capacity {
		l := this.groups[this.minCount]
		old := l.root.prev
		l.remove(old)
		if l.size == 0 {
			delete(this.groups, this.minCount)
		}
		delete(this.nodes, old.key)
	}
	n := &lfuNode{key: key, value: value, count: 1}
	this.nodes[key] = n
	this.group(1).pushFront(n)
	this.minCount = 1
}
