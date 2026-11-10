TOP = 10**4


def random_values(rng, n, k, top=TOP):
    return {"nums": [rng.randint(-top, top) for _ in range(n)], "k": k}


def descending(rng, n, k):
    # Decreasing from 10^4 to -10^4: the maximum leaves every window as the
    # window moves on.
    return {"nums": [TOP - i * 2 * TOP // (n - 1) for i in range(n)], "k": k}


def ascending(rng, n, k):
    return {"nums": [-TOP + i * 2 * TOP // (n - 1) for i in range(n)], "k": k}


def all_equal(rng, n, k):
    return {"nums": [rng.randint(-TOP, TOP)] * n, "k": k}


def descending_noisy(rng, n, k):
    # Decreasing overall, with small random noise: the maximum still leaves
    # almost every window, and values repeat.
    return {"nums": [max(-TOP, TOP - i * 2 * TOP // n - rng.randint(0, 5)) for i in range(n)], "k": k}
