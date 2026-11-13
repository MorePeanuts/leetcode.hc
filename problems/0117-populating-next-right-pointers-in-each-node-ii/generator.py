def complete(rng, n):
    return {"root": [rng.randint(-100, 100) for _ in range(n)]}


def chain(rng, n, side):
    values = [rng.randint(-100, 100)]
    for i in range(1, n):
        value = rng.randint(-100, 100)
        right = side == "right" or (side == "alternating" and i % 2 == 1)
        values.extend([None, value] if right else [value, None])
    while values and values[-1] is None:
        values.pop()
    return {"root": values}


def sparse(rng, n):
    values = [rng.randint(-100, 100)]
    pending = 1
    nodes = 1
    while nodes < n:
        pending -= 1
        for slot in range(2):
            take = nodes < n and (rng.random() < 0.75 or pending == 0 and slot == 1)
            if take:
                values.append(rng.randint(-100, 100))
                nodes += 1
                pending += 1
            else:
                values.append(None)
    while values[-1] is None:
        values.pop()
    return {"root": values}
