def descending(rng, n):
    return {"nums": [2 - (3 * i // n) for i in range(n)]}

def alternating(rng, n):
    return {"nums": [2 - i % 3 for i in range(n)]}

def mixed(rng, n):
    return {"nums": [rng.randint(0, 2) for _ in range(n)]}
