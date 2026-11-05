import heapq


class MedianFinder:
    # Two heaps: low holds the smaller half (negated, a max-heap), high the
    # larger half; low has as many elements as high, or one more.
    def __init__(self):
        self.low: list[int] = []
        self.high: list[int] = []

    def addNum(self, num: int) -> None:
        if self.low and num > -self.low[0]:
            heapq.heappush(self.high, num)
        else:
            heapq.heappush(self.low, -num)
        if len(self.low) > len(self.high) + 1:
            heapq.heappush(self.high, -heapq.heappop(self.low))
        elif len(self.high) > len(self.low):
            heapq.heappush(self.low, -heapq.heappop(self.high))

    def findMedian(self) -> float:
        if len(self.low) > len(self.high):
            return float(-self.low[0])
        return (-self.low[0] + self.high[0]) / 2
