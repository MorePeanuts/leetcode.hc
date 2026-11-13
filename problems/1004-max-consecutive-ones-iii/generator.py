def all_ones(rng, n):
    return {"nums": [1] * n, "k": 0}

def alternating(rng, n):
    return {"nums": [i % 2 for i in range(n)], "k": n // 4}

def all_zeros(rng, n):
    return {"nums": [0] * n, "k": n // 2}
