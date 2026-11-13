def repeated(rng, n, pattern):
    return {"s": (pattern * ((n + len(pattern) - 1) // len(pattern)))[:n]}
