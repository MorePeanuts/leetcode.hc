def random_temps(rng, n):
    return {"temperatures": [rng.randint(30, 100) for _ in range(n)]}


def all_equal(rng, n, value):
    # No day is ever warmer: every answer is 0, and scanning ahead from each
    # day reaches the end.
    return {"temperatures": [value] * n}


def warm_at_end(rng, n):
    # 99 every day but the last, which is 100: every day waits for the last,
    # and scanning ahead from each day reaches it.
    return {"temperatures": [99] * (n - 1) + [100]}


def sawtooth(rng, n):
    # 100 down to 30, over and over: every day but a 100 waits for the day
    # one step warmer in the next block, 70 days later (a 30 waits 1 day).
    return {"temperatures": [100 - i % 71 for i in range(n)]}


def rising(rng, n):
    # Slowly rising: each temperature held for a run of days, so most days
    # wait for the next run.
    run = max(1, n // 71)
    return {"temperatures": [min(100, 30 + i // run) for i in range(n)]}


def valleys(rng, n):
    # Random descents, each ended by a jump to a warmer day.
    temps = []
    while len(temps) < n:
        top = rng.randint(31, 100)
        length = rng.randint(1, top - 30)
        temps.extend(range(top - 1, top - 1 - length, -1))
        temps.append(top)
    return {"temperatures": temps[:n]}
