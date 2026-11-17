def chain(rng, n, side):
    root = [0]
    for value in range(1, n):
        if side == "left":
            root.extend([value, None])
        else:
            root.extend([None, value])
    while root[-1] is None:
        root.pop()
    return {"root": root, "p": n - 2, "q": n - 1}

def complete(rng, n):
    values = list(range(n))
    rng.shuffle(values)
    return {"root": values, "p": values[n - 2], "q": values[n - 1]}
