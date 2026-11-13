class Solution:
    def findMinHeightTrees(self, n: int, edges: list[list[int]]) -> list[int]:
        if n <= 2:
            return list(range(n))
        graph = [[] for _ in range(n)]
        degree = [0] * n
        for a, b in edges:
            graph[a].append(b)
            graph[b].append(a)
            degree[a] += 1
            degree[b] += 1
        leaves = [node for node in range(n) if degree[node] == 1]
        remaining = n
        while remaining > 2:
            remaining -= len(leaves)
            next_leaves = []
            for leaf in leaves:
                for neighbor in graph[leaf]:
                    degree[neighbor] -= 1
                    if degree[neighbor] == 1:
                        next_leaves.append(neighbor)
            leaves = next_leaves
        return sorted(leaves)
