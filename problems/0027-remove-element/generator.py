def mixed(rng, n):
    return {"nums": [0 if i % 5 < 2 else rng.randint(1, 50) for i in range(n)], "val": 0}


def tail_matches(rng, n):
    return {"nums": [50] + [i % 50 for i in range(n // 2)] + [50] * (n - n // 2 - 1), "val": 50}
