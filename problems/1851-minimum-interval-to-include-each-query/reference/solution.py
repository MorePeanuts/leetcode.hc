from heapq import heappop, heappush


class Solution:
    def minInterval(self, intervals: list[list[int]], queries: list[int]) -> list[int]:
        intervals.sort()
        answer = [-1] * len(queries)
        heap = []
        i = 0
        for query, index in sorted((q, j) for j, q in enumerate(queries)):
            while i < len(intervals) and intervals[i][0] <= query:
                left, right = intervals[i]
                heappush(heap, (right - left + 1, right))
                i += 1
            while heap and heap[0][1] < query:
                heappop(heap)
            if heap:
                answer[index] = heap[0][0]
        return answer
