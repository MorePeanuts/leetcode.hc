def equal(rng, n, value):
    return {"nums": [value] * n}

def halves(rng, n):
    return {"nums": [0] * (n // 2) + [1] * (n - n // 2)}
