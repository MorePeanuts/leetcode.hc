LO, HI = -10**4, 10**4


def random_values(rng, n, lo=LO, hi=HI):
    return {"nums": [rng.randint(lo, hi) for _ in range(n)]}


def increasing(rng, n):
    # Strictly increasing: the answer is n, and every subsequence is
    # increasing, the worst case of a recursion without memoization.
    return {"nums": [LO + 8 * i for i in range(n)]}


def decreasing(rng, n):
    return {"nums": [HI - 8 * i for i in range(n)]}


def all_equal(rng, n, value):
    return {"nums": [value] * n}


def non_decreasing(rng, n):
    # Every value repeated: a non-strict comparison doubles the answer.
    return {"nums": [LO + i // 2 for i in range(n)]}


def interleaved(rng, n):
    # Two increasing runs interleaved, a high one and a low one: the answer
    # is ceil(n / 2), and a greedy that keeps the first run it sees fails.
    half = (n + 1) // 2
    nums = []
    for i in range(n):
        if i % 2 == 0:
            nums.append(i // 2)
        else:
            nums.append(-half + i // 2)
    return {"nums": nums}


def noisy_increasing(rng, n, noise):
    # An increasing trend with random noise: long answers built from many
    # nearby candidates.
    return {"nums": [max(LO, min(HI, LO + 8 * i + rng.randint(-noise, noise))) for i in range(n)]}
