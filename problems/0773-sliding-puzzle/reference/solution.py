from collections import deque


class Solution:
    def slidingPuzzle(self, board: list[list[int]]) -> int:
        neighbors = ((1, 3), (0, 2, 4), (1, 5), (0, 4), (1, 3, 5), (2, 4))
        start = tuple(board[0] + board[1])
        queue = deque([(start, 0)])
        seen = {start}
        while queue:
            state, moves = queue.popleft()
            if state == (1, 2, 3, 4, 5, 0):
                return moves
            blank = state.index(0)
            for to in neighbors[blank]:
                tiles = list(state)
                tiles[blank], tiles[to] = tiles[to], tiles[blank]
                next_state = tuple(tiles)
                if next_state not in seen:
                    seen.add(next_state)
                    queue.append((next_state, moves + 1))
        return -1
