def timestamps(rng, n, mode):
    if mode == "dense":
        times = list(range(1, n + 1))
    elif mode == "high":
        times = list(range(1000000001 - n, 1000000001))
    elif mode == "boundary":
        times = [1 + 3000 * i for i in range(n)]
    elif mode == "sparse":
        times = [1 + 3001 * i for i in range(n)]
    else:
        t = 1
        times = []
        for _ in range(n):
            times.append(t)
            t += rng.choice([1, 2, 2999, 3000, 3001, 10000])
    return {"ops": ["RecentCounter"] + ["ping"] * n,
            "args": [[]] + [[t] for t in times]}
