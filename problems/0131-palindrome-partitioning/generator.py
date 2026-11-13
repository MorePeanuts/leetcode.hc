def repeated(rng, n, pattern):
    return {"s": (pattern * n)[:n]}


def framed(rng, n):
    return {"s": "a" + "b" * (n - 2) + "a"}
