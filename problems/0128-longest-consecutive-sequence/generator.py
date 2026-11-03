def shuffled_run(rng, n, start):
    nums = list(range(start, start + n))
    rng.shuffle(nums)
    return {"nums": nums}


def random_values(rng, n):
    return {"nums": rng.sample(range(-10**9, 10**9 + 1), n)}


def all_equal(rng, n, value):
    return {"nums": [value] * n}


def evens_then_odds(rng, n):
    return {"nums": list(range(0, n, 2)) + list(range(1, n, 2))}


def repeated_start(rng, n):
    # A run of n // 2 values whose start is repeated n - n // 2 times: walking
    # the run from every occurrence of its start, not from each distinct
    # start once, is quadratic.
    k = n // 2
    nums = list(range(1, k + 1)) + [1] * (n - k)
    rng.shuffle(nums)
    return {"nums": nums}


def runs_with_noise(rng, n, runs):
    # Planted runs of the given lengths, each shuffled into the array with a
    # duplicate of every tenth value, and isolated noise values: the noise is
    # a multiple of 4 far from the runs, so it never touches a run or another
    # noise value.
    nums = []
    base = 0
    for length in runs:
        nums.extend(range(base, base + length))
        nums.extend(range(base, base + length, 10))
        base += length + 2
    noise = n - len(nums)
    nums.extend(4 * x for x in rng.sample(range(10**6, 250000000), noise))
    rng.shuffle(nums)
    return {"nums": nums}
