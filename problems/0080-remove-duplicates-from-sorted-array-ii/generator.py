def paired(rng, n):
    return {"nums": [i // 2 - 10000 for i in range(n)]}

def all_equal(rng, n):
    return {"nums": [10000] * n}

def tripled(rng, n):
    return {"nums": [i // 3 - 5000 for i in range(n)]}
