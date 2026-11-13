class Solution:
    def eraseOverlapIntervals(self, intervals: list[list[int]]) -> int:
        intervals.sort(key=lambda interval: interval[1])
        end = intervals[0][1]
        kept = 1
        for start, finish in intervals[1:]:
            if start >= end:
                kept += 1
                end = finish
        return len(intervals) - kept
