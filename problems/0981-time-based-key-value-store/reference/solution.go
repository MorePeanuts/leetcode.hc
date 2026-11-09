package main

import "sort"

type entry struct {
	timestamp int
	value     string
}

// TimeMap keeps, per key, its entries in the order set was called: the
// timestamps of set are strictly increasing, so each slice is sorted.
type TimeMap struct {
	entries map[string][]entry
}

func Constructor() TimeMap {
	return TimeMap{entries: map[string][]entry{}}
}

func (this *TimeMap) Set(key string, value string, timestamp int) {
	this.entries[key] = append(this.entries[key], entry{timestamp, value})
}

func (this *TimeMap) Get(key string, timestamp int) string {
	es := this.entries[key]
	// The first entry set after timestamp; the one before it is the answer.
	i := sort.Search(len(es), func(i int) bool { return es[i].timestamp > timestamp })
	if i == 0 {
		return ""
	}
	return es[i-1].value
}
