def rare_middle(rng, n):
    left = n // 2
    return {"s": "a" * left + "z" + "b" * (n - left - 1), "k": left - 1}


def alphabet_cycle(rng, n, k):
    return {"s": "".join(chr(97 + i % 26) for i in range(n)), "k": k}


def split_runs(rng, n):
    s = ("a" * 99 + "b") * (n // 100) + "a" * (n % 100)
    return {"s": s, "k": n // 100 + 1}
