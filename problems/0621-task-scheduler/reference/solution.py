import heapq
from collections import Counter, deque


class Solution:
    # Simulate: at each interval run the task with the most copies left among
    # those not cooling down (a max-heap of counts); a task that ran waits in
    # a queue until its gap of n intervals is over. When every task left is
    # cooling down, skip the idle intervals at once.
    def leastInterval(self, tasks: list[str], n: int) -> int:
        heap = [-c for c in Counter(tasks).values()]
        heapq.heapify(heap)
        cooling: deque[tuple[int, int]] = deque()  # (-count left, last interval idle)
        time = 0
        while heap or cooling:
            time += 1
            if heap:
                left = heapq.heappop(heap) + 1
                if left:
                    cooling.append((left, time + n))
            else:
                time = cooling[0][1]
            if cooling and cooling[0][1] == time:
                heapq.heappush(heap, cooling.popleft()[0])
        return time
