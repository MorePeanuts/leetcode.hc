class Solution:
    def exist(self, board: list[list[str]], word: str) -> bool:
        rows, cols = len(board), len(board[0])
        def search(row, col, pos):
            if not (0 <= row < rows and 0 <= col < cols) or board[row][col] != word[pos]:
                return False
            if pos == len(word) - 1:
                return True
            saved = board[row][col]
            board[row][col] = "#"
            found = (search(row+1, col, pos+1) or search(row-1, col, pos+1)
                     or search(row, col+1, pos+1) or search(row, col-1, pos+1))
            board[row][col] = saved
            return found
        return any(search(row, col, 0) for row in range(rows) for col in range(cols))
