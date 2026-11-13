def bookings(rng, n, mode):
    if mode in ("ascending", "descending", "shuffled"):
        intervals = [[2 * i, 2 * i + 1] for i in range(n)]
        if mode == "descending":
            intervals.reverse()
        elif mode == "shuffled":
            rng.shuffle(intervals)
    elif mode == "adjacent":
        intervals = [[i, i + 1] for i in range(n)]
    elif mode == "covered":
        intervals = [[0, 1000000000]] + [[i, i + 1] for i in range(1, n)]
    else:
        intervals = []
        for _ in range(n):
            start = rng.randint(0, 999999999)
            end = start + rng.randint(1, min(100000, 1000000000 - start))
            intervals.append([start, end])
    return {"ops": ["MyCalendar"] + ["book"] * n,
            "args": [[]] + intervals}
