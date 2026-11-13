def equal_values(rng, n, value):
    return {"nums": [value]*n}
def impossible_even(rng, n):
    return {"nums": [100]*(n-1)+[98]}
def varied(rng, n):
    return {"nums": [rng.randint(1,100) for _ in range(n)]}
