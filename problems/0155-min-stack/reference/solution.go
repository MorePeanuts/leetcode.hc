package main

// A stack of values and, beside it, a stack of the minimum so far, pushed
// only when a value is at most the current minimum.
type MinStack struct {
	values []int
	mins   []int
}

func Constructor() MinStack {
	return MinStack{}
}

func (this *MinStack) Push(value int) {
	this.values = append(this.values, value)
	if len(this.mins) == 0 || value <= this.mins[len(this.mins)-1] {
		this.mins = append(this.mins, value)
	}
}

func (this *MinStack) Pop() {
	top := this.values[len(this.values)-1]
	this.values = this.values[:len(this.values)-1]
	if top == this.mins[len(this.mins)-1] {
		this.mins = this.mins[:len(this.mins)-1]
	}
}

func (this *MinStack) Top() int {
	return this.values[len(this.values)-1]
}

func (this *MinStack) GetMin() int {
	return this.mins[len(this.mins)-1]
}
