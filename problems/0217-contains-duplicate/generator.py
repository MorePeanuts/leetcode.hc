LO, HI = -10**9, 10**9


def distinct(rng, n):
    return {"nums": rng.sample(range(LO, HI + 1), n)}


def compact_distinct(rng, n):
    nums = list(range(-(n // 2), n - n // 2))
    rng.shuffle(nums)
    return {"nums": nums}


def with_pair(rng, n, i, j):
    nums = rng.sample(range(LO, HI + 1), n)
    nums[j] = nums[i]
    return {"nums": nums}


def all_equal(rng, n, value):
    return {"nums": [value] * n}


def ascending(rng, n):
    return {"nums": sorted(rng.sample(range(LO, HI + 1), n))}


def descending(rng, n):
    return {"nums": sorted(rng.sample(range(LO, HI + 1), n), reverse=True)}
