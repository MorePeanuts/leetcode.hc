def dense(rng, n, m):
    pairs = [(u, v) for u in range(1, n + 1) for v in range(1, n + 1) if u != v and v != u + 1]
    edges = [[i, i + 1, 1] for i in range(1, n)]
    edges += [[u, v, rng.randint(0, 100)] for u, v in rng.sample(pairs, m - len(edges))]
    rng.shuffle(edges)
    return {'times': edges, 'n': n, 'k': 1}


def chain(rng, n):
    return {'times': [[i, i + 1, 100] for i in range(n - 1, 0, -1)], 'n': n, 'k': 1}
