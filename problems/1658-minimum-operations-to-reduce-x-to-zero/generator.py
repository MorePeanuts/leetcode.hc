def equal(rng, n, value, x):
    return {"nums": [value] * n, "x": x}

def alternating(rng, n):
    return {"nums": [1 if i % 2 == 0 else 3 for i in range(n)], "x": n}
