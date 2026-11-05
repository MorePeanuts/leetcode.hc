def random_piles(rng, n, h):
    return {"piles": [rng.randint(1, 10**9) for _ in range(n)], "h": h}


def all_max(rng, n, h):
    # Every pile 10^9: with h = n the answer is 10^9, the largest possible.
    return {"piles": [10**9] * n, "h": h}


def planted_speed(rng, n, k):
    # Random piles and h = the hours they take at speed k: the answer is at
    # most k, and the hours at the answer are exactly h.
    piles = [rng.randint(1, 10**9) for _ in range(n)]
    h = sum((p + k - 1) // k for p in piles)
    return {"piles": piles, "h": h}


def small_piles(rng, n, h):
    return {"piles": [rng.randint(1, 10) for _ in range(n)], "h": h}
