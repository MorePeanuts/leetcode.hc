def chain(rng, n, direction="left"):
    values = [(i * 37) % 2001 - 1000 for i in range(n)]
    root = [values[0]]
    for i, value in enumerate(values[1:]):
        right = direction == "right" or (direction == "alternating" and i % 2 == 1)
        root.extend([None, value] if right else [value, None])
    while root[-1] is None:
        root.pop()
    return {"root": root}


def complete(rng, n):
    return {"root": [rng.randint(-1000, 1000) for _ in range(n)]}


def shallow_leaf(rng, n, leaf_on_left=True):
    """One depth-two leaf beside a long chain; deep traversal is unnecessary."""
    root = [0, 1, 2]
    if leaf_on_left:
        root.extend([None, None])
    for i in range(n - 3):
        root.extend([None, (i * 19) % 2001 - 1000])
        if i == 0 and not leaf_on_left:
            root.extend([None, None])
    return {"root": root}
