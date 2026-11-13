def almost_full(rng, n):
    return {"s": "a" * n, "t": "a" * (n-1)}
def late_failure(rng, n):
    return {"s": "a" * n, "t": "a" * (n//2) + "b"}
def equal_strings(rng, n):
    s = "".join(chr(65 + i % 26) for i in range(n))
    return {"s": s, "t": s}
