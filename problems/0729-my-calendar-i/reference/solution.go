package main

import "sort"

type MyCalendar struct{ events [][2]int }

func Constructor() MyCalendar { return MyCalendar{} }
func (c *MyCalendar) Book(startTime int, endTime int) bool {
	i := sort.Search(len(c.events), func(i int) bool { return c.events[i][0] >= startTime })
	if i > 0 && c.events[i-1][1] > startTime {
		return false
	}
	if i < len(c.events) && c.events[i][0] < endTime {
		return false
	}
	c.events = append(c.events, [2]int{})
	copy(c.events[i+1:], c.events[i:])
	c.events[i] = [2]int{startTime, endTime}
	return true
}
