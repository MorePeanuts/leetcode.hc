# Arrays of n + 1 integers in [1, n], n up to 10^5, in which exactly one
# value appears two or more times and every other value at most once.


def last_pair(rng, n):
    # A shuffle of 1..n-1, then n twice: the duplicate is the largest value
    # and both its copies are at the end, the worst case of comparing pairs
    # or of counting each value in turn.
    nums = list(range(1, n))
    rng.shuffle(nums)
    return {"nums": nums + [n, n]}


def last_pair_value(rng, n):
    # A shuffle of the values other than a random duplicate d, then d twice
    # at the end.
    d = rng.randint(1, n)
    nums = [v for v in range(1, n + 1) if v != d]
    rng.shuffle(nums)
    return {"nums": nums + [d, d]}


def repeated(rng, n, k):
    # A random duplicate d appearing k times (k >= 2), the other n + 1 - k
    # values distinct, all shuffled.
    d = rng.randint(1, n)
    others = rng.sample(range(1, n), n + 1 - k)
    nums = [v if v < d else v + 1 for v in others] + [d] * k
    rng.shuffle(nums)
    return {"nums": nums}
