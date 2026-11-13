def path(rng, n):
    return {"n": n, "edges": [[i - 1, i] for i in range(1, n)]}


def star(rng, n):
    center = n - 1
    return {"n": n, "edges": [[center, i] for i in range(n - 1)]}


def broom(rng, n):
    handle = n // 2
    edges = [[i - 1, i] for i in range(1, handle)]
    edges += [[handle - 1, i] for i in range(handle, n)]
    rng.shuffle(edges)
    return {"n": n, "edges": edges}
