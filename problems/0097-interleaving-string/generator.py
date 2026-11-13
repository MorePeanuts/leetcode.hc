def ambiguous_failure(rng, n):
    return {"s1": "a" * n, "s2": "a" * n, "s3": "a" * (2*n-1) + "b"}
def alternating(rng, n):
    return {"s1": "a" * n, "s2": "b" * n, "s3": "ab" * n}
def competing_prefix(rng, n):
    return {"s1": "a" * (n-1) + "b", "s2": "a" * n, "s3": "a" * (2*n-1) + "b"}
