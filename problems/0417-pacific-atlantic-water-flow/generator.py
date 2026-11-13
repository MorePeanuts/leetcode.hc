def plateau(rng, m, n, height):
    return {"heights": [[height] * n for _ in range(m)]}

def slope(rng, m, n):
    return {"heights": [[r*n+c for c in range(n)] for r in range(m)]}

def basin(rng, m, n):
    return {"heights": [[100000 if r in (0,m-1) or c in (0,n-1) else 0 for c in range(n)] for r in range(m)]}
