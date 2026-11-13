def chain(rng, n, probability, reverse):
    edges = [[i, i + 1] for i in range(n - 1)]
    if reverse:
        edges = [[b, a] for a, b in reversed(edges)]
    return {"n": n, "edges": edges, "succProb": [probability] * (n - 1), "start_node": 0, "end_node": n - 1}


def shortcuts(rng, n):
    edges = [[i, i + 1] for i in range(n - 1)] + [[i, i + 2] for i in range(n - 2)]
    return {"n": n, "edges": edges, "succProb": [0.99999] * (n - 1) + [0.5] * (n - 2), "start_node": 0, "end_node": n - 1}
