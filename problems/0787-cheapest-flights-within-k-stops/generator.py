def dense_dag(rng, n):
    flights = [[u, v, 1 + (v - u) % 100] for u in range(n) for v in range(u + 1, n)]
    rng.shuffle(flights)
    return {'n': n, 'flights': flights, 'src': 0, 'dst': n - 1, 'k': n - 1}


def chain(rng, n, allow):
    flights = [[i, i + 1, 1] for i in range(n - 1)] + [[0, n - 1, 10000]]
    return {'n': n, 'flights': flights, 'src': 0, 'dst': n - 1, 'k': n - 2 if allow else n - 3}
