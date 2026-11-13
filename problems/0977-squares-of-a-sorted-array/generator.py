def negative(rng, n):
    return {"nums": list(range(-n, 0))}

def mixed(rng, n):
    return {"nums": list(range(-n // 2, n - n // 2))}

def ties(rng, n):
    return {"nums": [-10000]*(n//2) + [10000]*(n-n//2)}
