class Solution:
    def solve(self, board):
        rows, cols = len(board), len(board[0])
        stack = []
        def mark(r,c):
            if board[r][c] == "O":
                board[r][c] = "#"
                stack.append((r,c))
        for r in range(rows):
            mark(r,0)
            mark(r,cols-1)
        for c in range(cols):
            mark(0,c)
            mark(rows-1,c)
        while stack:
            r,c = stack.pop()
            for nr,nc in ((r-1,c),(r+1,c),(r,c-1),(r,c+1)):
                if 0 <= nr < rows and 0 <= nc < cols:
                    mark(nr,nc)
        for r in range(rows):
            for c in range(cols):
                board[r][c] = "O" if board[r][c] == "#" else "X"
