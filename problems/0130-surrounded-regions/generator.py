def open_board(rng, m, n):
    return {"board": [["O"] * n for _ in range(m)]}

def enclosed(rng, m, n, gap=False):
    board = [["X" if r in (0,m-1) or c in (0,n-1) else "O" for c in range(n)] for r in range(m)]
    if gap:
        board[0][n//2] = "O"
    return {"board": board}

def snake(rng, m, n):
    board = [["X"]*n for _ in range(m)]
    for r in range(1,m-1):
        if r%2:
            for c in range(1,n-1):board[r][c]="O"
        else:board[r][n-2 if r%4==2 else 1]="O"
    board[0][1]="O"
    return {"board":board}
