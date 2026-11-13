def identical(rng, n, width):
    return {"strs": ["a" * width for _ in range(n)]}

def late_mismatch(rng, n, width):
    return {"strs": ["z" * width for _ in range(n - 1)] + ["z" * (width - 1) + "a"]}

def last_empty(rng, n, width):
    return {"strs": ["a" * width for _ in range(n - 1)] + [""]}
