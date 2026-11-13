def all_land(rng, n):
    return {"grid": [[0] * n for _ in range(n)]}

def framed(rng, n):
    return {"grid": [[int(i in (0, n - 1) or j in (0, n - 1)) for j in range(n)] for i in range(n)]}

def checkerboard(rng, n):
    return {"grid": [[(i + j) % 2 for j in range(n)] for i in range(n)]}

def winding_escape(rng, n):
    grid = [[1] * n for _ in range(n)]
    for i in range(1, n - 1):
        if i % 2 == 1:
            for j in range(1, n - 1):
                grid[i][j] = 0
        else:
            grid[i][1 if i % 4 == 0 else n - 2] = 0
    grid[0][1] = 0
    return {"grid": grid}
