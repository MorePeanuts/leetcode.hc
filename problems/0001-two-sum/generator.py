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
    if at == "ends":
        i, j = 0, n - 1
    elif at == "front":
        i, j = 0, 1
    elif at == "back":
        i, j = n - 2, n - 1
    else:
        i, j = sorted(rng.sample(range(n), 2))
    nums.insert(i, a)
    nums.insert(j, b)
    return {"nums": nums, "target": target}


def sorted_extremes(rng, n):
    nums = sorted(rng.sample(range(-999999996, 999999997, 3), n - 2))
    return {"nums": [-999999998] + nums + [999999997], "target": -1}


def all_equal(rng, n):
    return {"nums": [7] * (n - 2) + [2, 5], "target": 7}
