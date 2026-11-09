# Call sequences for KthLargest: the constructor with k and nums
# (len(nums) <= 10^4, 1 <= k <= len(nums) + 1), then m calls to add
# (m <= 10^4). Every value is in [-10^4, 10^4].

LO, HI = -10**4, 10**4


def _case(k, nums, vals):
    return {
        "ops": ["KthLargest"] + ["add"] * len(vals),
        "args": [[k, nums]] + [[v] for v in vals],
    }


def random_stream(rng, n, m, k):
    # n random initial values and m random adds.
    nums = [rng.randint(LO, HI) for _ in range(n)]
    vals = [rng.randint(LO, HI) for _ in range(m)]
    return _case(k, nums, vals)


def ascending_adds(rng, n, m, k):
    # n random initial values below 0, then m adds ascending over [0, 10^4]:
    # every add enters the k largest and moves the k-th largest up.
    nums = [rng.randint(LO, -1) for _ in range(n)]
    vals = [HI * i // max(m - 1, 1) for i in range(m)]
    return _case(k, nums, vals)


def descending_adds(rng, n, m, k):
    # n random initial values above 0, then m adds descending from 0 to
    # -10^4: each is the smallest value so far, the front of a sorted array.
    nums = [rng.randint(1, HI) for _ in range(n)]
    vals = [-(HI * i // max(m - 1, 1)) for i in range(m)]
    return _case(k, nums, vals)


def empty_start(rng, m):
    # No initial values, k = 1, m random adds.
    return _case(1, [], [rng.randint(LO, HI) for _ in range(m)])


def few_values(rng, n, m, k, values):
    # Values drawn from a few distinct ones: many ties at the k-th largest.
    pool = rng.sample(range(LO, HI + 1), values)
    nums = [rng.choice(pool) for _ in range(n)]
    vals = [rng.choice(pool) for _ in range(m)]
    return _case(k, nums, vals)
