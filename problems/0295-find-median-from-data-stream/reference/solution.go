package main

// Counts of each value in a Fenwick tree over [-10^5, 10^5]; the median is
// found by descending the tree to the k-th smallest value.
const (
	offset = 100000
	size   = 2*offset + 1
)

type MedianFinder struct {
	tree  [size + 1]int
	count int
}

func Constructor() MedianFinder {
	return MedianFinder{}
}

func (m *MedianFinder) AddNum(num int) {
	for i := num + offset + 1; i <= size; i += i & -i {
		m.tree[i]++
	}
	m.count++
}

// kth returns the k-th smallest value added (1-based).
func (m *MedianFinder) kth(k int) int {
	pos := 0
	step := 1
	for step*2 <= size {
		step *= 2
	}
	for ; step > 0; step /= 2 {
		if next := pos + step; next <= size && m.tree[next] < k {
			pos = next
			k -= m.tree[next]
		}
	}
	return pos - offset // pos + 1 is the 1-based index of the value
}

func (m *MedianFinder) FindMedian() float64 {
	if m.count%2 == 1 {
		return float64(m.kth(m.count/2 + 1))
	}
	return float64(m.kth(m.count/2)+m.kth(m.count/2+1)) / 2
}
