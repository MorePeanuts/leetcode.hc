package main

import "sort"

func eraseOverlapIntervals(intervals [][]int) int {
	sort.Slice(intervals, func(i, j int) bool { return intervals[i][1] < intervals[j][1] })
	end, kept := intervals[0][1], 1
	for _, interval := range intervals[1:] {
		if interval[0] >= end {
			kept++
			end = interval[1]
		}
	}
	return len(intervals) - kept
}
