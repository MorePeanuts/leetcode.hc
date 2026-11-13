def chamber(rng, n, exit_open):
    maze = [["+"] * n for _ in range(n)]
    for row in range(1, n - 1):
        for col in range(1, n - 1):
            maze[row][col] = "."
    if exit_open:
        maze[0][n - 2] = "."
    return {"maze": maze, "entrance": [n - 2, 1]}


def snake(rng, n):
    maze = [["+"] * n for _ in range(n)]
    for row in range(1, n - 1, 2):
        for col in range(1, n - 1):
            maze[row][col] = "."
        if row + 1 < n - 1:
            maze[row + 1][n - 2 if (row // 2) % 2 == 0 else 1] = "."
    last_row = n - 2 if n % 2 else n - 3
    end_col = n - 2 if (last_row // 2) % 2 == 0 else 1
    for row in range(last_row + 1, n):
        maze[row][end_col] = "."
    return {"maze": maze, "entrance": [1, 1]}


def corridor(rng, n):
    return {"maze": [["."] for _ in range(n)], "entrance": [n // 2, 0]}
