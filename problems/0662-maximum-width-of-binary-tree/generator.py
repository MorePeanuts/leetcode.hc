def complete(rng, n):
    return {"root": [rng.randint(-100, 100) for _ in range(n)]}


def chain(rng, n, right):
    root = [rng.randint(-100, 100)]
    for _ in range(n - 1):
        value = rng.randint(-100, 100)
        root.extend([None, value] if right else [value, None])
    while root[-1] is None:
        root.pop()
    return {"root": root}


def two_spines(rng, prefix, depth, near_limit=False):
    root = [1, None, None]
    tip = root
    for _ in range(prefix):
        tip[2] = [1, None, None]
        tip = tip[2]
    left = right = tip
    for i in range(depth):
        left[1] = [1, None, None]
        left = left[1]
        slot = 1 if near_limit and i == depth - 1 else 2
        right[slot] = [1, None, None]
        right = right[slot]
    queue = [root]
    values = []
    for node in queue:
        if node is None:
            values.append(None)
        else:
            values.append(node[0])
            queue.extend(node[1:])
    while values[-1] is None:
        values.pop()
    return {"root": values}
