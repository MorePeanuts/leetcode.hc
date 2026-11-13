def complete_bipartite(rng, n):
    middle = n // 2
    return {"graph": [list(range(middle, n)) if i < middle else list(range(middle)) for i in range(n)]}


def cycle(rng, n):
    return {"graph": [[(i - 1) % n, (i + 1) % n] for i in range(n)]}


def isolated(rng, n):
    return {"graph": [[] for _ in range(n)]}
