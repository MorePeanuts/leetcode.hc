def random_heights(rng, n):
    return {"height": [rng.randint(0, 10**4) for _ in range(n)]}


def increasing(rng, n):
    return {"height": [i * 10**4 // (n - 1) for i in range(n)]}


def decreasing(rng, n):
    return {"height": [(n - 1 - i) * 10**4 // (n - 1) for i in range(n)]}


def all_equal(rng, n, value):
    return {"height": [value] * n}


def tall_inside(rng, n):
    # Short lines everywhere except two of height 10^4 at a quarter and three
    # quarters of the way: the widest containers lose to the one between them.
    height = [rng.randint(0, 100) for _ in range(n)]
    height[n // 4] = 10**4
    height[3 * n // 4] = 10**4
    return {"height": height}


def valley(rng, n):
    # Tall at both ends, falling to 0 in the middle: the answer is the ends.
    half = n // 2
    return {"height": [abs(i - half) * 10**4 // half for i in range(n)]}
