def ones(rng, n, k):
    return {"nums": [1] * n, "k": k}

def sparse_twos(rng, n):
    return {"nums": [2 if i % 5000 == 0 else 1 for i in range(n)], "k": 1000000}
