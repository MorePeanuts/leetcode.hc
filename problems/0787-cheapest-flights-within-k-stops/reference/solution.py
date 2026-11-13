class Solution:
    def findCheapestPrice(
        self, n: int, flights: list[list[int]], src: int, dst: int, k: int
    ) -> int:
        distance = [float('inf')] * n
        distance[src] = 0
        for _ in range(k + 1):
            following = distance.copy()
            for source, destination, price in flights:
                following[destination] = min(following[destination], distance[source] + price)
            distance = following
        return -1 if distance[dst] == float('inf') else distance[dst]
