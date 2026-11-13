def uniform(rng, n, value):
    return {"nums": [value] * n}
def alternating(rng, n):
    return {"nums": [3 if i % 2 else -2 for i in range(n)]}
