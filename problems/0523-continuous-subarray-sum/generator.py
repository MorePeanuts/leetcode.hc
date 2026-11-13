def equal(rng, n, value):
    return {"nums": [value] * n, "k": 2147483647}

def increasing(rng, n):
    return {"nums": [i % 30000 + 1 for i in range(n)], "k": 2147483647}
