def chain(rng, n):
    return {"bombs": [[1 + 2 * i, 1, 2] for i in range(n)]}


def two_clusters(rng, n):
    bombs = [[1 + i, 1, n] for i in range(n - 1)]
    bombs.append([100000, 100000, 1])
    return {"bombs": bombs}


def isolated(rng, n):
    return {"bombs": [[1 + 900 * i, 1 + 900 * i, 1] for i in range(n)]}
