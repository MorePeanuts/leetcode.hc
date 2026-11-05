def random_heights(rng, n, top):
    return {"heights": [rng.randint(0, top) for _ in range(n)]}


def increasing(rng, n):
    return {"heights": [i * 10**4 // (n - 1) for i in range(n)]}


def decreasing(rng, n):
    return {"heights": [(n - 1 - i) * 10**4 // (n - 1) for i in range(n)]}


def all_equal(rng, n, value):
    return {"heights": [value] * n}


def pyramid(rng, n):
    # Rising to 10^4 in the middle and falling again.
    half = n // 2
    return {"heights": [10**4 - abs(i - half) * 10**4 // half for i in range(n)]}


def sawtooth(rng, n, period):
    # Rising teeth of the given period: the stack fills and empties each time.
    return {"heights": [(i % period + 1) * 10**4 // period for i in range(n)]}
