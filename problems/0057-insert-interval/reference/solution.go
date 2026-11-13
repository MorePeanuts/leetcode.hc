package main

func insert(intervals [][]int, newInterval []int) [][]int {
	answer := make([][]int, 0, len(intervals)+1)
	start, end := newInterval[0], newInterval[1]
	i := 0
	for i < len(intervals) && intervals[i][1] < start {
		answer = append(answer, intervals[i])
		i++
	}
	for i < len(intervals) && intervals[i][0] <= end {
		start = min(start, intervals[i][0])
		end = max(end, intervals[i][1])
		i++
	}
	answer = append(answer, []int{start, end})
	return append(answer, intervals[i:]...)
}
