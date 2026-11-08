def descending(rng, n, start):
    return {"nums": list(range(start, start - n, -1))}


def ascending(rng, n):
    return {"nums": list(range(-n // 2, -n // 2 + n))}


def random_values(rng, n):
    return {"nums": [rng.randint(-50000, 50000) for _ in range(n)]}


def equal(rng, n, value):
    return {"nums": [value] * n}


def two_blocks(rng, n):
    return {"nums": [50000] * (n // 2) + [-50000] * (n - n // 2)}


def organ_pipe(rng, n):
    middle = (n + 1) // 2
    return {"nums": list(range(middle)) + list(range(n - middle, 0, -1))}
