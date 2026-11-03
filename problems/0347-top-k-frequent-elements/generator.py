# Every input has a unique answer by construction: the k-th most frequent
# value is always strictly more frequent than the (k+1)-th.

LO, HI = -10**4, 10**4


def distinct_freqs(rng, m, k):
    # m values with the frequencies 1 to m, shuffled.
    values = rng.sample(range(LO, HI + 1), m)
    nums = [v for f, v in enumerate(values, 1) for _ in range(f)]
    rng.shuffle(nums)
    return {"nums": nums, "k": k}


def every_value(rng, k):
    # Every value from -10^4 to 10^4 once, k of them 1 to k more times.
    nums = list(range(LO, HI + 1))
    top = rng.sample(nums, k)
    nums += [v for f, v in enumerate(top, 1) for _ in range(f)]
    rng.shuffle(nums)
    return {"nums": nums, "k": k}


def two_values(rng, n, k):
    # n - 1 copies of 3 and one -3 in the middle.
    nums = [3] * (n - 1)
    nums.insert(n // 2, -3)
    return {"nums": nums, "k": k}


def near_tie(rng, n, m, k):
    # m values of equal frequency, k of them one more time.
    values = rng.sample(range(LO, HI + 1), m)
    f = (n - k) // m
    nums = [v for v in values for _ in range(f)] + values[:k]
    rng.shuffle(nums)
    return {"nums": nums, "k": k}
