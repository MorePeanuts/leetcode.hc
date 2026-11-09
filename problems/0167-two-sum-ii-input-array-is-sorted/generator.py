# Every input has exactly one answer by construction.
#
# - largest / smallest: the answer is the two largest values a < b (or
#   a == b twice), every other value is below a, so every other pair sums to
#   less than a + b; mirrored for the two smallest.
# - parity: the fillers are even, the target odd, the answer values an odd a
#   and an even b = target - a that no filler equals. An even + even sum is
#   even, and filler + a == target only for filler == b.


def largest(rng, n, a, b):
    # The answer at the last two indices: a scan over pairs reaches it last.
    fillers = sorted(rng.randint(-1000, a - 1) for _ in range(n - 2))
    return {"numbers": fillers + [a, b], "target": a + b}


def smallest(rng, n, a, b):
    # The answer at the first two indices; two pointers move the right one
    # all the way down.
    fillers = sorted(rng.randint(b + 1, 1000) for _ in range(n - 2))
    return {"numbers": [a, b] + fillers, "target": a + b}


def parity(rng, n, target, a):
    # The answer anywhere in the array, among repeated fillers.
    b = target - a
    evens = [v for v in range(-1000, 1001, 2) if v != b]
    fillers = [rng.choice(evens) for _ in range(n - 2)]
    return {"numbers": sorted(fillers + [a, b]), "target": target}


def few_values(rng, n, a, b):
    # Like largest, but the fillers repeat only three values below a.
    pool = rng.sample(range(-1000, a), 3)
    fillers = sorted(rng.choice(pool) for _ in range(n - 2))
    return {"numbers": fillers + [a, b], "target": a + b}
