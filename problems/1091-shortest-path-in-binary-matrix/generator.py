def open_grid(rng, n):
    return {"grid": [[0] * n for _ in range(n)]}


def barrier(rng, n):
    grid = [[0] * n for _ in range(n)]
    grid[n // 2] = [1] * n
    return {"grid": grid}


def diagonal(rng, n):
    return {"grid": [[int(row != col) for col in range(n)] for row in range(n)]}


def snake(rng, n):
    grid = [[0] * n if row % 2 == 0 else [1] * n for row in range(n)]
    for row in range(1, n, 2):
        grid[row][n - 1 if (row // 2) % 2 == 0 else 0] = 0
    grid[-1] = [0] * n
    return {"grid": grid}
