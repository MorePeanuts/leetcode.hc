def dense(rng, n, reverse=False, reachable=True):
    order = [0] + list(range(n - 2, 0, -1)) + [n - 1]
    graph = [[] for _ in range(n)]
    for i, node in enumerate(order):
        graph[node] = [v for v in order[i + 1:] if reachable or v != n - 1]
        if reverse:
            graph[node].reverse()
    return {"graph": graph}
