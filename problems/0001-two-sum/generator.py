# Every input has exactly one answer by construction: the filler values are
# multiples of 3, the target is 2 mod 3 and the two answer values are 1 mod 3,
# so filler + filler and filler + answer value never reach the target.


def _answer(rng):
    target = 3 * rng.randint(-333333333, 333333332) + 2
    lo, hi = max(-10**9, target - 10**9), min(10**9, target + 10**9)
    a = 3 * rng.randint(-((1 - lo) // 3), (hi - 1) // 3) + 1
    return a, target - a, target


def distinct(rng, n, at):
    nums = rng.sample(range(-999999999, 10**9, 3), n - 2)
    a, b, target = _answer(rng)
    # The answer at the last two indices ("back") or among the last 100
    # ("late"): a scan over pairs reaches it last.
    if at == "back":
        i, j = n - 2, n - 1
    else:
        i, j = sorted(rng.sample(range(n - 100, n), 2))
    nums.insert(i, a)
    nums.insert(j, b)
    return {"nums": nums, "target": target}


def sorted_back(rng, n, descending=False):
    # Ascending, the answer the two largest values, so a scan over pairs
    # reaches it last; descending, the values negated: the answer the two
    # smallest, last as well.
    target = 3 * rng.randint(300000000, 333333332) + 2
    a = 3 * rng.randint(target // 6, target // 3 - 1) + 1
    b = target - a
    nums = sorted(rng.sample(range(-999999999, b, 3), n - 2)) + [b, a]
    if descending:
        return {"nums": [-x for x in nums], "target": -target}
    return {"nums": nums, "target": target}


def repeated(rng, n, values):
    # The fillers drawn from a few values, so most of them repeat; the
    # answer at the last two indices.
    pool = rng.sample(range(-999999999, 10**9, 3), values)
    a, b, target = _answer(rng)
    return {"nums": [rng.choice(pool) for _ in range(n - 2)] + [a, b], "target": target}


def all_equal(rng, n):
    return {"nums": [7] * (n - 2) + [2, 5], "target": 7}
