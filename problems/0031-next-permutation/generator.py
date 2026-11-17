def descending(rng, n):
    return {"nums": list(range(n, 0, -1))}

def repeated_suffix(rng, n):
    return {"nums": [0] + [100] * (n - 1)}
