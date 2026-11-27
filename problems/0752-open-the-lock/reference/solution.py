from collections import deque


class Solution:
    def openLock(self, deadends: list[str], target: str) -> int:
        seen = bytearray(10000)
        for dead in deadends:
            seen[int(dead)] = 1
        if seen[0]:
            return -1
        goal = int(target)
        queue = deque([0])
        seen[0] = 1
        turns = 0
        while queue:
            for _ in range(len(queue)):
                state = queue.popleft()
                if state == goal:
                    return turns
                for place in (1, 10, 100, 1000):
                    digit = state // place % 10
                    up = state + (-9 if digit == 9 else 1) * place
                    down = state + (9 if digit == 0 else -1) * place
                    for neighbor in (up, down):
                        if not seen[neighbor]:
                            seen[neighbor] = 1
                            queue.append(neighbor)
            turns += 1
        return -1
