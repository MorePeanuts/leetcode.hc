def draws(rng, n, calls, mode):
    if mode == "equal":
        weights = [100000] * n
    elif mode == "last-heavy":
        weights = [1] * (n - 1) + [100000]
    elif mode == "first-heavy":
        weights = [100000] + [1] * (n - 1)
    elif mode == "alternating":
        weights = [1 if i % 2 == 0 else 100000 for i in range(n)]
    elif mode == "ramp":
        weights = [1 + i * 99999 // max(1, n - 1) for i in range(n)]
    else:
        weights = [rng.randint(1, 100000) for _ in range(n)]
    return {"ops": ["Solution"] + ["pickIndex"] * calls,
            "args": [[weights]] + [[] for _ in range(calls)]}
