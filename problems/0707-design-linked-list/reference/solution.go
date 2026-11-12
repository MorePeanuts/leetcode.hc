package main

type linkedNode struct {
	val        int
	prev, next *linkedNode
}

type MyLinkedList struct {
	head, tail *linkedNode
	size       int
}

func Constructor() MyLinkedList {
	head, tail := &linkedNode{}, &linkedNode{}
	head.next, tail.prev = tail, head
	return MyLinkedList{head: head, tail: tail}
}

// nodeAt also accepts size, returning the tail sentinel for insertion.
func (list *MyLinkedList) nodeAt(index int) *linkedNode {
	if index < list.size/2 {
		node := list.head.next
		for i := 0; i < index; i++ {
			node = node.next
		}
		return node
	}
	node := list.tail
	for i := list.size; i > index; i-- {
		node = node.prev
	}
	return node
}

func (list *MyLinkedList) Get(index int) int {
	if index < 0 || index >= list.size {
		return -1
	}
	return list.nodeAt(index).val
}

func (list *MyLinkedList) AddAtHead(val int) {
	list.AddAtIndex(0, val)
}

func (list *MyLinkedList) AddAtTail(val int) {
	list.AddAtIndex(list.size, val)
}

func (list *MyLinkedList) AddAtIndex(index int, val int) {
	if index < 0 || index > list.size {
		return
	}
	next := list.nodeAt(index)
	prev := next.prev
	node := &linkedNode{val: val, prev: prev, next: next}
	prev.next, next.prev = node, node
	list.size++
}

func (list *MyLinkedList) DeleteAtIndex(index int) {
	if index < 0 || index >= list.size {
		return
	}
	node := list.nodeAt(index)
	node.prev.next, node.next.prev = node.next, node.prev
	list.size--
}
