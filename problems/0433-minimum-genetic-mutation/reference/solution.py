from collections import deque


class Solution:
    def minMutation(self, startGene: str, endGene: str, bank: list[str]) -> int:
        queue = deque([(startGene, 0)])
        remaining = set(bank)
        remaining.discard(startGene)
        while queue:
            current, steps = queue.popleft()
            if current == endGene:
                return steps
            neighbors = [word for word in remaining if sum(a != b for a, b in zip(current, word)) == 1]
            for word in neighbors:
                remaining.remove(word)
                queue.append((word, steps + 1))
        return -1
