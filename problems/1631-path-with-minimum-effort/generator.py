def snake(rng, n):
    heights = [[1] * n if row % 2 == 0 else [1000000] * n for row in range(n)]
    for row in range(1, n, 2):
        heights[row][n - 1 if (row // 2) % 2 == 0 else 0] = 1
    return {"heights": heights}


def random_heights(rng, n):
    return {"heights": [[rng.randint(1, 1000000) for _ in range(n)] for _ in range(n)]}


def line(rng, n):
    return {"heights": [[1 if i % 2 == 0 else 1000000 for i in range(n)]]}
