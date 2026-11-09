# Lists of up to 5000 nodes, values in [-5000, 5000].


def random_list(rng, n):
    return {"head": [rng.randint(-5000, 5000) for _ in range(n)]}


def ascending(rng, n):
    # n distinct values from -5000 up: a long list that a recursive solution
    # walks n calls deep.
    return {"head": list(range(-5000, -5000 + n))}
