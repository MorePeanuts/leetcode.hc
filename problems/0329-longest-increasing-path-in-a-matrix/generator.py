def snake(rng, n):
    return {"matrix": [[r*n + (c if r % 2 == 0 else n-1-c) for c in range(n)] for r in range(n)]}
def branching(rng, n):
    return {"matrix": [[r+c for c in range(n)] for r in range(n)]}
def plateau(rng, n):
    return {"matrix": [[2147483647] * n for _ in range(n)]}
