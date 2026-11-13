def distinct(rng, n):
    return {"nums": list(range(n)), "k": n}

def far_duplicate(rng, n):
    return {"nums": list(range(n - 1)) + [0], "k": n - 2}

def last_pair(rng, n):
    return {"nums": list(range(n - 1)) + [n - 2], "k": n}
