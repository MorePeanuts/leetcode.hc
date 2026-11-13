class Solution:
    def insert(self, intervals: list[list[int]], newInterval: list[int]) -> list[list[int]]:
        answer = []
        start, end = newInterval
        i = 0
        while i < len(intervals) and intervals[i][1] < start:
            answer.append(intervals[i])
            i += 1
        while i < len(intervals) and intervals[i][0] <= end:
            start = min(start, intervals[i][0])
            end = max(end, intervals[i][1])
            i += 1
        answer.append([start, end])
        answer.extend(intervals[i:])
        return answer
