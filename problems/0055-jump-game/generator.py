def dead_end(rng, n):
    return {"nums": [n - 2 - i for i in range(n - 1)] + [0]}
def single_steps(rng, n):
    return {"nums": [1] * (n - 1) + [0]}
def alternating(rng, n):
    return {"nums": [2 if i % 2 == 0 else 0 for i in range(n)]}
