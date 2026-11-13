def units(rng, n):
    return {"nums": [-1 if i % 3 else 1 for i in range(n)]}
def bounded_blocks(rng, n):
    return {"nums": [0 if i % 9 == 8 else rng.randint(-5,5) for i in range(n)]}
def extreme_blocks(rng, n):
    return {"nums": [0 if i % 10 == 9 else -10 for i in range(n)]}
