TOP = 10**4


def random_values(rng, n, top, share):
    # Random values in [1, top], and target a share (in percent) of their
    # total: the answer is about that share of n.
    nums = [rng.randint(1, top) for _ in range(n)]
    return {"target": max(1, sum(nums) * share // 100), "nums": nums}


def no_answer(rng, n):
    # target is one more than the whole sum: the answer is 0.
    nums = [rng.randint(1, TOP) for _ in range(n)]
    return {"target": sum(nums) + 1, "nums": nums}


def whole_array(rng, n):
    # target is exactly the whole sum: only the whole array reaches it.
    nums = [rng.randint(1, TOP) for _ in range(n)]
    return {"target": sum(nums), "nums": nums}


def all_max(rng, n):
    # Every value 10^4 and target 10^9: with n = 10^5 the whole sum is
    # exactly target.
    return {"target": 10**9, "nums": [TOP] * n}


def spike_at_end(rng, n):
    # Small values, and target reached by a large value near the end with
    # its neighbours: the shortest window is at the very end.
    nums = [rng.randint(1, 10) for _ in range(n)]
    nums[-1] = TOP
    nums[-2] = TOP
    return {"target": 2 * TOP, "nums": nums}
