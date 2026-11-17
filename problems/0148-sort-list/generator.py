def ascending(rng, n):
    return {"head": list(range(n))}

def shuffled(rng, n):
    values = list(range(-n // 2, n - n // 2))
    rng.shuffle(values)
    return {"head": values}

def descending(rng, n):
    return {"head": list(range(n, 0, -1))}
