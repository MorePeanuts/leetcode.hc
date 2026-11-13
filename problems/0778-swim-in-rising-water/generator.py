def shuffled(rng, n):
    values = list(range(n * n))
    rng.shuffle(values)
    return {'grid': [values[r * n : (r + 1) * n] for r in range(n)]}


def late_destination(rng, n):
    return {'grid': [list(range(r * n, (r + 1) * n)) for r in range(n)]}


def barrier(rng, n):
    # A high middle row blocks the low endpoints until late water levels.
    cells = [(r, c) for r in range(n) for c in range(n) if r != n // 2] + [
        (n // 2, c) for c in range(n)
    ]
    grid = [[0] * n for _ in range(n)]
    for value, (r, c) in enumerate(cells):
        grid[r][c] = value
    grid[-1][-1], grid[0][1] = grid[0][1], grid[-1][-1]
    return {'grid': grid}
