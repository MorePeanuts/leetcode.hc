# Grids of m x n cells, 1 <= m, n <= 300, each "0" (water) or "1" (land).


def _grid(rows):
    return {"grid": [list(row) for row in rows]}


def all_land(rng, m, n):
    return _grid(["1" * n] * m)


def all_water(rng, m, n):
    return _grid(["0" * n] * m)


def checkerboard(rng, m, n):
    # Land where r + c is even: m * n / 2 islands of one cell, which touch
    # only diagonally.
    return _grid(["".join("1" if (r + c) % 2 == 0 else "0" for c in range(n)) for r in range(m)])


def random_grid(rng, m, n, percent):
    # Each cell is land with probability percent / 100.
    return _grid(["".join("1" if rng.randint(1, 100) <= percent else "0" for _ in range(n)) for _ in range(m)])


def snake(rng, m, n):
    # One island winding through the grid: full rows of land on even rows,
    # joined at alternating ends. Its path is about m * n / 2 cells long,
    # the deepest a depth-first search can go.
    rows = []
    for r in range(m):
        if r % 2 == 0:
            rows.append("1" * n)
        elif r % 4 == 1:
            rows.append("0" * (n - 1) + "1")
        else:
            rows.append("1" + "0" * (n - 1))
    return _grid(rows)


def spiral(rng, m, n):
    # One island spiralling inwards from the border, a ring of water
    # between its turns.
    g = [["0"] * n for _ in range(m)]
    top, left, bottom, right = 0, 0, m - 1, n - 1
    r, c = 0, 0
    while top <= bottom and left <= right:
        for c in range(left, right + 1):
            g[top][c] = "1"
        for r in range(top, bottom + 1):
            g[r][right] = "1"
        if top + 2 <= bottom:
            for c in range(right, left - 1, -1):
                g[bottom][c] = "1"
        if left + 2 <= right and top + 2 <= bottom:
            for r in range(bottom, top + 1, -1):
                g[r][left] = "1"
            g[top + 2][left + 1] = "1" if left + 1 <= right else g[top + 2][left + 1]
        top, left, bottom, right = top + 2, left + 2, bottom - 2, right - 2
    return {"grid": g}


def stripes(rng, m, n):
    # Vertical stripes of land one column wide: n / 2 islands of m cells.
    return _grid(["".join("1" if c % 2 == 0 else "0" for c in range(n))] * m)
