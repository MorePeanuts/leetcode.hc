# Inputs for findKthLargest: 1 <= k <= n <= 10^5 values in [-10^4, 10^4].

LO, HI = -10**4, 10**4


def random_values(rng, n, k):
    # n random values over the whole range.
    return {"nums": [rng.randint(LO, HI) for _ in range(n)], "k": k}


def ascending(rng, n, k):
    # n values non-decreasing over the whole range: the worst case of a
    # quickselect that takes the first or last element as its pivot.
    return {"nums": [LO + (HI - LO) * i // (n - 1) for i in range(n)], "k": k}


def descending(rng, n, k):
    # n values non-increasing over the whole range.
    return {"nums": [HI - (HI - LO) * i // (n - 1) for i in range(n)], "k": k}


def all_equal(rng, n, k, v):
    # n copies of v: the worst case of a two-way partition, whatever its pivot.
    return {"nums": [v] * n, "k": k}


def few_values(rng, n, k, values):
    # n values drawn from a few distinct ones: long runs equal to the pivot.
    pool = rng.sample(range(LO, HI + 1), values)
    return {"nums": [rng.choice(pool) for _ in range(n)], "k": k}
