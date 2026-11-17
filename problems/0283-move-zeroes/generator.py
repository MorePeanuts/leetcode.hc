def leading_zeroes(rng, n):
    return {"nums": [0] * (n // 2) + list(range(1, n - n // 2 + 1))}

def alternating(rng, n):
    return {"nums": [0 if i % 2 == 0 else -i for i in range(n)]}
