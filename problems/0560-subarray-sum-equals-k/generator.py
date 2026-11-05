def random_values(rng, n, lo, hi, k):
    return {"nums": [rng.randint(lo, hi) for _ in range(n)], "k": k}


def all_equal(rng, n, value, k):
    return {"nums": [value] * n, "k": k}


def alternating(rng, n, k):
    # 1, -1, 1, -1, ...: prefix sums alternate between 1 and 0, so many
    # subarrays sum to 0 and to +-1.
    return {"nums": [1 if i % 2 == 0 else -1 for i in range(n)], "k": k}


def planted_max(rng, n):
    # Random values in [-1000, 999] around one run of 10^4 copies of 1000:
    # k = 10^7, the maximum, is reached only by that run.
    run = 10**4
    before = rng.randint(0, n - run)
    nums = [rng.randint(-1000, 999) for _ in range(before)]
    nums += [1000] * run
    nums += [rng.randint(-1000, 999) for _ in range(n - run - before)]
    return {"nums": nums, "k": 10**7}
