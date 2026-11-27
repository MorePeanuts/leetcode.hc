class Solution:
    def maximumDetonation(self, bombs: list[list[int]]) -> int:
        edges = [[] for _ in bombs]
        for i, (x, y, radius) in enumerate(bombs):
            for j, (other_x, other_y, _) in enumerate(bombs):
                dx, dy = x - other_x, y - other_y
                if i != j and dx * dx + dy * dy <= radius * radius:
                    edges[i].append(j)

        best = 0
        for start in range(len(bombs)):
            seen = {start}
            stack = [start]
            while stack:
                for node in edges[stack.pop()]:
                    if node not in seen:
                        seen.add(node)
                        stack.append(node)
            best = max(best, len(seen))
            if best == len(bombs):
                break
        return best
