def uniform(rng, n, jump):
    return {"nums": [jump] * (n - 1) + [0]}
def sparse(rng, n):
    return {"nums": [2 if i % 2 == 0 else 0 for i in range(n)]}
