def chain(rng, n, side, offset=0):
    values = [(i + offset) % 201 - 100 for i in range(n)]
    root = [values[0]]
    for i, value in enumerate(values[1:]):
        if side == "left" or (side == "zigzag" and i % 2 == 0):
            root.extend([value, None])
        else:
            root.extend([None, value])
    while root and root[-1] is None:
        root.pop()
    return {"root": root}

def complete(rng, n):
    return {"root": [rng.randint(-100, 100) for _ in range(n)]}
