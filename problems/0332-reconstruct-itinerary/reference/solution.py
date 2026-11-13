from collections import defaultdict


class Solution:
    def findItinerary(self, tickets: list[list[str]]) -> list[str]:
        edges = defaultdict(list)
        for source, destination in tickets:
            edges[source].append(destination)
        for destinations in edges.values():
            destinations.sort(reverse=True)
        stack = ['JFK']
        route = []
        while stack:
            if edges[stack[-1]]:
                stack.append(edges[stack[-1]].pop())
            else:
                route.append(stack.pop())
        return route[::-1]
