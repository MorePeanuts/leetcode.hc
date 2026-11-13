def uniform(rng, n):
    return {"nums": [100] * n}
def varied(rng, n):
    return {"nums": [rng.randint(0, 100) for _ in range(n)]}
def alternating(rng, n):
    return {"nums": [0 if i % 2 else 99 for i in range(n)]}
