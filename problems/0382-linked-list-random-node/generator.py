def draws(rng, n, calls, mode):
    if mode == "distinct":
        values = list(range(-(n // 2), n - n // 2))
    elif mode == "duplicates":
        values = [-10000] * (n * 9 // 10) + [10000] * (n - n * 9 // 10)
    elif mode == "alternating":
        values = [-10000 if i % 2 else 10000 for i in range(n)]
    else:
        values = [rng.randint(-10000, 10000) for _ in range(n)]
    return {"ops": ["Solution"] + ["getRandom"] * calls,
            "args": [[values]] + [[] for _ in range(calls)]}
