def constant(rng, n, k):
    return {"mat": [[100] * n for _ in range(n)], "k": k}

def varied(rng, n, k):
    return {"mat": [[(i * 37 + j * 13) % 100 + 1 for j in range(n)] for i in range(n)], "k": k}
