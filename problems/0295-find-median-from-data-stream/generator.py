# Call sequences for MedianFinder. n is the number of addNum and findMedian
# calls (at most 5 * 10^4); the constructor comes first and is not counted.
# Every sequence starts with addNum, so findMedian never sees an empty
# structure.

LO, HI = -10**5, 10**5


def _case(nums, every):
    # Adds nums in order, with a findMedian after every every-th add, and a
    # final findMedian.
    ops, args = ["MedianFinder"], [[]]
    for i, x in enumerate(nums, 1):
        ops.append("addNum")
        args.append([x])
        if i % every == 0:
            ops.append("findMedian")
            args.append([])
    if ops[-1] != "findMedian":
        ops.append("findMedian")
        args.append([])
    return {"ops": ops, "args": args}


def _count(n, every):
    # The number of adds that, with their finds, make at most n calls.
    adds = n * every // (every + 1)
    while adds + adds // every + (1 if adds % every else 0) > n:
        adds -= 1
    return adds


def random_stream(rng, n, every, lo, hi):
    # Random values in [lo, hi], a findMedian after every every-th add.
    k = _count(n, every)
    return _case([rng.randint(lo, hi) for _ in range(k)], every)


def sorted_stream(rng, n, every, order):
    # Values spread over the whole range, ascending or descending: every new
    # value lands on the same side of the median.
    k = _count(n, every)
    nums = [LO + (HI - LO) * i // max(k - 1, 1) for i in range(k)]
    if order == "descending":
        nums.reverse()
    return _case(nums, every)


def extremes(rng, n, every):
    # Alternating -10^5 and 10^5, with zero now and then: the median jumps
    # between the extremes and their mean.
    k = _count(n, every)
    nums = []
    for i in range(k):
        nums.append(0 if i % 7 == 6 else (HI if i % 2 else LO))
    return _case(nums, every)


def duplicates(rng, n, every, values):
    # Random picks from a few distinct values: long runs of equal elements
    # around the median.
    k = _count(n, every)
    pool = rng.sample(range(LO, HI + 1), values)
    return _case([rng.choice(pool) for _ in range(k)], every)
