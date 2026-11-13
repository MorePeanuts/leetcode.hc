def all_land(rng, m, n):
    return {"grid": [[1] * n for _ in range(m)]}

def snake(rng, m, n):
    grid = [[int(r % 2 == 0 or c == (n - 1 if r % 4 == 1 else 0)) for c in range(n)] for r in range(m)]
    return {"grid": grid}
