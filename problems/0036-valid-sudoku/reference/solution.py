class Solution:
    def isValidSudoku(self, board: list[list[str]]) -> bool:
        seen: set[tuple[str, int, str]] = set()
        for i in range(9):
            for j in range(9):
                c = board[i][j]
                if c == ".":
                    continue
                keys = [("row", i, c), ("col", j, c), ("box", i // 3 * 3 + j // 3, c)]
                for key in keys:
                    if key in seen:
                        return False
                    seen.add(key)
        return True
